#include <stdio.h>
#include <stdlib.h>
#include "justify.h"

int main() {
    printf("Program is running\n");
    char* str;
    str = formatFile("justify");
    printf("%s", str);
}
