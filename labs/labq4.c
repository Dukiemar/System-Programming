#include <stdio.h>
#include <unistd.h>
main()
{
   int i,j;
   fork();
   {
     for (i=0; i<50; i++)
     printf("Hello\n");
   }
    wait();
    printf("Well done my child");
     
}