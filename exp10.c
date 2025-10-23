#include <stdio.h>

int sp[100][3], tran[100][3];
void trans(int mat[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    int nonZero = mat[0][2];
    int k = 1;
    tran[0][0] = cols;
    tran[0][1] = rows;
    tran[0][2] = nonZero;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (mat[i][1] == col) {
                tran[k][0] = mat[i][1];
                tran[k][1] = mat[i][0];
                tran[k][2] = mat[i][2];
                k++;
            }
        }
    }
    printf("\nTranspose of the sparse matrix:\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", tran[i][0], tran[i][1], tran[i][2]);
    }
}
int main() {
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &sp[0][0], &sp[0][1]);
    printf("Enter number of non-zero elements:\n");
    scanf("%d", &sp[0][2]);
    printf("Enter the sparse matrix elements (row, column, value):\n");
    for (int i = 1; i <= sp[0][2]; i++) {
        scanf("%d %d %d", &sp[i][0], &sp[i][1], &sp[i][2]);
    }
    trans(sp);
    return 0;
}

