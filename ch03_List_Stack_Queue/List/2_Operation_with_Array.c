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

// 3.2.8. 链表的游标实现
// 链表指针两个功能：1.每个结构体包含数据和指针；2. 结构体可通过malloc和free构建，释放
// 游标的对应实现：  1.构建一个全局数组，数组内的下标代替指针； 2. 通过改变数组内下标进行malloc和free。

// 游标方法，实现的一个全局表，实际是把节点结构体放入数组中，然后用数组下标连接起来，并通过下标实现类似指针的功能和操作。



// 函数声明----------------------------------------------------------------------------------------------------------------------------
// 要写入.h文件的函数原型，定义

#define ElementType int    // 这里可以定义数据类型

typedef int pNode;        // 没有指针，但是模拟成指针
typedef pNode List;
typedef pNode Position;

void InitializeCursorSpace(void);


List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType x, const List L);
Position FindPrev(ElementType x, List L);
void Insert(ElementType x, List L, Position P);
void DeleteList(List L);

struct Node
{
    ElementType element;
    Position Next;          // 数组下标
};


#define SpaceSize 100
struct Node CursorSapce[SpaceSize];    // 开辟表示存储节点的数组


//初始化数组
void InitializeCursorSpace()
{
    for(int i = 0; i < SpaceSize; i++)
        CursorSapce[i].Next = i + 1;    // 每个Node更新为下一个节点的下标；
    
    CursorSapce[SpaceSize - 1].Next = 0;  // 0表示NULL
}



// 模拟malloc功能，空间如果非空，则把CursorSpace头指针的下一个元素分配出去。第一个是CursorSapce[0];
Position CursorAlloc(void)
{
    Position p;
    
    p = CursorSapce[0].Next;
    CursorSapce[0].Next = CursorSapce[p].Next;    // 把空间头指针后移一个
    return p;
}

// 模拟free功能，把下标为p的节点收回空间，放于头结点后一个节点
void CursorFree(Position p)
{
    CursorSapce[p].Next = CursorSapce[0].Next;
    CursorSapce[0].Next = p;
}


// 判断是否为空
int IsEmpty(List L)
{
    return CursorSapce[L].Next == 0;
}

// 判断是否是链表末尾函数
int IsLast(Position P, List L)
{
    return CursorSapce[P].Next == 0;
}

// 查找输入元素x在链表的位置，如果未找到，返回0；
Position Find(ElementType X, List L)
{
    Position P;
    P = CursorSapce[L].Next;
    
    while(P && CursorSapce[P].element != X)
        P = CursorSapce[P].Next;
    
    return P;
}

// 对链表进行删除，如果出现多次，删除第一次出现的
void Delete(ElementType x, List L)
{
    Position p, temp;
    p = FindPrev(x,L);    // 找待删除节点的前一个节点
    
    if(!IsLast(p, L))     // 待删除的前一个节点不是最后一个节点，说明节点存在
    {
        temp = CursorSapce[p].Next;
        CursorSapce[p].Next = CursorSapce[temp].Next;
        CursorFree(temp);
    }
}

// 找某个节点的前一个节点
Position FindPrev(ElementType x, List L)
{
    Position p = L;
    Position temp = CursorSapce[p].Next;
    while(CursorSapce[temp].element != x && temp)
    {
        temp = CursorSapce[temp].Next;
        p = CursorSapce[p].Next;
    }
    return p;
}

// 在某个节点后插入操作
void Insert(ElementType x, List L, Position p)
{
    Position temp;
    temp = CursorAlloc();
    if(temp == 0)   // 如果下标为0，说明没有空间，头结点已经到最后一个位置了
        return;
    
    CursorSapce[temp].element = x;
    CursorSapce[temp].Next = CursorSapce[p].Next;
    CursorSapce[p].Next = temp;
}


// 清空整个链表
void DeleteList(List L)
{
    Position p = CursorSapce[L].Next;
    Position temp = p;
    
    while(temp != 0)
    {
        p = CursorSapce[p].Next;
        CursorFree(temp);
        if(p == 0)
            break;
        temp = p;
    }
    CursorSapce[L].Next = 0;
}



// 辅助函数：打印链表
void printList(List L)
{
    if(L == 0)
        printf("链表为空！");
    
    Position p = CursorSapce[L].Next;
    while (p != 0)
    {
        printf("%d ", CursorSapce[p].element);
        p = CursorSapce[p].Next;
        
    }
    printf("\n");
    
}


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    InitializeCursorSpace();
    List L = CursorAlloc();
    CursorSapce[L].Next = 0;
    Insert(4, L, L);
    Insert(3, L, L);
    Insert(2, L, L);
    Insert(1, L, L);
    
    printList(L);
    Position p = Find(3, L);
    if(p)
        printf("找到：%d \n", CursorSapce[p].element);
    else
        printf("未找到！");
    
    Delete(3, L);
    printList(L);
    
    return 0;
}



