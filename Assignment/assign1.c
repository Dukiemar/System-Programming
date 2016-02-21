//620040546
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char *argv[]){
       if(argc == 3){
	       FILE *fpt, *fpt2;
	       char dic_file[20] = {""}; strcpy(dic_file, argv[1]); //file we are reading from
	       char out_file[20] = {""}; strcpy(out_file, argv[2]); //file we are printing to
	       
	       char dic_word[20] = {""}; //Search for words in file
	       
	       char word_list[200] = {""}; //store all the suggested words (max 10)
	       char *list_pt = word_list; //pointer to list of suggested words
	       char add = -20; //adjust the word list pointer by increments of 20

	       char original_word[20] = {""}; //Take user input
	       char input_word[20] = {""}; //Make copy of user input so we can manipulate it
	       int word_count = 0; //no more than 10 words

	       int len; //size of string entered by user
	       int select; //will be used to determine which word to use
	       int var = 0;

	       printf("Please enter a word: ");
	       scanf("%s", original_word);
	       printf("\n");

	       strcpy(input_word, original_word); //copy user input
	       
	       fpt = fopen(dic_file, "r"); //open the file
	       
	       //check if the word exists in the dictionary
	       while(1){
		        fscanf(fpt, "%s", dic_word);
		        //if it does
		        if(strcmp(dic_word, input_word) == 0){
		                    printf("Found: %s\n", dic_word);
		                    break;
		        }//end if
		        
		        //if it does not
		        else if(feof(fpt)){
		             printf("\nThis word doesn't exists in our thesaurus: %s!!!\n", input_word);
		             break;
		        }//end else
	       }//end while
	       
	       len = strlen(input_word); //set len as the size of user string input
	       printf("\nSuggestions found: \n");
	       
	       //search if there are words matching the user entry
	       while(len > 0 && word_count < 11){
		                fseek(fpt, 1, SEEK_SET); //Go to the top of the file
		                input_word[len--] = 0; //remove the last byte of the user's entry
		                
		                //now check if there is a matching
		                while(1){
		                         fscanf(fpt, "%s", dic_word);
		                         //if there is a matching, display it
		                         if(strcmp(input_word, dic_word) == 0){
		                                               printf("\t\t\t%d. %s\n", ++var, dic_word);
		                                               word_count++; //check when the limit of 10 words has been reached
								
							       add = add + 20; //adjust the word_list pointer
							       strcpy(list_pt+add, dic_word); //store the word into word_list array
		                                               break;
		                         }//end if
		                         
		                         //if we didn't find a matching, stop search
		                         else if(feof(fpt)){
		                              break;
		                         }//end else
		                }//end while
	       }//end while
	       fclose(fpt); //close the file being read from
	
	       if(word_count > 0){
			printf("\nSelect a word from the list to use (# only)\n(To use your original instead, press 0): ");
			scanf("%d", &select);
			
			if(select == 0){
				fpt2 = fopen(out_file, "w");
				fprintf(fpt2, "%s", original_word);
				fclose(fpt2);
				printf("\nSUCCESSFULL CREATED: %s, WITH ENTRY: %s\n", out_file, original_word);			
			}			

			else if(select >= 1 && select <= var){
				select--;
				fpt2 = fopen(out_file, "w");
				fprintf(fpt2, "%s", (list_pt+(select*20)));
				fclose(fpt2);
				printf("\nSUCCESSFULL CREATED: %s, WITH ENTRY: %s\n", out_file, (list_pt+select*20));
			}

			else{
				printf("ERROR: Out of range!\n");
			}
	       }

	      else{
			fpt2 = fopen(out_file, "w");
			fprintf(fpt2, "%s", original_word);
			fclose(fpt2);
			printf("\nHOWEVER, SUCCESSFULL CREATED: %s, WITH ENTRY: %s\n", out_file, original_word);		
			
	      }
	}//end if
	
	else{
		printf("Error: improper argument(s)\n");
		printf("1. We are using the commandline for entry here\n");
		printf("2. Only 2 entry\n");
		printf("3. 1st entry should be where we are reading from\n");
		printf("4. 2nd entry should be where we are writing to\n");
		printf("5. Please add file extensions, eg .txt, .words\n");
	}//end else
}//end main
