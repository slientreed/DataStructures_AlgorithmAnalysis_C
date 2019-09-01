//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/31.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


// 不相交集（并查集）----------------------------------------------------------------------------------------------------------------------------

/*
 1. 树形数据结构，用于处理不相交集合的合并和查找。主要解决动态连通性，判断两个点是否连通。
 2. Find操作： 返回包含给定元素的集合的名字；
    Union操作：添加关系，如果a,b不在一个集合，使用Union操作把包含a,b的两个类合并为一个新的等价类。（去掉原来两个集合保持的不相交性）
 
 3. 数据结构：使用树结构表示每个集合，root表示每个集合名。Find操作返回root名；Union合并两个数，把一个数的根指向另一个树的root节点。
 
 */



# ifndef _DisjSet_H

#define NumSets 100
typedef int DisjSet[NumSets + 1];     //
typedef int SetType;
typedef int ElementType;


void Initilialize(DisjSet S);
void SetUnion(DisjSet S, SetType root1, SetType root2);
SetType Find(ElementType X, DisjSet S);

# endif



// 下面放在.c文件中

// 初始化例程，初始化为0,表示是根节点
void Initialize(DisjSet S)
{
    for(int i = NumSets; i > 0; i--)
        S[i] = 0;
}


// Union操作，直接把root2作为root1的子节点。有可能会使得树深度很大，查询效率不高（不是最好的）
void SetUnion(DisjSet S, SetType root1, SetType root2)
{
    S[root2] = root1;
}

// 查找操作，直接查找
SetType Find(ElementType X, DisjSet S)
{
    if(S[X] <= 0)    // root节点，表示某一集合，返回即可
        return X;
    else
        return Find(S[X], S);      // 继续以父节点值向上寻找
}



// 优化：----------------------------------------------------------------------------------------------------------------------------


// 把树的深度小的节点，插入深的节点，这样可以降低树深，减少Find复杂度。每个数组内的值如果为0则表示是root，如果为负值，则表示深度。
void SetUnion_Height(DisjSet S, SetType root1, SetType root2)
{
    if(S[root2] < S[root1])      // 深度小的root作为子节点
        S[root1] = root2;
    else
    {
        if(S[root1] == S[root2])  // 两个数高度相等，随便选取一个作为root，高度减1，更新高度
            S[root1]--;
        S[root2] = root1;
    }
}


// 查找操作时，进行路径压缩。从X到根的路径上的每一个节点都使它的父节点变成根。
// 代码中改变不大，只需要改变S[x]为Find()的返回值。
SetType Find_Path(ElementType X, DisjSet S)
{
    if(S[X] <= 0)
        return X;
    else
        return S[X] = Find(S[X], S);    // 把X路径上的节点的父节点变成根，降低树的高度
}




// 主函数----------------------------------------------------------------------------------------------------------------------------


int main() {
    
    DisjSet S;
    Initialize(S);
    
    SetUnion(S, 5, 6);
    SetUnion(S, 5, 7);
    
    printf("%d \n",Find(6, S) == Find(7, S));
    printf("%d \n",Find(2, S));
    
    
    return 0;
}



