#include<stdio.h>
#include<stdlib.h>  /* for func4            */
#include<time.h>    /* for func4            */

#define ASC1  32    /* space ( for func 1 ) */
#define ASC2 126    /* ~     ( for func 1 ) */

void func1(char st[]);

void func2(char st[]);

void func3(char st[]);

void func4(char st[]);

int main(void) {
    /* Lyrics of "Yesterday" by Beatles */
    char str1[] = "Yesterday, all my troubles seemed so far away.";
    char str2[] = "Now it looks as though they are here to stay.";
    char str3[] = "Oh, I believe in yesterday.";
    char str4[256];

    printf("--- func1 ---\n");
    printf("%s\n\n", str1);
    func1(str1);

    printf("--- func2 ---\n");
    printf("%s\n\n", str2);
    func2(str2);

    printf("--- func3 ---\n");
    printf("%s\n\n", str3);
    func3(str3);

    printf("--- func4 ---\n");
    printf("input a word: ");
    scanf("%s", str4);
    func4(str4);

    return 0;
}

void func1(char st[]) {
    int counter[256] = {0};
    //charの範囲は-128~127
    int position = -1;
    while (st[++position] != '\0') {
        counter[st[position] + 128]++;
    }
    //10個事に改行するのが要件っぽい(?)のでそれも考えて
    int length = 0;
    for (int i = 0; i < 256; ++i) {
        if (counter[i] == 0)continue;
        printf("%c:%d ", i - 128, counter[i]);
        if (length++ == 9) {
            printf("\n");
            length = 0;
        }
    }
    printf("\n\n");
}

void func2(char st[]) {
    int length = 0;
    while (st[++length] != '\0') {}
    for (int i = length - 1; i >= 0; --i) {
        printf("%c", st[i]);
    }
    printf("\n\n");
}

void func3(char st[]) {
    int wordCount = 0;
    int position = -1;
    /**
     * flag
     * 1->直前に空白以外の文字があった
     * 0->直前に空白があった、もしくははじめの状態
     */
    int flag = 0;
    while (st[++position] != '\0') {
        switch (st[position]) {
            case ' ':
                if (flag == 1) {
                    wordCount++;
                }
                flag = 0;
                break;
            default:
                flag = 1;
        }
    }
    //最後が空白で終わっていなかったら、最後の単語のカウントを行う
    if (flag) {
        wordCount++;
    }
    printf("number of characters = %d\n", position);
    printf("number of words      = %d\n\n", wordCount);
}

void func4(char st[]) {
    int length = -1;
    //stの長さを取得
    while (st[++length] != '\0') {}
    for (int i = 0; i < 10; ++i) {
        srand(i);
        int check[1000] = {0};
        int position = 0;
        char result[length + 1];
        result[length] = '\0';
        for (int j = 0; j < length; ++j) {
            for (int k = rand() % (length - j) + 1; k > 0; ++position) {
                if (position == length)position = 0;
                if (check[position] == 1) continue;
                if (--k == 0) break;
            }
            check[position] = 1;
            result[j] = st[position];
        }
        printf("%2d:%s\n", i + 1, result);
    }
}