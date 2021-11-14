#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>

int main() {
  char action;
  int i, j;
  do {
    scanf("%c", &action);
    switch (action) {
      case 'A':
        matrixInput();
        break;
      case 'B':
        scanf("%d%d", &i, &j);
        if (isTherePath(i, j) == true) {
          printf("true\n");
        } else {
          printf("false\n");
        }
        break;
      case 'C':
        scanf("%d%d", &i, &j);
        shortest(i, j);
        break;
    }
  } while (action != 'D');
  return 0;
}
