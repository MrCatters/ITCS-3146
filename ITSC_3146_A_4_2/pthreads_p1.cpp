/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;

const char* my_messages[4] = {"French: Bonjour!", "Japanese: konnichiwa!",
	"Hindi: Namaste!", "German: Guten Tag!"};   


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

void *printMessage(void *arg)
{
	// Convert to int pointer and then fetch data from the address.
	cout << my_messages[*(int *)arg] << endl;
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
   
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input

   // Create thread(s)
   // TODO: Modify according to assignment requirements
   int my_messages_size = sizeof(my_messages) / sizeof(my_messages[0]);
   for (int i = 0; i < my_messages_size; i++) {
	   rc = pthread_create(&id, NULL, printMessage, &i);
   }
	   

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   
   pthread_exit(0);
}
