//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/23.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 1.散列函数----------------------------------------------------------------------------------------------------------------------------
typedef unsigned int Index;
typedef Index Position;

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

// 2.2 开放定址法： 如果有冲突产生，就尝试另外的单元，直到找出空的单元为止。使用平方探测：h(x) = (Hash(x) + F(i)) mod TableSize;

#define ElementType int
#define MinTableSize 10

struct HashTbl;
typedef struct HashTbl* HashTable;


HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable T);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
void Delete(ElementType Key, HashTable H);
HashTable Rehash(HashTable H);              // 再散列，扩大新的散列表

int isPrime(unsigned int n);
int NextPrime(int n);


// .c文件----

enum KindOfEntry{ Legitimate, Empty, Deleted};          // 用于标记当前hash值的状态

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell* TheCells;             // *TheCell是一个HashEntry结构体的数组指针，需要初始化时开辟
};


// Hash初始化
HashTable InitializeTable( int TableSize )
{
    HashTable H;
    
    if( TableSize < MinTableSize )
    {
        printf("Table is Small!");
        return NULL;
    }
    
    // 分配Hash
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        printf("Space Error!");
    
    H->TableSize = NextPrime(TableSize);
    
    // 分配Hash数组
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if(H->TheCells == NULL)
        printf("Space Error!");
    
    for(int i = 0; i < H->TableSize; ++i)
        H->TheCells[i].Info = Empty;
    
    return H;
}


// 查找函数，如果存在返回key在散列中的位置；如果不出现，返回最后的单元。
Position Find(ElementType Key, HashTable H)
{
    Position cur_pos;
    int coll_num = 0;
    
    cur_pos = Hash_4(Key, H->TableSize);
    while( H->TheCells[cur_pos].Info != Empty && H->TheCells[cur_pos].Element != Key )
    {
        cur_pos += 2 * ++coll_num - 1;        // 平方探测的快速计算：F(i) = F(i - 1) + 2i - 1;
        if(cur_pos >= H->TableSize)
            cur_pos -= H->TableSize;
    }
    
    return cur_pos;
}


// 插入，如果key已经存在，就什么也不做。否则把key插入Find()找到的地方
void Insert(ElementType Key, HashTable H)
{
    Position pos;
    
    pos = Find(Key, H);
    if(H->TheCells[pos].Info != Legitimate)      // 如果当前查找位置可以插入
    {
        H->TheCells[pos].Info = Legitimate;      // 标志位
        H->TheCells[pos].Element = Key;
    }
}


// 删除值
void Delete(ElementType Key, HashTable H)
{
    Position pos;
    
    pos = Find(Key, H);
    if(H->TheCells[Key].Info == Legitimate)
    {
        H->TheCells[Key].Info = Empty;         // 修改标志位即可，懒惰删除
    }
}



// 再散列函数，把散列表扩大为原表二倍的素数大小
HashTable Rehash(HashTable H)
{
    int i, OldSize;
    Cell* OldCell;
    
    OldCell = H->TheCells;      // Hash指针
    OldSize = H->TableSize;
    
    H = InitializeTable(2 * OldSize);     // 重新初始化一个Hash
    
    for(i = 0; i < OldSize; ++i)
    {
        if(OldCell[i].Info == Legitimate)      // 插入旧表元素
            Insert(OldCell[i].Element, H);
    }
    
    free(OldCell);
    
    return H;
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
    printf("H->TableSize: %d \n", H->TableSize);
    
    for(int i = 0; i < H->TableSize; i++)
    {
        if(H->TheCells[i].Info == Legitimate)
            printf("H->TheCells[%d]: %d \n", i, H->TheCells[i].Element);
        else
            printf("H->TheCells[%d]:\n",i);
    }
    
    printf("\n");
    
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
    printf("%d \n", H->TheCells[temp].Element);
    
    Delete(2, H);
    Hash_print(H);
    
    return 0;
}



