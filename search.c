/*
Name        :Indrajith
Date        :02-10-24
Description :Search Function
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