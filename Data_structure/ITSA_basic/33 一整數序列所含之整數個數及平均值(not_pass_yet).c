#include <stdio.h>
int main() {
    int num = 0;
    char c;
    int size = 0;
    float sum = 0;

    while (scanf("%d", &num) != EOF) {
        size++;
        sum += num;
        scanf("%c", &c);
        if (c == '\n' || c == '\r') {
            char j;
            printf("Size: %d\n", size);
            printf("Average: %.3f\n", (float) sum / size);
            sum = 0;
            size = 0;
        }

    }
}
