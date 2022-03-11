#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using std::cin;
using std::cout;
using std::sqrt;
using std::string;
using std::to_string;
using std::setprecision;
using std::ios;
using std::endl;

int main() {
	bool Complex_number = false,
		Neg_numerator = false,
		Neg_solution = false;
	int Root_Coef = 1;
	double Denominator = 0.0,
		Discrim = 0.0,
		Simplify_root = 2.0,
		Simp_outside_root = 2.0,
		Value_a = 0.0,
		Value_b = 0.0,
		Value_c = 0.0,
		Whole_num_test = 0.0,
		Numerator = 0.0,
		Root_plus = 0.0,
		Root_minus = 0.0;
	string Root_coef_to_str = "";
	
	// Header
	cout << "Quadratic Equation Calculator" << "\n\n";
	cout << "This program solves for x when given a quadratic equation in the form \"ax^2 + bx + c = 0\"" << "\n\n";
	
	// Input
	cout << "Enter the value of a: ";
	cin >> Value_a;
	if (Value_a == 0)												// Error check, if a is equal to zero inform user of error and end program.
	{
		cout << "\n\n" << "The variable \"a\" cannot be 0.";
		return 0;
	}

	cout << "\n" << "Enter the value of b: ";
	cin >> Value_b;

	cout << "\n" << "Enter the value of c: ";
	cin >> Value_c;
	cout << "\n\n";

	// Processing

	Numerator = 0 - Value_b;											// Set -b in quadratic formula
	Discrim = (Value_b * Value_b) - (4 * Value_a * Value_c);			// Set discriminate in quadratic formula
	Denominator = 2 * Value_a;											// Set 2a in quadratic formula
	Neg_numerator = Numerator < 0 ? true : false;						// Value used for determining location of negative sign in exact solution												
	Neg_solution = Value_a < 0 && Value_b < 0 ? true : false;			// Value used for determining location of negative sign in exact solution
	Root_plus = (Numerator + sqrt(Discrim)) / Denominator;				// Holds value of plus root
	Root_minus = (Numerator - sqrt(Discrim)) / Denominator;				// Holds value of minus root
	Denominator = abs(Denominator);										// Sets denominator to positive value after accounting for sign
	Numerator = abs(Numerator);											// Sets numerator to positive value after accounting for sign
	
	if (Discrim < 0)													// Inform user the form of their roots
	{
	cout << "There are two complex roots." << "\n\n";					
	Complex_number = true;												// Tracks if complex number and converts
	Discrim = abs(Discrim);												// discriminate to non-negative number.
	}
	else if (Discrim == 0)
		cout << "There is one real number root." << "\n";
	else if (Discrim > 0)
		cout << "There are two real number roots." << "\n";

	while (Simplify_root * Simplify_root <= Discrim)											// Simplifies discriminate, simplify_root starts at 2
	{																							// because 1 would always evaluate as true.
		Whole_num_test = floor(Discrim / (Simplify_root * Simplify_root));
		if (Discrim / (Simplify_root * Simplify_root) == Whole_num_test)
		{																						// If discriminate can be divided into whole number by a square root of 
			Discrim = Discrim / (Simplify_root * Simplify_root);								// another number, divide discriminate and by the square root of a number and  
			Root_Coef = Root_Coef * Simplify_root;												// move other number out of discriminate and multiply by value outside the discriminate.															
		}
		else
			++Simplify_root;
	}
	while (Simp_outside_root < Denominator || Simp_outside_root < Numerator)		
	{																							// Simplifies what's outside the discriminate.		
		Whole_num_test = floor(Denominator / Simp_outside_root);								// Uses Whole number test to test if numerator outside the discriminate																						// Starts at value of 2.
		if (Denominator / Simp_outside_root == Whole_num_test)									// and denominator can share a multiple, if so divide out that 
		{																						// multiple.
			Whole_num_test = floor(Root_Coef / Simp_outside_root);
			if (Root_Coef / Simp_outside_root == Whole_num_test || Discrim == 0)
			{
				Whole_num_test = floor(Numerator / Simp_outside_root);
				if (Numerator / Simp_outside_root == Whole_num_test)
				{
					Numerator = Numerator / Simp_outside_root;
					Root_Coef = Root_Coef / Simp_outside_root;
					Denominator = Denominator / Simp_outside_root;
				}
				else
					++Simp_outside_root;
			}
			else
				++Simp_outside_root;
		}
		else
			++Simp_outside_root;
	}
	Root_coef_to_str = to_string(Root_Coef);		// Convert root coefficient to string for conditional operator use
	cout.setf(ios::fixed);		

	// Output
	cout << setprecision(1) << "You entered a = " << Value_a << ", b = " << Value_b << ", and c = " << Value_c << "." << "\n\n";
	cout << "The solution based on these values is: " << "\n\n" << setprecision(1);

	if (Discrim == 0)		// Output when just 1 root solution
	{
		cout << (Neg_solution == true ? "-" : "") << "(" << (Neg_numerator == true && Neg_solution != true ? "-" : "") << Numerator;

		if (Denominator != 1)																// Formatting, if denominator is 1 then it is excluded.
			cout << " / " << Denominator << ")";
		
		if (abs(Root_plus) != floor(abs(Root_plus)))										// Formatting, states exact value if solution is a whole number
			cout << "\n\nWhich is approximately: " << setprecision(6) << Root_plus;			// otherwise states approximate value.
		else
			cout << "\n\nWhich is exactly: " << setprecision(6) << Root_plus;
		
		cout << "\n\n" << "Since the discriminate is 0, both roots are the same.";
	}
	else if (Complex_number == true)		// Output when 2 complex root solutions
	{
		cout.precision(1);
		cout << (Neg_solution == true ? "-" : "") << "(" << (Neg_numerator == true && Neg_solution != true ? "-" : "") << Numerator					// First root
			<< (Neg_numerator == true ? " - " : " + ") << (Root_Coef != 1 ? Root_coef_to_str : "") << (Complex_number == true ? "i" : "")			// solution
			<< (Discrim != 0 ? " sqrt " : "") << Discrim << ")";		
		
		if (Denominator != 1)													// Formatting, if denominator is 1 then it is excluded.
			cout << " / " << Denominator << "\n";

		cout << "\nand\n\n";

		cout << (Neg_solution == true ? "-" : "") << "(" << (Neg_numerator == true && Neg_solution != true ? "-" : "") << Numerator					// Second root
			<< (Neg_numerator == false ? " - " : " + ") << (Root_Coef != 1 ? Root_coef_to_str : "") << (Complex_number == true ? "i" : "")			// solution
			<< (Discrim != 0 ? " sqrt " : "") << Discrim << ")";
		
		if (Denominator != 1)													// Formatting, if denominator is 1 then it is excluded.
			cout << " / " << Denominator;
	}
	else // Output when 2 real root solutions
	{

		cout << (Neg_solution == true ? "-" : "") << "(" << (Neg_numerator == true && Neg_solution != true ? "-" : "") << Numerator		// First root
			<< (Neg_numerator == true ? " - " : " + ") << (Root_Coef != 1 ? Root_coef_to_str : "") << (Discrim != 0 ? " sqrt " : "")		// solution
			<< Discrim << ")";
		
		if (Denominator != 1)																// Formatting, if denominator is 1 then it is excluded.
			cout << " / " << Denominator;

		if (abs(Root_plus) != floor(abs(Root_plus)))										// Formatting, states exact value if solution is a whole number
			cout << "\n\nWhich is approximately: " << setprecision(6) << Root_plus << "\n";			// otherwise states approximate value.
		else
			cout << "\n\nWhich is exactly: " << setprecision(6) << Root_plus << "\n";

		cout << "\nand\n\n" << setprecision(1);

		cout << (Neg_solution == true ? "-" : "") << "(" << (Neg_numerator == true && Neg_solution != true ? "-" : "") << Numerator		// Second root 
			<< (Neg_numerator == false ? " - " : " + ") << (Root_Coef != 1 ? Root_coef_to_str : "") << (Discrim != 0 ? " sqrt " : "")	// solution
			<< Discrim << ")";
			
		if (Denominator != 1)																// Formatting, if denominator is 1 then it is excluded.
			cout << " / " << Denominator;

		if (abs(Root_minus) != floor(abs(Root_minus)))										// Formatting, states exact value if solution is a whole number
			cout << "\n\nWhich is approximately: " << setprecision(6) << Root_minus;		// otherwise states approximate value.
		else
			cout << "\n\nWhich is exactly: " << setprecision(6) << Root_minus;
	}
	cout << "\n" << endl;
	return 0;
}