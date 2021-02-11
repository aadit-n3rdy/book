#include "stack.h"
#include <stdlib.h>

int main() {
  struct Stack* stack;
  stack = calloc(1, sizeof(struct Stack));
  stackinit(stack);
  stackPush(stack, 100);
  stackPush(stack, 200);
  int value;
  for(int i = 0; i < 3; i++) {
    stackPop(stack, &value);
    printf("%d\n", value);
  }
  stackFree(stack);
  free(stack);
  return 0;
}
