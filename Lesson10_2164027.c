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

#define N 10
int map[N][N] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, 0,  -1, 0,  -1, 0,  0,  0,  0,  -1},
        {-1, 0,  -1, 0,  -1, 0,  -1, -1, -1, -1},
        {-1, 0,  0,  0,  -1, 0,  -1, 0,  0,  -1},
        {-1, 0,  0,  0,  -1, -1, -1, -1, 0,  -1},
        {-1, -1, -1, 0,  -1, 0,  0,  0,  0,  -1},
        {-1, -1, -1, 0,  0,  0,  0,  0,  0,  -1},
        {-1, 0,  0,  0,  -1, -1, -1, 0,  -1, -1},
        {-1, 0,  0,  0,  -1, 0,  0,  0,  -2, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},};
typedef struct {
    int x, y;
} point;

int process(int data[N][N], point start, point goal);

int main() {
    point start = {1, 1};
    point goal = {8, 8};
    process(map, start, goal);
}

void countStep(int x, int y, int step, int data[N][N], int route[N][N]);

void checkAndMemo(int x, int y, int step, int data[N][N], int route[N][N]) {
    if (!((x < N && x >= 0) && (y < N && y >= 0))) return;
    if ((route[x][y] == 0 || route[x][y] > step) && (data[x][y] == 0 || data[x][y] == -2)) {
        route[x][y] = step;
        countStep(x, y, step + 1, data, route);
    }
}

void countStep(int x, int y, int step, int data[N][N], int route[N][N]) {
    checkAndMemo(x - 1, y, step + 1, data, route);
    checkAndMemo(x + 1, y, step + 1, data, route);
    checkAndMemo(x, y - 1, step + 1, data, route);
    checkAndMemo(x, y + 1, step + 1, data, route);
}

void trace(int data[N][N], int route[N][N], int step, int x, int y);

int trace_check(int data[N][N], int x, int y, int route[N][N], int step) {
    if (x < N && x >= 0 && y < N && y >= 0 && route[x][y] == step) {
        data[x][y] = 1;
        if (step > 1) {
            trace(data, route, step - 1, x - 1, y);
        }
        return 1;
    }
    return 0;
}

void trace(int data[N][N], int route[N][N], int step, int x, int y) {
    if (trace_check(data, x + 1, y, route, step - 1)) return;
    if (trace_check(data, x - 1, y, route, step - 1)) return;
    if (trace_check(data, x, y + 1, route, step - 1)) return;
    if (trace_check(data, x, y - 1, route, step - 1)) return;
}

int process(int data[N][N], point start, point goal) {
    int route[N][N] = {{0,},};
    countStep(start.x, start.y, 1, data, route);
    printf("ステップ数: %d", route[goal.x][goal.y]);
    trace(data, route, route[goal.x][goal.y], goal.x, goal.y);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%2d ", data[i][j]);
        }
        printf("\n");
    }
}