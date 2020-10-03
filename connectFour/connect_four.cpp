/*********************************************************************
 * ** Program Filename: connect_four.cpp
 * ** Author: Miya DeGeer
 * ** Date: 03/15/2020
 * ** Description: Plays through one or more full games of connect four
 * ** using connections from command line arguments.
 * ** Input:  string, char, integer
 * ** Output: string, integer, char**
 * *********************************************************************/


#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
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
	bool return_val = true;
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			return_val = false;
		}
	}

	return return_val;
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
	char current;
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}
	return sum;
}

/********************************************************************
** Function: column_input_checker
** Description: Takes in the user input for selecting a column to drop
** a piece.
** Parameters: int lartest
** Pre-Conditions: is_int, get_int, and largest have been declared
** elsewhere.
** Post-Conditions: A correct column input (in range + is an integer)
** is returned.
*********************************************************************/ 
int column_input_checker(int largest){
	string number;
	int num;
	do{
		cout << "Enter your column number:   ";
		cin >> number;
		cin.ignore();
		if (is_int(number)){
			num = get_int(number);
			if (num >= 0 && num <= largest){
				return num;
			}else{
				cout << "\nError: Column given is not in domain. Try again." << endl;
			}
		}else{
			cout << "\nError: Positive integer numbers only, please." << endl;
		}	
	}while(true);
}

/********************************************************************
** Function: choose_piece_human 
** Description: Let's the human user choose whether they wanna be
** x or o.
** Parameters: int player
** Pre-Conditions: player has been declared elsewhere
** Post-Conditions: Either x or o is returned as a player piece.
*********************************************************************/
char choose_piece_human(int player){
	string letter;
	while (true){
		cout << "\nPlayer " << player << ", please enter X or O as your piece." << endl;
		cin >> letter;
		if (letter == "o" || letter == "O"){
			return 'o';
		}else if (letter == "X" || letter == "x"){
			return 'x';
		}else{
			cout << "Error: Please only enter x or o." << endl;
		}
	}
}

/********************************************************************
** Function: choose_piece_computer
** Description: Selects other player's piece based on what first player
** chose.
** Parameters: char other
** Pre-Conditions: other has been declared elsewhere.
** Post-Conditions: Either x or o has been returned as character.
*********************************************************************/
char choose_piece_computer(char other){
	if (other == 'x'){
		return 'o';
	}
	return 'x';
}

/**************BOARD FUNCTIONS****************/
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
	char** a = new char*[row];
	for (int i = 0; i < row; i++){
		a[i] = new char[col];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			a[i][j] = ' ';
		}
	}

	return a;
}

/********************************************************************
** Function: make_space
** Description: Makes space for the numbers on the top of the board
** when printing.
** Parameters: int col
** Pre-Conditions: col has been declared elsewhere.
** Post-Conditions: Numbers are printed at the top of the board.
*********************************************************************/
void make_space(int col){
	int i;
	for (i = 0; i < col; ++i){
		if (i < 10){
			cout << " ";
		}
		cout << " " << i << " ";
	}
	cout << endl;
}

/********************************************************************
** Function: print_board
** Description: Prints out the board with all of the pieces in it.
** Parameters: char** board, int row
** Pre-Conditions: board, row, and col have been declared elsewhere.
** Post-Conditions: The board is printed and formatted to look nice for
** the user.
*********************************************************************/
void print_board(char** board, int row, int col){
	make_space(col);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[1;37;40m " << board[i][j] << " "; 
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[1;37;40m " << board[i][j] << " ";
			else
				cout << "|\033[1;30;47m " << board[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}
	cout << "\n" << endl;
}

/********************************************************************
** Function: delete_array
** Description: Deletes a 2d array that was declared on the heap
** Parameters: char ** a
** Pre-Conditions: a has been initialized elsewhere
** Post-Conditions: a is deleted off of the heap, the pointer for a
** is set to null.
*********************************************************************/ 
char ** delete_array(char **a, int rows, int cols){
	for (int i = 0; i < rows; i++){
			delete[] a[i];
	}
	delete[] a;
	a = NULL;	
}

/***************WINNER FUNCTIONS******************/
/*Row Winner*/
/********************************************************************
** Function: is_winner_row
** Description: Determines if there is a winner in a row in the board.
** Parameters: char** board, char piece, int rows, int cols
** Pre-Conditions: board, piece, rows, and cols have all been declared
** elsewhere.
** Post-Conditions: Returns true if there's a row win, false otherwise.
*********************************************************************/
bool is_winner_row(char** board, char piece, int rows, int cols){
	int counter;
	for (int r = 0; r < rows; r++){
		counter = 0;
		for (int c = 0; c < cols; c++){
			if (board[r][c] == piece){
				counter++;
			}else{
				counter = 0;
			}
			if (counter >= 4){
				return true;
			}
		}
	}
	return false;
}

/*Column Winner*/
/********************************************************************
** Function: is_winner_column
** Description: Determines if there is a winner in a column in the board.
** Parameters: char** board, char piece, int rows, int cols
** Pre-Conditions: board, piece, rows, and cols have all been declared
** elsewhere.
** Post-Conditions: Returns true if there's a column win, false otherwise.
*********************************************************************/
bool is_winner_column(char** board, char piece, int rows, int cols){
	int counter;
	for (int c = 0; c < cols; c++){
		counter = 0;
		for (int r = 0; r < rows; r++){
			if (board[r][c] == piece){
				counter++;
			}else{
				counter = 0;
			}
			if (counter >= 4){
				return true;
			}
		}
	}
	return false;
}

/*Diagonal One Winner*/
/********************************************************************
** Function: is_winner_diagone
** Description: Determines if there is a winner in a diagonal in 
** the board.
** Parameters: char** board, char piece, int rows, int cols
** Pre-Conditions: board, piece, rows, and cols have all been declared
** elsewhere.
** Post-Conditions: Returns true if there's a diagonal win,
** false otherwise.
*********************************************************************/
bool is_winner_diagone(char** board, char piece, int rows, int cols){
	int counter;
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			counter = 0;
			if (board[r][c] == piece && ((r+3) < (rows)) && ((c+3)) < (cols)){
				int r_new = r; int c_new = c;
				for (int i = 0; i <= 3; i++){
					if (board[r_new][c_new] == piece){
						counter++;
						r_new++;
						c_new++;
					}
					else{
						counter = 0;	
					}if (counter >= 4){
						return true;
					}
				}
			}
		}
	}
	return false;
}

/*Diagonal Two winner*/
/********************************************************************
** Function: is_winner_diagtwo
** Description: Determines if there is a winner in a diagonal 
** in the board.
** Parameters: char** board, char piece, int rows, int cols
** Pre-Conditions: board, piece, rows, and cols have all been declared
** elsewhere.
** Post-Conditions: Returns true if there's a diagonal win,
** false otherwise.
*********************************************************************/
bool is_winner_diagtwo(char** board, char piece, int rows, int cols){
	int counter;
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			counter = 0;
			if (board[r][c] == piece && ((r-3) >= 0) && ((c+3)) <= cols-1){
				int r_new = r; int c_new = c;
				for (int i = 0; i <= 3; i++){
					if (board[r_new][c_new] == piece){
						counter++;
						r_new--;
						c_new++;
					}	else{
						counter = 0;	
					}if (counter >= 4){
						return true;
					}
				}
			}
		}
	}
	return false;
}

/********************************************************************
** Function: is_winner_total
** Description: Determines if there's any win on the board.
** Parameters: char** board, char piece, int cols, int rows
** Pre-Conditions: board, piece, cols, and rows have been declared
** elsewhere.
** Post-Conditions: Returns true if there's any win on the board,
** false otherwise.
*********************************************************************/
bool is_winner_total(char **board, char piece, int cols, int rows){
	if ((is_winner_row (board,piece,cols,rows)) ||
	(is_winner_column (board,piece,cols,rows)) ||
	(is_winner_diagone (board,piece,cols,rows)) ||
	(is_winner_diagtwo (board,piece,cols,rows))){
		return true;
	}
	return false;
}

/********************************************************************
** Function: is_winnable
** Description: Determines if there's a tie (IE, no space left)
** Parameters: board, rows, cols
** Pre-Conditions: board, rows, and cols
** Post-Conditions: Returns true if the board is still playable,
** false otherwise.
*********************************************************************/
bool is_winnable(char** board, int rows, int cols){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			if (board[r][c] == ' '){
				return true;
			}
		}
	}
	return false;
}

/********************************************************************
** Function: has_free_spot
** Description: Determines if the column the user is trying to place in
** has a free spot, and is placeable.
** Parameters: char** board, int col, int rows
** Pre-Conditions: board,col, and rows have been declared elsewhere.
** Post-Conditions: returns the first row available in the column,
** returns -1 otherwise.
*********************************************************************/
int has_free_spot(char** board, int col, int rows){
	for (int r = rows-1; r >= 0; r--){
		if (board[r][col] == ' '){
			return r;
		}
	}
	return -1;
}

/********************************************************************
** Function: position_placing
** Description: Takes in user input on where they want to place their
** piece, places it if possible, continues to cycle until it is.
** Parameters: char** board, int rows, cols, player, and char piece
** Pre-Conditions: board, rows, cols, piece, and player have been
** declared elsewhere.
** Post-Conditions: Places the piece in the desired spot of the user.
*********************************************************************/
void position_placing(char** board, int rows, int cols, char piece, int player){
	int player_column;
	int temp;
	while(true){
		cout << "Its Player " << player << "s turn. Which column? (0 through " << cols-1 << ")." << endl;
		player_column = column_input_checker(cols-1);
		temp = has_free_spot(board,player_column,rows);
		if (temp != -1){
			board[temp][player_column] = piece;
			break;
		}else{
			cout << "Error: This column is full. Select a different one." << endl;
		}
	}
}

/*********************GAME FUNCTIONS*********************/
/********************************************************************
** Function: human_play
** Description: Lets the user choose where they wanna place their piece,
** determines if there's a win or a tie or not.
** Parameters: char** board, char piece, int player, int rows and cols.
** Pre-Conditions: board, piece, player, rows and cols have been
** declared elsewhere.
** Post-Conditions: A piece is placed. If its a win condition or a
** tie condition, game ends.
*********************************************************************/
bool human_play(char** board, char piece, int player, int rows, int cols){
	position_placing(board, rows,cols,piece,player);
	if (is_winner_total(board,piece,rows,cols)){
		print_board(board,rows,cols);
		cout << "Player " << player << " wins!!" << endl;
		return 0;
	}else if (!is_winnable(board,rows,cols)){
		print_board(board,rows,cols);
		cout << "It is a tie!" << endl;
		return 0;
	}
	return 1;
}

/********************************************************************
** Function: computer_play
** Description: Lets the computer place its piece randomly.
** Parameters: board, piece, rows, cols
** Pre-Conditions: board, peice, rows, and cols have all been declared
** elsewhere.
** Post-Conditions: Lets the computer place its piece randomly. If its
** a tie or winning condition, ends game.
*********************************************************************/
bool computer_play(char** board, char piece, int rows, int cols){
	cout << "It is now the computer's turn!" << endl;
	while (true){
		int random_col = rand() % cols;
		if (has_free_spot(board,random_col,rows) != -1){
			board[(has_free_spot(board,random_col,rows))][random_col] = piece;
			break;
		}
	}
	if (is_winner_total(board,piece,rows,cols)){
		print_board(board,rows,cols);
		cout << "The computer wins!" << endl;
		return 0;
	}else if (!is_winnable(board,rows,cols)){
		print_board(board,rows,cols);
		cout << "It is a tie!" << endl;
		return 0;
	}
	return 1;
}

/********************************************************************
** Function: play
** Description: Plays through one round of connect four.
** Parameters: board, p1_piece, mode, rows, cols
** Pre-Conditions: all of the above variables have been declared
** elsewhere, as well as the functions used within.
** Post-Conditions: One round of connect four is played, with the
** proper edits being made to the board.
*********************************************************************/
bool play(char** board, char p1_piece, char p2_piece, string mode,int rows,int cols){	
	if (!human_play(board,p1_piece,1,rows,cols)){
		return 0;
	}	
	print_board(board,rows,cols);
	if (mode == "1"){
		if (!computer_play(board,p2_piece,rows,cols)){
			return 0; 
		}
	}
	else if (mode == "2"){
		if (!human_play(board,p2_piece,2,rows,cols)){
			return 0;
		}
	}

	print_board(board,rows,cols);
	return 1;
}

/********************************************************************
** Function: game
** Description: Cycles through playing rounds/games until the user
** wants to end the program.
** Parameters: rows, cols, and mode
** Pre-Conditions: Rows, cols, and mode have all been declared
** elsewhere, along with all the functions inside.
** Post-Conditions: Multiple rounds of connect four are played until
** user gives instruction to stop.
*********************************************************************/
void game(int rows, int cols, string mode){
	string user_response;
	while (true){
		char ** board = create_blank_2d(rows,cols);
		char player_1_piece, player_2_piece;
		player_1_piece = choose_piece_human(1);
		player_2_piece = choose_piece_computer(player_1_piece);

		print_board(board,rows,cols);

		while (true){
			if (!play(board,player_1_piece,player_2_piece,mode,rows,cols)){
				break;
			}
		}
		delete_array(board,rows,cols);
		
		cout << "Would you like to play again? (Enter 0 for no.)" << endl;
		cin >> user_response;
		if (user_response == "0"){
			return;
		}		
	}
}

/********************************************************************
** Function: column_row_checker
** Description: Checks columns and rows to make sure they're ints and
** under 21.
** Parameters: string rc, string type
** Pre-Conditions: rc and type have been declared elsewhere. 
** Post-Conditions: A correct row/column is returned.
*********************************************************************/
int column_row_checker(string rc, string type){
	do{
		if (is_int(rc)){
			if (get_int(rc) <= 20){
				return (get_int(rc));
			}
			else{
				cout << "\nError: " << type << " cannot be over 20. ";
				cout << "Please enter " << type << " again." << endl;
			}
		}
		else{
			cout << "\nError: You entered an incorrect argument for your ";
			cout << type << ". Enter again." << endl;
		}
		cin >> rc;
	}while (true);
}

/********************************************************************
** Function: mode_checker
** Description: Checks the mode to make sure it is either 1 or 2.
** Parameters: string mode
** Pre-Conditions: mode has been declared elsewhere. 
** Post-Conditions: A correct mode is returned.
*********************************************************************/
string mode_checker(string mode){
	do{
		if (mode == "1" || mode == "2"){
			return (mode);
		}else{
			cout << "\nError: Please only enter either 1 or 2 as your mode." << endl;
		}
		cin >> mode;
	}while (true);
}

/********************************************************************
** Function: reentering_row_column
** Description: Makes user re-enter rows/columns if the correct amount
** was not given in command-line argument.
** Parameters: string type
** Pre-Conditions: type has been declared elsewhere. 
** Post-Conditions: A correct row/column is returned.
*********************************************************************/
int reentering_row_column(string type){
	string user_input;
	cout << "Please re-enter your " << type << ": ";
	cin >> user_input;
	cout << endl;
	return (column_row_checker(user_input, type));
}

/********************************************************************
** Function: reenter_mode
** Description: Makes user re-enter mode if the correct response was
** not given in command-line argument.
** Parameters: None.
** Pre-Conditions: mode_checker is functioning properly
** Post-Conditions: A correct mode is returned.
*********************************************************************/
string reenter_mode(){
	string user_input;
	cout << "Please re-enter your mode: ";
	cin >> user_input;
	cout << endl;
	return (mode_checker(user_input));
}

/********************************************************************
** Function: main
** Description: Runs through a game of connect four until the user wants
** to stop.
** Parameters: int argc, char argv
** Pre-Conditions: All other functions are working properly.
** Post-Conditions: A game of connect four is cycled until player wants
** to stop, prorgram ends.
*********************************************************************/
int main(int argc, char **argv){
	int rows;
	int cols;	
	string mode, r, c, m;
	if (argc == 4){
		r = argv[2];
		c = argv[3];
		m = argv[1];
		rows = column_row_checker(r, "row");
		cols = column_row_checker(c, "column");
		mode = mode_checker(m);
	}else{
		cout << "\nError: You did not enter the proper amount of arguments." << endl;
		cout << "You will now be prompted to re-enter.\n" << endl;
		rows = reentering_row_column("rows");
		cols = reentering_row_column("columns");
		mode = reenter_mode();
	}
	game(rows,cols,mode);
	return 0;
}
