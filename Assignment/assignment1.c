#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int true=1;//sets value to the boolean type
int false=0;//sets value to the boolean type
char *dict[45428];//declares aa array equal to the size of the linux.words file
char options[10];//declares an array to hold up to ten suggestions
char *output[255];//declares an array to hold the output data
char userInput[255]={""};
char word[10];
 FILE *fpt;//creates a pointer to the dictionary  
 FILE *outfpt;//create a pointer to the output file
main(int argc,char *argv[])
{
    if (validateArgument())//this function call checks to ensure that ann the commandline arguments are present
  {
    int num;
    int x;
    int i=0;
    int a;
   
    //FILE *outfpt;//create a pointer to the output file

    dict[0]=argv[1];
    output[0]=argv[2];
      //copies the file the will be created at output to the outfile array
  
    printf("Input text here to write to file:\n");
    scanf("%s\n",userInput);//reads in the inputted text from the user
    x=strlen(userInput);//gets the length of the user input
    strcpy(options,userInput);
    dict[0]=word;
    
    printf("%s\n",dict[0]);
    
    fpt=fopen(argv[1],"r");//opens linux.words for reading
    
    while(true)//create a loop to allow the scanning of each word
    {
      fscanf(fpt,"%s",word);//reads input from the streanm
      if(strcmp(userInput,word)==0)//compares the user input the the words in the dictionary
        {
          break;//terminates the loop
        }
      if(feof(fpt))//checks for the end of the file
        {
          printf("word not found");
          break;
        }
    }
    do{
        fseek(fpt,0,SEEK_SET);//sets the cursor to the begining of the file to be read in
        userInput[x--]=0;//decrement the ininputword size to create a sub string
      while(true)
      {
    
          fscanf(fpt,"%s",word);
          if(strcmp(userInput,word)==0)
        {
          printf("misspelled word,please see suggestions");
          strcpy(options,userInput);// add the mistspelt word to the list of suggestions
          strcpy(options,word);//add the other suggestion to the list of suggestion
          break;
        }
       if(feof(fpt))//checks for the end of the file
        {
          printf("No suitable suggestion found");//end of file reached and no suggestion found
          break;
        }
      fclose(fpt);//stop reading the dictionary
      }
      } while(x>0 && sizeof(options)<=10);//conditions for the while loop


    if(sizeof(options)!=1)//checks if a word has been suggested
    {
        for (i=0;i<sizeof(options);i++)//increments through the array of options
      {
        printf("%d\n",options[i]);// prints out the list suggestion to the screen
      }
        printf("\nSelect a number(position of the word,- start counting at 0-) to choose a replacement for the mis-spelt of keep the word if u wish");
        scanf("%d",&num);//accepts a corrsponding number for a suggestion
      if(num==0)
      {
        outfpt=fopen(argv[2],"w");//writes to output fill
        fprintf(outfpt,"%s",userInput);
        fclose(outfpt);
      }
  
      if(num>0)
      {
        outfpt=fopen(argv[2],"w");
        fprintf(outfpt,"%s",options[num]+userInput);//writes to output file
      }
            
    } 
  }
  else
    printf("An argument is missing from the execution");
  }


validateArgument(int argc)//function that checks for the command line arguments
{
  if (argc < 3) 
    return false;
  else return true;
    
}



