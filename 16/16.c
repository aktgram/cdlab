#include <stdio.h>
#include <string.h>

char stack[50];
char inp[50];
char act[50];

int i = 0, j = 0;
int len;

// Rules can be E->2E2 , E->3E3 , E->4

void check() {
  strcpy(act, "Reducing E -> ");

  // E->4
  for (int z = 0; z < len; z++) {
    if (stack[z] == '4') {
      printf("%s4", act);
      stack[z] = 'E';
      stack[z + 1] = '\0';

      printf("\n$%s\t%s$\t", stack, inp);
    }
  }

  // E->2E2
  for (int z = 0; z < len; z++) {
    if ((stack[z] == '2') && (stack[z + 1] == 'E') && (stack[z + 2] == '2')) {
      printf("%s2E2", act);
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 2] = '\0';

      printf("\n$%s\t%s$\t", stack, inp);
      i = i - 2;
    }
  }

  // E->3E3
  for (int z = 0; z < len; z++) {
    if ((stack[z] == '3') && (stack[z + 1] == 'E') && (stack[z + 2] == '3')) {
      printf("%s3E3", act);
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 2] = '\0';

      printf("\n$%s\t%s$\t", stack, inp);
      i = i - 2;
    }
  }
  return;
}

int main(int argc, char *argv[]) {
  printf("Enter the string: ");
  scanf("%s", inp);
  // strcpy(inp, "23432");

  len = strlen(inp);

  printf("\nstack \t input \t action\n");

  // printf("$%s\t%s$\t", stack, inp);
  printf("$\t%s$\t", inp);

  for (i = 0; j < len; i++, j++) {
    printf("SHIFT");

    stack[i] = inp[j];
    stack[i + 1] = '\0';

    inp[j] = ' ';

    printf("\n$%s\t%s$\t", stack, inp);
    check();
  }

  check();
  if (stack[0] == 'E' && stack[1] == '\0')
    printf("Accept\n");
  else // else reject
    printf("Reject\n");

  return 0;
}
