#include <stdio.h>

#define MATRIX_SIZE 4

int main(void)
{
  double matrix[MATRIX_SIZE][MATRIX_SIZE] = {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 2.0, 3.0, 4.0},
    {1.0, -1.0, 1.0, -1.0},
    {2.0, -3.0, 3.0, -1.0}
  };
  double target[MATRIX_SIZE] = {-2.0, 3.0, 0.0, 6.0};
  double tmp, difference;
  int i, j, row_i, column_i;

  for (row_i = 0; row_i < MATRIX_SIZE; row_i++) {
    for (column_i = 0; column_i < MATRIX_SIZE; column_i++) {
      printf("%10.3f ", matrix[row_i][column_i]);
    }
    printf("|%10.3f\n", target[row_i]);
  }
  puts("");

  for (i = 0; i < MATRIX_SIZE; i++) {

    if (matrix[i][i] == 0) {
      for (j = i+1; j < MATRIX_SIZE; j++) {

        if (matrix[j][j] != 0) {
          for (column_i = 0; column_i < MATRIX_SIZE; column_i++) {
            tmp = matrix[i][column_i];
            matrix[i][column_i] = matrix[j][column_i];
            matrix[j][column_i] = tmp;
          }
          tmp = target[i];
          target[i] = target[j];
          target[j] = tmp;
          break;
        }

      }
    }

    for (row_i = i + 1; row_i < MATRIX_SIZE; row_i++) {
      difference = matrix[row_i][i] / matrix[i][i];
      for (column_i = i; column_i < MATRIX_SIZE; column_i++) {
        matrix[row_i][column_i] -= difference * matrix[i][column_i];
      }
      target[row_i] -= difference * target[i];
    }

  }

  for (i = MATRIX_SIZE - 1; i >= 0; i--) {
    for (row_i = i - 1; row_i >= 0; row_i--) {
      difference = matrix[row_i][i] / matrix[i][i];
      for (column_i = MATRIX_SIZE - 1; column_i >= 0; column_i--) {
        matrix[row_i][column_i] -= difference * matrix[i][column_i];
      }
      target[row_i] -= difference * target[i];
    }
  }

  for (i = 0; i < MATRIX_SIZE; i++) {
    target[i] /= matrix[i][i];
    matrix[i][i] /= matrix[i][i];
  }

  for (row_i = 0; row_i < MATRIX_SIZE; row_i++) {
    for (column_i = 0; column_i < MATRIX_SIZE; column_i++) {
      printf("%10.3f ", matrix[row_i][column_i]);
    }
    printf("|%10.3f\n", target[row_i]);
  }

  return 0;
}
