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


// 3.4.1 队列的链表实现
// 使用单链表实现队列，注意定义两个结构体，一个是Queue结构体（包含表示队列的头尾指针），一个是Queue中的Node节点结构体（包含数据和下一个节点指针）。



// 函数声明----------------------------------------------------------------------------------------------------------------------------
// 函数原型，定义，实现

#define ElementType int


struct QueueRecord;
typedef struct QueueRecord* Queue;

Queue CreateQueue();
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType x, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);


// 定义队列中Node节点结构体
typedef struct Node
{
    ElementType Element;
    struct Node* Next;      // 指向下个节点的指针
}*pNode;


// 定义队列结构体
struct QueueRecord
{
    pNode Front;
    pNode Rear;
}*pQ;



// 创建一个队列
Queue CreateQueue()
{
    Queue q = (Queue)malloc(sizeof(struct QueueRecord));
    if(q == NULL)
    {
        printf("Space Error!");
        return NULL;
    }
    q->Front = NULL;
    q->Rear = NULL;
    
    return q;
}


// 队列判空
int IsEmpty(Queue Q)
{
    return Q->Front == NULL;
}


// 构造空队列
void MakeEmpty(Queue Q)
{
    Q->Front = NULL;
    Q->Rear = NULL;
}


// 销毁一个队列
void DisposeQueue(Queue Q)
{
    if(Q != NULL)
    {
        free(Q);
    }
}


// 入队数据
void Enqueue(ElementType x, Queue Q)
{

    struct Node* qNode = (pNode)malloc(sizeof(struct Node));
    if(qNode == NULL)
    {
        printf("Space Error!");
        return;
    }
    qNode->Element = x;
    qNode->Next = NULL;
    
    if(Q->Front == NULL)     // 如果队列为空
        Q->Front = qNode;
    if(Q->Rear == NULL)
        Q->Rear = qNode;
    else
    {
        Q->Rear->Next = qNode;
        Q->Rear = qNode;
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
        return Q->Front->Element;
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
    
    struct Node* tempNode = (pNode)malloc(sizeof(struct Node));
    tempNode = Q->Front;
    
    if(Q->Front == Q->Rear)    // 队中只有一个元素
    {
        Q->Front = NULL;
        Q->Rear = NULL;
    }
    else
        Q->Front = Q->Front->Next;
    
    free(tempNode);
}


// 出队，并返回出队的数据
ElementType FrontAndDequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Queue is Empty!");
        return NULL;
    }
    
    struct Node* tempNode = (pNode)malloc(sizeof(struct Node));
    tempNode = Q->Front;
    
    if(Q->Front == Q->Rear)
    {
        Q->Front = NULL;
        Q->Rear = NULL;
    }
    else
        Q->Front = Q->Front->Next;
    
    ElementType temp = tempNode->Element;
    free(tempNode);
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
    
    struct Node* tempNode = (pNode)malloc(sizeof(struct Node));
    tempNode = Q->Front;
    while(tempNode != NULL)
    {
        printf("%d ", tempNode->Element);
        tempNode = tempNode->Next;
    }
    printf("\n");
}


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    
    Queue q = CreateQueue();
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



