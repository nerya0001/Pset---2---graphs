#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>

int main() {
  char action;
  int i, j, path;
  do {
    scanf("%c", &action);
    switch (action) {
      case 'A':
        matrixInput();
        break;
      case 'B':
        scanf(" %d %d", &i, &j);
        if (isTherePath(i, j) == true) {
          printf("True\n");
        } else {
          printf("False\n");
        }
        break;
      case 'C':
        scanf(" %d %d", &i, &j);
        path = shortest(i, j);
        printf("%d\n", path);
        break;
    }
  } while (action != 'D');
  return 0;
}
