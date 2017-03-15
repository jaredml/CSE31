#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char hello[13] = "hello ", world[] = "world!\n", *s;
  s = strcat(hello,world);
  printf(s);
return 0;
}
