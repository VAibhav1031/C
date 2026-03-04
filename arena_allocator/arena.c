#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Arena {
    uint8_t *buffer;
    size_t size;
    size_t pos;

};

struct ArenaTemp{
    Arena *arena;
    size_t pos;
};


// whenever we have to pass the structs (custom datatype) to the function and all , then using stack based allocation for the structs wont help 
// cause that will become undefined when function exits , that remove (pop) stack frame of that function and pointer of that thing is null or undefined 


Arena *arena_create(size_t size){
    Arena *arena  = malloc(sizeof(Arena));
    arena->buffer = malloc(size);
    arena->size = size;
    arena->pos = 0;
    return arena;
}

void arena_destroy(Arena *arena){
    free(arena->buffer);
    free(arena);
}

void arena_reset(Arena *arena){
    arena->pos = 0;
}

size_t arena_get_pos(Arena *arena){
    return arena->pos;
}


void *arena_alloc(Arena *arena, size_t size){
    size_t aligned = (size + 7) & ~7;

    assert(arena->pos + aligned <= arena->size);

    void *ptr = arena->buffer+arena->pos;
    arena->pos += aligned;

    return ptr;

}

ArenaTemp arena_temp_begin(Arena *arena){

    ArenaTemp temp;
    temp.arena = arena;
    temp.pos = arena->pos;
    return temp;
}

// you would use the arena details given to the temp (struct one)
void arena_temp_end(ArenaTemp temp){
    temp.arena->pos = temp.pos;
}


// dont get confuse like why we are using ArenaTemp one to reset the thing , cause the arena it has is of the same struct nothing else 


