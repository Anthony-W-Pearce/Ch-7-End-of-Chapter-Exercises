#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
using std::ios;

int main() {
	const string SQUARED = "^2",
		CUBED = "^3";
	const double PI = 3.1415926535898,
		FOUR_THIRDS = 4.0 / 3.0;
	double Rectangle_length = 0.0,
		Rectangle_width = 0.0,
		Rectangle_area = 0.0,
		Triangle_a = 0.0,																	 
		Triangle_b = 0.0,																		
		Triangle_c = 0.0,
		Semiperimiter = 0.0,
		Heron_discriminate = 0.0,
		Triangle_area = 0.0,
		Circle_radius = 0.0,
		Circle_area = 0.0,
		Cylinder_radius = 0.0,
		Cylinder_height = 0.0,
		Cylinder_volume = 0.0,
		Sphere_radius = 0.0,
		Sphere_volume = 0.0;
	char Main_menu = 'x',
		Area_menu = 'x',
		Volume_menu = 'x';
	
	string Units = "";

	cout << "Anthony's Area and Volume Calculator" << "\n\n";
	// Main Menu Display
	cout << "-- Main Menu --" << "\n";
	cout << "1) Calculate Area" << "\n";
	cout << "2) Calculate Volume" << "\n";
	cin >> Main_menu;
	cout << "\n\n";
	// Output Formatting
	cout.setf(ios::fixed);
	cout.precision(3);
	
	switch (Main_menu)
	{
	case '1':
		// Beginning of Area Options	
		cout << "-- Area Menu --" << "\n";
		cout << "a) Rectangle" << "\n";
		cout << "b) Circle" << "\n";
		cout << "c) Triangle" << "\n";
		cin >> Area_menu;
		cout << "\n\n";

		switch (Area_menu)
		{
		case 'A':																						// Beginning of rectangle area code
		case 'a':

			// Rectangle input
			cout << "Enter rectangle length: ";
			cin >> Rectangle_length;
			cout << "\n" << "Enter rectangle width: ";
			cin >> Rectangle_width;
			cout << "\n" << "Enter the units of measure: ";
			cin >> Units;
			cout << "\n";
			// Rectangle Processing
			Rectangle_area = Rectangle_length * Rectangle_width;
			// Rectangle Output
			cout << "The area of your rectangle is: " << Rectangle_area << " " << Units << SQUARED;
			break;
		case 'B':																						// Beginning of circle area code
		case 'b':
			// Circle Input
			cout << "Enter circle radius: ";
			cin >> Circle_radius;
			cout << "\n" << "Enter the units of measure: ";
			cin >> Units;
			cout << "\n";
			// Circle Processing
			Circle_area = PI * (Circle_radius * Circle_radius);
			// Circle Output
			cout << "The area of your circle is: " << Circle_area << " " << Units << SQUARED;
			break;
		case 'C':																						// Beginning of triangle area code
		case 'c':																						// Uses Heron's formula																					
			// Triangle Input																			// s = (a+b+c)/2
			cout << "Enter length of triangle side a: ";												// Area = sqrt(s(s-a)(s-b)(s-c))
			cin >> Triangle_a;
			cout << "\n" << "Enter length of triangle side b: ";
			cin >> Triangle_b;
			cout << "\n" << "Enter length of triangle side c: ";
			cin >> Triangle_c;
			cout << "\n" << "Enter the units of measue: ";
			cin >> Units;
			// Triangle Processing
			if (Triangle_a + Triangle_b < Triangle_c || Triangle_b + Triangle_c < Triangle_a || Triangle_a + Triangle_c < Triangle_b)		// Check if triangle is valid
			{
				cout << "Not a Triangle. The sum of the length of two sides must be greater than the length of the remaining side.";
				return 0;
			}
			Semiperimiter = (Triangle_a + Triangle_b + Triangle_c) / 2;
			Heron_discriminate = Semiperimiter * (Semiperimiter - Triangle_a) * (Semiperimiter - Triangle_b) * (Semiperimiter - Triangle_c);
			Triangle_area = sqrt(Heron_discriminate);
			// Triangle Output
			cout << "\n" << "The area of your triangle is: " << Triangle_area << " " << Units << SQUARED;
			break;
		default:
			cout << "Invalid selection." << "\n\n";
			return 0;
		}
		break;
	case '2':
		// Beginning Volume Options
		cout << "-- Volume Menu --" << "\n";
		cout << "a) Cylinder" << "\n";
		cout << "b) Sphere" << "\n";
		cin >> Volume_menu;
		cout << "\n\n";
		switch (Volume_menu)
		{
		case 'A':
		case 'a':																					// Beginning of cylinder volume code
			// Cylinder Input
			cout << "Enter the radius of your cylinder: ";
			cin >> Cylinder_radius;
			cout << "\n" << "Enter the height of your cylinder: ";
			cin >> Cylinder_height;
			cout << "\n" << "Enter the units of measure: ";
			cin >> Units;
			cout << "\n";
			// Cylinder Processing
			Cylinder_volume = PI * (Cylinder_radius * Cylinder_radius) * Cylinder_height;
			// Cylinder Output
			cout << "The volume of your cylinder is: " << Cylinder_volume << " " << Units << CUBED;
			break;
		case 'B':
		case 'b':																					// Beginning of sphere volume code
			// Sphere Input
			cout << "Enter the radius of your sphere: ";
			cin >> Sphere_radius;
			cout << "\n" << "Enter the units of measure: ";
			cin >> Units;
			cout << "\n";
			// Sphere Processing
			Sphere_volume = FOUR_THIRDS * PI * (Sphere_radius * Sphere_radius * Sphere_radius);
			// Sphere Output
			cout << "The volume of your sphere is: " << Sphere_volume << " " << Units << CUBED;
			break;
		default:
			cout << "Invalid selection." << "\n\n";
			return 0;
		}
		break;
	default:
		cout << "Invalid selection." << "\n\n";
		return 0;
	}
	cout << "\n\n";
	
	cout << "** END OF CALCULATION **" << "\n\n";
	return 0;
}