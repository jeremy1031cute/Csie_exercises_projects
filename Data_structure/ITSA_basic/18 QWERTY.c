#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100000];
    char sorted_list[] = "~!@#$%^&*()_++  `1234567890-==  qwertyuiop[]\\  {}||  asdfghjkl;''  :""  zxcvbnm,.//  <>??";
    int list_len = strlen(sorted_list);

    gets(input);
    int input_len = strlen(input);
    //strlen () not include '\0' but include \n

    for (int i = 0 ; i < input_len; i++) {
        input[i] = tolower(input[i]);
    }

    for (int i = 0 ; i < input_len; i++) {
        for (int j = 0 ; j < list_len; j++) {
            if (input[i] == sorted_list[j]) {
                printf("%c", sorted_list[j + 1]);
                break;
            }
        }
    }
    printf("\n");
}
