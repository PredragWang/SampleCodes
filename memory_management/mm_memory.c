#include "mm_memory.h"

bool initialized = FALSE;
void *managed_mem_start; // start of the memory managed by this program
void *last_valid_addr;

void init(){
    // last valid address from the OS
    last_valid_addr = sbrk(0);
    managed_mem_start = last_valid_addr;
    initialized = TRUE;
}

void* mm_malloc(size_t size){
    void *cur_location;
    mem_ctrl_blk *cur_location_mcb;
    void *mem_location;

    if(!initialized) {
        init();
    }
    // the control block should also be included in the allocation
    size = size + sizeof(mem_ctrl_blk);

    mem_location = 0;

    cur_location = managed_mem_start;
    
    /*
     * Go through all the previously allocated space and find available space
     * When reaching a memory control block, check if the momory lead by 
     * the block has enough size, if yes, allocate it
     */
    while (cur_location < last_valid_addr) {
        cur_location_mcb = (mem_ctrl_blk *)cur_location;
        if (cur_location_mcb->avail) {
            if (cur_location_mcb->size >= size) {
                cur_location_mcb->avail = FALSE;
                mem_location = cur_location;
                break;
            }
        }
        // current location is not suitable, jump to the next control block
        cur_location = cur_location + cur_location_mcb->size;
    }
    
    /*
     * Previously no space to allocate in previously allocated blocks
     */
    if (mem_location == 0) {
        // advance the program break point and more spaces are available
        sbrk(size);
        mem_location = last_valid_addr;
        last_valid_addr += size;
        cur_location_mcb = mem_location;
        cur_location_mcb->avail = FALSE;
        cur_location_mcb->size = size;
    }
    mem_location = mem_location + sizeof(mem_ctrl_blk);
    return mem_location;
}

void mm_free(void *start) {
    mem_ctrl_blk *mcb;
    mcb = start - sizeof(mem_ctrl_blk);
    mcb->avail = TRUE;
    // Merge the freed memory spaces
    if (!initialized) return;
    void *cur_location, *next_location;
    mem_ctrl_blk *cur_location_mcb, *next_location_mcb;
    cur_location = managed_mem_start;
    
    /*
     * Go through all the memory control blocks and merge continuous available spaces
     */
    while (cur_location < last_valid_addr) {
        cur_location_mcb = (mem_ctrl_blk *)cur_location;
        next_location = cur_location + cur_location_mcb->size;
        next_location_mcb = (mem_ctrl_blk *)(next_location);
        // if current location and next location are both available, merge them
        if (cur_location_mcb->avail && next_location != last_valid_addr && next_location_mcb->avail){
            cur_location_mcb->size += next_location_mcb->size;
        }
        else {
            cur_location = next_location; 
        }
    }
    return;
}

