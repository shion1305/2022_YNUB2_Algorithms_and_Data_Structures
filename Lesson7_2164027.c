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

void sort(int l, int r);

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
int sorted[18];

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
    //まずは初期化。インデックス番号の列を並び替えることでソートを行う。
    for (int i = 0; i < 18; ++i) {
        sorted[i] = i;
    }

    sort(0, 17);

    //print header
    printf("\n\n年齢と性別によるデータ統計\n");
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
}


/*
 * 今回の課題ではクイックソートを用いて
 */
//値を交換する関数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getValue(int i) {
    return size_by_category[i % 2][i % 9];
}

void sort(int l, int r) {
    //今回配列が属性の配列が18個あるので最初の値はl=0,r=17
    // それぞれ変数を定義する
    //基準値
    int t;
    //左右のポジションをメモ
    int R, L;
    //引数を元に初期値をセットする
    R = r;
    L = l;
    // 基準は真ん中に設定。対応する値をgetValueで取得する。
    t = getValue((l + r) / 2);
    while (1) {
        // 基準より大きい値を右から見つけていく
        while (t < getValue(R)) R--;
        //基準値と比較し、小さい値を見つけたら
        while (getValue(L) < t) L++;
        // LとRが反転した時に終了する。
        if (L >= R) break;
        // 並び替えの為のインデックス番号を格納した配列に対して置換処理を行う。
        swap(&sorted[R--], &sorted[L++]);
    }
    //左右に分けたデータそれぞれに対して再帰処理
    if (R + 1 < r) sort(R + 1, r);
    if (l < L - 1) sort(l, L - 1);
}