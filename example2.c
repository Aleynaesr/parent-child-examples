#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
int main ()
{
FILE *filePointer;
    int countEven = 0;
    int sayi;  

pid_t child_pid, child_pid1;

child_pid = fork ();

if (child_pid != 0) {
      filePointer = fopen ("randomfile.txt" , "w");
	
       for(int i=1;i<=1000000;i++) {
 	    sayi = rand() ;
                fprintf(filePointer , "%d\n" , sayi);

            if (sayi %2 == 0 ) {
                countEven++;
       }
}

printf("[PARENT] Child process ID: %d\n[CHILD1] Wrote 1000000 integers to randomfile.txt ,terminating\n", (int) child_pid );

wait(NULL);

    child_pid1 = fork ();

    if (child_pid1 != 0)
    {

 printf("[PARENT] Child process ID: %d [CHILD2] Even numbers: %d Odd numbers: %d , terminating.\n[PARENT] Terminating.\n", (int) child_pid1 , countEven , 1000000-countEven);
    }
}

 fclose(filePointer);

return 0;
}


