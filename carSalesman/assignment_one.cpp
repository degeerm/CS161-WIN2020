/**********************************************************************************
 ** Program Filename: assignmentone.cpp
 ** Author: Miya DeGeer
 ** Date: 01/18/2020
 ** Description: Calculates gross income, taxes, and taxed income of car salesman.
 ** Input: monthly salary, months worked, cars sold, misconducts observed, cost of car,
 **        tax year, state.
 ** Output: Gross income, taxes to pay, taxed income.
 **********************************************************************************/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

/********************************************************************
 ** Function: gross_income
 ** Description: Calculates gross income of car salesman
 ** Paramters: monthly salary, months worked, # of cars sold,
 ** misconducts observed, car cost.
 ** Pre-Conditions: Above data passed in.
 ** Post-Condition: Gross income returned.
 ********************************************************************/
float gross_income(int sm, int nm, int nc, int mis, int cc){

	/*determines salary amount*/
	float sa = sm * nm;

	/*determines car profits + prints for user*/
	srand(time(NULL));
	float sp = cc + (cc * (((rand() % 5)+5)/100.0));
	cout << "The average sell price (generated randomly) is $" << sp << ". You earn 2 percent of the profit, which is $" << (sp *0.02)<< endl;
	float p = 0.02 * (nc * (1.0*sp-cc));

	/*determines deduction*/
	int d;
	if (mis == 0){
		d = 0;
	}
	
	else{
		d = 100 * pow(2, mis-1);
	}

	/*return statement*/
	return (sa + p - d);
}

/*****************************************************************
 ** Function: taxes
 ** Description: calculates taxes for car salesman
 ** Parameters: tax year, state, gross income
 ** Pre-Conditions: Above data collected, gross income calculated
 ** Post-Conditions: returns tax information
 *****************************************************************/
float taxes(int y, string s, float i){
		
	/*tax year 2017*/
	if (y == 0){

		/*State A 2017*/
		if (s == "A"){
			return (i *.06);
		}

		/*State B 2017*/
		else if (s == "B"){
			if (i < 2000){
				return 0;
			}
			else if (i >= 2000 and i <= 10000){
				return 100;
			}
			else if (i > 10000){
				return ((i - 10000)*.1)+100;
			}
		}

		/*State C 2017*/
		else if (s ==  "C"){
			if (i >= 0 and i <= 3500){
				return (i * .05);
			}
			
			else if (i > 3500 and i <= 9000){
				return ((i - 3500) * 0.07)+175;
			}

			else if (i > 9000 and i <= 125000){
				return ((i - 9000) * 0.09)+560;
			}

			else if (i > 125000){
				return ((i - 125000) * 0.099) + 11000;
			}
		}
	}

	/*tax year 2018*/
	else if (y == 1){

		/*State A 2018*/
		if (s == "A"){
			return (i * 0.08);
		}
		
		/*State B 2018*/
		else if (s == "B"){
			if (i < 2500){
				return 0;
			}
			else if (i >= 2500 and i <= 10000){
				return 115;
			}
			else if (i > 10000){
				return ((i - 10000)*.105)+115;
			}
		}

		/*State C 2018*/
		else if (s == "C"){
			if (i <= 3450){
				return (i * 0.05);
			}
			
			else if (i > 3450 and i <= 8700){
				return ((i - 3450) * 0.07)+172.5;
			}

			else if (i > 8700 and i <= 125000){
				return ((i-8700) * 0.09)+540;
			}

			else if (i > 125000){
				return ((i-125000) * 0.099)+11007;
			}
		}
	}
}

/*****************************************************************
 ** Function: main
 ** Description: Takes in input, prints out tax information
 ** Paramaters: None
 ** Pre-Conditions: None
 ** Post-Conditions: program ends
 *****************************************************************/
int main(){

	/*variable declaration (user input)*/
	int sal_month;
	int num_months;
	int car_cost;
	int num_cars;
	int misconducts;
	int year;
	string state;

	/*variable declaration (to be calculated later)*/
	float income;
	float tax;

	/*accepting user input*/
	cout << "Enter your monthly salary: " << endl;
	cin >> sal_month;
	cout << "Enter number of months you worked in year: " << endl;
	cin >> num_months;
	cout << "Enter the cost of the car: " << endl;
	cin >> car_cost;
	cout << "Enter the number of cars you sold in year: " << endl;
	cin >> num_cars;
	cout << "Enter number of misconducts observed in year: " << endl;
	cin >> misconducts;
	cout << "Which tax year? Enter 0 for 2017, 1 for 2018: " << endl;
	cin >> year;
	cout << "Which state are you in? Enter A, B, or C: " << endl;
	cin >> state;

	/*untaxed income function call*/
	income = gross_income(sal_month, num_months, num_cars, misconducts, car_cost);

	/*taxes function call*/
	tax = taxes(year,state,income);

	/*printing*/
	cout << "Gross income: $" << income << "." << endl;
	cout << "Taxes: $" << tax << "." << endl;
	cout << "Income after tax: $" << (income -tax) << "." << endl;

	return 0;
}
