#include <stdio.h>

char stack[20];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int ISP(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '(')
        return 0;
    return -1;
}

int ICP(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '(')
        return 3;
    return -1;
}

void infixtopostfix(char infix[20])
{
    char postfix[20], ch;
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((ch = pop()) != '(')
            {
                postfix[k] = ch;
                k++;
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' ||
                 infix[i] == '*' || infix[i] == '/')
        {
            while (top != -1 && ISP(stack[top]) >= ICP(infix[i]))
            {
                postfix[k] = pop();
                k++;
            }
            push(infix[i]);
        }
        else
        {
            postfix[k] = infix[i];
            k++;
        }
    }

    while (top != -1)
    {
        postfix[k] = pop();
        k++;
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s", postfix);
}

int main()
{
    char infix[20];

    printf("Enter the Infix Expression: ");
    scanf("%s", infix);

    infixtopostfix(infix);

    return 0;
}