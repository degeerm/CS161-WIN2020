#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int num_bits;
	cout << "How many bits do you want? " << endl;
	cin >> num_bits;

	cout << "Maximum UNSIGNED value for your bits: " << pow(2,num_bits) - 1 << endl;
	cout << "Maximum SIGNED value for your bits: " << pow(2,(num_bits-1)) - 1 << endl;
	cout << "Minimum SIGNED value for youe bits: " << -1 * pow(2, (num_bits - 1)) << endl;

	//cout << "max un " << (pow(2,num_bits) - 1) +1 << endl;
	//cout << "max s " << (pow(2,(num_bits-1) -1)) + 1 << endl;
	//cout << "min s " << (pow(2,(num_bits-1) * -1)) - 1 << endl;
	return 0;
}
