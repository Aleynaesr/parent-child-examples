#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main ()
{
FILE *filePointer;
FILE *filePointer2;
FILE *filePointerR;
FILE *filePointerR1;
    int sayi;
    char letter; 
    char read;
    char reader;
pid_t child_pid, child_pid1;

child_pid = fork ();

if (child_pid != 0) {
printf("[PARENT] Child process ID: %d\n ", (int) child_pid );
      
    filePointer = fopen ("data1.txt" , "w");
	 printf("[CHILD1] Wrote:" );
       for(int i=1;i<=10;i++) {
 	    sayi = rand() % 10 ;             
                 fprintf(filePointer , "%d " , sayi); 
                         printf("%d ", sayi ); }
                            printf("to file.\n" );
                                sleep(1);
                        
    child_pid1 = fork ();
    if (child_pid1 != 0)
    {
      printf("[PARENT] Child process ID: %d\n ", (int) child_pid1 );
    
   filePointer2 = fopen ("data2.txt" , "w");
    printf("[CHILD2] Wrote: " );
     for (int j=1;j<=10;j++) {
          char alph[] = "abcdefghijklmnopqrstuvwxyz";
          letter= alph[(rand() % 26)]; 
          fprintf(filePointer2 , "%c ", letter); 
           printf("%c ", letter );     }
              printf("to file \n [PARENT]"); 
      } 
   filePointerR = fopen("data1.txt", "r");
   filePointerR1 = fopen("data2.txt", "r");

 while ((fscanf(filePointerR, "%c", &read)) == 1 && (fscanf(filePointerR1, "%c", &reader) == 1 )) {
        printf("%c ", read );
        printf("%c ", reader );}
  }  
  fclose(filePointer);
  fclose(filePointer2);
   fclose(filePointerR);
  fclose(filePointerR1);
  return 0;
}
