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

#include <stdio.h>

typedef struct {
    int time;
    int age;
    int gender;
} patient;

void print_statistics_by_age_gender();

int read();

patient data[10000];
int size = 0;

int main() {
    printf("データのサイズは計%d件です。\n", read());
    print_statistics_by_age_gender();
}

int read() {
    FILE *file;
    file = fopen("../patients.txt", "r");
    patient tmp;
    while (fscanf(file, "%d %d %d", &tmp.time, &tmp.age, &tmp.gender) != EOF) {
        data[size++] = tmp;
    }
    return size;
}

//〇〇年代、男/女で集計していく
//今回のデータセットでは年代は10,20,20,30,40,50,60,70,80,90のいずれか。
int size_by_category[2][9];

void print_statistics_by_age_gender() {
    for (int i = 0; i < 18; ++i) {
        size_by_category[i % 2][i % 9] = 0;
    }
    for (int i = 0; i < size; ++i) {
        size_by_category[data[i].gender - 1][data[i].age / 10 - 1]++;
    }

    //print header
    printf("年齢と性別によるデータ統計\n");
    printf("+=====+========+======+\n");
    printf("| age | gender | size |\n");
    printf("+=====+========+======+\n");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("|  %d0 |  ", i + 1);
            if (j == 0) {
                printf("  man");
            } else {
                printf("woman");
            }
            printf("   %3d |\n", size_by_category[j][i]);
        }
    }
    printf("+=====+========+======+\n");
    //クイックソートを用いて揃える。
}

////値を交換する関数
//void swap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
///*クイックソート*/
//void QuickSort(int A[], int left, int right){
//    // 変数定義
//    int Left, Right;
//    int pivot;
//
//    // 初期値は引数から
//    Left = left; Right = right;
//
//    // 基準は真ん中に設定
//    pivot = A[(left + right) / 2];
//
//    // ソーティング
//    while (1) {
//        // 基準より小さい値を左から見つけていく
//        while (A[Left] < pivot) Left++;
//
//        // 基準より大きい値を右から見つけていく
//        while (pivot < A[Right]) Right--;
//
//        // 見つかった値の順序が逆になったら終了
//        if (Left >= Right) break;
//
//        // 値を交換
//        swap(&A[Left], &A[Right]);
//
//        // 次の値に移動
//        Left++; Right--;
//
//    }
//
//    //左のデータ群を対象としてクイックソートを再帰
//    if (left < Left - 1) QuickSort(A, left, Left - 1);
//
//    //右のデータ群を対象としてクイックソートを再帰
//    if (Right + 1 < right) QuickSort(A, Right + 1, right);
//
//}