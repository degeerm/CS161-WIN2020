#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

string pass_creator(int le, int up, int low, int num){
	srand(time(NULL));
	string password;

	for (int u = 0; u < up; u++){
		password += (char)(65 + rand() % 26);
	}

	for (int l= 0; l < low; l++){
		password += (char)(97 + rand() % 26);
	}

	for (int n = 0; n < num; n++){
		password += (char)(48 + rand() % 10);
	}

	return password;
}


int main(){
	while (true){
		int length = 0;
		int upper = 0;
		int lower = 0;
		int numbers = 0;

		int counter = 0;

		int user = 0;
		cout << "Welcome to password creator!" << endl;
		cout << "How long do you want the password to be?" << endl;
		cin >> length;
		cout << "Do you want letters (0-no, 1-yes)?" << endl;
		cin >> user;
		if (user == 1){
			cout << "Do you want uppercase (0-no, 1-yes)" << endl;
			cin >> user;
			if (user == 1){
				cout << "How many uppercase?" << endl;
				cin >> upper;
				counter += upper;
			}

			cout << "Do you want lowercase (0-no, 1-yes)" << endl;
			cin >> user;
			if (user == 1){
				cout << "How many lowercase?" << endl;
				cin >> lower;
				counter += lower;
			}
		}
		cout << "Do you want numbers? (0-no, 1-yes)" << endl;
		cin >> user;
		if (user == 1){
			cout << "How many numbers?" << endl;
			cin >> numbers;
			counter += numbers;
		}
		
	       	if (counter <= length){
			cout << pass_creator(length,upper,lower,numbers) << endl;
		}

		else{
			cout << "Password too long!!!!!" << endl;
		}

		cout << "Would you like to generate another password? (0-no,1-yes)" << endl;
		cin >> user;
		if (user == 0){
			break;
		}
	}
	

	return 0;
}
