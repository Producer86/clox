#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

// we store all constants in constant pools
typedef struct {
  int count;
  int capacity;
  Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void freeValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);

void printValue(Value value);

#endif
