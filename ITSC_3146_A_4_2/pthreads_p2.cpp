/*
 @file: pthreads_skeleton.cpp
 
 @author: Zachary Palko, zpalko@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;


// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
void *routineName(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   cout << "Thread is running..." << endl;
   return 0;
}


// Counts all of the negatives present in the nums array.
void *countNegatives(void *arg)
{
   int total = 0;
   for (int i=0; i < 10; i++){
      // Casts to a pointer of type int.
      // Adds i to increment memory addresses.
      // Finally, dreferences the variable.
      if ((*((int*)arg+i)) < 0)
      {
	     total++;
      }
   }
   // Print out all negative numbers.
   cout << "Total negative numbers: " + to_string(total) + "\n\n";
   return 0;
}


// Finds the averages of all numbers in nums.
void *average(void *arg)
{
   float average=0;
   // Iterates through list and adds to the average.
   for (int i=0; i < 10; i++)
   {
	   average += (*((int*)arg+i));
   }
   average /= 10;
   
   // Print out the average of all of the numbers.
   cout << "Average of all numbers: " + to_string(average) + "\n\n";
   return 0;
}


// Prints out the reverse of all entered numbers.
void *reverse(void *arg)
{
	cout << "Numbers reversed: " << endl;
	for (int i=9; i > -1; i--)
	{
		cout << (*((int*)arg+i)) << endl;
	}
	cout << endl;
	return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
 
   // Array that will store user input.
   int nums[10];
   
   // Prompts user to enter number 10 times.
   cout << "Please enter 10 numbers: " << endl;
   for (int i=0; i < 10; i++){
	   cin >> nums[i];
   }
   cout << endl;
   
   // Create thread(s)
   rc = pthread_create(&id, NULL, countNegatives, &nums);
   rc = pthread_create(&id, NULL, average, &nums);
   rc = pthread_create(&id, NULL, reverse, &nums);


   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   
   pthread_exit(0);
}
