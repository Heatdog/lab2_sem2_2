
#ifdef USE_LIST
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include "list.h"
#include <stdio.h>
#include <string.h>


void queue_list_input_p(List* list, int time) {
    printf("\nPlease, enter information about passengers in form:\nid/ta/ts\nwhere id- id of passenger; ta- arrival"
        "time, ts - service time\n");
    queue_list_input(list, time);
}

void queue_list_input(List* list, int time) {
    Item* value = NULL;
    if (list->head == NULL && list->tail == NULL) {
        value = item_input(time);
        list->head = value;
        list->tail = value;
    }
    else if (list->head != NULL && list->tail != NULL) {
        value = item_input(time);
        list->tail->next = value;
        list->tail = value;
        list->tail->next = NULL;
    }
}

Item* item_input(int time) {
    int ta, ts;
    char id[10];
    Item* value = (Item*)malloc(sizeof(Item));
    input_three(id, &ta, &ts, time);
    value->ptr.ta = ta;
    value->ptr.ts = ts;
    strcpy(value->ptr.id, id);
    value->next = NULL;
    return value;
}

Massive queue_list_output_p(Massive mass, int time) {
    printf("\nNow, time is %d\n", time);
    printf("current situation at the airport: \n");
    for (int i = 0; i < mass.number; i++) {
        printf("\nAt the reception desk %d\n", i + 1);
        List* list = mass.list[i];
        queue_list_output(list);
        mass.list[i] = list;
        list = NULL;
    }
    return mass;
}

void queue_list_output(List* list) {
    if (list->head == NULL) {
        printf(" ");
    }
    else if (list->time_process != list->head->ptr.ts) {
         queue_list_print(list);
    }
    else {
        list->time_process = 0;
        Item* ptr = list->head;
        list->head = list->head->next;
        if (list->head == NULL && list->tail != NULL) {
            list->head = list->tail;
        }
        printf("%s/%d/%d\t", ptr->ptr.id, ptr->ptr.ta, ptr->ptr.ts);
        free(ptr);
        queue_list_print(list);
    }
}

void queue_list_print(List* list) {
    Item* ptr = list->head;
    list->time_process++;
    while (1) {
        printf("%s/%d/%d\t", ptr->ptr.id, ptr->ptr.ta, ptr->ptr.ts);
        ptr = ptr->next;
        if (ptr == NULL) {
            break;
        }
    }
}

void del_list(Massive mass) {
    Item* ptr, *ptr_prev;
    for (int i = 0; i < mass.number; i++) {
        ptr = mass.list[i]->head, ptr_prev = NULL;
        while (ptr != NULL) {
            ptr_prev = ptr;
            ptr = ptr->next;
            free(ptr_prev);
        }
        free(mass.list[i]);
    }
    free(mass.list);
}
#endif