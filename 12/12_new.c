#include <stdio.h>
#include <stdlib.h>
typedef struct dfastate
{
    int states[10];
    int count;
} dfastate;

// to check whether the new state created already exists
int check(dfastate dfs[10], int new, int count)
{
    for (int i = 0; i <= new - 1; i++)
    {
        int sn = 0, si = 0;
        if (dfs[i].count == count)
        {
            // count same and sum same, distinct numbers so both states same
            for (int j = 0; j < dfs[i].count; j++)
            {
                sn += dfs[new].states[j];
                si += dfs[i].states[j];
            }
            if (sn == si)
                return 1;
        }
    }
    return 0;
}
int main()
{
    int n, t, s, f, a;
    printf("Enter the number of alphabets: ");
    scanf("%d", &a);

    int alpha[a];
    printf("Enter the alphabets: ");
    for (int i = 0; i < a; i++)
    {
        scanf(" %d", &alpha[i]);
    }

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the number of start states: ");
    scanf("%d", &s);

    int start[s];
    printf("Enter the start states: ");
    for (int i = 0; i < s; i++)
    {
        scanf(" %d", &start[i]);
    }

    printf("Enter the number of final states: ");
    scanf("%d", &f);

    int final[f];
    printf("Enter the final states: ");
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &final[i]);
    }

    printf("Enter no of transition: ");
    scanf("%d", &t);

    int trans[t][3];
    printf("Enter the transitions: ");
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &trans[i][0], &trans[i][1], &trans[i][2]);
    }

    // intialise dfa with start states of nfa as the first state
    dfastate dfs[10];
    for (int i = 0; i < s; i++)
    {
        dfs[0].states[i] = start[i];
        dfs[0].count++;
    }

    int j = 0;
    // j contains the number of dfa states, and gets incremented upon
    // creation of new dfa state
    for (int i = 0; i <= j; i++)
    {
        // for each alphabet/possible z
        for (int z = 0; z < a; z++)
        {
            // count stores the new dfa states' no of elements
            int count = 0;
            printf("\n{ ");

            // the below loop takes each transition of each element and
            // creates a new dfa state

            // for each state in nfa, which is one single state of dfa
            for (int k = 0; k < dfs[i].count; k++)
            {
                // print the dfa state
                printf("%d ", dfs[i].states[k]);

                // for each transition from the state considered k, for alphabet z
                for (int m = 0; m < t; m++)
                {
                    int exist = 0;
                    if (trans[m][0] == dfs[i].states[k] && trans[m][1] == alpha[z])
                    {

                        for (int d = 0; d < count; d++)
                        {
                            // if element already exists dont put it again
                            if (dfs[j + 1].states[d] == trans[m][2])
                            {
                                exist = 1;
                                break;
                            }
                        }
                        // else add new element to the new dfa state
                        if (!exist)
                            dfs[j + 1].states[count++] = trans[m][2];
                    }
                }
            }
            printf("}\t\t%d\t\t{", alpha[z]);

            // count contains elements in the new dfa state
            for (int c = 0; c < count; c++)
                printf("%d ", dfs[j + 1].states[c]);

            printf("}");

            // checking if the new state calculated is already present in dfa
            int repeat = check(dfs, j + 1, count);
            if (!repeat)
            {
                dfs[j].count = count;

                // new dfa state created, so increment j for starting next loop
                j++;
            }
        }
    }

    return 0;
}