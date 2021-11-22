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

  // printf("\n");
  // for(int i = 0; i < 10; i++) {
  //   printf("|");
  //   for(int j = 0; j < 10; j++) {
  //     printf(" %d ", matrix[i][j]);
  //   }
  //   printf("|\n");
  // }
  // printf("\n");
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
  if (i == j) {
    return -1;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmpMatrix[i][j] = matrix[i][j];
    }
  }


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

  // printf("\n");
  // for(int i = 0; i < 10; i++) {
  //   printf("|");
  //   for(int j = 0; j < 10; j++) {
  //     printf(" %d ", tmpMatrix[i][j]);
  //   }
  //   printf("|\n");
  // }
  // printf("\n");
  if (tmpMatrix[i][j] == 0) {
    return -1;
  } else {
    return tmpMatrix[i][j];
  }
}
