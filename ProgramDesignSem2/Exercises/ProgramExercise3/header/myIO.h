void _check_args(int argc, char **argv, int *notation, int *action);
int _get_input(char **tokens);
void _free_tokens(char **tokens, int tokenLens);
void _exp_print(char **expression, int expLens, int mode);
void _calcResult_print(int result);
void _error_message(int condition);
//for different condition(just like choose)
#define TooMany 1
#define TooLess 2
#define Unknown 3
#define Duplicate 4

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2

#define Rev 1
#define Nor 2
