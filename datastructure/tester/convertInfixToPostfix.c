#include<stdio.h>
#include<ctype.h>

char stackSize[100];
int topStack = -1;

void stackPush(char x)
{
    stackSize[++topStack] = x;
}

char stackPop()
{
    if(topStack == -1)
        return -1;
    else
        return stackSize[topStack--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Satck Expression:Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            stackPush(*e);
        else if(*e == ')')
        {
            while((x = stackPop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stackSize[topStack]) >= priority(*e))
                printf("%c ",stackPop());
            stackPush(*e);
        }
        e++;
    }
    
    while(topStack != -1)
    {
        printf("%c ",stackPop());
    }return 0;
}