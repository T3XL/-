#include "stack.h"

bool bracketsCheck(char A[])
{
    SqStack s;
    initStack(&s);
    for(int i=0;A[i]!='\0';++i)
    {
        if(A[i] == '(' || A[i] == '[' || A[i] == '{')
            push(&s,A[i]);
        if(A[i] == ')')
        {
            char c;
            pop(&s,&c);
            if(c=='(')
                continue;
            else
                return false;
        }
        else if(A[i] == ']')
        {
            char c;
            pop(&s,&c);
            if(c=='[')
                continue;
            else
                return false;
        }
        else if(A[i] == '}')
        {
            char c;
            pop(&s,&c);
            if(c=='{')
                continue;
            else
                return false;
        }
    }
    if(stackEmpty(s))
        return true;
    else
        return false;
}