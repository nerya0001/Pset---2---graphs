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
  return false;
}

int shortest(int i, int j) {
  printf("hey hey\n");
  return 0;
}
