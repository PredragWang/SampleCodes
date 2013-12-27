/*
 * Simple implementation of memory management including malloc and free.
 *
 * Using sbrk() system call to get and advance the end of the address spaces
 * within the memory management.
 *
 * Author: Garrett Wang
 *
 * Reference:  
 * Article Source: IBM developerWorks
 * Article Title: Inside memory management
 * URL: http://www.ibm.com/developerworks/library/l-memory/
 */
#include <unistd.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

typedef struct memory_control_block {
    bool avail;
    size_t size;
}mem_ctrl_blk;

extern void* mm_malloc(size_t size);
extern void mm_free(void* start);
