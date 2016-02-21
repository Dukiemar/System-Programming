#include <stdio.h>

main()
{
    int x;
    int arr[8];
    int z=1;
    int num;
       printf("Enter the decimal number to convert:\n");
       scanf("%d",&num);
       while (num!=0)
       {
           arr[z++]=num%2;
           num=num/2;
          // z++;
       }
    for (x=z-1;x>0;x--)
    {
        printf("%d",arr[x]);
    }
    
}

