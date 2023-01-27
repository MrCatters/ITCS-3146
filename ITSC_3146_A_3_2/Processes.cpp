//
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//

// Zachary Palko

/*
 @file Processes.cpp
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @description: <ADD DESCRIPTION>
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */


#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"
#include <unistd.h>


using namespace std;


// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
	return getpid();
}


// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();
   
   // DO NOT CHANGE THIS LINE OF CODE
   process_id = id;
   
   // If process creation fails.
   if(id == -1)
   {
      return "Error creating process";
   }
   // If the child.
   else if (id == 0)
   {
	  cout << "I am a child process!" << endl;
	  return "I am bored of my parent, switching programs now";
   }
   // Waits for the child process to terminate.
   else
   {
	  wait(0);
	  return "My child process just terminated!";
   }
}


// Part 3: Working With External Commands"
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();
   
   // https://linux.die.net/man/3/execvp
   // Checks if the current program is the child.
   if (id == 0)
   {
	   // Executes commands passed by array.
	   execvp("ls", args);
   }
   
}

#endif /* TestProg_cpp */
