#include "input.h"
#include <stdio.h>



void input_int(int* a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n == 0 || n < 0) {
            printf("You're wrong! Try again\n");
            scanf("%*c");
        }
    } while (n <= 0);
}

void input_three(char id[10], int* ta, int* ts, int time) {
    int n;
    do {
        n = scanf(" %s%d%d", id, ta, ts);
        if (n < 3) {
            printf("You're wrong! Try again\n");
            scanf("%*c");
        }
        if (ts == 0) {
            printf("You`re wrong! Service time can`t be 0!");
            scanf("%*c");
        }
        if (*ta > time) {
            printf("Please, repeat again! Your flight hasn't arrived yet!\n");
        }
    } while (n < 3 || *ta > time);
}