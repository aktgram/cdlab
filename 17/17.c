#include <stdio.h>
#include <ctype.h>

int n;
char productions[10][10];

void input()
{
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", productions[i]);
    }
}

void display()
{
    printf("\nOptimized Code: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", productions[i]);
    }
}

void replace(char findChar, char replaceDigit, int prodIndex)
{
    for (int i = prodIndex + 1; i < n; i++)
    {
        int j = 2;
        if (productions[i][0] == findChar)
        {
            break;
        }

        while (productions[i][j] != '\0')
        {
            if (productions[i][j] == findChar)
            {
                productions[i][j] = replaceDigit;
            }
            j++;
        }
    }
}

void propagate()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (isdigit(productions[i][2]) && productions[i][3] == '\0')
        {
            replace(productions[i][0], productions[i][2], i);
        }
    }
}

int main()
{
    input();
    propagate();
    display();
    return 0;
}