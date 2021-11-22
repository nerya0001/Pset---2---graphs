#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>


int matrix[10][10];
int tmpMatrix[10][10];

int shortest(int i, int j);

//input
int matrixInput() {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  return 0;
}

//is there a path
int isTherePath(int i, int j) {
  if (shortest(i, j) != -1) {
    return true;
  }
  return false;
}

//shortest path
int shortest(int i, int j) {
  /*do all the calculations and return the size of the shortest path*/
  if (i == j) {
    return -1;
  }

  //filling tmp matrix
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmpMatrix[i][j] = matrix[i][j];
    }
  }

  //the algorithm
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (tmpMatrix[i][k] != 0 && tmpMatrix[k][j] != 0) {
          if (tmpMatrix[i][j] > tmpMatrix[i][k] + tmpMatrix[k][j] || tmpMatrix[i][j] == 0) {
            tmpMatrix[i][j] = tmpMatrix[i][k] + tmpMatrix[k][j];
          }
        }
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    tmpMatrix[i][i] = 0;
  }

  if (tmpMatrix[i][j] == 0) {
    return -1;
  } else {
    return tmpMatrix[i][j];
  }
}
