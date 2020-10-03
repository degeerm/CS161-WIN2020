#include <iostream>
#include <cstring>

using namespace std;

void swap_sentence(string &string1,string &string2){
	string temp = string1;
	string1 = string2;
	string2 = temp;
	cout << "In swap function …" << endl;
	cout << "string1: " << string1 << endl; 
	cout << "string2: " << string2 << endl; 

}

int main(){

	string sentence1, sentence2;
	cout << "Enter sentence 1: ";
	getline (cin, sentence1);
	cout << "Enter sentence 2: ";
	getline (cin, sentence2);
	swap_sentence(sentence1, sentence2);
	cout << "In main function …" << endl;
	cout << "sentence1: " << sentence1 << endl;
	cout << "sentence2: " << sentence2 << endl;

	return 0;
}
