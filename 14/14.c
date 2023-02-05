#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char prod[10][10];

char ch; // For catching null in input. Ithillaathe output varoola

int fIndex = 0; // Output index
char f[20];     // Output string

void input()
{
    printf("Enter no. of productions: ");
    scanf("%d", &n);
    printf("\nEnter productions: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s%c", prod[i], &ch);
    }
}

void first(char element)
{
    for (int k = 0; k < n; k++)
    {
        if (prod[k][0] == element)
        {
            // Upper case ALLATHATH because it considers small and symbols
            if (!isupper(prod[k][2]))
            {
                f[fIndex++] = prod[k][2];
            }
            // UpperCase aanenki athintem first
            else
            {
                first(prod[k][2]);
            }
        }
    }
}

void follow(char element)
{
    if (prod[0][0] == element)
    {
        f[fIndex++] = '$';
    }

    // For Every Production
    for (int i = 0; i < n; i++)
    {
        // Iterating through RHS of each prod
        for (int j = 2; j < strlen(prod[i]); j++)
        {
            if (prod[i][j] == element)
            {
                if (prod[i][j + 1] != '\0')
                {
                    // Add terminal symbol to output array
                    if (!isupper(prod[i][j + 1]))
                    {
                        f[fIndex++] = prod[i][j + 1];
                    }
                    // Call first of Variable
                    else if (isupper(prod[i][j + 1]))
                    {
                        first(prod[i][j + 1]);
                    }
                }
                // If element is the last and dhe ee condition
                //
                // For follow(A)
                // A -> BA INVALID
                // C -> BA VALID
                if (prod[i][j + 1] == '\0' && prod[i][0] != element)
                {
                    follow(prod[i][0]);
                }
            }
        }
    }
}

void display()
{
    for (int i = 0; i < fIndex; i++)
    {
        printf("'%c' ", f[i]);
    }

    // Resetting output index
    strcpy(f, " ");
    fIndex = 0;
}

int main()
{

    char inputChar;

    input();

    int choice = 1;
    while (choice != 0)
    // for (int stuff = 0; stuff < 5; stuff++)
    {
        printf("Enter the element whose first and follow is to be found: ");
        scanf(" %c", &inputChar);

        first(inputChar);
        printf("First: {");
        display();
        printf("}\n\n");

        follow(inputChar);
        printf("Follow: {");
        display();
        printf("}\n\n");

        printf("Continue? 0 for no, 1 for yes : ");
        scanf("%d", &choice);
    }

    return 0;
}