//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/1.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>


// 2. 给了几个运行时间复杂度为对数的例子：O(log(n)):二分查找，欧几里得算法，幂运算


// 1. 二分查找
int BinarySearch(const int A[], int x, int n)
{
    int low, mid, high;
    
    low = 0; high = n - 1;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if( A[mid] < x)
            low = mid + 1;
        else if(A[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    
    return -1;
}

// 2. 欧几里得算法： 计算最大公因数， 辗转相除
int Gcd(int m, int n)
{
    int rem;
    
    while(n > 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }
    
    return m;
}

// 3. 幂运算 :  求 X^n次方
long int Pow(int x, int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(n & 1 == 0)         // n为偶数
        return Pow(x * x, n / 2);
    else
        return Pow(x * x, n / 2) * x;
        
}


// 一个例子程序，计算随机选取小于等于n的正整数互素的概率
void PosPrime(int n)
{
    int prime = 0;          // 素数的个数
    int sum = 0;           // 总数
    
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            sum++;
            if(Gcd(i, j) == 1)       // 如果两个数互素
                prime++;
        }
    
    printf("两个数互素的概率是： %f\n", (double)prime / sum);
}



int main() {
    
    //int arr[] = {3,4,6,8,11,-15};
    //int Value = BinarySearch(arr, 11, 6);
    
    /*
     // 2.
    printf("输入两个数:");
    int m, n;
    scanf("%d %d", &m, &n);
    int Value = Gcd(m, n);
    printf("%d \n", Value);
     */
    
    int n;
    printf("输入一个整数：");
    scanf("%d", &n);
    PosPrime(n);
    
    return 0;
}
