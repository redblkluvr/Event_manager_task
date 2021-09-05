#include<stdio.h>
#include"header.h"
void main()
{	int event_to_show,choice;
	printf("\nEnter the no of modules: ");
	scanf("%d",&no_of_modules);
	module_init();
	do
	{
		printf("\nEnter the event to show : ");
		scanf("%d",&event_to_show);
		trigger_event(event_to_show);
		printf("\nDo you want to continue press 1 : ");
		scanf("%d",&choice);
	}while(choice == 1);
}
