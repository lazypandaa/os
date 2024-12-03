#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
 
int main() { 
    pid_t child_pid; 
    int status; 
 
    child_pid = fork(); 
 
    if (child_pid < 0) { 
        perror("Fork failed"); 
        return 1; 
    } 
 
    if (child_pid == 0) { 
        printf("Child process\nPID is %d\n", getpid()); 
        execl("/bin/ls", "ls", "-l", (char *)NULL); 
        perror("Exec failed"); 
        return 1; 
    } else { 
        printf("Parent process: My PID is %d, Child PID is %d\n", getpid(), child_pid); 
        wait(&status); 
        printf("Parent process: Child process exited with status %d\n", status); 
    }   
    return 0;
}

