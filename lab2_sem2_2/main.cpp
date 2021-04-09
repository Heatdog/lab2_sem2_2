//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>


#ifdef USE_VECTOR
#include "vector.h"
#else
#include "list.h"
#endif
#include <stdio.h>
#include <string.h>




int main() {
    int number, time = 0, choose;
    printf("Please, enter number of check-in counters:\n");
    input_int(&number);
    Massive mass = { 0, NULL };
#ifdef USE_VECTOR
    printf("Vector");
    mass.vect = (Vector*) calloc(number, sizeof(Vector));
#else
    mass.list = (List**)calloc(number, sizeof(List));
#endif
    mass.number = number;
    for (int i = 0; i < number; i++) {
#ifdef USE_VECTOR
        mass.vect[i].tail = 0;
        mass.vect[i].head = 0;
        mass.vect[i].value = NULL;
        mass.vect[i].time_process = 0;
        mass.vect[i].value = (queue*) calloc(4, sizeof(queue));
#else
        mass.list[i] = (List*)malloc(sizeof(List));
        mass.list[i]->time_process = 0;
        mass.list[i]->head = NULL;
        mass.list[i]->tail = NULL;
#endif
    }
    while (time < 20) {//можно больше ставить
        printf("\nDo you want to close this program? Yes - 0/ No - 1\n");
        input_int(&choose);
        if (choose == 0) {
            break;
        }
            int k = rand() % number;
#ifdef USE_VECTOR
            Vector vect = mass.vect[k];
            vect = queue_vector_input_p(vect, time);
            mass.vect[k] = vect;
            mass = queue_vector_output_p(mass, time);
#else
            List* list = mass.list[k];
            queue_list_input_p(list, time);
            mass.list[k] = list;
            mass = queue_list_output_p(mass, time);
#endif
            time++;
        }
#ifdef USE_VECTOR
        del_vect(mass);
#else
        del_list(mass);
#endif
        //_CrtDumpMemoryLeaks();
        return 0;
    
}

