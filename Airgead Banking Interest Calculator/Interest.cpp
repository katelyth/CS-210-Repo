#include <iostream>
#include <iomanip>
#include "Interest.h"


//function to get the Initial investment from user
double Interest::GetInvestment() {
	cout << "Initial Investment Amount: " << endl;
	cin >> initialInvestment;
	return initialInvestment;
}

//function to get Monthly Deposit from user 
double Interest::GetMonthlyDeposit() {
	cout << "Monthly Deposit: " << endl;
	cin >> monthlyDeposit;
	return monthlyDeposit;
}

//function to get Interest Rate from User
double Interest::GetRate() {
	cout << "Annual Interest Rate: " << endl;
	cin >> rate;
	return rate;
}

//Function to get the length of investment from the user
int Interest::GetYears() {
	cout << "Number of Years: " << endl;
	cin >> years;
	return years;
}

//function to print the report headers based on user input
void Interest::PrintHeader(string t_string, double t_initialInvestment, double t_interestRate) {
	//output user's initial investment and rate
	cout << "Your initial investment is: $" << t_initialInvestment << endl;
	cout << "your rate is: " << t_interestRate << "%" << endl;
	cout << endl;
	//output report header
	cout << "==============================================" << endl;
	cout << "     Annual Balance " << t_string << " Monthly Deposits     " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "  Year        Balance        Annual Interest  " << endl;
	cout << "----------------------------------------------" << endl;
	cout << " 0             $" << fixed << setprecision(2) << t_initialInvestment << "           $0.00" << endl;
}

//print annual details based on interest earned that year
void Interest::PrintDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {

	cout << " " << t_year << "             $" << fixed << setprecision(2) << t_yearEndBalance << "         $" << t_interestEarned << endl;
}

//function to calculate the monthly/annual balance without additional monthly deposits
double Interest::CalculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) {

	//set variables
	double monthlyInterest = (initialInvestment) * ((t_interestRate / 100) / 12);
	double interestEarnedThisYear = monthlyInterest * 12;
	int yearIndex = 0;
	double balance = t_initialInvestment;
	string s = "Without";
	
	//call the printheader function to print the header of the report
	PrintHeader(s, t_initialInvestment, t_interestRate);

	//for loop to calculate the annual interest earned and year ending balance
	for (int i = 0; i < t_numberOfYears; i++) {
		//reset annual interest to 0 at the beggining of each year
		interestEarnedThisYear = 0;
		//for loop to calculate interest earned each month (compounding monthly)
		for (int m = 0; m < 12; m++) {
			monthlyInterest = balance * ((t_interestRate / 100) / 12);
			balance += monthlyInterest;
			interestEarnedThisYear += monthlyInterest;
		}
		//add one to yearIndex and print the year end details
		yearIndex += 1;
		PrintDetails(yearIndex, balance, interestEarnedThisYear);
	}
	return balance;
	// return the final balance	
}

//function to calculate interest with additional monthly deposit
double Interest::CalculateBalanceWithMonthlyDeposit(double t_initialInvestment, double t_interestRate, double t_monthlyDeposit, int t_numberOfYears) {
	//initialize variables
	double balance = initialInvestment;
	double monthlyInterest = balance * ((t_interestRate / 100) / 12);
	double interestEarnedThisYear = 0;
	int yearIndex = 0;
	string s = "With";
	
	//call the printheader function to print report headers
	PrintHeader(s, t_initialInvestment, t_interestRate);
	//for loop to return annual interest and year end balance
	for (int i = 0; i < t_numberOfYears; i++) {
		//reset interest to 0 at the beginning of the year
		interestEarnedThisYear = 0;
		//for loop to calculate monthly interest (interest compoounds monthly) including the monthly deposit
		for (int m = 0; m < 12; m++) {
			monthlyInterest = (balance + t_monthlyDeposit) * ((t_interestRate/100) / 12);
			balance += t_monthlyDeposit + monthlyInterest;
			interestEarnedThisYear += monthlyInterest;
		}
		//add one to the year & print year end details
		yearIndex += 1;
		PrintDetails(yearIndex, balance, interestEarnedThisYear);
	}

	return balance;
	// return the final balance
}

int main()
{
	//initialize variables
	int years;
	double initial;
	double rate;
	double deposit;
	string userInput = "Yes";
	
	//while loop to run the program until the user types No
	while (userInput != "No") {
		cout << "Enter Investment Details Below." << endl;

		//use functions to get the user details
		Interest obj1;
		years = obj1.GetYears();
		initial = obj1.GetInvestment();
		rate = obj1.GetRate();
		deposit = obj1.GetMonthlyDeposit();

		//call functions to calculate balances with & without monthly deposit
		obj1.CalculateBalanceWithoutMonthlyDeposit(initial, rate, years);

		obj1.CalculateBalanceWithMonthlyDeposit(initial, rate, deposit, years);
		
		//ask the user if they would like to continue the program or not
		cout << "Would you like to calculate with a different amount? (Yes / No)" << endl;
		cin >> userInput;
	}
}
