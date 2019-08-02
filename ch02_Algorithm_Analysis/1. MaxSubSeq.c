//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/1.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>


// 问题：给定一个数组，求最大子序列。
// 书中给了四种方法，不断优化，O(n^3) , O(n^2), O(nlog(n)), O(n),见证算法的威力。


static int MaxSubSum(const int A[], int left, int right);

int Max3(int *a, int *b, int *c)
{
    if(*a < *b)
        *a = *b;
    if(*a < *c)
        *a = *c;
    
    return *a;
}


// 方法1：三重循环，找出所有的子数组，对比找出最大值。  O(n^3)
int MaxSubsequenceSum_Solu1(const int A[], int n)
{
    int CurSum, MaxSum, i, j, k;
    MaxSum = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            CurSum = 0;
            for(k = i; k <= j; k++)
                CurSum += A[k];           // 累加每个子数组，和当前最大值比较，如果大，更新最大值
            
            if(CurSum > MaxSum)
                MaxSum = CurSum;
        }
    
    return MaxSum;
}


// 方法2：二重循环，不用每次在内层循环继续循环，直接比较内层循环的较大值
int MaxSubsequenceSum_Solu2(const int A[], int n)
{
    int CurSum, MaxSum, i, j;
    MaxSum = 0;
    
    for(i = 0; i < n; i++)
    {
        CurSum = 0;
        for(j = i; j < n; j++)
        {
            CurSum += A[j];
            
            if(CurSum > MaxSum)      // 在每层循环内，找出最大子数组的值
                MaxSum = CurSum;
        }
    }
    return MaxSum;
}


// 方法3： 分治，递归策略。把数组分成两块，分别在然后分别在两块递归。
// 分治后，最大子序列出现在3处：1. 整个出现在数据左半部； 2. 整个出现在右半部分；3. 跨越中部，分别从中间一个元素往左右两边，找相连的包含最后一个元素最大值。最后这3个最大值相比较
// 时间复杂度： O(nlog(n)) , log(n)的复杂度来自于对数组的分块。

int MaxSubsequenceSum_Solu3(const int A[], int n)
{
    return MaxSubSum(A, 0, n - 1);
}

static int MaxSubSum(const int A[], int left, int right)
{
    
    int MaxLeftSum, MaxRightSum;             // 左右子数组最大值
    int MaxLeftBorderSum, MaxRightBorderSum;  // 跨越中间子数组最大值
    int LeftBorderSum, RightBorderSum;
    int center, i;
    
    if(left == right)
        if(A[left] > 0)          // 如果小于0，返回0
            return A[left];
        else
            return 0;
    
    center = left + (right - left) / 2;                         // 划分左右子数组，然后在左右子数组中递归
    MaxLeftSum = MaxSubSum(A, left, center);
    MaxRightSum = MaxSubSum(A, center + 1, right);
    
    MaxLeftBorderSum = 0; LeftBorderSum = 0;      // 从center往左边找连接的最大值
    for(i = center; i >= left; i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    
    MaxRightBorderSum = 0;RightBorderSum = 0;    // 从center往右边找相连的最大值
    for(i = center + 1; i <= right; i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    int sum_mid = MaxLeftBorderSum + MaxRightBorderSum;
    
    return Max3(&(MaxLeftSum), &(MaxRightSum), &(sum_mid));
}


// 方法4：联机算法，不断给出当前时刻的最大值。
// 思路：在判断当前累加和小于0，就舍弃掉这个子数组，从下个开始。

int MaxSubsequenceSum_Solu4(const int A[], int n)
{
    int CurSum = 0, MaxSum = 0,i;
    
    for(i = 0; i < n; i++)
    {
        CurSum += A[i];
        
        if(CurSum > MaxSum)        // 判断，更新MaxSum
            MaxSum = CurSum;
        else if(CurSum < 0)       // 如果当前子数组累加和小于0,则丢弃，重新累加
            CurSum = 0;
    }
    
    return MaxSum;
}



int main() {
    
    int arr[] = {-2,11,-4,13,-5,-2};
    
    int MaxValue = MaxSubsequenceSum_Solu4(arr, 6);
    printf("%d \n", MaxValue);
    
    return 0;
}
