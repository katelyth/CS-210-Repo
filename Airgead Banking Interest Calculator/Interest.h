#pragma once
using namespace std;

//function declarations for the "Interest" class
class Interest {
public:
	double initialInvestment = 0;
	double monthlyDeposit = 0;
	double rate = 0;
	int years = 0;
	
	void PrintHeader(string t_string, double t_initialInvestment, double t_interestRate);
	void PrintDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
	double CalculateBalanceWithMonthlyDeposit(double t_initialInvestment, double t_interestRate, double t_monthlyDeposit, int t_numberOfYears);
	double CalculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears);
	double GetInvestment();
	double GetMonthlyDeposit();
	double GetRate();
	int GetYears();

private:
	



};