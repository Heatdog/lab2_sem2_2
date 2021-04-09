typedef struct {
    char id[10];
    int ta;
    int ts;
}queue;

typedef struct Item {
    queue ptr;
    struct Item* next;
} Item;


#ifdef USE_VECTOR
typedef struct {
    int head;
    int tail;
    queue* value;
    int time_process;
}Vector;
#else
typedef struct {
    Item* head;
    Item* tail;
    int time_process;
} List;
#endif

typedef struct {
    int number;
#ifdef USE_VECTOR
    Vector* vect;
#else
    List** list;
#endif
}Massive;



void input_int(int*);
void input_three(char[10], int*, int*, int);