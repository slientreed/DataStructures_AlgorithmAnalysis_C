//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/24.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>




// 1.定义结构----------------------------------------------------------------------------------------------------------------------------
/*
 1. 堆的性质：1.完全二叉树； 2. 父节点比左右子节点小
 2. 堆的数据结构组成：一个数组，表示最大值的整数，当前堆的大小。
 3. 写代码时，注意堆是完全二叉树：某一元素位置i，左儿子在位置2i，右儿子在2i+1，父亲在i/2下取整。不用指针， 直接在数组找父节点和子节点。
 */

#define ElementType int

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initialize( int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);


// 堆结构定义，放在.c文件
struct HeapStruct
{
    int Capacity;      // 堆结构能存的最大值
    int Size;          // 堆内的个数
    ElementType *Elements;
};


// 2.操作----------------------------------------------------------------------------------------------------------------------------

// 初始化
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    
    H = malloc(sizeof(struct HeapStruct));
    if(H == NULL)
    {
        printf("The Heap is Full!");
        return NULL;
    }
    
    // 开辟堆中的数组元素
    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if(H->Elements == NULL)
    {
        printf("Space Error!");
        return NULL;
    }
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = (INT_MIN); // 放一个很小的数放到位置0处，保证小于堆中的任何值；在插入时判断用来终止循环
    
    return H;
}

// 销毁堆
void Destory(PriorityQueue H)
{
    if(H != NULL)
    {
        free(H->Elements);
        free(H);
    }
}


// 清空堆
void MakeEmpty(PriorityQueue H)
{
    if(H != NULL)
    {
        free(H->Elements);
        H->Capacity = 0;
        H->Size = 0;
    }
}


// 向堆中插入元素
void Insert(ElementType X, PriorityQueue H)
{
    if(IsFull(H))
    {
        printf("The Heap is Full!");
        return;
    }
    
    int i;
    for(i = ++H->Size; H->Elements[i / 2] > X; i /= 2)                 // 如果一直到根节点，终止条件是0位置的元素一定小于X值；其他找到位置则插入
        H->Elements[i] = H->Elements[i / 2];        // 上滤，把父节点往下移动
    H->Elements[i] = X;            // 找到位置，插入
}


// 删除最小元素:找到最小元素容易，二叉堆的第一个元素；删除第1个元素，就要找到最后一个元素要移动到的位置；一直下滤，直到找到最后一个元素该插入的位置。
ElementType DeleteMin(PriorityQueue H)
{
    if(IsEmpty(H))
    {
        printf("Heap is Empty!");
        return H->Elements[0];
    }
    
    int i, child;
    ElementType MinElement, LastElement;
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    
    for(i = 1; i * 2 <= H->Size; i = child)
    {
        // 找更小的孩子
        child = i * 2;
        if(child != H->Size && H->Elements[child + 1] < H->Elements[child])    // 左孩子（2i）和右孩子(2i+1)比较
            child++;
        
        if(LastElement > H->Elements[child])   // 找最后一个元素的位置：如果最后一个小于当前孩子最小值，则插入；否则更新当前i位置值，然后继续往下一层找位置
            H->Elements[i] = H->Elements[child];
        else
            break;
    }
    
    H->Elements[i] = LastElement;       // 把最后一个元素放到该放的位置
    printf("最小值是：%d \n", MinElement);
    return MinElement;
}


// 找出堆的最小值,第1个元素
ElementType FindMin(PriorityQueue H)
{
    if(H != NULL)
        return H->Elements[1];
    else
        return NULL;
}


//判断堆是否为空
int IsEmpty(PriorityQueue H)
{
    return (H->Size == 0);
}


// 判断堆是否满
int IsFull(PriorityQueue H)
{
    return (H->Capacity == H->Size);
}


// 3.辅助函数----------------------------------------------------------------------------------------------------------------------------


void Heap_print(PriorityQueue H)
{
    if(H != NULL)
    {
        for(int i = 1; i <= H->Size; ++i)
            printf("%d ", H->Elements[i]);
    }
    printf("\n");
}


// 主函数----------------------------------------------------------------------------------------------------------------------------


int main() {
    
    PriorityQueue H;
    
    H = Initialize(20);
    Insert(13, H);
    Insert(21, H);
    Insert(16, H);
    Insert(24, H);
    Insert(31, H);
    Insert(19, H);
    Insert(68, H);
    Insert(65, H);
    Insert(26, H);
    Insert(32, H);
    
    Heap_print(H);
    
    DeleteMin(H);
    Heap_print(H);
    
    return 0;
}



