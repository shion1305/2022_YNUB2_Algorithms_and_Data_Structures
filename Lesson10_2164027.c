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
    int x;
    int y;
} point;

int process(int data[N][N], point start, point goal);

int main() {
    point start = {1, 1};
    point goal = {8, 8};
    process(map, start, goal);
}

int checkAndMemo(int x, int y, int step, int data[N][N], int route[N][N]) {
    if ((x < N && x >= 0) && (x < N && x >= 0)) {
        if ((route[x][y] == 0 || route[x][y] > step) && (data[x][y] == 0 || data[x][y] == -2)) {
            route[x][y] = step;
            return 1;
        }
    }
    return 0;
}

int countStep(int x, int y, int step, int data[N][N], int route[N][N]) {
    if (checkAndMemo(x - 1, y, step + 1, data, route)) {
        countStep(x - 1, y, step + 1, data, route);
    }
    if (checkAndMemo(x + 1, y, step + 1, data, route)) {
        countStep(x + 1, y, step + 1, data, route);
    }

    if (checkAndMemo(x, y + 1, step + 1, data, route)) {
        countStep(x, y + 1, step + 1, data, route);
    }
    if (checkAndMemo(x, y + 1, step + 1, data, route)) {
        countStep(x, y + 1, step + 1, data, route);
    }
}

int process(int data[N][N], point start, point goal) {
    int route[N][N] = {{0,},};
    countStep(1, 1, 1, data, route);
    printf("%d", route[goal.x][goal.y]);
}