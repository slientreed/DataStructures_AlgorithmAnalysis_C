//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/9.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 3.4.1 队列的数组实现

// 队列的实现要注意判空：1.是在结构体中加入一个size单元表示；2.另一种方法是使用队尾和队首指针的关系：rear = front - 1时则为空。
// 不管使用哪种方法，要注意前后一致，这里采用第1种，在结构体内增加一个size变量记录。



// 函数声明----------------------------------------------------------------------------------------------------------------------------
// 函数原型，定义，实现

#define ElementType int

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType x, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);


struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
}*pQ;


// 队列判空
int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}


// 判满队列
int IsFull(Queue Q)
{
    return Q->Capacity == Q->Size;
    //return Q->Rear = (Q->Front + Q->Size - 1) % Q->Capacity;         // 判满件，因为是循环，所以判断rear是否是front后面一个
}


// 创建一个队列
Queue CreateQueue(int MaxElements)
{
    Queue q = (Queue)malloc(sizeof(struct QueueRecord));
    if(q == NULL)
    {
        printf("Space Error!");
        return NULL;
    }
    
    q->Front = -1;
    q->Rear = -1;
    q->Size = 0;
    q->Capacity = MaxElements;
    return q;
}


// 构造空队列
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}


// 销毁一个队列
void DisposeQueue(Queue Q)
{
    if(Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}


// 入队数据
void Enqueue(ElementType x, Queue Q)
{
    if(IsFull(Q))
    {
        printf("Queue is Full!");
        return;
    }
    else
    {
        Q->Rear++;
        Q->Rear %= Q->Capacity;     // rear可能到了结尾，构建循环队列
        Q->Size++;
        Q->Array[Q->Rear] = x;
        
    }
}

// 返回队首元素
ElementType Front(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Queue is Empty!");
        return NULL;
    }
    else
    {
        return Q->Array[Q->Front];
    }
}

// 出队数据
void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Queue is Empty!");
        return;
    }
    else
    {
        Q->Front++;
        Q->Front %= Q->Capacity;
        Q->Size--;
    }
}


// 出队，并返回出队的数据
ElementType FrontAndDequeue(Queue Q)
{
    ElementType temp;
    
    if(IsEmpty(Q))
    {
        printf("Queue is Empty!");
        return NULL;
    }
    else
    {
        temp = Q->Array[Q->Front];
        Q->Front++;
        Q->Front %= Q->Capacity;
        Q->Size--;
    }
    return temp;
}


// 辅助函数，打印队列
void PrintQueue(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Queue is Empty!");
        return;
    }
    
    int index = Q->Front;
    for(int i = 0; i < Q->Size; i++)
    {
        printf("%d ", Q->Array[index]);
        index++;
        index %= Q->Capacity;
    }
    printf("\n");
}


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    
    Queue q = CreateQueue(10);
    MakeEmpty(q);
    
    Enqueue(1, q);
    Enqueue(2, q);
    Enqueue(3, q);
    Enqueue(4, q);
    Enqueue(5, q);
    
    PrintQueue(q);
    
    Dequeue(q);
    PrintQueue(q);
    
    int temp = FrontAndDequeue(q);
    printf("%d \n", temp);
    PrintQueue(q);
    
    DisposeQueue(q);
    //PrintQueue(q);
    
    
    return 0;
}



