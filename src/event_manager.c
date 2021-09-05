#include<stdio.h>
#include"header.h"
#include<stdbool.h>
#include<stdlib.h>
struct event_structure
{      

	int module_ID;
	int events_interested;
	void (*mod_ptr)();
	struct event_structure *next;

}*list = NULL,*p1,*p2;

void register_event(int,int,void(*)());


bool get_events(int i,void (*call_fun)())
{       
	int event_per_module,event_id,choice,j;
	printf("\nEnter the no of events for module %d : ",i+1);
	scanf("%d",&event_per_module);
	if(event_per_module <= 32)
	{
		for(j = 0;j < event_per_module;j++)
		{
			printf("\nEnter the event ID : ");
			scanf("%d",&event_id);
			if(event_id != 0 && event_id > 32)
			{
				printf("\nThe event ID you entered is not valid ....!");
				printf("\nDo you wish to re-enter for that event?? If so, Press 1..: ");
				scanf("%d",&choice);
				if(choice == 1)
				{
					j--;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				set_bit(event_bitmap_init,event_id);
			}
		}
		register_event(i+1,event_bitmap_init,call_fun);
	}
	else
	{
		printf("\nThe event ID you entered is not valid ....!");
		return 0;
	}
	return 1;
}

void register_event(int module_id,int event_ids,void (*fun_ptrs)())
{
	p2 = (struct event_structure*)malloc(sizeof(struct event_structure*));
	p2 -> module_ID = module_id;
	p2 -> events_interested = event_ids;
	p2 -> mod_ptr = fun_ptrs;

	if(list == NULL)
	{
		list = p1 = p2;
		return;
	}

	p1 -> next = p2;
	p1 = p2;
	return;

}

void trigger_event(int event_to_show)
{
	struct event_structure *print;
	print = list;
	bool no_interested = 1;
	while(print)
	{ 
		if(get_bit(print->events_interested,event_to_show)){
			print->mod_ptr();
			no_interested = 0; 
		}
		print = print -> next;
	}
	if(no_interested)
	{
		printf("\nNo modules intrested in this event..!\n");
	}
}
