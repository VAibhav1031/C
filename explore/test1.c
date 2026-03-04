#include <stdio.h>
#include <stdlib.h>

void main() {
    int *pt = malloc(sizeof(*pt));

    // *ptr = 343;
    printf("the value is here %d",*pt);
    //
    // free(ptr);
    //
    // printf("the value is here %d",*ptr);
    //
    // ptr = NULL; // It make things more better i would say , like now trhe pointer 

    // printf("the value is here %d",*ptr);
    // this will give you the segmentation fault core dump  
}
