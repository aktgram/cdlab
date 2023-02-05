#include <ctype.h>
#include <stdio.h>
#include <string.h>

int i = 0;
char input[30];
int error = 0;

void E();
void EPrime();
void T();
void TPrime();
void F();

void E()
{
  T();
  EPrime();
}

void F()
{
  if (isalnum(input[i]))
  {
    i++;
  }
  else if (input[i] == '(')
  {
    i++;
    E();
    if (input[i] == ')')
      i++;
    else
      error = 1;
  }
  else
    error = 1;
}

void TPrime()
{
  if (input[i] == '*')
  {
    i++;
    F();
    TPrime();
  }
}

void T()
{
  F();
  TPrime();
}

void EPrime()
{
  if (input[i] == '+')
  {
    i++;
    T();
    EPrime();
  }
}

int main()
{

  scanf("%s", input);
  int len = strlen(input);
  E();

  if ((len == i) && (error == 0))
  {
    printf("Accepted..\n");
  }
  else
  {
    printf("Rejected..\n");
  }

  return 0;
}
