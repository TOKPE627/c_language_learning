#include<stdio.h>
#include<ctype.h>

int stack[20];
int top = -1;

void pushElement(int x)
{
    stack[++top] = x;
}

int popElement()
{
    return stack[top--];
}

int main()
{
    char expression[30];
    char *ex;
    int number1,number2,number3,number;
    printf("Stack expression: Enter the expression :: ");
    scanf("%s",expression);
    ex = expression;
    while(*ex != '\0')
    {
        if(isdigit(*ex))
        {
            number = *ex - 48;
            pushElement(number);
        }
        else
        {
            number1 = popElement();
            number2 = popElement();
            switch(*ex)
            {
            case '+':
            {
                number3 = number1 + number2;
                break;
            }
            case '-':
            {
                number3 = number2 - number1;
                break;
            }
            case '*':
            {
                number3 = number1 * number2;
                break;
            }
            case '/':
            {
                number3 = number2 / number1;
                break;
            }
            }
            pushElement(number3);
        }
        ex++;
    }
    printf("\nThe expression has result %s  =  %d\n\n",expression,popElement());
    return 0;
}
