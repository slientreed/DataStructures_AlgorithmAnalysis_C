//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/22.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 1.散列函数----------------------------------------------------------------------------------------------------------------------------
typedef unsigned int Index;

// 1.1 简单散列:把字符串中字符ASCII码值加起来。
Index Hash_1(const char* Key, int TableSize)
{
    unsigned int HashVal = 0;
    
    while (*Key != '\0') {
        HashVal += *Key++;           // 累加字符ASCII值
    }
    
    return HashVal % TableSize;              // 如果表很大，则表的利用率很低。
}


// 1.2 假设至少有两个字符组成
Index Hash_2(const char* key, int TableSize)
{
    return (key[0] + 27 * key[1] + 27 * 27 * key[2]) % TableSize;
}


// 1.3 涉及所有字符的公式。h = ((k3) * 32 + k2) * 32 + k1;    32是为了便于左移
Index Hash_3(const char* key, int TableSize)
{
    unsigned int HashVal = 0;
    
    while (*key != '\0')
    {
        HashVal = (HashVal << 5) + *key++;
    }
    
    return HashVal % TableSize;
}

// 散列函数：只有int型
Index Hash_4(const int key, int TableSize)
{
    unsigned HashVal = 0;
    int temp = key;
    if(temp == 0)
    {
        printf("the key is lower 0! \n");
        exit(-1);
    }
    while(temp != 0)
    {
        HashVal = (HashVal << 3) + temp % 10;
        temp /= 10;
    }
    
    return HashVal % TableSize;
}


// 2.解决冲突----------------------------------------------------------------------------------------------------------------------------

// 2.1 分离链接法：把散列到同一个值的元素保留到一个表中

#define ElementType int
#define MinTableSize 10

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
void Delete(ElementType key, HashTable H);


int isPrime(unsigned int n);
int NextPrime(int n);


struct ListNode
{
    ElementType Element;
    Position Next;
};


typedef Position List;
struct HashTbl
{
    int TableSize;      // 哈希表大小
    List* TheLists;    // 链表数组指针
};


// 初始化函数，返回H结构，包含一个整数和指向一个表的指针
HashTable InitializeTable(int TableSize)
{
    
    HashTable H;
    
    if(TableSize < MinTableSize)
    {
        printf("Table is too small!");
        return NULL;
    }
    
    // 开辟table
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
    {
        printf("Space Error!");
        return NULL;
    }
    
    H->TableSize = NextPrime(TableSize);      // 选一个素数作为TableSize
    
    // 分配数组链表
    H->TheLists = malloc(sizeof(List) * H->TableSize);      // 链表数组指针
    if(H->TheLists == NULL)
    {
        printf("Space Error!");
        return NULL;
    }
    
    
    // 分配链表头指针
    for(int i = 0; i < H->TableSize; ++i)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL)
        {
            printf("Space Error!");
            return NULL;
        }
        else
            H->TheLists[i]->Next = NULL;
    }
    
    return H;
}


// 查找函数,返回节点
Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    
    L = H->TheLists[Hash_4(Key, H->TableSize)];   // 找到hash对应的位置，L指向链表头结点
    P = L->Next;
    
    while (P != NULL && P->Element != Key)
    {
        P = P->Next;
    }
    return P;
}


// 插入例程
void Insert(ElementType Key, HashTable H)
{
    Position pos, NewCell;
    List L;
    
    pos = Find(Key, H);     // 如果已经存在则什么也不干
    if( pos == NULL )
    {
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL)
            printf("Spece Error!");
        else
        {
            L = H->TheLists[Hash_4(Key, H->TableSize)];    // 查找要插入的hash;
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}

// 删除对应值元素
void Delete(ElementType key, HashTable H)
{
    Position pos, front_cell, cur_cell;
    List L;
    
    pos = Find(key, H);
    if(pos != NULL)
    {
        L = H->TheLists[Hash_4(key, H->TableSize)];
        front_cell = L;
        while(front_cell->Next != NULL && front_cell->Next->Element != key)   // 在链表中找到key值节点
            front_cell = front_cell->Next;
        
        cur_cell = front_cell->Next;               // 删除节点，并free
        front_cell->Next = cur_cell->Next;
        free(cur_cell);
    }
    
}


// 辅助函数----------------------------------------------------------------------------------------------------------------------------

// 判断一个数是否是素数
int isPrime(unsigned int n)
{
    unsigned int i;
    if(n < 2)
        return -1;
    
    for(i = 2; i < n; ++i)
    {
        if(n % i == 0)
            return 0;
    }
    
    return 1;
}

// 求当前数的下一个素数
int NextPrime(int n)
{
    int i;
    for(i = n; ;++i)
    {
        if(isPrime(i) == 1)
            return i;
    }
    
    exit(-1);
}

// 打印hash表
void Hash_print(HashTable H)
{
    Position p;
    
    printf("H->TableSize: %d \n", H->TableSize);
    for(int i = 0; i < H->TableSize; ++i)
    {
        printf("H->TheLists[%d]:", i);
        p = H->TheLists[i];
        p = p->Next;
        while(p != NULL)
        {
            printf("%d ", p->Element);
            p = p->Next;
        }
        printf("\n");
    }
}


// 主函数----------------------------------------------------------------------------------------------------------------------------


int main() {
    
    
    HashTable H = NULL;
    H = InitializeTable(11);
    
    Insert(1, H);
    Insert(2, H);
    Insert(3, H);
    Insert(4, H);
    Insert(17, H);
    
    Hash_print(H);
    
    Position temp = Find(4, H);
    printf("找到：%d \n", temp->Element);
    
    Delete(2, H);
    Hash_print(H);
    
    return 0;
}



