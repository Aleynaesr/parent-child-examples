#include <stdio.h>
#include <unistd.h>
#define COUNT 3
#include <time.h>
#include <string.h>
#include<sys/wait.h>
#include <stdlib.h>
#define MAX_PIDS 32
#include <sys/mman.h>
#include <errno.h>

volatile pid_t *pids;
int ct = COUNT, child = 0;
int i,x,y;
int temp;
int main(int argc, char *args[]) {
   srand((unsigned)time(NULL));
char *fName=args[1];
int rng=atoi(args[2]);

    FILE *filePointer = fopen(fName, "w");
    FILE *filePointerR = fopen(fName, "r");      

int a[rng]; 
char buffer[256];

pid_t child_pid = 1;

    while (ct-- > 0 && child_pid > 0)

        if (( child_pid = fork() ) > 0){            
child++;
sleep(1);
}
 if (child_pid != 0) {
        printf("[PARENT] Done.\n"); }
 else {

if(child==0){
printf("[PARENT] Creating first process...\n ");
printf("[CHILD] Creating %s with %d integers... \n", fName, rng );

for(i=0; i<rng; i++){
 int sayi = rand() % 1000; 

fprintf(filePointer,"%d\n", sayi); }
fclose(filePointer);  }
  if(child==1){

printf("[PARENT] Creating second process... \n ");
printf("[CHILD2] Executing Sort Command... \n ");

execl("/usr/bin/sort", "-n", args[1], (char*)NULL); }

 if(child==2){
sleep(1);
printf("[PARENT] Executing third process... \n [CHILD3] ");

     x=0;
      while (fgets(buffer, sizeof(buffer), filePointerR)) {
     a[x]=atoi(buffer);
                x++; }
for (i=0; i < (rng-1); ++i)
 {
    for (y=0;y<rng- 1- i;++y )
 {
    if (a[y] > a[y+1])
           {
 temp = a[y+1];
  a[y+1] = a[y];
       a[y] = temp;
           } }}
       printf("Min: %d  , max: %d\n ", a[0] , a[rng-1]);
          }}
return 0;
}
