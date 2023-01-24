//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

// Zachary Palko

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};

// Displays the contents of the patient list with commas between fields.
void displayPatientList(struct patient patients[]){
	for(int i = 0; i < 6; i++){
		cout << patients[i].age << ", ";
		cout << patients[i].name << ", ";
		cout << patients[i].balance << endl;
	}
}

// https://cplusplus.com/doc/tutorial/pointers/
// Compares two patients by age.
// Returns -1 if the age of the first patient is less than the second patient's age.
// Returns 0 if the ages are equal.
// Returns 1 otherwise.
int comparePatientsByAge(const void *patient1, const void *patient2){
	
    // Assigns the age field of the patient struct to an int variable.
	int patientAge1 = ((struct patient *)patient1) -> age;
	int patientAge2 = ((struct patient *)patient2) -> age;
		
    // Compares the two ages and returns the result.
	if (patientAge1 < patientAge2) {
		return -1;
	} else if (patientAge1 == patientAge2) {
		return 0;
	} else {
		return 1;
	}
	
}



// Compares two patients by balance.
// Returns -1 if the balance of the first patient is less than the second patient's balance.
// Returns 0 if the balances are equal.
// Returns 1 otherwise.
int comparePatientsByBalance(const void *patient1, const void *patient2){
	
    // Assigns the balance field of the patient struct to a float variable.
	float patientBalance1 = ((struct patient *)patient1) -> balance;
	float patientBalance2 = ((struct patient *)patient2) -> balance;
	
    // Compares the two balances and returns the result.
	if (patientBalance1 < patientBalance2) {
		return -1;
	} else if (patientBalance1 == patientBalance2) {
		return 0;
	} else {
		return 1;
	}
	
}


// http://www.cplusplus.com/reference/cstring/strncmp/
// Compares two patients by name.
// Returns -1 if the name of the first patient is less than the second patient's name.
// Returns 0 if the ages are equal.
// Returns 1 otherwise.
int comparePatientsByName(const void *patient1, const void *patient2){
	// Assigns the address of the name field of the patient struct to a void pointer.
    void *patientName1 = &((struct patient *)patient1) -> name;
	void *patientName2 = &((struct patient *)patient2) -> name;
	
    // Compares the two names and returns the result.
	int relation = strncmp((char*)patientName1, (char*)patientName2, 20);
	if (relation < 0) {
		return -1;
	} else if (comparePatientsByAge(patient1, patient2) == 0) {
		return 0;
	} else {
		return 1;
	}
	
}



//  The main program
int main()
{
    
    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 200},
        {32, "Tyra Banks    ", 750},
        {62, "Mario O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    

    // Prompts the user to enter data for a new patient
    cout << "Enter your last name: ";
    cin >> patient_list[5].name;
    cout << endl;
    cout << "Enter your age: ";
    cin >> patient_list[5].age;
    cout << endl;
    cout << "Enter your account balance: ";
    cin >> patient_list[5].balance;
    cout << endl;
    cout << "Patient List: " << endl;

    // Displays the contents of the array
    displayPatientList(patient_list);
    cout << endl;

    
    // Sorts the array by age and display the results
    cout << "Sorting..." << endl;
    qsort(patient_list, 6, sizeof(patient), comparePatientsByAge);

    cout << "Patient List - Sorted by Age: " << endl;
    displayPatientList(patient_list);
    cout << endl;
    

    // Sorts the array by balance and display the results
    cout << "Sorting..." << endl;
    cout << "Patient List - Sorted by Balance Due: " << endl;
    qsort(patient_list, 6, sizeof(patient), comparePatientsByBalance);

    displayPatientList(patient_list);
    cout << endl;
    
    
    // Sorts the array by name and display the results
    cout << "Sorting..." << endl;
    qsort(patient_list, 6, sizeof(patient), comparePatientsByName);
    cout << "Patient List - Sorted by Name: " << endl;

    displayPatientList(patient_list);
    cout << endl;
    
    return 0;
}
