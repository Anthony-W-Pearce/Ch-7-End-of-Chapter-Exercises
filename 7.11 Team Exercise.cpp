#include <iostream>
#include <iomanip>
using std::sqrt;
using std::cin;
using std::cout;
using std::setw;
int main()
{
    int Menu_choice = 0,
    User_number = 0;

    cout << setw(12) << "" << "Basic Number Trials" << "\n\n";

    // User Input
    cout << "Enter the number you want to know more about: ";
    cin >> User_number;
    // Menu Display
    cout << "\n" << setw(5) << "" << "1) Is the number odd or even?";
    cout << "\n" << setw(5) << "" << "2) Is the number positive or negative?";
    cout << "\n" << setw(5) << "" << "3) What is the square root of the number?" << "\n\n";
    // User Input 2
    cout << "Enter the number of the question you want answered: ";
    cin >> Menu_choice;
    cout << "\n";
    // Processing
    switch (Menu_choice)
    {
    case 1:
        if (User_number == 0)                                                                                   // Display if number is even or odd
            cout << setw(9) << "" << "Your number, " << User_number << ", is zero.";
        else if (User_number % 2 == 0)
            cout << setw(9) << "" << "Your number, " << User_number << ", is even.";
        else
            cout << setw(9) << "" << "Your number, " << User_number << ", is odd.";
        break;
    case 2:                                                                                                     // Display sign of user's number
        if (User_number > 0)
            cout << setw(9) << "" << "Your number, " << User_number << ", is positive.";
        else if (User_number < 0)
            cout << setw(9) << "" << "Your number, " << User_number << ", is negative.";
        else
            cout << setw(9) << "" << "Your number, " << User_number << ", is zero.";
        break;
    case 3:
        if (User_number < 0)
            cout << "Your number is negative and results in a complex number.";                                 // Check if complex
        else
            cout << setw(5) << "" << "Your number, " << User_number << ", has a square root of: " << sqrt(User_number) << ".";       // Display square root
        break;
    default:                                                                                                    // Error check menu choice
        cout << setw(5) << "" << "Invalid menu selection.";
        break;
    }
    cout << "\n\n";
    return 0;
}
