#ifndef SAVINGS_H
#define SAVINGS_H

// Create savings class
class Savings {

public:
	Savings(double t_investment, double t_monthlyDeposit, double t_rate, int t_years);

	virtual ~Savings();

	void noMonthlyDep();
	void withMonthlyDep();

private:
	double m_startingDeposit;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numYears;
};
#endif