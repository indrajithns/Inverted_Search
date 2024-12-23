/*
 * File: save_database.c
 * Handles saving the inverted search database to a file.
 *
 * This file contains the implementation for saving the current state of the
 * inverted search database to a user-specified file. The database is saved
 * in a readable format, including words, their occurrences, and associated file details.
 *
 * Functions:
 * - `void save_database(Wlist *head[])`:
 *   - Iterates through the database and calls `write_databasefile` for each non-empty index.
 *   - Opens the user-specified file and ensures all data is saved.
 * - `int write_databasefile(Wlist *head, FILE* databasefile)`:
 *   - Traverses the word list and associated file data, writing them to the file.
 *   - Includes detailed information such as word occurrences and file counts.
*/

#include "inverted_search.h" 

void save_database( Wlist *head[])
{
    //prompt the user for new file 

    char file_name[FNAME_SIZE];
    printf("Enter The File Name: ");
    scanf("%s" , file_name);

    //open file

    FILE *fptr = fopen(file_name , "w" );

    for(int i = 0; i <27; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i] , fptr);
        }
    }
    fclose(fptr);
    printf("Database Saved\n");
}

int write_databasefile(Wlist *head, FILE* databasefile)
{
    if (head == NULL || databasefile == NULL)
    {
        return FAILURE; // Nothing to write
    }

    // Traverse the Wlist linked list
    Wlist *current_word_node = head;
    while (current_word_node != NULL)
    {
        // Write the index, word, and file count
        fprintf(databasefile, "# [index]  word is [ %s ] : file count is [ %d ]", current_word_node->word, current_word_node->file_count);

        // Now, we need to traverse the linked list of Ltable
        Ltable *current_table_node = current_word_node->Tlink;
        while (current_table_node != NULL)
        {
            // Write the file name and the word count for that file
            fprintf(databasefile, " : file_name is [ %s ] : word count is [ %d ]", 
                    current_table_node->file_name, current_table_node->word_count);
            current_table_node = current_table_node->table_link;
        }
        
        // End the line after writing details for the current word node
        fprintf(databasefile, "\n");
        
        // Move to the next word node
        current_word_node = current_word_node->link;
    }
    return SUCCESS;
}




