/*********************************************************************
 * ** Program Filename: string_checker.cpp
 * ** Author: Miya DeGeer
 * ** Date: 03/01/2020
 * ** Description: Various functions that allow for manipulation of strings
 * ** Input:  char, char*, int, string
 * ** Output: char*, string
 * *********************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define MAX_LENGTH 1023
using namespace std;

//***BASIC INPUT CHECKING/MANIPULATION FUNCTIONS***//

/********************************************************************
** Function: is_int
** Description: Determines if string is an integer or not.
** Parameters: string num
** Pre-Conditions: Correct string given into is_int
** Post-Conditions: Returns true (is an int) or false (is not an int)
*********************************************************************/ 
bool is_int(string num){
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			return false;
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
	int len = prompt.length();
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}
	return sum;
}
/********************************************************************
** Function: integer_input_checker
** Description: Cycles through asking user input until it is correct.
** Parameters: None.
** Pre-Conditions: get_int/is_int works
** Post-Conditions: Returns integer version of (correct) user input
*********************************************************************/ 
int integer_input_checker(){
	int checker = 1;
	string number;
	do{
		cin >> number;
		if (is_int(number)){
			int num = get_int(number);
			cin.ignore();
			return (num);
		}else
			cout << "Error: Positive integer numbers only." << endl;
			cin.ignore();
	}while(checker);
}

/********************************************************************
** Function: contains_sub_string
** Description: determines if substring is located in larger one
** Parameters: char* sentence, char* sub_string, int index
** Pre-Conditions: Correct c-style strings given into function
** Post-Conditions: Returns boolean if it's inside the function at index
*********************************************************************/ 
bool contains_sub_string(char* sentence, char* sub_string, int index){
	int i = index;
	if (i + strlen(sub_string) <= strlen(sentence)){
		for (int i = index; i < strlen(sentence); i++){
			for (int j = 0; j < strlen(sub_string); j++){	
				if (sub_string[j] != sentence[i + j]){
					return false;
				}
				if ((j == strlen(sub_string)-1)){
					if (sentence[1+i+j] == ' ' || j+i >= strlen(sentence)-1){
						return true;
					}
				}
			}
		}
	}
	return false;
}

/********************************************************************
** Function: string_to_lower
** Description: changes all uppercase letters to lowercase
** Parameters: char *s, char *s_new
** Pre-Conditions: Correct string given into to_lower
** Post-Conditions: Returns sentence with all lowercase + other chars
** into s_new.
*********************************************************************/
void string_to_lower(char *s, char *s_new){
	for (int i = 0; i <= strlen(s); i++){
		if ((int)s[i] >= 65 
		and (int)s[i] <= 90){
			s_new[i] = (char)((int)s[i] + 32);
		} 
		else{
			s_new[i] =  s[i];
		}
	}	
}

/********************************************************************
** Function: char_input_checker
** Description: Cycles through asking user input for character 
** until it is a good letter, converts it to lower case if needed.
** Parameters: int num
** Pre-Conditions: Some character has been declared outside of function,
** int num has been declared outside of the function
** Post-Conditions: Returns valid character
*********************************************************************/ 
char char_input_checker(int num){
	string user_input;
	while (true){
		cout << "\nEnter character #" << num << ", to be used in swap." << endl;
		cin >> user_input;
		if (user_input.length() == 1){
			if ((user_input.at(0)>='A') && user_input.at(0) <= 'Z'){
				return ((char)((int)user_input.at(0) + 32));
			}else if (user_input.at(0) >= 'a' && user_input.at(0) <= 'z'){
				return (user_input.at(0));
			}else{
				cout << "Error: Please only enter a letter." << endl;
			}
		}else{
			cout << "\nError: Please enter a singular letter to be used in swap." << endl;
			continue;
		}
	}
}

/********************************************************************
** Function: purge_string
** Description: Purges strings of all special characters (maybe spaces)
** Parameters: char *str, char *new_str, int sp_or_n
** Pre-Conditions: str and new_str are declared; sp_or_n either 0 or 1
** Post-Conditions: Returns version of str into new_str w/o characters
*********************************************************************/ 
void purge_string(char *str, char *new_str, int sp_or_n){
	int j = 0;
	for (int i = 0; i < (strlen(str)); i++){
		//checks if it's a letter, OR if spaces are allowed + its a space
		if (((int)str[i] >= 65 && (int)str[i]<=90) ||
		((int)str[i] >= 97 && (int)str[i]<=122) ||
		((int)str[i] == 32 && sp_or_n == 1)){
			new_str[j] = str[i];
			j++;
		}
	}
}

/********************************************************************
** Function: create_blank_2d
** Description: Splits a character array into a 2d array based on spaces
** and it initializes all values to null.
** Parameters: int row, int col
** Pre-Conditions: row and col have been initialized elsewhere
** Post-Conditions: User_input is split into 2-d array within arr,
** all values in a are initialized to null.
*********************************************************************/ 

char **create_blank_2d(int row, int col){
	char **a;
	a = new char*[row];
	for (int i = 0; i < row; i++){
		a[i] = new char [col];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			a[i][j] = '\0';
		}
	}
	return a;
}

/********************************************************************
** Function: delete_array
** Description: Deletes a 2d array that was declared on the heap
** Parameters: char ** a
** Pre-Conditions: a has been initialized elsewhere
** Post-Conditions: a is deleted off of the heap, the pointer for a
** is set to null.
*********************************************************************/ 
char ** delete_array(char **a){
	for (int i = 0; i < (MAX_LENGTH); i++){
			delete []a[i];
	}
	delete[] a;
	a = NULL;	
}


//***VOWELS V CONSONANT FUNCTIONS***//

/********************************************************************
** Function: vowels_v_const
** Description: Determines whether or not #of vowels = # of consonants
** Parameters: char *s
** Pre-Conditions: s has been declared elsewhere 
** Post-Conditions: Returns if they're the same (1) or not (0)
*********************************************************************/ 
bool vowels_v_const(char *s){
	char *snew = new char[MAX_LENGTH];
	int vowel_count = 0;
	int cons_count = 0;
	purge_string(s,snew,0);
	for (int i = 0; i < strlen(snew); i++){
		if (snew[i] == 'a' || snew[i] == 'A' || snew[i] == 'e' || snew[i] == 'E' ||
		snew[i] == 'i' || snew[i] == 'I' || snew[i] == 'o' || snew[i] == 'O' ||
		snew[i] == 'u' || snew[i] == 'U'){
			vowel_count++;
		}else{
			cons_count++;
		}
	}
	delete snew;
	if (vowel_count == cons_count){
		return 1;
	}
	return 0;	
}

/********************************************************************
** Function: vow_v_con_format
** Description: Formats the vowels v consonants results for user
** Parameters: char *s
** Pre-Conditions: s has been declared elsewhere 
** Post-Conditions: Prints out more user-friendly version of results
*********************************************************************/ 
void vow_v_con_format(char *s){
	int result = vowels_v_const(s);
	if (result == 1){
		cout << "#of consonants == #of vowels" << endl;
	}
	else{
		cout << "#of consonants != #of vowels" << endl;
	}
}

//***SWITCH LETTER FUNCTIONS***//

/********************************************************************
** Function: letter_swap
** Description: Switches out all matching characters in the string
** Parameters: char *s
** Pre-Conditions: s has been declared somewhere
** Post-Conditions: s is altered so all let1s are replaced with let2.
*********************************************************************/ 
void letter_swap(char *s){
	char lower_1 = char_input_checker(1);
	char lower_2 = char_input_checker(2);
	char upper_1 = (char)((int)lower_1-32);
	char upper_2 = (char)((int)lower_2-32);
	int i = 0;
	for (i = 0; i < strlen(s); i++){
		if (s[i] == lower_1){
			s[i] = lower_2;
		}
		else if (s[i] == upper_1){
			s[i] = upper_2;
		}
	}
	s[i+1] = '\0';
	cout << "\nYour swapped string is: " << s << endl; 
}

//***FLIP STRING FUNCTIONS***//

/********************************************************************
** Function: flip_string
** Description: Flips one string around, and stores it in another.
** Parameters: char *s, char *snew
** Pre-Conditions: s and snew have been declared somewhere
** Post-Conditions: s is flipped around into snew.
*********************************************************************/ 
void flip_string(char *s, char *snew){
	int new_index = 0;
	for (int i = strlen(s)-1; i >= 0; i--){
		char current = s[i];
		snew[new_index] = current;
		new_index++;
	}
}

/********************************************************************
** Function: flip_string_format
** Description: Formats the newly flipped string for one of the options
** Parameters: char *s
** Pre-Conditions: s has been declared somewhere
** Post-Conditions: Prints out flipped string from new variable.
*********************************************************************/ 
void flip_string_format(char *s){
	char *s2 = new char[strlen(s)];
	flip_string(s,s2);
	cout << "\nYour flipped string is: " << s2 << endl;
	delete s2;
}

//***PALINDROME FUNCTIONS***//

/********************************************************************
** Function: is_palindrome
** Description: Determines whether or not something is palindrome
** prints it out
** Parameters: char *s
** Pre-Conditions: s has been declared somewhere
** Post-Conditions: Prints out whether or not string is palindrome
*********************************************************************/ 
void is_palindrome(char *s){
	/*declarations*/
	char *snew = new char[strlen(s)];
	char *snew_t = new char[strlen(s)];
	
	/*cleaning up strings*/
	purge_string(s,snew,0);
	purge_string(s,snew_t,0);
	string_to_lower(snew,snew);
	string_to_lower(snew_t,snew_t);
	
	/*Flip String*/
	flip_string(snew, snew);
	for (int i = 0; i < strlen(s); i++){
		if (snew_t[i] != snew[i]){
			cout << "This is not a palindrome." << endl;
			delete snew;
			delete snew_t;
			return;
		}
	}
	cout << "This is a palindrome." << endl;
	delete snew;
	delete snew_t;
}

//***WORD FREQUENCY FUNCTIONS***//

/********************************************************************
** Function: splitter
** Description: Splits a character array into a 2d array based on spaces
** Parameters: char *user_input, char arr[][1023]
** Pre-Conditions: user_input and arr have been declared elsehwere
** Post-Conditions: User_input is split into 2-d array within arr,
** returns number of rows for convienience.
*********************************************************************/ 
int splitter (char *user_input, char **arr){
	int r = 0, c = 0;
	int i = 0;
	while (i < strlen(user_input)){

		/*if it's a space OR first character, probably a word*/
		if (user_input[i] == ' ' or i == 0){
			if (i != 0){
				i++;
			}
			/*While the character isn't a space OR end of string, add it to 2d Array*/
			while (user_input[i] != ' ' and i < strlen(user_input)){
				arr[r][c] = user_input[i];
				i++; c++;
			}
			r++;
			c = 0;
		}else{
			i++;
		}
	}
	return r;
}

/********************************************************************
** Function: check_2d_array
** Description: Takes in the users values for the words they're checking
** the frequency of, sets those in a heap array if valid (equals number
** of words), returns array
** Parameters: int num_words
** Pre-Conditions: num_words has been initialized elsewhere
** Post-Conditions: returns an array of the words the user is going
** to check for
*********************************************************************/ 
char ** check_2d_array(int num_words){	
	while (true){
		/*Array Declarations*/
		char ** arr = create_blank_2d(MAX_LENGTH, MAX_LENGTH);
		char * old_user_input = new char[MAX_LENGTH];
		char * user_input = new char[MAX_LENGTH];
		
		/*User Input*/
		cout << "\nPlease enter " << num_words << " words, with a space between each one." << endl;
		cin.getline(old_user_input, MAX_LENGTH);
		
		/*Cleaning up the string*/
		purge_string(old_user_input,user_input,1);
		string_to_lower(user_input,user_input);
		
		/*Splitting it into 2d Array*/	
		int rows = splitter(user_input,arr);

		/*Checking to make sure they actually entered the amount they said they would*/
		if (rows != num_words){
			cout << "\nError: Please only enter " << num_words << " words with one space in-between." << endl;	
			delete_array(arr);

		}else{
			delete old_user_input;
			delete user_input;
			return arr;
		}
	}
}

/********************************************************************
** Function: searcher
** Description: searches through string for incidences of strings within
** 2d array, prints out how many times it's found.
** Parameters: char *str, char ** arr, int num_words
** Pre-Conditions: str and arr, and num_words have been declared elsewhere
** Post-Conditions: How many times each element within arr happens within
** str, is printed to the screen.
*********************************************************************/ 
void searcher(char *str, char** arr, int num_words){
	cout << "\nThe frequency of your words is:" << endl;
	//overarching going through each word
	for (int r = 0; r < num_words; r++){
		int counter = 0;
		//going through the string to see if i can find incidence
		for (int j = 0; j < strlen(str); j++){
			if (str[j] == ' ' || j == 0){
				if (j!= 0){
					j++;
				}
				if (arr[r][0] == str[j]){
					if (contains_sub_string(str,arr[r],j)){
						counter++;
						j += strlen(arr[r])-1;
					}
				}
			}
		}
		for (int c = 0; c < strlen(arr[r]); c++){
			cout << arr[r][c];
		}
		cout << ": " << counter << endl;
	}
}

/********************************************************************
** Function: word_frequency
** Description: Counts the occurences of words user gives in
** Parameters: char *old_str
** Pre-Conditions: old_str declared outside, inside functions working
** properly.
** Post-Conditions: Prints out how many times a list of given words 
** within a bigger string.
*********************************************************************/ 
void word_frequency(char *old_str){

	/*Variable declarations*/
	char * str = new char [MAX_LENGTH];	
	char ** arr;
	cout << "How many words would you like to search for?" << endl;
	int num_words = integer_input_checker();
	arr = check_2d_array(num_words);
	purge_string(old_str,str,1);
	string_to_lower(str,str);	
	searcher(str, arr, num_words);	
	
	delete_array(arr);
	delete str;
}

//***OUTPUT FUNCTIONS***//

/********************************************************************
** Function: input_take_option
** Description: Cycles through taking input for manipulation choice 
** until correct
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Returns the user choice for input, so it's correct
*********************************************************************/ 
string input_take_option(){
	string user_choice = "";
	while (true){
		cout << "\nWhich option would you like to do?" << endl;
		cout << "1) Vowels VS. Consonants" << endl;
		cout << "2) Letter Swap" << endl;
		cout << "3) Flip String" << endl;
		cout << "4) Palindrome Detector" << endl;
		cout << "5) Word Frequency" << endl;
		cout << "6) Quit\n" << endl;
		cin >> user_choice;
		if (user_choice != "1" && user_choice != "2" && user_choice != "3"
		&& user_choice != "4" && user_choice != "5" && user_choice != "6"){
			cout << "Error: Please only input 1-6." << endl;
		}else if (user_choice == "6"){
			cout << "Thank you for using string modifier!" << endl;
			exit(0);
		}
		else{
			return user_choice;
		}
	}	
}

/********************************************************************
** Function: option_picker
** Description: Uses user input to decide which operation to make.
** Parameters: char *s
** Pre-Conditions: s has been declared somewhere
** Post-Conditions: Performs selected operation based on the string.
*********************************************************************/ 
void option_picker(char *s){
	string user_choice = input_take_option();
	if (user_choice == "1"){
		vow_v_con_format(s);
	}else if (user_choice == "2"){
		letter_swap(s);	
	}else if (user_choice == "3"){
		flip_string_format(s);
	}else if (user_choice == "4"){
		is_palindrome(s);
	}else if (user_choice == "5"){
		word_frequency(s);		
	}
	cout << endl;
}

/********************************************************************
** Function: main
** Description: Takes in user input to do various string-manipulations
** practices.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Does string manipulation until user says stop.
*********************************************************************/ 
int main(){
	char user_input[MAX_LENGTH];
	cout << "\nWelcome to String Modifier! Please enter a string 1023 characters or less." << endl;
	cin.getline(user_input,MAX_LENGTH);
	if (cin.fail()){
		cin.ignore(1023,'\n');
		cin.clear();
	}
	string continue_or_not = "1";
	while(true){
		option_picker(user_input);
	}
	return 0;
}
