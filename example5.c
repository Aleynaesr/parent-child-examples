#include <stdio.h>
#include <unistd.h>
#define COUNT 3
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include<sys/wait.h>
#include<sys/mman.h>
#define MAX_PIDS 32
#include <sys/types.h>
#include <errno.h>

volatile pid_t *pids;
int ct = COUNT, child = 0;
int i;
int main(int argc, char *args[]) {
  srand((unsigned)time(NULL));
char *fName=args[1];
char *fName2=args[2];
   char chr1[16];
   char chr2[16];
   char buffer[1024];
strcpy(chr1, args[1]);
strcpy(chr2, ".gz");
strcat(chr1, chr2);
   
   FILE *filePointer = fopen(fName, "w");
   FILE *filePointerR = fopen(fName, "r");

        pid_t child_pid = 1;

 while (ct-- > 0 && child_pid > 0)
          if ((child_pid = fork()) > 0){
            child++; 
wait(NULL);  }
  
if (child_pid != 0) {
   
              printf("[PARENT] Done. \n");
}
         else {
              if(child==0){
              printf("[PARENT] Creating first process...\n");
                   printf("[CHILD1] Writing 40000 random chars to %s ... \n", fName );

       for(i=1; i<=40000; i++){
    char chars = "abcdefghıjklmnopqrstuvwxyz"[random () % 26];
       fprintf(filePointer,"%c",chars);
       }
           fclose(filePointer);
                         sleep(1);}

    if(child==1){
        printf("[PARENT] Creating second process...\n [CHILD2] Executing Zip Command \n");
            execlp("gzip","gzip","-k",args[1],NULL);
}

  if(child==2){
        printf("[PARENT] Creating third process...\n [CHILD3] Executing ls Command \n");
            execl("/bin/ls", "ls","-i", (char *) 0);
      sleep(1);
}}
return 0;
}
