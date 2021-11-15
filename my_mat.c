#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int matrix[10][10];
int tmpMatrix[10][10];

int matrixInput() {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  return 0;
}

int isTherePath(int i, int j) {
  if (shortest(i, j) != INT_MAX) {
    return true;
  }
  return false;
}

int shortest(int i, int j) {
  /*do all the calculations and return the size of the shortest path*/
  //initializing tmp matrix to infinity
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmpMatrix[i][j] = INT_MAX;
    }
  }

  //copying tha values from the matrix
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmpMatrix[i][j] = matrix[i][j];
    }
  }

  //the algorithm itself
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (tmpMatrix[i][j] > tmpMatrix[i][k] + tmpMatrix[k][j]) {
          tmpMatrix[i][j] = tmpMatrix[i][k] + tmpMatrix[k][j];
        }
      }
    }
  }
  return tmpMatrix[i][j];
}
