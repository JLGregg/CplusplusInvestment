#include <iostream>
#include <stdlib.h>
#include "savings.h"

using namespace std;

void UserMenus() {
    // Clear screen so if user wants to enter a new amount the screen is cleared
    system("CLS");

    cout << "*************************************" << endl;
    cout << "*************Data Input**************" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of years: " << endl;

    // Waiting for user to continue
    system("pause");

    cout << endl;

    // Get user inputs
    cout << "*************************************" << endl;
    cout << "*************Data Input**************" << endl;
    cout << "Initial Investment Amount: $";

    double t_investment, t_monthlydeposit, t_interest;
    int t_years;

    cin >> t_investment;
    cout << "Monthly Deposit: $";
    cin >> t_monthlydeposit;
    cout << "Annual Interest: %";
    cin >> t_interest;
    cout << "Number of years: ";
    cin >> t_years;

    // Waiting for user to continue
    system("pause");

    // Create savings object
    Savings userSavings = Savings(t_investment, t_monthlydeposit, t_interest, t_years);

    cout << endl;

    // Call method
    userSavings.noMonthlyDep();

    cout << endl;

    // Call method with monthly deposit if monthly deposit is greater than 0
    if (t_monthlydeposit > 0) {

        userSavings.withMonthlyDep();
    }

}

int main() {

    while (true) {
        
        // Call usermenu function
        UserMenus();

        // Ask the user if they want to calculate another

        cout << endl << "Do you want to try another amount? (y/n): ";

        string userInput;
        cin >> userInput;

        // Break if the user does not want to try another. Set not equal to y so any other input breaks loop.
        if (userInput != "y") {

            break;
        }

        cout << endl;
    }

    return 0;
}
