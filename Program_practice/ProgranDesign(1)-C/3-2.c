#include <stdio.h>
int main(){
    int x, sum=0;
    char ch;

    while(ch != '\n' && ch != EOF){
        ch=getchar();
        switch(ch){
            case 'A': case 'a': case 'E': case 'e':
            case 'I': case 'i': case 'L': case 'l':
            case 'N': case 'n': case 'O': case 'o':
            case 'R': case 'r': case 'S': case 's':
            case 'T': case 't': case 'U': case 'u':
                x=1;
                sum+=x;
                break;
            case 'D': case 'd': case 'G': case 'g':
                x=2;
                sum+=x;
                break;
            case 'B': case 'b': case 'C': case 'c':
            case 'M': case 'm': case 'P': case 'p':
                x=3;
                sum+=x;
                break;
            case 'F': case 'f': case 'H': case 'h':
            case 'V': case 'v': case 'W': case 'w':
            case 'Y': case 'y':
                x=4;
                sum+=x;
                break;
            case 'K': case 'k':
                x=5;
                sum+=x;
                break;
            case 'J': case 'j': case 'X': case 'x':
                x=8;
                sum+=x;
                break;
            case 'Q': case 'q': case 'Z': case 'z':
                x=10;
                sum+=x;
                break;
            default:
                break;
        }
    }

    printf("%d",sum);
    return 0;
}
