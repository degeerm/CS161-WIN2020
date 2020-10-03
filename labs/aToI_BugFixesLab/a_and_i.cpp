#include <iostream>
using namespace std;


/*******************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character
********************************************************************/
int atoi(char c){
	return((int)c);
}


/*******************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int decimal
** Pre-Conditions: the input is an integer
** Post-Conditions: returned the character which represents the
decimal value
********************************************************************/ 
char itoa(int i){
	
	return((char)i);
}

int main(){
	cout << atoi('6') << endl;
	cout << itoa(82) << endl;
	return 0;
}
