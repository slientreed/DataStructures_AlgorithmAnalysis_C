//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/19.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// .h文件，函数数据声明----------------------------------------------------------------------------------------------------------------------------

#define ElementType int

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};


AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FinMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);

static int GetHight(AvlTree T);

// 辅助函数，返回较大值
int Max(ElementType a, ElementType b)
{
    if(a > b)
        return a;
    else
        return b;
}

// .c文件，函数原型实现----------------------------------------------------------------------------------------------------------------------------

// 建立空树，清除树
AvlTree MakeEmpty(AvlTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}


// 查找指定元素
AvlTree Find(ElementType X, AvlTree T)
{
    if(T == NULL)
        return NULL;
    
    if(X < T->Element)
        return Find(X, T->Left);
    else if(X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}


// 查找最小值,递归
AvlTree FindMin(AvlTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

// 查找最大值，循环
AvlTree FindMax(AvlTree T)
{
    if(T != NULL)
        while (T->Right != NULL) {
            T = T->Right;
        }
    return T;
}


// 返回高度
static int GetHight(AvlTree T)
{
    if(T == NULL)
        return -1;
    else
        return T->Height;
}


// 旋转恢复函数----------------------------------------------------------------------------------------------------------------------------

// 左左单旋，往节点T的左子树增加左节点，使得T不平衡
static AvlTree SingleRotateWithLeft(AvlTree k2)
{
    AvlTree k1;
    
    k1 = k2->Left;      // k1一定是k2的左子树，把k2变成k1右子树
    k2->Left = k1->Right;
    k1->Right = k2;
    
    k2->Height = Max(GetHight(k2->Left), GetHight(k2->Right)) + 1;    // 更新k1，k2的高度
    k1->Height = Max(GetHight(k1->Left), k2->Height) + 1;
    
    return k1;         // k1变成根
}


// 右右单旋，往节点T的右子树增加右节点，使得T不平衡
static AvlTree SingleRotateWithRight(AvlTree k2)
{
    AvlTree k1;
    
    k1 = k2->Right;         // k1是k2的右子树，把k2变成k1左子树
    
    printf("%d \n",k1->Element);
    
    k2->Right = k1->Left;
    k1->Left = k2;
    
    k2->Height = Max(GetHight(k2->Left), GetHight(k2->Right)) + 1;
    printf("树高：%d\n", k2->Height);
    
    k1->Height = Max(k2->Height, GetHight(k1->Right)) + 1;
    printf("跟树高：%d \n", k1->Height);
    
    return k1;
}


// 左右双旋， k3的左子树k1,k1的右子树k2产生的不平衡。先对k1,k2进行右右单旋，再对k2,k3左左单旋；最终k2为根节点
static AvlTree DoubleRotateWithLeft(AvlTree k3)
{
    k3->Left = SingleRotateWithRight(k3->Left);       // 先对k3左子树k1进行右右单旋
    
    return SingleRotateWithLeft(k3);              // 在对k3进行左左单旋
}


// 右左双旋：k3的右子树k1, k1的左子树k2产生不平衡。先对k1,k2进行左左单旋，再对k3，k2进行右右单旋；最终k2位根节点
static AvlTree DoubleRotateWithRight(AvlTree k3)
{
    k3->Right = SingleRotateWithLeft(k3->Left);   // 先对k3左子树k1进行左左单旋
    
    return SingleRotateWithRight(k3);             // 再对k3进行右右单旋
}


// 函数----------------------------------------------------------------------------------------------------------------------------


// 插入函数，注意调整
AvlTree Insert(ElementType X, AvlTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct AvlNode));
        if(T == NULL)
        {
            printf("Space Error!");
            return NULL;
        }
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if(X < T->Element)
    {
        T->Left = Insert(X, T->Left);         // 不断递归向左子树插
        
        if(GetHight(T->Left) - GetHight(T->Right) == 2)        // 在T的左子树插入，左子树插入引起不平衡，要么是左右双旋，要么左左单旋
        {
            if(X < T->Left->Element)               // 插入值小于T左子树，插入左边，左左单旋；
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);      // 在不平衡的右边插入，要左右双旋；
        }
    }
    else if(X > T->Element)
    {
        T->Right = Insert(X, T->Right);       // 不断递归向右子树插入
        
        // 向右子树插入，引起右子树高度大，不平衡；如果插入最后右子树的左子树 - 右左双旋，如果插入最后右子树的右子树 - 右右单旋
        if(GetHight(T->Right) - GetHight(T->Left) == 2)
        {
            if(X > T->Right->Element)           // 插入右边，右右单旋
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);    // 插入左边，右左双旋
        }
    }
    
    T->Height = Max(GetHight(T->Left), GetHight(T->Right)) + 1;         // 更新高度
    return T;
    
}



// 删除节点。首先是找到节点，类似二叉查找树删除，三种情况：2个孩子，1个孩子，或者没有孩子。判断是否会引起不平衡，如果会，调整至删除不会引起不平衡；
AvlTree Delete(ElementType X, AvlTree T)
{
    AvlTree TempNode;
    
    if(T == NULL)
    {
        printf("No Found!");
        return NULL;
    }
    else if(X < T->Element)
    {
        T->Left = Delete(X, T->Left);
        if(GetHight(T->Right) - GetHight(T->Left) == 2)     // 删除左子树的，引起不平衡，右左双旋，或者右右单旋
        {
            AvlTree temp = T->Right;
            if(GetHight(temp->Right) > GetHight(temp->Left))    // T右子树的右子树高，右右单旋T即可
                T = SingleRotateWithRight(T);
            else                                     // 否则要右左双旋，先调整左边，在向上调整右边
                T = DoubleRotateWithRight(T);
                
        }
    }
    else if(X > T->Element)
    {
        T->Right = Delete(X, T->Right);
        if(GetHight(T->Left) - GetHight(T->Right) == 2)      // 删除右子树节点，引起不平衡；左右双旋，或者左左单旋
        {
            AvlTree temp = T->Left;
            if(GetHight(temp->Left) > GetHight(temp->Right))   // T左子树的左子树高，左左单旋即可
                SingleRotateWithLeft(T);
            else                                             // T左子树的右子树高，双旋，先右右单旋，再左左单旋
                DoubleRotateWithLeft(T);
        }
    }
    
    //下里说明找到节点，进行3种情况判断，进行删除节点,懒惰删除法（用左子树最大孩子或者右子树最小孩子代替）
    else if(T->Left && T->Right)           // 情况3： 有2个孩子
    {
        if(GetHight(T->Right) > GetHight(T->Left))   // 右子树高，用右子树最小孩子代替;因为最小孩子一定没有左孩子，方便删除。
        {
            TempNode = FindMin(T->Right);
            T->Element = TempNode->Element;
            T->Right = Delete(T->Element, T->Right);   // 递归删子节点，变成情况1或2,有1个或者0个孩子，直接删
        }
        else
        {
            TempNode = FindMax(T->Left);           // 左子树高，找左子树最大值代替
            T->Element = TempNode->Element;
            T->Left = Delete(T->Element, T->Left);
        }
    }
    else                 // 情况1，2： 有1个或者0个孩子，直接删/用存在的孩子代替
    {
        TempNode = T;
        if(T->Left)
            T = T->Left;
        else if(T->Right)
            T = T->Right;
        else
            T = NULL;
        
        free(TempNode);
    }
    
    return T;
}





// 辅助函数----------------------------------------------------------------------------------------------------------------------------

// 中序遍历
void InOrder(AvlTree T)
{
    if(T != NULL)
    {
        InOrder(T->Left);
        printf("%d ", T->Element);
        InOrder(T->Right);
    }
}


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    AvlTree T = malloc(sizeof(struct AvlNode));
    T->Element = 4;
    T->Height = 0;
    T->Left = NULL;
    T->Right = NULL;
     
    //AvlTree T = NULL;
    //Insert(4, T);
    
    T = Insert(1, T);
    InOrder(T);
    printf("\n");
    
    T = Insert(2, T);
    InOrder(T);
    printf("\n");
    
    T = Insert(3, T);
    InOrder(T);
    printf("\n");
    
    T = Insert(5, T);
    InOrder(T);
    printf("\n");
    
    T = Insert(6, T);
    InOrder(T);
    printf("\n");
    
    T = Insert(7, T);
    //Insert(7, T);
    
    InOrder(T);
    printf("\n");
    
    Delete(5, T);
    InOrder(T);
    printf("\n");
    
    return 0;
}



