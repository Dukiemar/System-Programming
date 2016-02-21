#include<stdio.h>
#include<string.h>
main()
{
    int x,i,n;
    char temp[30];
    char str[30];
    printf("Please input a string:");
    scanf("%s",str);
    n=strlen(str);
 
 for (i=0;i<n-1;i++)
 {
     for (x=i+1;x<n;x++)
     {
        if (str[i]>str[x])
        {
            temp[x]=str[i];
            str[i]=str[x];
            str[x]=temp[x];
        }
     }
 }
}