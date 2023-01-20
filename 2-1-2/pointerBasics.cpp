// Zachary Palko

#include<iostream>
using namespace std;

int main() {
	int myInt = 15;
	int *myPointer = &myInt;
	
	// Check memory address and variables.
	cout << &myInt << endl;
	cout << myPointer << endl;
	cout << myInt << endl;
	cout << *myPointer << endl;
	
	// Reasigns variables to 10 and checks what has changed.
	myInt = 10;
	cout << &myInt << endl;
	cout << myPointer << endl;
	cout << myInt << endl;
	cout << *myPointer << endl;
}
