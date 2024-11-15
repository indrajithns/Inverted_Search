/*
Name        :Indrajith
Date        :02-10-24
Description :Update Database Function
 */

#include "inverted_search.h"

int update_database( Wlist *head[], Flist **f_head)
{
    //promopt the user for new file 

    char file_name[FNAME_SIZE];

    printf("Enter The File Name: ");
    scanf("%s" , file_name);


    //validation 

    
    int i = 1 , empty;
    
	empty = isFileEmpty(file_name);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s Is Not Available\n" , file_name);
	    printf("Hence We Are Not Adding That File Into File Linked List\n");
	    i++;
	    return FAILURE;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File : %s Is Not Having Contents In It\n" , file_name);
	    printf("Hence We Are Not Adding That File Into File Linked List\n");
	    i++;
	    return FAILURE;
	}
	else
	{
	    int ret = to_create_list_of_files(f_head , file_name);

	    if(ret == SUCCESS)
	    {
		    printf("Successfull : Inserting The File %s Into File Linked List\n" , file_name);
	    }
	    else if(ret == REPEATATION)
	    {
		    printf("This File Is Not Added To File Linked List As It Is Repeated\n");
	    }
	    else
	    {
		    printf("Failure\n");
	    }

	    i++;
	    //continue;        

	}


    //fun() is used to check for file availability and check for file contents

    int isFileEmpty(char *filename)
    {
        FILE *fptr = fopen(filename , "r" );
        if(fptr == NULL)
        {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
        }

        //Check for content

        fseek(fptr , 0 , SEEK_END);

        if(ftell(fptr) == 0)
        {
        return FILE_EMPTY;
        }

    }

    int to_create_list_of_files(Flist **f_head, char *name)
    {
        // Check if the linked list is empty
        if (*f_head == NULL)
        {
            // Create a new node
            *f_head = (Flist *)malloc(sizeof(Flist));
            if (*f_head == NULL)
            {
                perror("Failed To Allocate Memory For Flist Node");
                return FAILURE; // Memory allocation failed
            }

            // Initialize the new node
            strncpy((*f_head)->file_name, name, FNAME_SIZE);
            (*f_head)->link = NULL;
            return SUCCESS; // Successfully added the first file
        }

        // Traverse the linked list to check for duplicates
        Flist *current = *f_head;
        while (current != NULL)
        {
            if (strcmp(current->file_name, name) == 0)
            {
                return REPEATATION; // Duplicate found
            }
            current = current->link;
        }

        // No duplicates found, insert the new file at the end of the list
        Flist *new_node = (Flist *)malloc(sizeof(Flist));
        if (new_node == NULL)
        {
            perror("Failed To Allocate Memory For Flist Node");
            return FAILURE; // Memory allocation failed
        }

        // Initialize the new node
        strncpy(new_node->file_name, name, FNAME_SIZE);
        new_node->link = NULL;

        // Find the end of the list and insert the new node
        current = *f_head;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = new_node; // Append the new node

        return SUCCESS; // Successfully added the file
    }

        while(*f_head)
        {
        if(!strcmp((*f_head)->file_name , file_name))
        {
            create_database(*f_head,head);
        }

        *f_head = (*f_head)->link;
        }
    return SUCCESS; 
}