/*******************************************************************
** Program Filename: patterns.cpp
** Author: Miya DeGeer
** Date: 01/20/2020
** Description: Prints variety of patterns based on user input
** Input: Number or asterisk, number of rows (if asterisk)
** Output: Number/asterisk diamond like patterns
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

/********************************************************************
** Function: void num_print_top 
** Description: Prints the top half of the number pattern
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Top half of number pattern printed
*********************************************************************/ 
void num_print_top(){
	for (int i = 1; i <= 9; i+=2){
		for (int j = 0; j < ((9-i)/2); j++){
			cout << " ";
		}
		for (int j = 1; j <= i; j++){
			cout << j;
	
		}
		cout << "" << endl;
	}
}

/********************************************************************
** Function: void num_print_bottom
** Description: Prints bottom half of number pattern
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Bottom half of number pattern printed
*********************************************************************/ 
void num_print_bottom(){
	for (int i = 1; i <= 7; i+=2){
		for (int j = 1; j < ((i+3)/2); j++){
			cout << " ";
		}
		int c = 1;
		while (c <= (9-(i+1))){
			cout << c;
			c++;
		}
	
		cout << "" << endl;
	}
}

/********************************************************************
** Function: num_print
** Description: Prints both halves of number pattern
** Parameters: None
** Pre-Conditions: num_print_top & num_print_bottom working properly
** Post-Conditions: number pattern is printed
*********************************************************************/ 
void num_print(){
	num_print_top();
	num_print_bottom();
}

/********************************************************************
** Function: aster_print_top 
** Description: Prints top half of asterisk pattern.
** Parameters: int row
** Pre-Conditions: row is valid integer
** Post-Conditions: Top half of asterisk pattern printed
*********************************************************************/ 
void aster_print_top(int row){
	/*Top Half*/
	for (int i = 1; i <= row; i+=2){
		for (int j = 0; j < ((row-i)/2); j++){
			cout << " ";

		}
		for (int j = 1; j <= i; j++){
			cout << "*";
	
		}
	cout << "" << endl;	
	}

}

/********************************************************************
** Function: aster_print_bottom
** Description: Prints bottom half of asterisk pattern.
** Parameters: int row
** Pre-Conditions: row is a valid integer
** Post-Conditions: Bottom half of asterisk pattern printed
*********************************************************************/ 
void aster_print_bottom(int row){
	/*Bottom Half*/
	for (int i = 1; i <= row-2; i+=2){
		for (int j = 1; j < ((i+3)/2); j++){
			cout << " ";
		}
		for (int j = 0; j <= (row-i-2); j++){
			cout << "*";
		}
	
		cout << "" << endl;
	}
}

/********************************************************************
** Function: aster_print
** Description: Prints both halves of asterisk pattern
** Parameters: int row
** Pre-Conditions: row is a valid integer
** Post-Conditions: Both halves of asterisk pattern printed.
*********************************************************************/ 
void aster_print(int row){
	aster_print_top(row);
	aster_print_bottom(row);
}

/********************************************************************
** Function: int main
** Description: Cycles through making patterns based on user input
** Parameters: None
** Pre-Conditions: All functions are working properly
** Post-Conditions: Number/asterisk patterns printed until user ends program
*********************************************************************/ 
int main(){
	string user_choice;
	int row;
	do{
		cout << "Welcome to Patterns! Want to print Asterisks (1) or Numbers (2)?" << endl;
		cin >> user_choice;
		if (user_choice == "1"){
			cout << "How many rows? Positive odd rows only please." << endl;
			cin >> row;
			aster_print(row);
		}else if (user_choice == "2"){
			num_print();
		}
		cout << "Go again? (enter '0' to stop, '1' to continue)" << endl;
		cin >> user_choice;
	}while(user_choice != "0");
	
	return 0;
}
