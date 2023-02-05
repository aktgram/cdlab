#include <stdio.h>
#include <string.h>

int num;
char states[20][20];
char closures[20][20];

void display()
{
  for (int i = 0; i < num; i++)
  {
    printf("\n Epsilon closure of %s = { ", states[i]);
    printf(" %s", closures[i]);
    printf(" } \n");
  }
}

int main(int argc, char *argv[])
{

  FILE *fp = fopen("input10.txt", "r");

  printf("Enter the no of states: ");
  scanf("%d", &num);
  printf("Enter the states :");

  for (int k = 0; k < num; k++)
  {
    scanf("%s", states[k]);
  }

  char a[3], x[3], b[3];

  for (int i = 0; i < num; i++)
  {
    char s[3];
    strcpy(s, states[i]);
    strcpy(closures[i], s);

    while (fscanf(fp, "%s %s %s", a, x, b) != EOF)
    {
      if ((strcmp(a, s) == 0) && (strcmp(x, "e") == 0))
      {
        strcat(closures[i], " ");
        strcat(closures[i], b);
        strcpy(s, b);
      }
    }
    rewind(fp);
  }
  display();
  return 0;
}
