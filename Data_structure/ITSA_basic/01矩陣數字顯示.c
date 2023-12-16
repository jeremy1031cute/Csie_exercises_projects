#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char display[5][10][6] = {
    {"*****", "    *", "*****", "*****", "*   *", "*****", "*****", "*****", "*****", "*****"},
    {"*   *", "    *", "    *", "    *", "*   *", "*    ", "*    ", "    *", "*   *", "*   *"},
    {"*   *", "    *", "*****", "*****", "*****", "*****", "*****", "    *", "*****", "*****"},
    {"*   *", "    *", "*    ", "    *", "    *", "    *", "*   *", "    *", "*   *", "    *"},
    {"*****", "    *", "*****", "*****", "    *", "*****", "*****", "    *", "*****", "    *"}, };

    char str[5];
    scanf("%s", str);
    for (int col = 0; col < 5; col++) { //up to down
        for (int row = 0; row < 4; row++) { //right to left
            int d = str[row] - '0'; //turn char into int
            if (row > 0)
                printf(" ");
            printf("%s", display[col][d]);
        }
        printf("\n");
    }
    return 0;
}
