
#include "MemoryAllocator.h"

#include <stdbool.h>
//#include <zconf.h>

#define SIZE 1000
void * memory_block[SIZE];
struct MemoryAllocator{
//    void * memoryPoll;
//    size_t size;
//    bool used;
//    MemoryAllocator* next;
//
//
    void * start;
    size_t size_;
};
typedef struct data{
    bool used;
    size_t size;
} Data;
// memoryPool is a ptr to an already-existing large memoryblock
MemoryAllocator* MemoryAllocator_init( void * memoryPool,size_t size){
    MemoryAllocator*  memoryAllocator = (MemoryAllocator*) memoryPool;
    memoryAllocator->size_ = size;
    size_t i;
    //split too big block, init the len of the block
    for (i = 0; i < SIZE;) {
        if(((Data *)memory_block[i])->used == 0){
            if(((Data *)memory_block[i])->size > size){
                memoryAllocator->start = (memory_block + i);
                ((Data *)memory_block[i])->used = 1;
                ((Data *)memory_block[i])->size = size;
                //((Data *)memory_block[i+ size])->size = old_size - size ;
                ((Data *)memory_block[i+size])->used = 0;
                break;
            }
            else if(((Data *)memory_block[i])->size == size){
                memoryAllocator->start = (memory_block + i);
                ((Data *)memory_block[i])->used = 1;
                break;
            }
            else{
                memoryAllocator->start;
                //do nothing
            }
        }
        i = (((Data *)memory_block[i])->size + sizeof(Data))/sizeof(int*);
    }
    return memoryAllocator;
}
//Returns a ptr to the memoryPool
//DTOR
void* MemoryAllocator_release(MemoryAllocator* allocator){
}
void* MemoryAllocator_allocate(MemoryAllocator* allocator,size_t size){
}
/* Merge the next adjacent block is free */
void MemoryAllocator_free(MemoryAllocator* allocator, void *ptr){
    Data * d_ptr = (Data *)ptr;
    d_ptr->used = 0;
}
/* Merges all adjacent free blocks, and returns the size oflargest free block */
size_t MemoryAllocator_optimize (MemoryAllocator*allocator){
    size_t total_size = 0;
    size_t i;
    for (i = 0;  i< SIZE;) {
        if(((Data *)memory_block[i])->used == 0) {
            total_size += ((Data *)memory_block[i])->size;
        }
        i = (((Data *)memory_block[i])->size + sizeof(Data))/sizeof(int*);
    }
}