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



// 3.3.2. 栈的实现：数组 ：使用数组避免指针，但是需要提前指定一个数组的大小。
// 使用数组时，设置一个TopOfStack标志位，每次压栈，其加1，出栈减1.
// 主要看stuct StackRecord的定义


// 声明和定义，存放于.h文件

#define ElementType int

struct StackRecord;
typedef struct StackRecord *Stack;


int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);
void Push(ElementType x, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void DisposeStack(Stack S);


struct StackRecord
{
    int Capacity;       // 容量
    int TopOfStack;     // 当前元素指针
    ElementType *Array;
}*pS;


// 创建一个栈
Stack CreateStack(int MaxElements)    // 说明栈的容量
{
    Stack s;
    s = malloc(sizeof(struct StackRecord));
    if(s == NULL)
    {
        printf("Out Of Space!");
        return NULL;
    }
    
    s->Array = malloc(sizeof(ElementType) * MaxElements);
    if(s->Array == NULL)
    {
        printf("Out of Space!");
        return NULL;
    }
    s->Capacity = MaxElements;
    MakeEmpty(s);
    
    return s;
}

// 创建一个空栈,或使栈为空
void MakeEmpty(Stack S)
{
    S->TopOfStack = -1;
}

// 释放栈
void DisposeStack(Stack S)
{
    if(S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

// 判空
int IsEmpty(Stack S)
{
    return S->TopOfStack == -1;
}

int IsFull(Stack S)
{
    return S->Capacity == S->TopOfStack;
}


// 入栈
void Push(ElementType x, Stack S)
{
    if(IsFull(S))
    {
        printf("Full Stack!");
        return;
    }
    else
        S->Array[++S->TopOfStack] = x;
        
}

// 返回栈顶元素
ElementType Top(Stack S)
{
    if(IsEmpty(S))
    {
        printf("Stack Empty!");
        return NULL;
    }
    else
    {
        return S->Array[S->TopOfStack];
    }
    
}

// 从栈中弹出元素
void Pop(Stack S)
{
    if(IsEmpty(S))
    {
        printf("Empty Stack!");
        return;
    }
    else
    {
        S->TopOfStack--;
    }
}




// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    Stack s = CreateStack(20);
    Push(1, s);
    Push(2, s);
    Push(3, s);
    Push(4, s);
    int temp = Top(s);
    printf("%d \n", temp);
    
    
    return 0;
}



