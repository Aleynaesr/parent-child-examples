#include <stdio.h>
#include <unistd.h>
#define COUNT 3
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_PIDS 32
#include<sys/mman.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <errno.h>
  volatile pid_t *pids;
int ct = COUNT;
int child= 0;
int main(int argc, char *args[]) {
   srand((unsigned)time(NULL));
 char *fName=args[1];
   
int rng=atoi(args[3]);
   
 char *fName2=args[2];
   
int rng2=atoi(args[4]);
    FILE *filePointer = fopen(fName, "w");
       FILE *filePointer2 = fopen(fName2, "w");
    pid_t child_pid = 1;

 while (ct-- > 0 && child_pid > 0)
        if ((child_pid = fork()) > 0)
            child++;
wait(NULL);
    if (child_pid != 0) {
sleep(3);
        printf("[PARENT] Done.\n");
}
 else {
  if(child==0){
printf("[PARENT] Creating first process...\n");
printf("[CHILD1] Writing %d random integers to %s...\n", rng , fName );

 for(int j=0; j<rng; j++){
   int sayi =rand() % 800 + 100;
	 fprintf(filePointer,"%d\n", sayi);}
sleep(1); 
fclose(filePointer);}
  if(child==1){

printf("[PARENT] Creating second process...\n");
printf("[CHILD2] Writing %d random integers to %s...\n", rng2 , fName2 );

sleep(2);
   for(int i=0; i<rng2; i++){
    int sayi2 = rand() % 800 + 200;
	 fprintf(filePointer2,"%d\n",sayi2);
        }
 fclose(filePointer2);     }

 if(child==2)    {
sleep(3);
printf("[PARENT] Creating third process...\n [CHILD3] Sorting both files: \n");
  execl("/usr/bin/sort","-n", args[2], args[1], (char*)NULL);
             }
    return 0;
}
}
