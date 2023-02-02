// Zachary Palko

#include <pthread.h>
#include <iostream>

using namespace std;


void *PrintHello(void *arg)
{
   // Casts the void* arg to an int type that can be used.
   int argInt = *((int*) arg);
   cout << "Hello World from thread with arg: " << argInt << "!\n";
   return 0;
}

int main()
{
   // Create needed varables for pthread.
   pthread_t id;
   int rc;
   cout << "In main: creating thread \n";
   
   // Prompt user for input.
   cout << "Please enter an integer: ";
   int t;
   cin >> t;

   // Create new pthread.
   rc = pthread_create(&id, NULL, PrintHello, (void*) &t);

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
      return -1;
   }

   pthread_exit(0);
}
