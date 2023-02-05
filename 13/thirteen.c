#include <stdio.h>
#include <stdlib.h>

typedef struct transition
{
    char transitionChar;
    int finalStateValue;
} transition;

typedef struct state
{
    int stateValue;
    int finalState;
    transition *transitions;
} state;

void main()
{
    printf("Enter the no:of states: ");
    int stateCount;
    scanf("%d", &stateCount);

    printf("Enter the no:of input elements: ");
    int inputCount;
    scanf("%d", &inputCount);
    printf("Enter the input symbols: ");
    char *input = (char *)malloc(inputCount * sizeof(char));
    for (int i = 0; i < inputCount; i++)
        scanf(" %c", &input[i]);

    // to find reachable states
    int *reachableStates = (int *)malloc(stateCount * sizeof(int));
    for (int i = 0; i < stateCount; i++)
        reachableStates[i] = 0;

    state *DFA = (state *)malloc(stateCount * sizeof(state));
    for (int i = 0; i < stateCount; ++i)
    {
        DFA[i].stateValue = i;
        DFA[i].finalState = 0;

        DFA[i].transitions = (transition *)malloc(inputCount * sizeof(transition));
        printf("Enter the transitions for state %d:\n", i);
        for (int j = 0; j < inputCount; ++j)
        {
            scanf(" %c", &DFA[i].transitions[j].transitionChar);
            scanf("%d", &DFA[i].transitions[j].finalStateValue);
        }
    }

    printf("Enter the start state:");
    int startState;
    scanf("%d", &startState);

    printf("Enter the no:of final states: ");
    int finalStateCount;
    scanf("%d", &finalStateCount);
    printf("Enter the final states: ");
    for (int i = 0; i < finalStateCount; ++i)
    {
        int finalState;
        scanf("%d", &finalState);
        DFA[finalState].finalState = 1;
    }

    // to identify unreachable states
    int front = 0, rear = 0;
    int queue[20];
    queue[rear] = startState;

    while (front != -1)
    {
        int currentState = queue[front];
        front++;
        if (front > rear)
            front = -1;

        if (reachableStates[currentState] != 1)
        {
            reachableStates[currentState] = 1;

            for (int i = 0; i < inputCount; i++)
            {
                if (front == -1)
                    front = rear = 0;
                else
                    rear++;
                queue[rear] = DFA[currentState].transitions[i].finalStateValue;
            }
        }
    }

    for (int k = 0; k < stateCount; k++)
        if (reachableStates[k] == 1)
            for (int l = k + 1; l < stateCount; ++l)
                if (reachableStates[l] == 1 && DFA[k].finalState == DFA[l].finalState)
                {
                    int flag = 0;
                    for (int m = 0; m < inputCount; ++m)
                    {
                        if (DFA[k].transitions[m].finalStateValue != DFA[l].transitions[m].finalStateValue)
                        {
                            flag = 1;
                            break;
                        }
                    }

                    // duplicate state removed
                    if (flag == 0)
                    {
                        reachableStates[l] = 0;
                        for(int m=0;m<inputCount;++m)
                            if(DFA[l].transitions[m].finalStateValue==l)
                                DFA[k].transitions[m].finalStateValue=k;
                    }
                }

    // print minimal DFA
    printf("\nMinimal DFA:\n");
    for (int i = 0; i < stateCount; ++i)
    {
        if (reachableStates[i] == 1)
        {
            printf("State %d:\n", i);
            for (int j = 0; j < inputCount; ++j)
                if (reachableStates[DFA[i].transitions[j].finalStateValue] == 1)
                    printf("%c->%d\n", DFA[i].transitions[j].transitionChar, DFA[i].transitions[j].finalStateValue);
            printf("\n");
        }
    }

    free(DFA);
    free(reachableStates);
}