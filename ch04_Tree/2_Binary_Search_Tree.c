//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/14.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ElementType int

struct TreeNode;
typedef struct TreeNode* position;
typedef struct TreeNode* SearchTree;


SearchTree MakeEmpty(SearchTree T);
position Find(ElementType X, SearchTree T);
position FindMin(SearchTree T);
position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);


struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};


// 建立一个空树
SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    
    return NULL;
}


// 查找操作，返回具有关键字X的节点的指针
position Find(ElementType X, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(X < T->Element)
        return Find(X, T->Left);
    if(X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}


// 查找最小值，从根开始，有左儿子不断向左；递归
position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);      // 递归左孩子的左孩子
}


// 查找最大值，从根开始，右孩子不断向右
position FindMax(SearchTree T)
{
    if(T != NULL)
    {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    return T;
}


// 插入操作，如果已存在什么也不做（也可以记录重复值）
SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));    // 生成一个树节点
        if(T == NULL)
        {
            printf("Space Error!");
            return 0;
        }
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->Element)
            T->Left = Insert(X, T->Left);
    else if(X > T->Element)
            T->Right = Insert(X, T->Right);
    
    return T;
}


// 删除节点，三种情况：叶子节点，有1个孩子，2个孩子；
SearchTree Delete(ElementType X, SearchTree T)
{
    position temp;
    
    if(T == NULL)
    {
        printf("Space Error!");
        return 0;
    }
    
    if(X < T->Element)
        T->Left = Delete(X, T->Left);     // 递归左子树
    else if( X > T->Element)
        T->Right = Delete(X, T->Right);
    else
    {
        if(T->Left && T->Right)     // 3. 如果当前节点有两个孩子，找右子树最小节点代替（其一定没有左孩子），并删除
        {
            temp = FindMin(T->Right);
            T->Element = temp->Element;
            T->Right = Delete(T->Element, T->Right);    // 删除右子树最小节点，一定没有左孩子，一个孩子
        }
        else                    // 2. 有0个或者1个孩子情况
        {
            temp = T;
            if(T->Left == NULL)
                T = T->Right;
            else if(T->Right == NULL)
                T = T->Left;
            
            free(temp);
        }
    }
    
    return T;
}


// 辅助函数----------------------------------------------------------------------------------------------------------------------------

// 中序打印排序树(有序输出)
void PrintTree(SearchTree T)
{
    if(T == NULL)
        return ;
    
    PrintTree(T->Left);
    printf("%d ", T->Element);
    PrintTree(T->Right);
}


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    SearchTree T = malloc(sizeof(struct TreeNode));
    T->Element = 6;
    T->Left = NULL;
    T->Right = NULL;
    Insert(2, T);
    Insert(8, T);
    Insert(1, T);
    Insert(4, T);
    Insert(3, T);
    Insert(5, T);
    PrintTree(T);
    printf("\n");
    
    Delete(2, T);
    PrintTree(T);
    printf("\n");
    
    return 0;
}



