#include <stdio.h>
#include <string.h>
char inp[30], temp[10], reg = 'A';
void gen_code(char op)
{
    int i = 0, j = 0;
    while (inp[i] != '\0')
    {
        if (inp[i] == op)
        {
            printf("%c\t%c\t%c\t%c\n", op, inp[i - 1], inp[i + 1], reg);
            temp[j - 1] = reg;
            i += 2;
            reg++;
        }
        temp[j++] = inp[i++];
    }
    temp[++j] = '\0';
    strcpy(inp, temp);
}
int main()
{
    char *s = "/*+-=";
    printf("Enter the expression : ");
    scanf("%s", inp);
    printf("Op\tArg1\tArg2\tRes\n\n");
    for (int i = 0; i < strlen(s); i++)
        gen_code(s[i]);
}