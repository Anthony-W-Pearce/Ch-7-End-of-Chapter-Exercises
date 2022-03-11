#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::abs;
using std::floor;
using std::ios;
using std::to_string;

int main() {
	bool Negative = false;
	int Numerator = 0,
		Denominator = 0,
		Whole_Number = 0;
	char Negative_sign = '-';

	cout << "Anthony's Fraction Display Program" << "\n\n";

	// User Input
	cout << "Enter Your Numerator: ";
	cin >> Numerator;
	cout << "\n";

	cout << "Enter Your Denominator: ";
	cin >> Denominator;
	cout << "\n";

	// Processing
	if (Numerator < 0 && Denominator > 0)									// Tracks status of sign and converts numerator 
	{																		// and denominator to positive values for output.
		Negative = true;													// Sign given in output shows '-' Negative bool
		Numerator = abs(Numerator);											// is true.
	
	}
	else if (Numerator > 0 && Denominator < 0)
	{
		Negative = true;
		Denominator = abs(Denominator);
	}
	else if (Numerator < 0 && Denominator < 0)
	{
		Numerator = abs(Numerator);
		Denominator = abs(Denominator);

	}

	if (Numerator >= Denominator && Denominator != 0)											// If needed, converts to mixed fraction
	{
		Whole_Number = floor(Numerator / Denominator);
		Numerator = Numerator - (Denominator * Whole_Number);
	}

	// Results Output
	if (Denominator == 0)													
		cout << " Your fraction is undefined, cannot have a denominator of 0" << "\n" << endl;	// Inform user of error in their input
	else
	{
		cout << "Your fraction is: " << (Negative == true ? "-" : "")		// Output displays '-' if either numerator or denominator is < 0, but not if both are.
			<< (Whole_Number > 0 ? to_string(Whole_Number) : "")			// Convert int to string so no type incompatabilities.
			<< (Whole_Number > 0 ? " " : "")								// If whole number exists, insert space between whole number and fraction
			<< Numerator << "/" << Denominator << "\n" << endl;				// Display fraction
	}
	return 0;
}