#include "Stack.h"
#include <stdbool.h>


//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。


bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    bool ret;
    while(*s != '\0')
    {
        if(*s == '[' || *s == '(' || *s == '{')
        {
            StackPush(&st,*s);
            s++;
        }
        else
        {
            if(StackEmpty(&st))
            {
                ret = false;
                break;
            }
            char top = StackTop(&st);
            if(top != '[' && *s == ']')
            {
                ret = false;
                break;
            }
            if(top != '{' && *s == '}')
            {
                ret = false;
                break;
            }
            if(top != '(' && *s == ')')
            {
                ret = false;
                break;
            }
            StackPop(&st);
            s++;
        }
    }

    if(*s == '\0')
        ret  = StackEmpty(&st);//返回1是空，返回0是非空
    StackDestroy(&st);

    return ret;
}

int main()
{
    char *a = "()[]{}";
    bool b = isValid(a);
    if(b == false)
        printf("false");
    if(b == true)
        printf("true");

    return 0;
}