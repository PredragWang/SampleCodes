#include "mm_memory.h"
#include <stdio.h>

int main(int argc, char **argv){
    printf("mcb size: %ld\n", sizeof(mem_ctrl_blk));
    void *m1 = mm_malloc(3);
    void *m2 = mm_malloc(4);
    void *m3 = mm_malloc(5);
    void *m4 = mm_malloc(5);
    mm_free(m2);
    mm_free(m3);
    return 0;
}
