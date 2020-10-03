#include <iostream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

int fib_iter(int n){
	int sum = 0;
	int n1 = 0;
	int n2 = 1;
	for (int i = 0; i < n-1; i++){
		sum = (n1 + n2);
		n1 = n2;
		n2 = sum;
	}
	return sum;
}

int fib_recur(int n){
	if (n <= 1){
		return n;
	}
	else{
		return (fib_recur(n-1) + fib_recur(n-2));
	}
}

int main() {
	typedef struct timeval time;
	time stop, start;
	gettimeofday(&start, NULL); 
	cout << fib_recur(10) << endl;
	//Time your iterative or recursive function here.
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
	cout << "Seconds: " << stop.tv_sec-start.tv_sec <<endl;
	else
	cout << "Micro: " << stop.tv_usec-start.tv_usec <<endl;
	return 0;
} 
