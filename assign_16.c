/*

NAME                : Arjun Vasavan

DESCRIPTION         :

Pre-requisites:

• Knowledge about system calls, How to read and understand ‘man pages’. 
• Good knowledge about signals and signal handling.
 • Working of sigaction system call and signal masking. 
Objective: 

 To understand importance of signal masking. 
Requirements: 

1. Write a signal handler function for any signal, say SIGINT .
2. While its running inside handler (use loop) block other signals(atleast 3) being received . 
3. Use sa_mask from struct sigaction to set signals to be blocked (Refer man ). 
4. To create a signal set use variable of sigset_t. 
5. To add or remove signals from set use sigaddset, sigdelset functions (refer man). 
6. Process will receive blocked signals once its out from handler. 

Sample execution: 

 1. ./block_signal
      Process 2345 waiting for signal.. press ctrl + c from terminal. 
      SIGINT received  
Inside handler 
Inside handler 
. .
.....

2. Now open another terminal and send signal to process using kill command. 
Bash$ kill SIGUSR1 2345 
Bash$ kill SIGTERM 2345 
Bash$ kill SIGABRT 2345 
 
3. After exiting from handler will respond to blocked signal.

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig)
{
    printf("\nSIGINT received\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("Inside handler (%d)\n", i);
        sleep(2);
    }

    printf("Exiting SIGINT handler\n");
}

int main()
{
    struct sigaction act;

    printf("Process %d waiting for signal.. press Ctrl+C\n", getpid());

    act.sa_handler = sigint_handler;
    sigemptyset(&act.sa_mask);

    sigaddset(&act.sa_mask, SIGUSR1);
    sigaddset(&act.sa_mask, SIGTERM);
    sigaddset(&act.sa_mask, SIGABRT);

    act.sa_flags = 0;

    if (sigaction(SIGINT, &act, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    while (1)
        pause();

    return 0;
}
