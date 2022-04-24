#include <iomanip>
#include <iostream>
#include "savings.h"

using namespace std;

// Constructor
Savings::Savings(double t_investment, double t_monthlyDeposit, double t_rate, int t_years) {

	this->m_startingDeposit = t_investment;
	this->m_monthlyDeposit = t_monthlyDeposit;
	this->m_interestRate = t_rate;
	this->m_numYears = t_years;

}

// Destructor
Savings::~Savings() {
}

// Calculating without additional monthly deposits and printing
void Savings::noMonthlyDep() {

	cout << "   Balance and Interest without additional Monthly Deposits" << endl;
	cout << "=============================================================================" << endl;
	cout << setw(12) << "Year" << setw(25) << "Year End Balance" << setw(40) << "Year End Earned Interest Rate" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	int curYear = 1;
	double endingBalance = this->m_startingDeposit;

	// Loop from starting year until numYears
	while (curYear <= this->m_numYears) {
		// Calculating interest and adding to the balance
		double earnedInterest = endingBalance * this->m_interestRate / 100;
		endingBalance += earnedInterest;

		// Display
		cout << right << setw(10) << curYear << fixed << setprecision(2) << setw(20) << endingBalance << setw(35) << earnedInterest << endl;

		// Increase current year so it doesn't get stuck in loop
		curYear += 1;

	}

}

void Savings::withMonthlyDep() {

    cout << "   Balance and Interest without additional Monthly Deposits" << endl;
    cout << "=============================================================================" << endl;
    cout << setw(12) << "Year" << setw(25) << "Year End Balance" << setw(40) << "Year End Earned Interest Rate" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    int curYear = 1;
    double endingBalance = this->m_startingDeposit;

    while (curYear <= this->m_numYears) {

        // Calculating monthly interest and compounding interest
        int month = 1;
        double earnedInterest = 0.0;
        double monthlyEndingBalance = endingBalance;

        // Looping until months = 12. 1 year
        while (month <= 12) {

            // Calculating monthly interest
            monthlyEndingBalance += this->m_monthlyDeposit;

            // Annual interest rate which has to be divided by 12
            double monthlyinterest = monthlyEndingBalance * this->m_interestRate / (100 * 12);
            earnedInterest += monthlyinterest;
            monthlyEndingBalance += monthlyinterest;

            // Increasing the month by 1
            month += 1;

        }

        // After looping for 12 months
        endingBalance = monthlyEndingBalance;

        cout << right << setw(10) << curYear << fixed << setprecision(2) << setw(20) << endingBalance << setw(35) << earnedInterest << endl;

        // Increasing current year by 1
        curYear += 1;

    }

}
