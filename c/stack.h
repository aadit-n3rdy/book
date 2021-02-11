#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Stack {
  int* bottom;
  int* top;
  unsigned int size;
};

bool stackinit(struct Stack* stackPtr) {
  bool result = true;
  if(stackPtr == NULL) {
    result = false;
    fprintf(stderr, "ERROR: Passed nullptr to stackinit");
  }
  else {
    stackPtr->bottom = (int*)calloc(1, sizeof(int));
    stackPtr->top = stackPtr->bottom;
    stackPtr->size = 0;
  }
  return result;
}

bool stackPush(struct Stack* stackPtr, int element) {
  bool result = true;
  if(stackPtr == NULL) {
    result = false;
    fprintf(stderr, "ERROR: Passed nullptr to stackPush");
  }
  else {
    stackPtr->size += 1;
    stackPtr->bottom = (int*)realloc(stackPtr->bottom, sizeof(int)*(stackPtr->size+1));
    stackPtr->top = stackPtr->bottom + stackPtr->size * sizeof(int);
    *(stackPtr->top) = element;
  }
  return result;
}

bool stackPop(struct Stack* stackPtr, int* value) {
  bool result = true;
  if(stackPtr == NULL) {
    result = false;
    fprintf(stderr, "ERROR: Passed nullptr to stackPop");
  }
  else {
    if(stackPtr->size <= 0) {
      result = false;
      fprintf(stderr, "ERROR: Tried popping empty stack");
    }
    else {
      stackPtr->size -= 1;
      if(value) {
	*value = *(stackPtr->top);
      }
      stackPtr->bottom = (int*)realloc(stackPtr->bottom, sizeof(int)*(stackPtr->size+1));
      stackPtr->top = stackPtr->bottom + stackPtr->size * sizeof(int);
    }
  }
  return result;
}

bool stackFree(struct Stack* stackPtr) {
  bool result = true;
  if(stackPtr == NULL) {
    result = false;
    fprintf(stderr, "ERROR: Passed NULL to stackFree");
  }
  else {
    stackPtr->top = NULL;
    free(stackPtr->bottom);
    stackPtr->size = -1;
  }
  return result;
}
