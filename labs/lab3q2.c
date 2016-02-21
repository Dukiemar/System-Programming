#include <stdio.h>

main()
{
    FILE *fpt;
    struct inventory 
    {
        char name[30];
        int count;
        float price;
    }   log[75];
    
    fpt=fopen("variables.txt","w");
    fprintf(fpt,"%c,%d,%f",inventory.name,inventory.count,inventory.price);
    fclose(fpt);
}