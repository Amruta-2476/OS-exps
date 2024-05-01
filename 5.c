// touch demo.c 
// touch exp5.c
// ls ==> exp5.c  demo.c  
// nano demo.c
// write this :
     #include <stdio.h>
     #include <sys/types.h>
    //  #include <unistd.h>
     int main() {
       fork();
       printf("Hello world!\n");
       return 0;
     }

// nano exp5.c
// write this :
    #include <stdio.h>
    #include <sys/types.h>
    // # include <unistd.h>

    int main()
    {
        int pid_tpid, mypid, myppid;
        int pid = getpid();
        printf("Before fork: Process id is %d\n", pid);
        pid = fork();
        if (pid < 0)
        {
            printf("fork() failure\n");
            return 1;
        }
        // Child Process
        if (pid == 0)
        {
            printf("This is Child Process\n");
            mypid = getpid();
            myppid = getppid();
            printf("Process id is %d and PPID is %d\n", mypid, myppid);
        }
        else
        {
            // Parent Process
            sleep(2);
            printf("This is Parent Process\n");
            mypid = getpid();
            myppid = getppid();
            printf("Process id is %d and PPID is %d\n", mypid, myppid);
            printf("Newly created process id or child pid is %d\n", pid);
        }
        return 0;
    }

// gcc demo.c -o demo
// ./demo
        // Hello world!
        // Hello world!

// gcc exp5.c -o exp5
// $ ./exp5
        // Before fork: Process id is 9871
        // This is child process
        // Process id is 9872 and PPID is 9871
        // This is parent process 
        // Process id is 9871 and PPID is 4153
        // Newly created process id or child pid is 9872

