#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main ()
{
FILE *filePointer;
    char ch;
    int countAlpha = 0;
    int countNum = 0;
    filePointer = fopen("data.txt", "r");

    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            if (isalpha(ch)) {
                countAlpha++;
            }
            else if (isdigit(ch)) {
                countNum++;
            }
        }  }

pid_t child_pid, child_pid1;

child_pid = fork ();
if (child_pid != 0)
{
       printf(" [PARENT] Child process ID: %d\n  [CHILD1] Number of letters: %d\n ", (int) child_pid , countAlpha);
    child_pid1 = fork ();
    if (child_pid1 != 0)
    {
        printf(" [PARENT] Child process ID: %d\n  [CHILD2] Number of numbers:  %d\n", (int) child_pid1 , countNum);
    }
}
 fclose(filePointer);
return 0;
}
