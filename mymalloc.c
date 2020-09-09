#include <stdlib.h>
#include "mymalloc.h"

struct metadata {
    int size;
    struct metadata *next;
};

static char *heap;
static int heapsize;
static int top;
static struct metadata *free_head;
 
void mymalloc_init(char *_heap, int _heapsize){
    heap = _heap;
    heapsize = _heapsize;
    top = 0;
    free_head = NULL;
}

void *mymalloc(int size){
    if(size == 0){
        size = 1;
    }
    size = (size + 7)/ 8 * 8;
    
    size += sizeof(struct metadata);
    
    struct metadata *prev = NULL;
    for(struct metadata *ptr = free_head; ptr; ptr = ptr->next){
        if(size <= ptr->size){
            if(prev == NULL){
                free_head = ptr->next;
            } else{
                prev->next = ptr->next;
            }
            //have enough size to allocate
            return (void *)ptr + sizeof(struct metadata);
        }
        prev = ptr;
    }
    
    if(size < 0 || size > heapsize || heapsize - size < top){
        return NULL;
    }
    
    //allocate more memory from top to top + size
    struct metadata *res = (struct metadata *)&heap[top];
    top += size;
    res->size = size;
    res->next = NULL;
    return(void *)res + sizeof(struct metadata);
}

void myfree(void *ptr){
    struct metadata *md = ptr - sizeof(struct metadata);
    md->next = free_head;
    free_head = md;
}
