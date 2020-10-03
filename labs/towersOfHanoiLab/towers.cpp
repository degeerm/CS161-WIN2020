#include <iostream>
#include <string>

using namespace std;

void create_2d(int ** array, int row_size, int column_size){

	array = new int*[row_size];
	for (int i = 0; i < column_size; i++){
		array[i] = new int;
	}
}

void delete_2d(int ** array, int column_size){
	for (int i = 0; i < column_size; i++){
		delete []array[i];
	}
	delete []array;
}

void print_board(int board[3][3], int rows, int cols){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			cout << board[c][r] << " ";
		}
		cout << endl;
	}
	for (int c = 0; c < cols; c++){
		cout << "- ";
	}
	cout << endl;
}
void move(int disks, int board[][3], int from, int to){
	for (int i = 0; i < disks; i++){
		if (board[from][i] != 0){
			cout << "board from i ONE" << board[from][i] << endl;

			//board[to][i] = board[from][i];
			for(int j = 2; j >=0 ; j-- ){
				cout << "HEre be j: " << j << endl;
				if(board[to][j] == 0){
					//cout << "To and j: "<< to << j << endl;
					cout << "board from i" << board[from][i] << endl;
					board[to][j]= board[from][i];
					board[from][i] = 0;
					return;

				}
					
			}
			
		}
	}
	
	//return;
}
void towers(int num_of_disks, int tot_disks, int b[][3], int from_col, int to_col, int spare){
	if (num_of_disks >= 1){
		towers (num_of_disks-1,tot_disks,b, from_col, spare, to_col);
		move (tot_disks, b, from_col, to_col);
		print_board(b,3,3);
		towers(num_of_disks-1,tot_disks,b, spare,to_col,from_col);	
	}	
}



int main(){
	//Static Implementation
	int disks = 3;
	int array[][3] = {{0},{0},{0}};
	for (int i = 2; i >= 0;i--){
		array[0][i] = i+1;
	}
	print_board(array,3,3);
	towers(disks,disks,array,0,1,2);	
	
}
