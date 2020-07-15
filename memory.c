#include <stdlib.h>

#include "memory.h"

/*
depending on the two sizes:
old       new         operation
0         non-zero    allocate new block
non-zero  0           free allocation
non-zero  < old       shrink existing allocation
nen-zero  > old       grow existing allocation
*/
void *reallocate(void *previous, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(previous);
    return NULL;
  }
  void *result = realloc(previous, newSize);
  if (result == NULL)
    exit(1);

  return result;
}
