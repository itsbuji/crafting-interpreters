#include <stdio.h>
#include <stdint.h>


// chunk.h
typedef enum {
  OP_RETURN,
} OpCode;


typedef struct {
  int count;
  int capacity;
  uint8_t *code;
} Chunk;


void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk uint8_t byte);


int main(int argc, const char* argv[]) {
  printf("start of the program!");
  return 0;
}


void initChunk(Chunk* chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void writeChunk(Chunk* chunk uint8_t byte) {
  // check if capacity is less than new count(count+1)
  // if less double the capacity
  if( chunk->capacity < chunk->count + 1 ) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = oldCapacity < 8 ? 8 : oldCapacity * 2;
  }
}
