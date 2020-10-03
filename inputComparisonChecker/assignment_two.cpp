/*********************************************************************
 * ** Program Filename: assignment_two.cpp
 * ** Author: Miya DeGeer
 * ** Date: 01/26/2020
 * ** Description: Various functions that aid in input/comparison
 * ** Input: string, float, int, char
 * ** Output: bool, string, int, char
 * *********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*********************************************************************
 * ** Function: check_range
 * ** Description: Checks to see if an integer is in a given range
 * ** Parameters: int lower_bound, int upper_bound, int test_value
 * ** Pre-Conditions: Correct integers are given into check_range
 * ** Post-Conditions: returns true (in rannge) or false (not in range)
 * *********************************************************************/ 
bool check_range(int lower_bound, int upper_bound, int test_value){	
	bool return_val = false;

	if (lower_bound <= test_value and upper_bound >= test_value){
		return_val = true;
	}
	
	return return_val;
}

/*********************************************************************
 * ** Function: is_capital
 * ** Description: Checks to see character is a capital letter.
 * ** Parameters: char letter
 * ** Pre-Conditions: Correct character given into is_capital
 * ** Post-Conditions: Returns true (is capital) or false (not capital)
 * *********************************************************************/ 
bool is_capital(char letter){
	bool return_val = false;
	if ((int)letter >= 65 and (int)letter <= 90){
		return_val = true;
	}
	return return_val;
}


/*********************************************************************
 * ** Function: is_even
 * ** Description: Checks to see if integer is even
 * ** Parameters: int num
 * ** Pre-Conditions: Correct integers given into is_even
 * ** Post-Conditions: Returns true (even) or false (not)
 * *********************************************************************/ 
bool is_even(int num){
	bool return_val = false;
	
	if (num % 2 == 0){
		return_val = true;
	}
	
	return return_val;
}

/*********************************************************************
 * ** Function: is_odd
 * ** Description: Checks to see if integer is odd
 * ** Parameters: int num
 * ** Pre-Conditions: Correct integers given into is_odd
 * ** Post-Conditions: Returns true (odd) or false (not)
 * *********************************************************************/ 
bool is_odd(int num){
	bool return_val = false;
	
	if (num % 2 != 0){
		return_val = true;
	}

	return return_val;

}

/*********************************************************************
 * ** Function: equality_test
 * ** Description: Checks if two numbers are equal/their relationship
 * ** Parameters: int num1, int num2
 * ** Pre-Conditions: Correct integers given into equality_test
 * ** Post-Conditions: Returns -1, 0, or 1
 * *********************************************************************/ 
int equality_test(int num1, int num2){
	int return_val = 0;

	if (num2 > num1){
		return_val = -1;
	}
	else if (num1 > num2){
		return_val = 1;
	}

	return return_val;
}

/*********************************************************************
 * ** Function: float_is_equal
 * ** Description: Checks to see if floats are equal w/in precision
 * ** Parameters: float num1, float num2, float precision
 * ** Pre-Conditions: Correct floats given into float_is_equal
 * ** Post-Conditions: Returns true (equal) or false (not equal)
 * *********************************************************************/ 
bool float_is_equal(float num1, float num2, float precision){
	bool return_val = true;
	float dif = abs(num1 - num2); 	
	if (dif > precision){
		return_val = false;
	}

	return return_val;
}

/********************************************************************
** Function: is_int
** Description: Determines if string is an integer or not.
** Parameters: string num
** Pre-Conditions: Correct string given into is_int
** Post-Conditions: Returns true (is an int) or false (is not an int)
*********************************************************************/ 
bool is_int(string num){
	bool return_val = true;
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			return_val = false;
		}
	}

	return return_val;
}

/*********************************************************************
** Function: numbers_present
** Description: Determines if string contains any numbers.
** Parameters: string sentence
** Pre-Conditions: Correct string given into numbers_present
** Post-Conditions: Returns true (numbers are present) or false (not)
*********************************************************************/ 
bool numbers_present(string sentence){
	bool return_val = false;
	for (int i = 0; i < sentence.length(); i++){
		if ((int)sentence.at(i) >= 48 and (int)sentence.at(i) <= 57){
			return_val = true;
		}
	}
	return return_val;
}

/********************************************************************
** Function: letters_present
** Description: determines if there are letters in a given string
** Parameters: string sentence
** Pre-Conditions: Correct string given into letters_present
** Post-Conditions: Returns true (numbers present) or false (not)
*********************************************************************/ 
bool letters_present(string sentence){
	bool return_val = false;
	for (int i = 0; i < sentence.length(); i++){
		if (((int)sentence.at(i) >= 65 and (int)sentence.at(i) <= 90)
		or ((int)sentence.at(i) >= 97 and (int)sentence.at(i) <= 122)){
			return_val = true;
		}
	}
	return return_val;
  
}

/********************************************************************
** Function: contains_sub_string
** Description: determines if substring is located in larger one
** Parameters: string sentence, string sub_string
** Pre-Conditions: Correct strings given into function
** Post-Conditions: Returns boolean of if it is located or not
*********************************************************************/ 
bool contains_sub_string(string sentence, string sub_string){
	bool return_val = false;
	for (int i = 0; i < sentence.length(); i++){
		if (sentence.at(i) == sub_string.at(0)
		and (i + sub_string.length() <= sentence.length())){
			for (int j = 0; j < sub_string.length(); j++){	
				if (sub_string.at(j) != sentence.at(i + j)){
					break;
				}
				if (j == sub_string.length()-1){
					return_val = true;
				}
			}
		}
	}

	return return_val;
}


/********************************************************************
** Function: word_count
** Description: determines how many words are in a string
** Parameters: string sentnece
** Pre-Conditions: Correct string given into word count
** Post-Conditions: Returns integer of how many words
*********************************************************************/ 
int word_count(string sentence){
	int word_count = 1;
	for (int i = 0; i < sentence.length(); i++){
		if ((int)sentence.at(i) == 32 or (int)sentence.at(i) == 95){
			word_count++;
		}
		
		/*makes sure the string isnt "" so it doesnt default to one*/
		/*if (sentence == ""){
			word_count = 0;
		}*/
	}
	return word_count;
}

/********************************************************************
** Function: to_upper
** Description: changes all lowercase letters to uppercase
** Parameters: string sentnece
** Pre-Conditions: Correct string given into to_upper
** Post-Conditions: Returns sentence with all uppercase + other chars
*********************************************************************/
string to_upper(string sentence){
	string return_sentence;
	for (int i = 0; i < sentence.length(); i++){
		if ((int)sentence.at(i) >= 97 
		and (int)sentence.at(i) <= 122){
			return_sentence += (char)((int)sentence.at(i) - 32);
		}
		else{
			return_sentence += sentence.at(i);
		}
	}
	
	return return_sentence;
}

/********************************************************************
** Function: to_lower
** Description: changes all uppercase letters to lowercase
** Parameters: string sentence
** Pre-Conditions: Correct string given into to_lower
** Post-Conditions: Returns sentence with all lowercase + other chars
*********************************************************************/
string to_lower(string sentence){
	string return_sentence;
	for (int i = 0; i < sentence.length(); i++){
		if ((int)sentence.at(i) >= 65 
		and (int)sentence.at(i) <= 90){
			return_sentence += (char)((int)sentence.at(i) + 32);
		}
		else{
			return_sentence += sentence.at(i);
		}
	}
	
	return return_sentence;
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
	int len = prompt.length();
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}
	return sum;
}

int main(){

	/*Check Range Function*/
	cout << "TESTING: check_range(0,100,30)" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << check_range(0,100,30) << endl;
	(check_range(0,100,30)==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: check_range(0,100,150)" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << check_range(0,100,150) << endl;
	(check_range(0,100,150)==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Capital Function*/
	cout << "TESTING: is_capital(\'A\')" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << is_capital('A') << endl;
	(is_capital('A')==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: is_capital(\'b\')" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << is_capital('b') << endl;
	(is_capital('b')==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Is Even*/
	cout << "TESTING: is_even(4)" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << is_even(4) << endl;
	(is_even(4)==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: is_even(3)" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << is_even(3) << endl;
	(is_even(3)==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Is Odd*/
	cout << "TESTING: is_odd(4)" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << is_odd(4) << endl;
	(is_odd(4)==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: is_odd(3)" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << is_odd(3) << endl;
	(is_odd(3)==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;


	/*Equality Test*/
	cout << "TESTING: equality_test(3,3)" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << equality_test(3,3) << endl;
	(equality_test(3,3)==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: equality_test(3,4)" << endl;
	cout << "Expected: -1" << endl;
	cout << "Actual: " << equality_test(3,4) << endl;
	(equality_test(3,4)==-1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: equality_test(4,3)" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << equality_test(4,3) << endl;
	(equality_test(4,3)==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Float is Equal*/
	cout << "TESTING: float_is_equal(3.4,3.5,0.1)" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << float_is_equal(3.4,3.5, 0.1) << endl;
	(float_is_equal(3.4,3.5,0.1)==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: float_is_equal(3.04,3.05,0.001)" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << float_is_equal(3.04,3.05, 0.001) << endl;
	(float_is_equal(3.04,3.05,0.001)==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Is Integer*/
	cout << "TESTING: is_int(\"3\")" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << is_int("3") << endl;
	(is_int("3")==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: is_int(\"3e3\")" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << is_int("3e3") << endl;
	(is_int("3e3")==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Numbers Present*/
	cout << "TESTING: numbers_present(\"Hey There!\")" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << numbers_present("Hey There!") << endl;
	(numbers_present("Hey There!")==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: numbers_present(\"4ey There!\")" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << numbers_present("Hey 4here!") << endl;
	(numbers_present("4ey There!")==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;
	
	/*Letters Present*/
	cout << "TESTING: letters_present(\"12345\")" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << letters_present("12345") << endl;
	(letters_present("12345")==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: letters_present(\"12e45\")" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << letters_present("12e45") << endl;
	(letters_present("12e45")==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;
	
	/*Contains sub string*/
	cout << "TESTING: contains_sub_string(\"whats up dude!\", \"hey\")" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << contains_sub_string("whats up dude", "hey") << endl;
	(contains_sub_string("whats up dude", "hey")==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: contains_sub_string(\"Hello World!\", \"rld!\")" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << contains_sub_string("Hello World!", "rld!") << endl;
	(contains_sub_string("Hello World!", "rld!")==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Word Count*/
	cout << "TESTING: word_count(\"Hey whats up guys\")" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual: " << word_count("Hey whats up guys") << endl;
	(word_count("Hey whats up guys")==4)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: word_count(\"helloworld\")" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << word_count("helloworld") << endl;
	(word_count("helloworld")==1)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*To upper*/
	cout << "TESTING: to_upper(\"helLo wORld!\")" << endl;
	cout << "Expected: HELLO WORLD!" << endl;
	cout << "Actual: " << to_upper("helLo wORld!") << endl;
	(to_upper("helLo wORld!")=="HELLO WORLD!")? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: to_upper(\"n1C3 to SE3 y0u!\")" << endl;
	cout << "Expected: N1C3 TO SE3 Y0U!" << endl;
	cout << "Actual: " << to_upper("n1c3 to SE3 y0u!") << endl;
	(to_upper("n1C3 to SE3 y0u!")=="N1C3 TO SE3 Y0U!")? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*To lower*/
	cout << "TESTING: to_lower(\"helLo wORld!\")" << endl;
	cout << "Expected: hello world!" << endl;
	cout << "Actual: " << to_lower("helLo wORld!") << endl;
	(to_lower("helLo wORld!")=="hello world!")? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: to_lower(\"n1C3 to SE3 y0u!\")" << endl;
	cout << "Expected: n1ce to se3 y0u!" << endl;
	cout << "Actual: " << to_lower("n1c3 to SE3 y0u!") << endl;
	(to_lower("n1C3 to SE3 y0u!")=="n1c3 to se3 y0u!")? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "\n" << endl;

	/*Get Int*/
	cout << "TESTING: get_int(\"123\")" << endl;
	cout << "Expected: 123" << endl;
	cout << "Actual: " << get_int("123") << endl;
	(get_int("123")==123)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	cout << "TESTING: get_int(\"Hello There!\")" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << get_int("Hello There!") << endl;
	(get_int("Hello There!")==0)? cout << "\tPASSED\n": cout<<"\tFAILED\n";

	return 0;
}
