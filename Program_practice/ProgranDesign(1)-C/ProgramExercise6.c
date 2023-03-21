#include <stdio.h>
#include <ctype.h>
int main(){
    int Bytes_num =0, Lowercase_num =0, Uppercase_num =0, Digit_num =0, Whitespace_num =0, Line_num =1;
    int AtoZ_num[26]={0,0};
    char ch=0, word_before_eeof=0;

    while((ch =getchar())!=EOF){
        switch(ch){
            case 'a'...'z':
                Bytes_num++;
                Lowercase_num++;
                  break;
            case 'A'...'Z':
                Bytes_num++;
                Uppercase_num++;
                  break;
            case '0'...'9':
                Bytes_num++;
                Digit_num++;
                  break;
            case ' ': case '\t': case '\v': case '\f': case '\r':
                Bytes_num++;
                Whitespace_num++;
                  break;
            case '\n':
                    Bytes_num++;
                    Line_num++;
                    Whitespace_num++;
                  break;
            default:
                Bytes_num++;
                  break;
        }

        if('a'<=ch && ch<='z')
            ch=toupper(ch);
        if('A'<=ch && ch<='Z'){
            AtoZ_num[(int)ch-65]++;
        }
        word_before_eeof=ch;
    }

    if(word_before_eeof == '\n'){
        Line_num--;
    }

    printf("Bytes Count: %d\n", Bytes_num);
    printf("Lowercase Count: %d\n", Lowercase_num);
    printf("Uppercase Count: %d\n", Uppercase_num);
    printf("Digit Count: %d\n",Digit_num);
    printf("Whitespace Count: %d\n", Whitespace_num);
    printf("Line Count: %d\n", Line_num);

    for(int i=0;i<26;i++){
        putchar('A'+i);
        putchar('/');
        putchar('a'+i);
        printf(": %d,",AtoZ_num[i]);
        printf(" %.3f\n",(float)AtoZ_num[i]/(Lowercase_num+Uppercase_num));
    }
    return 0;
}
