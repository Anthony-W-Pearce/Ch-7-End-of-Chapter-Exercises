#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
using std::cin;
using std::cout;
using std::to_string;
using std::setw;
using std::left;



int main() {
	bool PM = false;

	int Hour = 0,
		Minute = 0,
		Second = 0,
		Converted_hour = 0;

	cout << setw(34) << "Military Time Converter" << "\n";

	cout << "\n" << "This program will convert 24 hour military time to standard time." << "\n\n";

	// Input
	cout << "Enter the hours of the time to convert: ";
	cin >> Hour;

	cout << "\n\n" << "Enter the minutes of the time to convert: ";
	cin >> Minute;

	cout << "\n\n" << "Enter the seconds of the time to convert: ";
	cin >> Second;
	cout << "\n\n";

	// Processing
	if (Hour > 24 || Hour <= 0)						// Error Check
	{
		cout << setw(34) << "Error: Invalid Hour Entry" << "\n\n";
		return 0;
	}
	else if (Minute > 59 || Minute < 0)
	{
		cout << setw(34) << "Error: Invalid Minute Entry" << "\n\n";
		return 0;
	}
	else if (Second > 59 || Second < 0)
	{
		cout << setw(34) << "Error: Invalid Second Entry" << "\n\n";
		return 0;
	}

	if (Hour > 12)
	{
		PM = true;
		Converted_hour = Hour - 12;
	}

	// Output
	cout << setw(35) << "The time you entered is: " << "\n\n";
	cout << setw(18);
	cout << (Hour < 10 ? "0" : "") << Hour << ":" << (Minute < 10 ? "0" : "") << Minute << ":" << (Second < 10 ? "0" : "") << Second << " " << (PM == true ? "PM" : "AM");

	cout << "\n\n" << setw(35) << "Your converted time is: " << "\n\n";
	cout << setw(18);
	
	cout << (Converted_hour < 10 ? "0" : "") << Converted_hour << ":" << (Minute < 10 ? "0" : "") << Minute << ":" << (Second < 10 ? "0" : "") << Second << " " << (PM == true ? "PM" : "AM");

	cout << "\n\n";

	return 0;
}