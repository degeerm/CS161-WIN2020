/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>
using namespace std;

int main(){

	int x=3, y;
	char myAnswer;
	bool again = 1;
	while (again){
	
		y = x;
		cout << "y is set to: " << y << endl;
		cout << "x is set to: " << x << endl;

		cout << "Please input a number for y: ";
		cin >> y;

		if(x > y){
			cout << "X is greater than Y\n";
			cout << "would you like to input another number? (1 for yes, 0 for no)" << endl;
			cin >> again;

		}else if (x < y){
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number? (1 for yes, 0 for no)" << endl;
			cin >> again;
		}else{
			cout << "X and y are equal." << endl;
			cout << "Would you like to input another number? (1 for yes, 0 for no)" << endl;
			cin >> again;
		}
	}


	for(x = 0; x < 10; x++){
		cout << x << endl;
	}
	
	int num;	
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
	int product = 1;
	for(int x = num; x > 0; x--){
		product = product * x;
	}
	cout << product << endl;

	cout << "Are you enjoying cs161? (y or n) " << endl;
	char myanswer;
	cin >> myanswer;
	if(myanswer == 'y')
		cout << "YAY" << endl;
	else if (myanswer == 'n')
		cout << "YOU WILL SOON!" << endl;
	else
		cout << "THATS NOT AN ANSWER" << endl;

	return 0;
}
