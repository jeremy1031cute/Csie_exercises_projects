#include <stdio.h>

int main()
{
    int row = 0, col = 0;

    scanf("%d %d ", &row, &col);

    int matrix[row][col];
    int inverse_matrix[col][row];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
            inverse_matrix[j][i] = matrix[i][j];
        }
    }

    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            printf("%d", inverse_matrix[i][j]);
            if(j != row - 1)
                printf(" "); //the last num in every row can't ' '
        }
        printf("\n");
    }
}
