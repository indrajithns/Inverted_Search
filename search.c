/*
 * File: search.c
 * Implements the search functionality for the inverted search database.
 *
 * This file contains the implementation of the search function used to find a specific word
 * within the inverted search database. The function checks if the word exists in the database,
 * and if so, displays the details of its occurrences across various files.
 *
 * Functions:
 * - `int search(Wlist *head, char *word)`:
 *   - Searches for a word in the linked list of `Wlist` nodes.
 *   - If the word is found, it prints the files in which the word appears and how many times.
 *   - If the word is not found in any list node, it prints a message stating that the word was not found.
*/

#include "inverted_search.h" 
int search( Wlist *head, char *word)
{
    //check empty or not

    if(head == NULL)
    {
		printf("List Is Empty , Search Not Possible\n");
		return 0;
    }

    //traverse 

    while(head)
    {
	//compare new word with each node word

	if(!strcmp(head->word , word))
	{
	    printf("Word %s Is Present In %d File/s \n" , word , head->file_count);

	    Ltable *Thead = head->Tlink;

	    while(Thead)
	    {
			printf("In File : %s    %d Time/s " , Thead->file_name , Thead->word_count);

			Thead = Thead->table_link;
	    }
	    printf("\n");
	    return 0;
	}
	head = head->link;
    }
    printf("Search Word Not Present\n");
}