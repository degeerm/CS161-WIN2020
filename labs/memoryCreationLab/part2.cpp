#include <iostream>
using namespace std;
//takes in the memory address of a pointer
void delete_func(int *p){
	delete p;
	//delete deletes the content, null points it to zero
	p = NULL;
}

void create_memory(int **p){
	//implied pointer the pointer that it's pointing to is a new int
	*p = new int;
}

//takes the reference of *p
void create_memory_2(int *&p){
	p = new int;
}

// creates a new pointer
void create_memory_3(){
	//limited to this scope, cannot delete it outside
	int *p = new int;
	delete_func(p);
}

int main(){
	int num1 = 10;
	int num2;
	int num3;
	int **p;
	int* new_p;
	create_memory(p);
	create_memory_2(new_p);	
	create_memory_3();
	delete_func(new_p);
	delete_func(*p);
	return 0;
}
