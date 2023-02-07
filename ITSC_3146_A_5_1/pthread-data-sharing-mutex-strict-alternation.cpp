// Zachary Palko

#include <iostream>
#include <pthread.h>
#include <stdlib.h>

int count;
int turn = 0;   //  Shared variable used to implement strict alternation

void* myFunction(void* arg)
{
	int actual_arg = *((int*) arg);
	int i = 0;
	
	while (i < 10)
	{ 
		// Critical code
		// Creates a busy wait until the next thread is finished.
		while (turn != actual_arg){}
		count++;
		std::cout << "Thread #" << actual_arg << " count = " << count << std::endl;
		i++;
		// Switched the turns between threads.
		turn = abs(actual_arg - 1);

		// Non-critical code.
		//  Random wait - This code is just to ensure that the threads
		//  show data sharing problems
		int max = rand() % 100000;
		for (int x = 0; x < max; x++);
		// End of random wait code
	}
	pthread_exit(NULL);
}


//  HINT: It is not necessary to make any changes in main()
int main()
{
    int rc[2];
    pthread_t ids[2];
    int args[2];
    
    count = 0;
    for(unsigned int i = 0; i < 2; ++i) {
        args[i] = i;
        rc[i] = pthread_create(&ids[i], NULL, myFunction, (void*) &args[i]);
    }
    
    for(unsigned int i = 0; i < 2; ++i) {
        pthread_join(ids[i], NULL);
    }
    
    std::cout << "Final count = " << count << std::endl;
    pthread_exit(NULL);
}
