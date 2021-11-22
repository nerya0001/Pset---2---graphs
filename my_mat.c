#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>


int matrix[10][10];
int tmpMatrix[10][10];

int shortest(int i, int j);

int matrixInput() {
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
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmpMatrix[i][j] = matrix[i][j];
    }
  }


  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (tmpMatrix[i][j] > tmpMatrix[i][k] + tmpMatrix[k][j] && (tmpMatrix[i][k] + tmpMatrix[k][j]) != 0) {
          tmpMatrix[i][j] = tmpMatrix[i][k] + tmpMatrix[k][j];
        }
      }
    }
  }

  if (tmpMatrix[i][j] == 0) {
    return -1;
  } else {
    return tmpMatrix[i][j];
  }
}
