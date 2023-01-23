//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

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

void displayPatientList(struct patient patients[]){
	for(int i = 0; i < 6; i++){
		cout << patients[i].age << ", ";
		cout << patients[i].name << ", ";
		cout << patients[i].balance << endl;
	}
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
// https://stackoverflow.com/questions/37881240/what-is-const-void
// https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs
// `const void`
	// Const stands for constant. 
	// void means the pointer can hold data of any type.
int comparePatientsByAge(const void *patient1, const void *patient2){
	
	int patientAge1 = ((struct patient *)patient1) -> age;
	int patientAge2 = ((struct patient *)patient2) -> age;
		
	if (patientAge1 < patientAge2) {
		return -1;
	} else if (patientAge1 == patientAge2) {
		return 0;
	} else {
		return 1;
	}
	
}



//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)


//  The main program
int main()
{
    
    //  Storing some test data
    struct patient patient_list[5] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 200},
        {32, "Tyra Banks    ", 750},
        {62, "Mario O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    
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
    displayPatientList(patient_list);
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    qsort(patient_list, 6, sizeof(patient), comparePatientsByAge);
    cout << "Patient List - Sorted by Age: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE
    displayPatientList(patient_list);
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    
    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    displayPatientList(patient_list);
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    
    cout << "Patient List - Sorted by Name: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    displayPatientList(patient_list);
    cout << endl;
    
    return 0;
}
