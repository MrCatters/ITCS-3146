// Zachary Palko

#include <iostream>
#include <pthread.h>
#include <stdlib.h>

#define TOTAL_THREADS 2

int count;
int turn;                  // Shared variable, indicates
                           // whose turn it is to execute

bool interested[TOTAL_THREADS];  // Shared variable, indicates
                                 // processes interested in executing

// The thread_id will be either 0 or 1
void enter_region(int thread_id)
{
   int other;                       // ID of the other thread
   other = thread_id - 1;           // The oposite of thread_id
   // Sets the thread's interest state.
   interested[thread_id] = true;
   turn = other;
   // Busy wait.
   while (turn == other && interested[other] == true);
}

// Allows other threads to have access by setting interest pos to false.
void leave_region(int thread_id)
{
   interested[thread_id] = false;
}


void* myFunction(void* arg)
{
	int thread_id = *((int*) arg);
    
	for(unsigned int i = 0; i < 10; ++i) {
	  // Start of critical region and region lock.
	  enter_region(thread_id);
      count++;
      std::cout << "Thread #" << thread_id << " count = " << count << std::endl;
      // End of critical region and region unlock.
	  leave_region(thread_id);
	  
      //  Random wait - This code is just to ensure that the threads
      //  show data sharing problems
      int max = rand() % 1000000;
      
      for (int x = 0; x < max; x++);
      
      // End of random wait code
	}
    
	pthread_exit(NULL);
}


//  HINT: It is not necessary to make any changes in main()
int main()
{
    int rc[TOTAL_THREADS];
    pthread_t ids[TOTAL_THREADS];
    int args[TOTAL_THREADS];
    
    count = 0;
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        args[i] = i;
        rc[i] = pthread_create(&ids[i], NULL, myFunction, (void*) &args[i]);
    }
    
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        pthread_join(ids[i], NULL);
    }
    
    std::cout << "Final count = " << count << std::endl;
    pthread_exit(NULL);
}
