#include<stdio.h>

#define COLUMN_SIZE 9
#define ROW_SIZE 9

int main(void) {
    int table[ROW_SIZE][COLUMN_SIZE];
    FILE *fp = fopen("./kuku.csv", "r");
    printf("column size = %d\n", COLUMN_SIZE);
    printf("row size = %d\n", ROW_SIZE);
    for (int i = 0; i < ROW_SIZE; ++i) {
        for (int j = 0; j < COLUMN_SIZE - 1; ++j) {
            fscanf(fp, "%d,", &table[i][j]);
        }
        fscanf(fp, "%d", &table[i][8]);
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%5d", table[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
}