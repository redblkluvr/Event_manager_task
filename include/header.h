#include<stdbool.h>

bool get_events(int,void(*)());

void trigger_event(int);


#define set_bit(num,bit) (num)=(num)|(1<<(bit-1))
#define get_bit(num,bit) (num)&(1<<(bit-1))

int module_init();

void mod1();
void mod2();
void mod3();
void mod4();
void mod5();
void mod6();
void mod7();
void mod8();
void mod9();
void mod10();

int no_of_modules;
int event_bitmap_init;

