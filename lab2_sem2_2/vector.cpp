#ifdef USE_VECTOR
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include "vector.h"
#include <stdio.h>
#include <string.h>


Vector queue_vector_input_p(Vector vect, int time) {
    printf("\nPlease, enter information about passengers in form:\nid/ta/ts\nwhere id- id of passenger; ta- arrival"
        "time, ts - service time\n");
    vect = queue_vector_input(vect, time);
    return vect;
}

Vector queue_vector_input(Vector vect, int time) {
    int ta, ts;
    char id[10];
    queue value;
    if ((vect.tail <= VECT_SIZE && vect.tail != vect.head) || (vect.tail <= VECT_SIZE && vect.tail == vect.head && vect.time_process - 1 == vect.value[vect.head].ts) || (vect.tail <= VECT_SIZE && vect.tail == vect.head && vect.value[vect.tail].ts == 0)) {
        input_three(id, &ta, &ts, time);
        strcpy(value.id, id);
        value.ts = ts;
        value.ta = ta;
        vect.value[vect.tail] = value;
        vect.tail++;
    }
    else if (vect.tail > VECT_SIZE && vect.head != 0) {
        input_three(id, &ta, &ts, time);
        strcpy(value.id, id);
        value.ts = ts;
        value.ta = ta;
        vect.tail = 0;
        vect.value[vect.tail] = value;
        vect.tail++;
    }
    else if (vect.tail > VECT_SIZE && vect.head == 0) {
        printf("the queue is full!\n");
    }
    else if (vect.tail == vect.head) {
        printf("the queue is full!\n");
    }
    return vect;
}

Massive queue_vector_output_p(Massive mass, int time) {
    printf("\nNow, time is %d\n", time);
    printf("current situation at the airport: \n");
    for (int i = 0; i < mass.number; i++) {
        printf("\nAt the reception desk %d\n", i + 1);
        Vector vect = mass.vect[i];
        vect = queue_vector_output(vect, time);
        mass.vect[i] = vect;
    }
    return mass;
}

Vector queue_print_output(Vector vect, int i, int time) {
    int head = vect.head;
    queue value = vect.value[i];
    if (i == head && value.ta <= time) {
        printf("%s/%d/%d\t", value.id, value.ta, value.ts);
        if (vect.time_process == value.ts) {
            vect.head++;
            if (vect.head > VECT_SIZE && vect.tail != 0) {
                vect.head = 0;
            }
            strcpy(vect.value[i].id, "0");
            vect.value[i].ta = 0;
            vect.value[i].ts = 0;
            vect.time_process = 0;
        }
        else {
            vect.time_process++;
        }
    }
    else {
        if (value.ts != 0) {
            printf("%s/%d/%d\t", value.id, value.ta, value.ts);
        }
    }
    return vect;
}

Vector queue_vector_output(Vector vect, int time) {
    if (vect.head < vect.tail) {
        for (int i = vect.head; i < vect.tail; i++) {
            vect = queue_print_output(vect, i, time);
        }
    }
    else if (vect.head > vect.tail) {
        for (int i = vect.head; i < VECT_SIZE + 1; i++) {
            vect = queue_print_output(vect, i, time);
        }
        if (vect.head < vect.tail) {
            for (int i = vect.head; i < vect.tail; i++) {
                vect = queue_print_output(vect, i, time);
            }
        }
        for (int i = 0; i < vect.head; i++) {
            vect = queue_print_output(vect, i, time);
        }
    }
    else if (vect.head == vect.tail && vect.value[vect.head].ts != 0) {
        for (int i = vect.head; i < VECT_SIZE + 1; i++) {
            vect = queue_print_output(vect, i, time);
        }
        for (int i = 0; i < vect.head; i++) {
            vect = queue_print_output(vect, i, time);
        }
    }
    else if (vect.head == vect.tail && vect.value[vect.head].ts == 0) {
        printf("\n");
    }
    return vect;
}

void del_vect(Massive mass) {
    for (int i = 0; i < mass.number; i++) {
        free(mass.vect[i].value);
    }
    free(mass.vect);
    mass.number = 0;
}
#endif