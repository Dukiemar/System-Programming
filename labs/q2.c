//#include <stdlib.h>
#include<stdio.h>
#include<string.h>
main ()
{
    char string[30];
    char temp[30];
    int n, i, j;

    printf("Please input a string: ");
    scanf("%s",&string);
    
    n = strlen(string);

    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            int  s = tolower(string[i]) - tolower(string[j]);
            if ( s == 0 )
            { 
                s = string[i] - string[j];
            }

            if (s > 0)
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    printf("\n%s", string);
    printf("\n");
}