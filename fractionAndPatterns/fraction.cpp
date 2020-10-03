/********************************************************************
** Program Name: fraction.cpp
** Author: Miya DeGeer
** Date: 01/16/2020
** Description: Takes in a fraction input, returns simplified verson
** Input: string
** Output: formatted int
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/********************************************************************
** Function: is_int
** Description: Determines if string is an integer or not.
** Parameters: string num
** Pre-Conditions: Correct string given into is_int
** Post-Conditions: Returns true (is an int) or false (is not an int)
*********************************************************************/ 
bool is_int(string num){
	int minus_counter = 0;
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			if (num.at(i) == '-' && minus_counter <= 1){
				minus_counter++;	
			}else{
				return false;
			}
		}
	}
	return true;
}

/********************************************************************
** Function: get_int
** Description: If a string is an integer, returns integer version
** Parameters: string prompt
** Pre-Conditions: Correct string given into get_int, is_int works
** Post-Conditions: Returns integer version of string
*********************************************************************/
int get_int(string prompt){
	int sum = 0;
	int minus_counter = 0;
	int len = prompt.length();
		if (prompt.find('-') != -1){
			len = len - 1;
			prompt.erase(0,1);
			minus_counter = 1;	
		}
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}
		if (minus_counter == 1)
			sum *=-1;
	return sum;
}

/********************************************************************
** Function: input_checker
** Description: Cycles through asking user input until it is correct.
** Parameters: int demornot
** Pre-Conditions: demornot is either 1 or 0, get_int/is_int works
** Post-Conditions: Returns integer version of user input
*********************************************************************/ 

int input_checker(int demornot){
	int checker = 1;
	string number;
	do{
		cin >> number;
		if (is_int(number)){
			int num = get_int(number);
			if ((demornot == 0) || (demornot == 1 && num !=0))
				return (num);
			else if(demornot == 1 && num == 0)
				cout << "Error: Denominator cannot be zero." << endl;
		}else
			cout << "Error: Whole integer numbers only." << endl;
	}while(checker);
}


/********************************************************************
** Function: int g_c_d
** Description: Finds the greatest common denominator of two numbers
** Parameters: int num1, int num2
** Pre-Conditions: num1 and num2 are valid integers
** Post-Conditions: greatest common divisor (int) returned
*********************************************************************/ 
int g_c_d(int num1, int num2){
	if (num2 == 0)
		return (num1);
	else
		return (g_c_d(num2, num1 % num2));
}


/********************************************************************
** Function: bool to_lowest_terms
** Description: Reduces two numbers to their lowest terms.
** Parameters: int numerator, int denominator
** Pre-Conditions: numerator and denominator are initialized elsewhere
** Post-Conditions: Num/denom reduced, returns 0 if denom is 0
*********************************************************************/ 
bool to_lowest_terms(int &numerator, int &denominator){
	if (denominator == 0)
		return false;
	int greatest_common = g_c_d(numerator, denominator);
	numerator = numerator/greatest_common;
	denominator = denominator/greatest_common;

	return 1;
}

/********************************************************************
** Function: void format_string 
** Description: Prints two numbers in appropriate fraction form.
** Parameters: int num1, int num2
** Pre-Conditions: num1 and num2 are valid integers
** Post-Conditions: Prints fraction version of num1 and num2.
*********************************************************************/ 
void format_string(int num1,int num2){
	if(num2 == 1){
		cout << "The lowest terms of your fraction are: " << num1 << endl;
	}
	else{
		cout << "The lowest terms of your fraction are: " << num1 << "/" << num2 << endl;
	}	
}

/********************************************************************
** Function: void conversion_checker 
** Description: Cycles through user input until they put a valid checker var
** Parameters: string checker
** Pre-Conditions: checker is initialized elsewhere
** Post-Conditions: Either "0" or "1" is assigned to checker to be used
*********************************************************************/ 

void conversion_checker(string &checker){
	do{
		cout << "Do another conversion? (1 for yes, 0 for no)" << endl;
			cin >> checker;
			if (checker != "0" && checker != "1")
				cout << "Error: Please enter either 0 or 1." << endl;
	}while (checker != "1" && checker != "0");
}

/********************************************************************
** Function: int main
** Description: Receives/checks input, fraction stuff, then repeats
** Parameters: none
** Pre-Conditions: All other functions are working properly
** Post-Conditions: Fractions are done until user ends program
*********************************************************************/ 
int main(){
	/*Used to check for if user wants to do more conversions*/
	string checker = "1";
	do{

		/*Passing in/checking input.*/
		cout << "Enter your numerator." << endl;
		int numer = input_checker(0);
		
		cout << "Enter your denominator." << endl;
		int denom = input_checker(1);
		
		/*Changes numerator and denominator to be in lowest terms.*/
		to_lowest_terms(numer,denom);
		
		/*Prints out the results.*/
		format_string(numer,denom);
		
		/*Cycles through conversion checking.*/
		conversion_checker(checker);

	}while (checker != "0");

	return 0;
}

