//Joel Asante
//A Loan Calculator with Interest

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
// Declaing variables am going to use
	float monthlyPayment;
	float loanAmount;
	float  principal;
	float interestRate;
	float interestAmount;
	float remainingBalance;
	int num_of_years = 1;
	const int months_in_year = 12; 

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
// Creating a menu to prompt the user with some questions
	cout << "Please enter the current amount of your loan" << endl;
	cin >>  loanAmount;
	cout << "Please enter the interest Rate" << endl;
	cin >> interestRate;
	cout << "Please enter monthly payment" << endl;
	cin >> monthlyPayment;
	cout << "Please enter years wish to simulate" << endl;
	cin >> num_of_years;
//Using loop to iterate through the years
	for ( int i =1; i <= num_of_years; i++)
	{
		cout << "\nYear " << i << endl;

		cout << setw(10) << "Month" << setw(11) << "Interest" << setw(11)
			<< "Principal" << setw(12) << endl;
		cout << setw(10) << "___" << setw(11) << "______" << setw(11)
			<< "______" << setw(12) << setw(11) << endl;

		float totalInterest = 0, totalPrincipal = 0;
//Loop for number of months
		for ( int a = 1; a <= months_in_year; a++)
		{
			interestAmount = 0;
			principal  = 0;

			interestAmount = (interestRate * loanAmount) / 100;

			interestAmount = interestAmount / 12;

			principal = monthlyPayment - interestAmount;

			remainingBalance = loanAmount - principal;

			loanAmount = remainingBalance;

			totalInterest += interestAmount;

			totalPrincipal += principal;
//precision is fixed and its set to 2
			cout << fixed;
			cout << setprecision(2);

			cout << setw(10) << a << setw(10) << interestAmount << setw(12)
				<< principal << setw(12)  << setw(10) << endl;
		}
		
		cout << fixed << setprecision(2);
//Print details for each year
		cout << setw(20) << "_____"  << setw(12) << "_____"  << endl;
		cout << "Year "<< i <<" Totals: " << setw(7) << totalInterest
			<< setw(12) << totalPrincipal << endl;
	        cout << "Remaining Balance at the year end: " << remainingBalance  <<  endl;
	}

return 0;
}
