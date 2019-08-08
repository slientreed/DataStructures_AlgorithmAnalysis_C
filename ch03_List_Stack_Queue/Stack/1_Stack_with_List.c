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


// 3.3.1. 栈的实现：链表: 链表实现方便，操作线性时间。缺点是当涉及大量malloc和free时，开销大。这个问题可考虑用数组实现

// 声明和定义，存放于.h文件

#define ElementType int

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


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    Stack s = CreateStack();
    Push(1, s);
    Push(2, s);
    Push(3, s);
    Push(4, s);
    int temp = Top(s);
    printf("%d \n",temp);
    
    
    return 0;
}



