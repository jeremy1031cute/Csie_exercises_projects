int precedCmp(char *oper1, char *oper2);
int infixCalc(char **tokens, int tokenLens);
int prefixCalc(char **tokens, int tokenLens);
int postfixCalc(char **tokens, int tokenLens);

//precedCmp
#define isAddOrMinus(x) (x[0] == '+' || x[0] == '-') ? 1 : 0


//infixCalc
//#include <ctype.h>//isdigit();
