#include <stdio.h>
int main()
{
    int j = 0, k = 0, conti = 0;//conti:前面有不是空白的字元
    char ch;

    while(ch != '\n' && ch != EOF)
    {
        ch=getchar();
        switch(ch)
        {
            case 'A': case 'a': case 'E': case 'e':
            case 'I': case 'i': case 'O': case 'o':
            case 'U': case 'u':
                j++;
                break;
            default:
                break;
        }
        if(ch == ' ')
        {
            if(conti != 0)
                k++;
            conti = 0;
        } else
            conti += 1;
    }

    if(conti != 0)
        k++;

    printf("%d %d",j,k);
    return 0;
}
