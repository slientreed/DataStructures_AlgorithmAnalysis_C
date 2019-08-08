//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/5.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>

// 3.2.1. 链表的指针实现方法:
// 问题1 ：现在只是int类型，利用C++模板，进行泛型


// 函数声明----------------------------------------------------------------------------------------------------------------------------

// 要写入.h文件：函数原型，节点定义

struct Node;                    // 节点为结构体类型
typedef struct Node* pNode;     // 节点指针
typedef pNode List;
typedef pNode Position;         // 节点指针类型

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int x, List L);
void Delete(int x, List L);
Position FindPrevious(int x, List L);
void Insert(int x, List L, Position P);
void DeleteList(List L);


// 放到.c文件
struct Node
{
    int element;
    Position next;
};


// 函数实现----------------------------------------------------------------------------------------------------------------------------
// 注意这里指针实现，都用了一个表头header，指向链表第一个节点。


// 创建并返回一个空的线性表
List MakeEmpty(List L)
{
    Position p;
    p = (Position)malloc(sizeof(struct Node));
    p->next = NULL;
    
    return p;
}


// 判空，如果链表L为空，返回True;
int IsEmpty( List L)     // L是header节点，指向链表真正第一个节点
{
    return L->next == NULL;
}


// 如果P是最后一个节点，返回true；
int IsLast(Position P, List L)   //  头结点L未使用
{
    return P->next == NULL;
}


// 返回x在链表L中的节点，如果未找到返回NULL；
Position Find(int x, List L)
{
    Position p;
    
    p = L->next;
    while(p != NULL && p->element != x)
        p = p->next;
    
    return p;                // 返回的是节点指针类型
}


// 删除元素值x节点：删除第一次出现的x，如果未出现x则什么也不做。
void Delete(int x, List L)
{
    Position p, temp;
    
    p = FindPrevious(x,L);   // 找到x前面一个节点
    if( !IsLast(p, L))
    {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}


// 返回x的前一个节点
Position FindPrevious(int x, List L)
{
    Position p;
    p = L;
    while(p->next != NULL && p->next->element != x)
        p = p->next;
    
    return p;
}


// 插入元素，把一个元素值x插入到P指示的位置之后
void Insert(int x, List L, Position p)
{
    Position temp;
    temp = malloc(sizeof(struct Node));
    //if(temp == NULL)
        //FatalError("Out of space!!");
    
    temp->element = x;
    temp->next = p->next;
    p->next = temp;
}

// 从头打印链表
void PrintList(List L)
{
    Position temp;
    temp = L->next;
    while(temp != NULL)
    {
        printf("%d ", temp->element);
        temp = temp->next;
    }
    printf("\n");
}




// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    List L = malloc(sizeof(struct Node));
    List l = MakeEmpty(L);
    
    Insert(1, l, l);
    Insert(2, l, l);
    Insert(3, l, l);
    Insert(4, l, l);
    
    List temp = Find(2, l);
    printf("%d \n", temp->element);
    
    PrintList(l);
    
    Delete(2, l);
    PrintList(l);
    
    return 0;
}



