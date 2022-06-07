/*
 * Copyright (c) 2022 Shion Ichikawa.
 * <==============================FOR VIEWERS==============================>
 *      If you find software that doesn’t have a license, that generally means
 * you have no permission from the creators of the software to use, modify, or
 * share the software. Although a code host such as GitHub may allow you to
 * view and fork the code, this does not imply that you are permitted to use,
 * modify, or share the software for any purpose.
 * <=======================================================================>
 */

/**************************************************/
/*                                                */
/* sample program sample08.c ( for answer08.c )   */
/*                                                */
/**************************************************/
#include<stdio.h>
#include<stdlib.h> /* for srand(),rand()   */

#define N1 1000    /* range of rand：[1,N] */
#define N2  100    /* total number of data */

int flag[N1] = {0};
int data[N2] = {0};

void make_rand_data(void);

void write_data(char fname[]);

void read_data(char fname[]);

void quicksort(int left, int right);

void merge_sort(char f1[], char f2[], char f3[]);

int main(void) {
    srand(1);  /* random seed = 1 */

    /* (1)make random data and save them */
    make_rand_data();
    write_data("rand1.txt");
    make_rand_data();
    write_data("rand2.txt");

    /* (2)quicksort */
    read_data("rand1.txt");
    quicksort(0, N2 - 1);
    write_data("data1.txt");
    read_data("rand2.txt");
    quicksort(0, N2 - 1);
    write_data("data2.txt");

    /* (3)merge_sort */
    merge_sort("data1.txt", "data2.txt", "data3.txt");

    return 0;
}

void make_rand_data(void) {
    int i, n;

    for (i = 0; i < N2; i++) {
        do {
            n = rand() % N1 + 1;
        } while (flag[n] != 0);
        flag[n] = 1;
        data[i] = n;
    }
}

void write_data(char fname[]) {
    FILE *fp;
    int i, n;

    fp = fopen(fname, "w");
    printf("output file: %s\n", fname);
    for (i = 0; i < N2; i++) {
        fprintf(fp, "%d\n", data[i]);
        printf("%4d ", data[i]);
        if (i % 10 == 9) printf("\n");
    }
    printf("\n");
    fclose(fp);
}

void read_data(char fname[]) {
    FILE *fp;
    int i;

    fp = fopen(fname, "r");
    for (i = 0; i < N2; i++)
        fscanf(fp, "%d", &data[i]);
    fclose(fp);
}

void quicksort(int left, int right) {
    int i, j, x, w;

    if (left < right) {
        i = left;
        j = right;
        x = data[(left + right) / 2];
        do {
            while (data[i] < x) i++;
            while (x < data[j]) j--;
            if (i <= j) {
                if (i < j) {
                    w = data[i];
                    data[i] = data[j];
                    data[j] = w;
                }
                i++;
                j--;
            }
        } while (i <= j);
        if (left < j) quicksort(left, j);
        if (i < right) quicksort(i, right);
    }
}
/*
 * コード編集はmerge_sort内のみで行った。
 */
void merge_sort(char f1[], char f2[], char f3[]) {
    //retrieve data
    read_data(f1);
    int d1[N2];
    for (int i = 0; i < N2; ++i) {
        d1[i] = data[i];
    }
    read_data(f2);
    int d2[N2];
    for (int i = 0; i < N2; ++i) {
        d2[i] = data[i];
    }
    //finished retrieving data

    FILE *fp = fopen(f3, "w");

    //merge sorting starts from here
    int p1 = 0, p2 = 0, flag = 1;
    while (p1 < N2 && p2 < N2) {
        if (d1[p1] < d2[p2]) {
            fprintf(fp, "%4d", d1[p1++]);
        } else {
            fprintf(fp, "%4d", d2[p2++]);
        }
        if (flag++ % 10 == 0) {
            fprintf(fp, "\n");
        }
    }
    //process for remaining data starts from
    while (p1 < N2) {
        fprintf(fp, "%4d", f1[p1++]);
        if (flag++ % 10 == 0) {
            fprintf(fp, "\n");
        }
    }
    while (p2 < N2) {
        fprintf(fp, "%4d", f2[p2++]);
        if (flag++ % 10 == 0) {
            fprintf(fp, "\n");
        }
    }
    //process for remaining data ends here
}
