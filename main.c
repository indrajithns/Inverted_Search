/*
 * File: main.c
 * Entry point for the Inverted Search application.
 *
 * This file contains the main function for the Inverted Search project.
 * The program builds an inverted index for words in multiple files, allowing
 * users to search, update, display, and save the database.
 *
 * Functionalities:
 * - Validates command-line arguments to ensure files are provided.
 * - Creates a linked list of files for further processing.
 * - Provides a menu-driven interface for the following operations:
 *   1. Create Database: Processes files to build an inverted index.
 *   2. Display Database: Displays the word list and associated details.
 *   3. Update Database: Adds new files to the existing database.
 *   4. Search: Searches for a specific word in the database.
 *   5. Save Database: Saves the current state of the database to a file.
*/

#include "inverted_search.h" 

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = { NULL} ; 

    //validate CLA

    if(argc <= 1)
    {
        printf("Enter The Valid Command Line Argument\n");
        printf("./main.exe  file1.txt   file2.txt.....\n");
        return 0;
    }


    //create file linked list

    //declare head pointer

    Flist *f_head = NULL;


    //validate the files

    file_validation_n_file_list(&f_head, argv);


    if(f_head == NULL)
    {
        printf("No Files Added To File Linked List\n");
        printf("Hence The Process Got Terminated\n");
        return 1;
    }

//prompt the user for choice 
    
    int continue_flag = 1;
    while(continue_flag)
    {
        // Display the menu
        int option; 
        printf("Select Your Choice From Following Options: \n");
        printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Datebase\n");

        // Get the user's choice
        printf("Enter Your Choice: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            //create_database(f_head , head);
            if(create_database(f_head , head) == FAILURE)
            {
                printf("Failed To Create Database\n");
            }
            else
            {
                printf("Database Created Sucessfully\n");
            }
            break;

            case 2:
            //display_database(head);
            if(display_database(head) == FAILURE)
            {
                printf("Database Is Empty\n");
            }
            else
            {
                printf("Database Displayed Sucessfully\n");
            }
            break;
            
            case 3:
            {
                //update_database(head , &f_head);
                if(update_database(head , &f_head) == FAILURE)
                {
                    printf("Failed To Update Database\n");
                }
                else
                {
                    printf("Database Updated Sucsessfully\n");
                }
            }
            break;

            case 4:
            {
            char word[WORD_SIZE];
            printf("Enter The Word To Search: "); 
            scanf("%s"  , word);
            int index = tolower(word[0]) % 97 ;
            //search(head[index] , word);
            if(search(head[index] , word) == FAILURE)
            {
                printf("Word Not Found\n");
            }
            }
            break;

            case 5:
            {
                save_database(head);
                printf("Database Saved Sucessful\n");
            }
            break;

            default:
            printf("Choose Correct Option\n");

        }

        char selection;
        int valid_input = 0;
        while(!valid_input)
        {
            printf("Do You Want to Continue ?\n");
            printf("Enter y/Y to Continue and n/N to Discontinue: ");
            
            scanf(" %c", &selection);
            if(selection == 'y' ||selection == 'Y')
            {
                valid_input = 1;  // Continue the menu
                continue_flag = 1;
            }
            else if(selection == 'n' ||selection == 'N')
            {
                valid_input = 1;  // Exit the menu
                continue_flag = 0;
                printf("Discontinued....!!!!\n");
            }
            else
            {
                printf("Invalid Choice!\n");
            } 

        }
    }
    return 0;
}


































