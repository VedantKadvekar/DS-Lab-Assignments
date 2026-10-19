#include <stdio.h>
#include <string.h>

char stack[20][30];
int top = -1;

void push(char op[30]);
void pop(char op[30]);
void posttopre(char post[20]);

void push(char op[30])
{
    top++;
    strcpy(stack[top], op);
}

void pop(char op[30])
{
    strcpy(op, stack[top]);
    top--;
}

int main()
{
    char post[20];

    printf("Enter the postfix expression: ");
    scanf("%s", post);

    posttopre(post);

    return 0;
}

void posttopre(char post[20])
{
    char prefix[30];
    char op1[30];
    char op2[30];
    char temp[2];
    int i;

    for (i = 0; post[i] != '\0'; i++)
    {
        if (post[i] == '+' || post[i] == '-' ||
            post[i] == '*' || post[i] == '/')
        {
            pop(op1);
            pop(op2);

            temp[0] = post[i];
            temp[1] = '\0';

            strcpy(prefix, temp);
            strcat(prefix, op2);
            strcat(prefix, op1);

            push(prefix);
        }
        else
        {
            temp[0] = post[i];
            temp[1] = '\0';

            push(temp);
        }
    }

    pop(prefix);

    printf("Prefix expression: %s", prefix);
}