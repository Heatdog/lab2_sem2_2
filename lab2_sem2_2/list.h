#include "input.h"

#ifdef USE_LIST

void queue_list_input_p(List*, int);
void queue_list_input(List*, int);
Massive queue_list_output_p(Massive, int);
void queue_list_output(List*);
void queue_list_print(List*);
void del_list(Massive mass);
Item* item_input(int);

#endif