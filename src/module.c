#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"header.h"


void mod1()
{
	printf("\n ####Module 1 is interested in this event ####\n");
}
void mod2()
{
	printf("\n ####Module 2 is interested in this event ####\n");
}
void mod3()
{
	printf("\n ####Module 3 is interested in this event ####\n");
}
void mod4()
{
	printf("\n ####Module 4 is interested in this event ####\n");
}
void mod5()
{
	printf("\n ####Module 5 is interested in this event ####\n");
}
void mod6()
{
	printf("\n ####Module 6 is interested in this event ####\n");
}
void mod7()
{
	printf("\n ####Module 7 is interested in this event ####\n");
}
void mod8()
{
	printf("\n ####Module 8 is interested in this event ####\n");
}
void mod9()
{
	printf("\n ####Module 9 is interested in this event ####\n");
}
void mod10()
{
	printf("\n ####Module 10 is interested in this event ####\n");
}

void (*reg_ptr[])()={&mod1,&mod2,&mod3,&mod4,&mod5,&mod6,&mod7,&mod8,&mod9,&mod10};


int module_init()
{
	bool result=1;
	int i,choice;
	if(no_of_modules<=10)
	{
		for(i=0;i<no_of_modules;i++)
		{
			event_bitmap_init=0;
			result = get_events(i,reg_ptr[i]);
			if(!result)
			{
				printf("\nDo you want to enter again for module %d.. Press 1 : ",i+1);
				scanf("%d",&choice);
				if(choice==1)
				{
					i--;
				}
				else
				{
					return 0;
				}
			}

		}
	}
	else
	{
		printf("\nModule limit exceeded..!\nEXITING......\nRetry :)");
		return 0;
	}
}
