//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/8.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 栈结构和操作定义----------------------------------------------------------------------------------------------------------------------------

#define ElementType char
struct Node;
typedef struct Node* pNode;
typedef pNode Stack;

int IsEmpty(Stack s);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void pop(Stack s);

struct Node
{
    ElementType Element;
    pNode Next;
}*pN;


// 判空
int IsEmpty(Stack s)
{
    return s->Next == NULL;
}

// 创建一个空栈
Stack CreateStack(void)
{
    Stack s;
    s = malloc(sizeof(struct Node));
    if(s == NULL)
        printf("Out of Space!");
    
    s->Next = NULL;
    MakeEmpty(s);
    return s;
}


// 清空栈
void MakeEmpty(Stack s)
{
    if(s == NULL)
        return;
    else
        while (!IsEmpty(s)) {
            pop(s);
        }
}

// 压栈
void Push(ElementType x, Stack s)
{
    pNode tempNode = malloc(sizeof(struct Node));
    if(tempNode == NULL)
    {
        printf("Out of Space!");
        return;
    }
    else
    {
        tempNode->Element = x;
        tempNode->Next = s->Next;
        s->Next = tempNode;           // 每次入栈，放入头节点的下一个
    }
}

// 返回栈顶元素
ElementType Top(Stack s)
{
    if(!IsEmpty(s))
    {
        return s->Next->Element;
    }
    else
    {
        printf("Empty Stack!");
        return 0;
    }
}

// 出栈
void pop(Stack s)
{
    pNode tempNode;
    if(IsEmpty(s))
    {
        printf("Empty Stack!");
        return;
    }
    else
    {
        tempNode = s->Next;
        s->Next = s->Next->Next;
        free(tempNode);
    }
}


// 示例2---------------------------------------------------------------------------------------------------------------------------

// 例子2：后缀表达式计算，以及把中缀变成后缀表达式。
// 1. 后缀表达式计算：按照运算符出现顺序，从左到右，如果是操作数则入栈；否则碰到操作符则取两个数进行计算，结果入栈作为下次操作数。
// 2. 中缀转后缀：  1.读到操作数则入数组；2. 读到运算符，把优先级比这个小的或者等于的运算符出栈，在入栈这个；3. 左括号，入栈； 4. 读右括号，把栈内左括号之前的所有运算符出栈，存入数组，再把左括号出栈。



// 中缀表达式转换成后缀表达式
char *TransExp(char* str)
{
    char resStr[100];   // 保存转换后的后缀字符串
    Stack s = CreateStack();
    
    int i = 0, j = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')   // 如果是数字，直接存到后缀表达式中
            resStr[j++] = str[i];
        else if(str[i] == '(')          // 左括号入栈
            Push(str[i], s);
        else if(str[i] == ')')          // 如果是右括号，则把左括号上面所有元素出栈，放入后缀表达式
        {
            while (!IsEmpty(s)) {
                if(Top(s) != '(')
                {
                    resStr[j++] = Top(s);
                    pop(s);
                }
                else                     // 左括号扔掉
                {
                    pop(s);
                    break;
                }
            }
        }
        else if(str[i] == '+' || str[i] == '-')       // 如果是操作符，把高于等于它的所有操作符出栈，放入后缀中
        {
            while(!IsEmpty(s))
            {
                char c = Top(s);
                if(c == '+' || c == '-' || c == '/' || c == '*')
                {
                    resStr[j++] = Top(s);
                    pop(s);
                }
                else
                    break;
            }
            Push(str[i], s);                   // 把当前操作数入栈
        }
        else if(str[i] == '*' || str[i] == '/')
        {
            while (!IsEmpty(s)) {
                char c = Top(s);
                if(c == '*' || c == '/')
                {
                    resStr[j++] = str[i];
                    pop(s);
                }
                else
                    break;
            }
            Push(str[i], s);
        }
        
        i++;
    }
    
    while(!IsEmpty(s))           // 出栈剩下的字符串，添加到后缀中
    {
        resStr[j++] = Top(s);
        pop(s);
    }
    
    return resStr;
}


// 后缀表达式的计算
int calExp(char* exp)
{
    puts(exp);    // 输出转换后的后缀字符串
    //int len = strlen(exp);
    //printf("%d \n", len);
    
    Stack s = CreateStack();
    
    int i = 0;
    while(exp[i] != '\0')
    {
        if(exp[i] >= '0' && exp[i] <= '9')
            Push(exp[i], s);
        else if(exp[i] == '+')
        {
            char c = Top(s);
            int m = c - '0';
            pop(s);
            char t = Top(s);
            int n = t - '0';
            pop(s);
            Push((m + n + '0'), s);
        }
        else if(exp[i] == '-')
        {
            char c = Top(s);
            int m = c - '0';
            pop(s);
            char t = Top(s);
            int n = t - '0';
            pop(s);
            Push((m - n + '0'), s);
        }
        else if(exp[i] == '*')
        {
            char c = Top(s);
            int m = c - '0';
            pop(s);
            char t = Top(s);
            int n = t - '0';
            pop(s);
            Push((m * n + '0'), s);
        }
        else if(exp[i] == '/')
        {
            char c = Top(s);
            int m = c - '0';
            pop(s);
            char t = Top(s);
            int n = t - '0';
            pop(s);
            Push((m / n + '0'), s);
        }
        i++;
    }
    
    int res = Top(s) - '0';
    return res;
}




// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    // 例子2测试
    
    char str[100];
    char* resStr = (char *)malloc(sizeof(char) * 100);
    printf("输入要中缀表达式：");
    scanf("%s",str);
    //gets(str);
    resStr = TransExp(str);  // 转换为后缀
    int res = calExp(resStr);
    printf("后缀表达式计算值：%d \n", res);
    
    return 0;
}

