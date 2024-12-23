/*
 * File: insert_last.c
 * Implementation of functions to insert nodes into the word list and update the link table.
 *
 * This file contains functions to insert new words into the word linked list (Wlist)
 * and to create and update the associated link table (Ltable) for tracking word occurrences 
 * in specific files.
 *
 * Functions:
 * - `insert_at_last`: Adds a new word to the end of the Wlist and initializes its associated Ltable node.
 * - `update_link_table`: Creates and links a new Ltable node for a word, storing its file name and initial word count.
*/

#include "inverted_search.h" 

extern char *fname;

int insert_at_last(Wlist **head, data_t *data)
{
    //create node

    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
	return FAILURE;

    new->file_count = 1;
    strcpy(new->word,data);
    new->Tlink = NULL;
    new->link = NULL;

    //call  fun() to update Ltable node
    update_link_table(&new);

    //check Wlist is empty or not

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // non empty 
    Wlist *temp = *head;

    //traverse through the list

    while(temp->link)
    {
        temp = temp->link;
    }

    temp->link = new;
    return SUCCESS;
}


int update_link_table(Wlist **head)
{
    //create node
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
	return FAILURE;

    //update fields

    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    (*head)->Tlink = new;
    return SUCCESS;
}


















