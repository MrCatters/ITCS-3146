// Zachary Palko

#include<iostream>
using namespace std;

//Declares the function before execution
void swapint(int *num1, int *num2);

int main() {
	int num1, num2;
	
	// Prompts user for two numbers.
	cout << "Please enter two numbers:" << endl;
	cin >> num1;
	cin >> num2;
	cout << endl;
	
	// Swap the values and print.
	cout << "The two numbers after swap:" << endl;
	swapint(&num1, &num2);
	cout << num1 << endl;
	cout << num2 << endl;

}

// Switches the memory addresses referred to by each variable.
void swapint(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}
