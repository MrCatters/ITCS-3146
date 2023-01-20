// Zachary Palko

#include<iostream>
using namespace std;

int main(){
	int my_ints[4];
	int *my_ptrs[4];
	int i, j;
	
	// Prompts user to enter four numbers.
	cout << "Input four numbers:" << endl;
	for (i=0; i<4; i++){
		cin >> my_ints[i];
	}
	cout << endl;

	// Assigns memory locations from my_ints to my_ptrs array.
	for (i=0; i<4; i++){
		my_ptrs[i] = &my_ints[i];
	}

	// Bubble sort the pointers
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if (*my_ptrs[i] < *my_ptrs[j]){
				int *temp = my_ptrs[i];
				my_ptrs[i] = my_ptrs[j];
				my_ptrs[j] = temp;
			}
		}
	}		
	
	// Printing out referenced values in my_ptrs
	cout << "Printing out sorted my_ptrs:" << endl;
	for (i=0; i<4; i++){
		cout << *my_ptrs[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	// Prints out unmodified values from my_ints.
	cout << "Printing out unmodified values from my_ints:" << endl;
	for (i=0; i<4; i++){
		cout << my_ints[i] << " ";
	}
	cout << endl;
}
