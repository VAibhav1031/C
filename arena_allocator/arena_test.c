#include <stdio.h>
#include "arena.h"
#include <string.h>

struct node{
    uint8_t value;
    uint8_t next;
};

struct ArenaTemp{
    Arena *arena;
    size_t pos;
};


void temp_check();

int main(){

    Arena *arena  = arena_create(1024);

    //alocate some stuf
    int *a = arena_alloc_array(arena, int,10);
    char *str = arena_alloc(arena, 100);

    a[0]=42;

    strcpy(str,"hello arena!");

    printf("%d %s\n",a[0],str);

    //reset the arena , this only reset the pointer,memory isnt cleared, we are going to reuse adn it will overwritten over the old ones .
    arena_reset(arena);


    //reuse the memory
    //
    int *b = arena_alloc_array(arena, int, 5);
    
    b[0]=99;
    
    printf("%d \n",b[0]);
   
    // this will create the panic and abortt because of assert use
    // int *c = arena_alloc_array(arena, int, 1020);

    arena_destroy(arena);

    temp_check();

    return 0;

}

void temp_check(){
    Arena *arena = arena_create(1024*1024);

    int *a = arena_alloc_array(arena, int, 100);

    int val = 23;
    for(int i = 0;i<= 100 ; i++){
        a[i] = ((val*i)+1);
    }

    printf("see this :%d \n",a[99]);

    printf("current_pos before bookmark: %zu \n",arena_get_pos(arena));
    
    ArenaTemp temp_m = arena_temp_begin(arena);

   { 
    char *str  = arena_alloc(temp_m.arena, 100);

    strcpy(str,"There is something you must understanding..");

    // currently the pos is increased , but we have bookmarked before this begin thing we can go back easily 
    
    printf("current_pos : %zu \n",arena_get_pos(arena));

    //coming back to the bookmark position
   }

    arena_temp_end(temp_m);


   printf("current_pos : %zu \n",arena_get_pos(arena));
   arena_destroy(arena);
}

