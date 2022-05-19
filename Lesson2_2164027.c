#include <stdio.h>

//�f����T���̂��Ċy�������!
//�f���𓖂Ă�Q�[��������쐬�����B
/*
 * �f���łȂ����͑f�������ꗗ�\���ł���悤�ɂ������B
 * Int�ŕ\���ł���ő�̐�����2,147,483,647
 * 2~29�܂ł̑f��(�v)���|�����킹���6,469,693,230
 * ����č���o�͂�����f���͍��X20�ł���B
 */

int isPrime(int a);

int sqrtFast(int *current, long *nL, long target);

int nextPrime(int t);

int main() {
    int target, size = 0;
    int result[20];
    while (1) {
        printf("���͂��ꂽ�������f�����ǂ������肷���!\n");
        printf("�f������͂��Ă݂悤!!!");
        scanf("%d", &target);
        printf("%d\n", target);
        if (target < 2) {
            printf("���������͂��Ă�������(2~2147483647)");
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

    printf("�I��");
    if (size==1) {
        printf("������!�f���ł����B");
    }else if(size!=0){
        printf("�f���ł͂���܂���ł���!���͂��ꂽ���l�͈ȉ��̔{���ł��B\n");
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
    //�f�����ł�܂�2�𑫂��Ă����B
    while (!isPrime(t)) {
        t += 2;
    }
    return t;
}


//�f���ł��邩�ǂ����𔻒肷��֐��ł���B

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
