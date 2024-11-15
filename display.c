/*
Name        :Indrajith
Date        :02-10-24
Description :Display Database Function
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