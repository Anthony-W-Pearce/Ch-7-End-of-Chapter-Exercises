#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::setw;

int main() {
	float Interest_rate = 0.0F,
		Loan_amount = 0.0F,
		Interest_total = 0.0F,
		Interest_and_fees = 0.0F;

	cout << "Loan Cost Calculator" << "\n\n";

	// User Inputs
	cout << "Enter the interest rate of the loan (min: 1% max: 18%): ";
	cin >> Interest_rate;
	cout << "\n";
	if (Interest_rate > 18 || Interest_rate < 1)
	{
		cout << "Interest rate not in the allowed parameters." << "\n\n";
		return 0;
	}
	
	cout << "\n\n" << "Enter the amount of the loan (min:100 max:1000): ";
	cin >> Loan_amount;
	cout << "\n";
	if (Loan_amount > 1000 || Loan_amount < 100)
	{
		cout << "Loan amount is not in the allowed parameters." << "\n\n";
		return 0;
	}
	cout << "\n\n";

	// Processing
	Interest_total = Loan_amount * (Interest_rate / 100);

	if (Loan_amount > 500)
		Interest_and_fees = Interest_total + 25;
	else
		Interest_and_fees = Interest_total + 25;

	// Report Output
	cout.setf(ios::fixed);
	cout.precision(2);

	cout << setw(16) << left << "Amount Requested" << right << setw(15) << "Interest Rate" << setw(20) << "Fees and Interest" << "\n";
	cout << setw(16) << Loan_amount << setw(15) << Interest_rate << setw(20) << Interest_and_fees << "\n" << endl;





	return 0;
}