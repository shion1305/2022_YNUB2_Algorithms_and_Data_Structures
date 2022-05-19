#include <stdio.h>

//‘f”‚ğ’T‚·‚Ì‚Á‚ÄŠy‚µ‚¢‚æ‚Ë!
//‘f”‚ğ“–‚Ä‚éƒQ[ƒ€‚ğ¡‰ñì¬‚µ‚½B
/*
 * ‘f”‚Å‚È‚¢‚Í‘fˆö”‚ğˆê——•\¦‚Å‚«‚é‚æ‚¤‚É‚µ‚½‚¢B
 * Int‚Å•\Œ»‚Å‚«‚éÅ‘å‚Ì®”‚Í2,147,483,647
 * 2~29‚Ü‚Å‚Ì‘f”(Œv)‚ğŠ|‚¯‡‚í‚¹‚é‚Æ6,469,693,230
 * ‚æ‚Á‚Ä¡‰ño—Í‚µ‚¤‚é‘f”‚Í‚X20ŒÂ‚Å‚ ‚éB
 */

int isPrime(int a);

int sqrtFast(int *current, long *nL, long target);

int nextPrime(int t);

int main() {
    int target, size = 0;
    int result[20];
    while (1) {
        printf("“ü—Í‚³‚ê‚½”š‚ª‘f”‚©‚Ç‚¤‚©”»’è‚·‚é‚æ!\n");
        printf("‘f”‚ğ“ü—Í‚µ‚Ä‚İ‚æ‚¤!!!");
        scanf("%d", &target);
        printf("%d\n", target);
        if (target < 2) {
            printf("³‚µ‚­“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(2~2147483647)");
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

    printf("I—¹");
    if (size==1) {
        printf("‚ ‚½‚è!‘f”‚Å‚µ‚½B");
    }else if(size!=0){
        printf("‘f”‚Å‚Í‚ ‚è‚Ü‚¹‚ñ‚Å‚µ‚½!“ü—Í‚³‚ê‚½”’l‚ÍˆÈ‰º‚Ì”{”‚Å‚·B\n");
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
    //‘f”‚ª‚Å‚é‚Ü‚Å2‚ğ‘«‚µ‚Ä‚¢‚­B
    while (!isPrime(t)) {
        t += 2;
    }
    return t;
}


//‘f”‚Å‚ ‚é‚©‚Ç‚¤‚©‚ğ”»’è‚·‚éŠÖ”‚Å‚ ‚éB

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
