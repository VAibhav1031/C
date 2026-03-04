#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>
#include <stdint.h>

typedef struct Arena Arena;
typedef struct ArenaTemp ArenaTemp;

Arena *arena_create(size_t size);
void arena_destroy(Arena *arena);
void *arena_alloc(Arena *arena, size_t size);
void arena_reset(Arena *arena);

size_t arena_get_pos(Arena *arena);

ArenaTemp arena_temp_begin(Arena *arena);
void arena_temp_end(ArenaTemp temp);

//helpers  (easy to use)
#define arena_alloc_type(arena,type) (type *)arena_alloc(arena, sizeof(type))   
#define arena_alloc_array(arena, type, count) (type *)arena_alloc(arena, sizeof(type) * count)   


#endif
