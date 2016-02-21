#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dict[45428];
char options[10];
char outfile[255];

main()
{
    //if validate argument()==true;
    int i=0;
    FILE *fpt;
    FILE *fp2;
    fpt=fopen("linux.words","r");
    
    //fp2=fopen(argv[2],"w")
    //fscanf(fp,"%s",dict);
   
    
    int x;
    
    
    for (x=0;x<sizeof(dict);x++)
    {
        printf("%d\n",dict[x]);
    }
}

validateargument()
{
  if argc < 2 return error one file missing need dictionary and file to compare
    else return true
    
}
    
//spellcheck()
//{
  //  FILE *fpt
    //fpt=fopen("argv[2]","r");
    
    //read each word call function to check if it ==anything in dictionary 
    //if u have it write it next file
//}
//create a new function to do dictionary search and call it each time u check and reduce string
//{
  //  writeTonew()
    
//}