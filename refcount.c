#include <stdio.h>
#include "refcount.h"

void* re_mallc(int nbytes){
    //malloc byte size and 8 bytes for poinnters
    int* rcp = malloc (nbytes + 8);
    *rcp = 1;
    return ((void*) rcp) + 8;
}

void rc_keep_ref(void* p){
    int* rcp = p - 8;
    (*rcp)++;
}

void rc_free_ref(void* p){
    int* rcp = p -8;
    (*rcp)--;
    if(!*p){
        free(rcp);
    }
}

void rc_print(void* p){
    int* rcp = p - 8;
    printf("ref counr for %p is %d\n", p, *rcp);
}
