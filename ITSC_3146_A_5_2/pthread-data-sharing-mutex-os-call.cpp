// Zachary Palko

#include <iostream>
#include <pthread.h>
#include <stdlib.h>


#define TOTAL_THREADS 4


int count;
// Mutex used to lock threads.
pthread_mutex_t the_mutex = PTHREAD_MUTEX_INITIALIZER;

void* myFunction(void* arg)
{
	int actual_arg = *((int*) arg);
    
	for(unsigned int i = 0; i < 10; ++i) {
        
        // Locks other threads from access using mutex function.
        pthread_mutex_lock(&the_mutex);
        count++;
        std::cout << "Thread #" << actual_arg << " count = " << count << std::endl;
        // Unlocks access allowing other threads that are waiting.
        pthread_mutex_unlock(&the_mutex);

         //  Random wait - This code is just to ensure that the threads
         //  show data sharing problems
         int max = rand() % 100000;
      
         for (int x = 0; x < max; x++);
      
         // End of random wait code
	}
    
	pthread_exit(NULL);
}


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
