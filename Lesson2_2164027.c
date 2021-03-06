#include <stdio.h>

//素数を探すのって楽しいよね!
//素数を当てるゲームを今回作成した。
/*
 * 素数でない時は素因数を一覧表示できるようにしたい。
 * Intで表現できる最大の整数は2,147,483,647
 * 2~29までの素数(計)を掛け合わせると6,469,693,230
 * よって今回出力しうる素数は高々20個である。
 */

int isPrime(int a);

int sqrtFast(int *current, long *nL, long target);

int nextPrime(int t);

int main() {
    int target, size = 0;
    int result[20];
    while (1) {
        printf("入力された数字が素数かどうか判定するよ!\n");
        printf("素数を入力してみよう!!!");
        scanf("%d", &target);
        printf("%d\n", target);
        if (target < 2) {
            printf("正しく入力してください(2~2147483647)");
        } else {
            break;
        }
    }
    int tmp = 2;
    while (target != 1) {
        if (target % tmp == 0) {
            result[size++] = tmp;
            do {
                target /= tmp;
            } while (target % tmp == 0);
        } else {
            tmp = nextPrime(tmp);
        }
    }

    printf("終了");
    if (size==1) {
        printf("あたり!素数でした。");
    }else if(size!=0){
        printf("素数ではありませんでした!入力された数値は以下の倍数です。\n");
        for (int i = 0; i < size; ++i) {
            printf("%d, ", result[i]);
        }
    } else {
        printf("error");
    }
    return 0;
}

int nextPrime(int t) {
    if (t == 2)return 3;
    t += 2;
    //素数がでるまで2を足していく。
    while (!isPrime(t)) {
        t += 2;
    }
    return t;
}


//素数であるかどうかを判定する関数である。

int isPrime(int a) {
    int j;
    if (!(a % 2)) {
        return 0;
    }
    int aS = 2;
    long nL = 9;
    while (sqrtFast(&aS, &nL, a)) {}
    if (a % 3 == 0) {
        return 0;
    }
    for (j = 7; j <= aS; j += 6) {
        if (a % j == 0 || a % (j + 4) == 0) {
            return 0;
        }
    }
    return 1;
}

int sqrtFast(int *current, long *nL, long target) {
    if (target > *nL) {
        ++*current;
        *nL += *current * 2;
        ++*nL;
        return 1;
    }
    return 0;
}
