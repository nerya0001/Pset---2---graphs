#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>
// #include <math.h>

int matrixInput() {
  int matrix[10][10];
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
        scanf("%d", &matrix[i][j]);
    }
  }
  return 0;
}

int isTherePath(int i, int j) {
  if (shortest(i, j) != -1) {
    return true;
  }
  return false;
}

int shortest(int i, int j) {
  /*do all the calculations and return the size of the shortest path*/
  return -1;
}
