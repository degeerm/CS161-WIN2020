#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int x;
	srand(time(NULL));

	x = rand() % 6;
	cout << x << endl;

	if (x == 0){
		cout << "Bummer, Im zero!!!" << endl;
	}

	else if (x == 1 || x == 3 || x == 5){
		cout << "Im an odd number!" << endl;
	}

	else if (x == 2 || x == 4){
		cout << "Im an even number!" << endl;
	}


	/*
	x = rand();
	cout << "X = " << x << endl;
	//result 1: some pretty big numbers, different each time
	//result 2: same numbers each time
	//result 3: different number each time it runs, but both nums are same	
	srand(time(NULL));
	x = rand();
	cout << "X = " << x <<endl;
	*/
	return 0;

	
}
