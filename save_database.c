/*
Name        :Indrajith
Date        :02-10-24
Description :Save Database Function
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




