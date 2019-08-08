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


// 示例问题1----------------------------------------------------------------------------------------------------------------------------------


//例子1：平衡符号， 判断()[]{}是否匹配。

// 思路：从字符串中读字符，如果为([{则压入栈，)]}就取栈顶元素，如果不匹配则不平衡；如果到了文件尾，栈不空，不平衡；
// 1. 不匹配；  2. 字符串读到一个闭符号，栈已空；   3. 字符串结尾，但是栈不为空


// 从键盘输入字符串，读取存到str中
void getString(char str[], int size)
{
    fgets(str, size, stdin);    // fgets()从指定流中读入一行，存入str指向的字符串中，stdin表示标准输入流
}

// 返回字符串字符的个数
int getSize(char str[], int length)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    
    return i;
}

// 检查字符串是否是平衡字符,是返回1，否则返回0
int checkChar(char str[], int size)
{
    int flag = 1;
    Stack s = CreateStack();
    for(int i = 0; i < size; i++)
    {
        char c = str[i];
        switch(c){
                case '(':
                case '[':
                case '{':
                    Push(c, s);
                    break;
                case ')':
                case ']':
                case '}':
                    if(!IsEmpty(s))
                    {
                        char stop = Top(s);
                        pop(s);
                        if( (c == ')' && stop != '(') || (c == ']' && stop != '[') || (c == '}' && stop != '{') )   // 1. 不匹配
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else
                    {
                        flag = 0;           // 2. 栈空，字符串不空
                        break;
                    }
        }
    }
    
    if(IsEmpty(s) && flag == 1)   // 情况3，两者要同时为空；
        flag = 1;
    else
        flag = 0;
    
    return flag;
}





// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    // 例子1：测试语句
    
    char str[100];
    printf("请输入字符串：");
    getString(str, 100);   // 用户输入字符
    int len = getSize(str, 100);
    int flag = checkChar(str, len);
    if(flag == 1)
        printf("是平衡！\n");
    else
        printf("不平衡！\n");
    
    
    
    return 0;
}



