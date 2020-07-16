#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
  initVM();
  Chunk chunk;
  initChunk(&chunk);
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 100);
  writeChunk(&chunk, constant, 100);

  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 101);
  writeChunk(&chunk, constant, 101);

  writeChunk(&chunk, OP_ADD, 101);

  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 101);
  writeChunk(&chunk, constant, 101);

  writeChunk(&chunk, OP_DIVIDE, 101);
  writeChunk(&chunk, OP_NEGATE, 101);

  writeChunk(&chunk, OP_RETURN, 100);

  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);
  return 0;
}
