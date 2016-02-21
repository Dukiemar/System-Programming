
             #include <stdio.h>
             #include <unistd.h>
             #include <string.h>
             main()
             {
             char arr[80],*args[3];
             int i;
             printf("testing the exec() function...\n");
             strcpy(arr,"ls");
             args[0]="ls";
             args[1]="-l";
             args[2]=NULL;
             i=execvp(arr,args);
             printf("Testing for the execvp() function failed");
             }