#include <stdio.h>

unsigned int hashCalc(char *key, int tableSize) {
    unsigned int hashVal = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        char ch = key[i];
        hashVal = 37 * hashVal + ch;
    }

    return hashVal % tableSize;
}

int main() {
    char text[100];
    int tSize;

    scanf("%s", text);
    scanf("%d", &tSize);

    printf("%u\n", hashCalc(text, tSize));

    return 0;
}

