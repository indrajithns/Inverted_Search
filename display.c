/*
 * File: display.c
 * Implementation of functions to display the inverted index database.
 *
 * This file contains functions to traverse and print the contents of the inverted index.
 * The index is displayed with details such as word, the number of files containing the word, 
 * and the frequency of the word in each file.
 *
 * Functions:
 * - `display_database`: Iterates through the index and displays its contents in a formatted structure.
 * - `print_word_count`: Prints the word and its file-related details including frequency and file names.
*/

#include "inverted_search.h" 
int display_database( Wlist *head[] )
{

    printf("[Index]	[Word]	File_count file/s	File: File_name	word_count\n");

    for(int i = 0; i < 27; i++)
    {
		if(head[i] != NULL)
		{
			print_word_count(head[i]);
		}
    }
	return SUCCESS;
}

int print_word_count(Wlist *head)
{
    //traverse through Wlist till last node

    while(head != NULL)
    {
		printf("[%d]   [%s]   %d file/s " , tolower(head->word[0]) % 97 , head->word , head->file_count);
		Ltable *Thead = head->Tlink;

		//traverse through Ltable list

		while(Thead)
		{
			printf("File : %s    %d" , Thead->file_name , Thead->word_count);
			Thead = Thead->table_link;
		}
		printf("\n");

		head = head->link;
    }
}