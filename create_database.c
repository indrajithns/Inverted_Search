/*
Name        :Indrajith
Date        :02-10-24
Description :Create Database Function
 */

#include "inverted_search.h"

char *fname;

int create_database(Flist *f_head, Wlist *head[])
{
    //travers through the file linked list

    while(f_head)
    {
        read_datafile(f_head , head , f_head->file_name);
        f_head = f_head->link;
    }
return SUCCESS;
}

//read content of file 
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag = 1;
    fname = filename; 
    //open the file in read mode

    FILE *fptr = fopen(filename ,"r");

    //declare an arra to store word

    char word[WORD_SIZE];

    while(fscanf(fptr , "%s", word) != EOF)
    {
        // index

        int index = tolower(word[0]) % 97;

        //other than alphabet 
        if(!(index >= 0 && index <= 25))
            index = 26;

        if(head[index] !=  NULL)
        {
            Wlist *temp = head[index];

            //compare the new word with each node words

            while(temp)
            {
            if(!strcmp(temp->word , word))
            {
                update_word_count(&temp , filename);
                flag = 0;
                break;
            }
            temp = temp->link;
            }
        }

        if(flag == 1)
        {
            // if words are not repeating    
            insert_at_last(&head[index] , word);
        }
    }
}

int update_word_count(Wlist ** head, char * file_name)
{
    // Check if the head is NULL
    if (*head == NULL) 
        return FAILURE;

    Wlist *current_word_node = *head;
    Ltable *current_table_node = current_word_node->Tlink;

    // Traverse the linked list of Ltable
    while (current_table_node)
    {
        // Check if the filenames are the same
        if (strcmp(current_table_node->file_name, file_name) == 0)
        {
            // If filenames are the same, increment word_count
            current_table_node->word_count++;
            return SUCCESS; // Update successful
        }
        current_table_node = current_table_node->table_link;
    }

    // If no matching file was found, we need to create a new Ltable entry
    // Increment the file_count in Wlist node
    current_word_node->file_count++;

    // Create a new Ltable node for the new file
    Ltable *new_table_node = (Ltable *)malloc(sizeof(Ltable));
    if (!new_table_node)
    {
        perror("Failed To Allocate Memory For Ltable Node");
        return FAILURE; // Memory allocation failed
    }

    // Initialize the new Ltable node
    strncpy(new_table_node->file_name, file_name, FNAME_SIZE);
    new_table_node->word_count = 1; // Since this word appears for the first time in this file
    new_table_node->table_link = NULL;

    // Insert the new Ltable node at the end of the linked list
    if (current_word_node->Tlink == NULL)
    {
        // If the linked list is empty, make this the first node
        current_word_node->Tlink = new_table_node;
    }
    else
    {
        // Otherwise, traverse to the end of the list
        current_table_node = current_word_node->Tlink;
        while (current_table_node->table_link)
        {
            current_table_node = current_table_node->table_link;
        }
        // Append the new node
        current_table_node->table_link = new_table_node;
    }

    return SUCCESS; // Successfully added new entry
}



















