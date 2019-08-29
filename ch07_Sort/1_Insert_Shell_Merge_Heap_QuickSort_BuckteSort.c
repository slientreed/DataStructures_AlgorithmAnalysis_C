//
//  main.c
//  DataStructures
//
//  Created by mark on 2019/8/28.
//  Copyright © 2019年 mark. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define ElementType int
void Swap(int *a, int *b);

// 1. 插入排序：----------------------------------------------------------------------------------------------------------------------------

// 1. 插入排序：两层遍历，第二层每次从当前值前面找要插入的位子；因为前面的已经有序，如果前一个大于当前值，则前一个往后移，如果找到比当前值小的，当前值插入该位置。
void InsertSort(ElementType A[], int N)
{
    int j, pos;
    ElementType temp;
    
    for(pos = 1; pos < N; ++pos)     // 第一层往后遍历，保证每个往前的元素都是有序的
    {
        temp = A[pos];
        for(j = pos; j > 0 && A[j - 1] > temp; --j)       // 第二层：当前待插入值往前比较，如果前一个元素比当前元素大，则往后移;否则如果找到比当前值小的元素，则插入该元素后面即可
            A[j] = A[j - 1];
        A[j] = temp;                // 插入该元素
    }
}



// 2. 希尔排序：----------------------------------------------------------------------------------------------------------------------------

// 2. 希尔排序，每一趟通过比较一定间隔的元素，使得间隔一定距离的这些元素有序；然后随着各趟比较所用间隔距离的减少，直到只比较相邻元素的最后一趟排序为止，此时整个数组都有序。
void ShellSort(ElementType A[], int N)
{
    int i, j, Increment;
    ElementType temp;
    
    for( Increment = N / 2; Increment > 0; Increment /= 2)        // 间隔每次减少，初始值为 N / 2
    {
        for(i = Increment; i < N; ++i)              // 从间隔的位置开始，进行插入排序，进行 N - Increment趟
        {
            temp = A[i];
            for(j = i; j >= Increment; j -= Increment)    // 每一趟保证相隔一定间隔的元素是有序的
            {
                if(temp < A[j - Increment])              // 插入排序：如果当前待插入元素小，则继续往前找插入位置
                    A[j] = A[j - Increment];
                else
                    break;                              // 找到位置，跳出循环，插入即可
            }
            A[j] = temp;
        }
    }
}



// 3. 堆排序：----------------------------------------------------------------------------------------------------------------------------

#define LeftChild(i) (2 * (i) + 1)         // 包含了0位置，所以左子树为 2i + 1;

// 3. 堆排序：使用数组，建一个二叉堆，发费时间O(n);然后执行DeleteM操作，每次O(log(n));
//    每次DeleteMin操作拿出的元素都放在最后，最终得到一个倒序的数组，即完成排序


// 调整函数：构建一个大堆，每次对堆调整，保持堆的性质
void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Temp;
    
    for(Temp = A[i]; LeftChild(i) < N; i = Child)   // 从根节点开始判断，循环根的性质
    {
        Child = LeftChild(i);
        if( Child != N - 1 && A[Child + 1] > A[Child] )    // 比较根节点的左右子节点的较大值
            Child++;
        if(Temp < A[Child])        // 如果当前节点小于子节点的较大值，子节点移动到根节点位置
            A[i] = A[Child];
        else                      // 否则，当前节点大于子节点的较大值，插入到当前即可
            break;
    }
    A[i] = Temp;      // 把当前值放入正确位置
}


// 堆排序函数
void HeapSort(ElementType A[], int N)
{
    int i;
    for(i = N / 2; i >= 0; --i)      // 构建一个最大堆：把原数组构建成存放最大堆的数组。这里是对二叉堆从下往上调整，N/2是最后一个根节点。
        PercDown(A, 0, N);
    for(i = N - 1; i > 0; --i)
    {
        Swap(&A[0], &A[i]);     // 把最大值放到数组最后
        PercDown(A, 0, i);      // 调整，找出(0,i)位置的最大值放入到0位置。
    }
}



// 4. 归并排序：----------------------------------------------------------------------------------------------------------------------------

// 4. 归并排序：分治的经典用法，把数组分成两块，然后对每块排序，把排序完的两块合并成一个，即可。
//    其中用到两个有序数组合并成一个有序数组的用法


void MSort(ElementType A[], ElementType TempArray[], int left, int right);
void Merge(ElementType A[], ElementType TempArray[], int Lpos, int Rpos, int RightEnd);

// 归并主函数
void MergeSort(ElementType A[], int N)
{
    ElementType* TempArray;
    
    TempArray = malloc(N * sizeof(ElementType));
    if(TempArray != NULL)
    {
        MSort(A, TempArray, 0, N - 1);
        free(TempArray);
    }
    else
    {
        printf("Space Error!");
        return;
    }
}

// 对数组分治，然后排序
void MSort(ElementType A[], ElementType TempArray[], int left, int right)
{
    int center;
    if(left < right)               // 对整个数组进行递归
    {
        center = left + (right - left) / 2;
        MSort(A, TempArray, left, center);        // 递归分组处理,直到剩下一个元素，然后执行合并Merge()函数，实现不断合并
        MSort(A, TempArray, center + 1, right);
        
        Merge(A, TempArray, left, center + 1, right); // 对分好的数组进行合并
    }
}


// 合并两个有序数组函数
void Merge(ElementType A[], ElementType TempArray[], int Lpos, int Rpos, int RightEnd)  // Lpos表示左半部分的开始，Rpos表示右半部分的开始
{
    int i, LeftEnd, NumElements, TempPos;
    
    LeftEnd = Rpos - 1;   // 左半边终点
    TempPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    
    // 合并两个有序数组,放到一个临时的有序数组中
    while( Lpos <= LeftEnd && Rpos <= RightEnd)
    {
        if(A[Lpos] <= A[Rpos])                    // 如果左半边第大，插入左半边的
            TempArray[TempPos++] = A[Lpos++];
        else                                      // 右半边大，插入右半边的
            TempArray[TempPos++] = A[Rpos++];
    }
    
    while(Lpos <= LeftEnd)                   // 如果左半边有剩余，插入其剩余元素
        TempArray[TempPos++] = A[Lpos++];
    while (Rpos <= RightEnd)                 // 如果右半边有剩余，插入其剩余元素
        TempArray[TempPos++] = A[Rpos++];
    
    // 从临时数组，把有序元素，复制到A数组中去
    for(i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TempArray[RightEnd];

}



// 5. 快速排序：----------------------------------------------------------------------------------------------------------------------------

/*
// 1.快排思路：也是一种分治的递归算法，由4步完成：
        1. S中元素个数是0或1，返回；
        2. 从S中选取一个元素v，作为枢纽元；
        3. 根据枢纽把S分成两部分，前一部分S1的元素都小于枢纽v的值，后一部分S2都大于枢纽v；
        4. 递归quicksort()S1，S2两部分。
 
 // 2. 快排细节：
        1. 枢纽元选取：如果选取第1个元素，如果是有序，则复杂度O(n^2)；最好随机选取/或者选择左边，右边，中间三个的平均值。
        2. 分割策略： 1. 把枢纽元和最后一个数据交换使得枢纽元离开要被分割的数据段。i从第1个元素开始，j从倒数第2个元素开始；
                    2. i向后移动，碰到比枢纽大的停住；j向前移动，碰到比枢纽小的停住；如果i,j都停住，则交换i,j的元素值；然后继续移动，直到i > j;
                    3. 最后一步是把枢纽元和i指向的元素交换，完成。
        3. 小数组问题：当一个数组过小，由于递归开销反而不如插入排序。所以当递归到小数组（大小看情况选择）时候，可选用插入排序完成。
*/

void Qsort(ElementType A[], int Left, int Right);


// 选取左边，中间，右边3个元素的平均值作为枢纽元，然后对这三者排序，返回枢纽值
ElementType Median3(ElementType A[], int Left, int Right)
{
    int center = (Left + Right) / 2;
    
    // 通过交换，保证 A[Left] <= A[center] <= A[Right];
    if(A[Left] > A[center])
        Swap(&A[Left], &A[center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[center] > A[Right])
        Swap(&A[center], &A[Right]);
    
    Swap(&A[center], &A[Right - 1]);      // 把枢纽元放到最后一个元素
    return A[Right - 1];
}



// 快排主程序
void QuickSort(ElementType A[], int N)
{
    Qsort(A, 0, N - 1);
}

// 快排核心函数，实现对数组的分割和递归调用
# define Cutoff (3)        // 当数组小于3，使用插入排序
void Qsort(ElementType A[], int Left, int Right)
{
    int i,j;
    ElementType pivot;
    
    if(Left + Cutoff <= Right)          // 当数组大于3时，进行快排；否则进行插入排序
    {
        pivot = Median3(A, Left, Right);
        
        i = Left + 1, j = Right - 2;    // 因为在返回枢纽的Mediman3函数中，最左边，最右边已经放到枢纽的对应位置了
        for(;i < j;)
        {
            while(A[i] < pivot){i++;}       //  分割策略：A[i]小于枢纽，i不断向后移动
            while(A[j] > pivot){j--;}       // A[j] 大于枢纽，j不断向前移动
    
              // 把书中修改了一下，意思一样
            if(i < j)                  // 如果i,j两者都停止，则交换A[i],A[j]
                Swap(&A[i], &A[j]);
            else
                break;
            
            // Swap(&A[i], &A[j]);
        }
        
        Swap(&A[i], &A[Right - 1]);    // 把枢纽值放回该放的地方，和i交换
        
        Qsort(A, Left, i - 1);       // 对左右两个子区间递归
        Qsort(A, i + 1, Right);
        
    }
    else
        InsertSort(A + Left, Right - Left + 1);
}




// 6. 桶排序：----------------------------------------------------------------------------------------------------------------------------
/*
 1. 桶排序思路：基于计数的排序方法，而不是和前面5个一样基于比较（基于比较有个下界是O(NlogN)。其思路是把N个数据分到有限数量M个桶内（桶内可以是链表/数组），在对每个桶的数据进行排序，最后把所有桶内有序的数据拼接在一起，就组成了有序的数据。复杂度是O(M + N).M的复杂度主要来自每个桶内数据的排序，当M = N时，每个桶内数据不用排序，最快O(N).
 
 2. 步骤：1. 选取固定数量的空桶；
         2. 把数据分到对应的桶中，并记录桶的内数据数量；
         3. 对桶内数量不为0的数据排序，使得每个桶内数据有序；
         4. 对所有桶进行拼接，形成有序数据。
 
 3. 参考：https://blog.csdn.net/hitwhylz/article/details/9987367
 */


// 返回未排序数组的最大元素值
int getMaxVal(ElementType Arr[], int N)
{
    int maxVal = Arr[0];
    for(int i = 1; i < N; ++i)
    {
        if(Arr[i] > maxVal)
            maxVal = Arr[i];
    }
    
    return maxVal;
}


// 桶排序函数
void BucketSort(ElementType Arr[], int N)
{
    int BucketLen = getMaxVal(Arr, N) + 1;      // 桶的大小
    int BucketArr[BucketLen];   // 创建桶
    for(int i = 0; i < BucketLen; ++i)    // 初始化桶为0
        BucketArr[i] = 0;
    
    for(int i = 0; i < N; i++)       // 把数据一个一个放到桶中，Arr[i] = 桶的下标, 并记录桶的内的个数
        BucketArr[ Arr[i] ]++;
    
    int j = 0;
    for(int i = 0; i < BucketLen; i++)      // 再把桶的下标按顺序放回原数组，完成排序
    {
        while(BucketArr[i] != 0)           // 如果桶下标对应数据个数不为0，则把下标放到原数组，完成排序
        {
            Arr[j++] = i;
            BucketArr[i]--;
        }
    }
        
}



// 辅助函数----------------------------------------------------------------------------------------------------------------------------

// 打印数组
void PrintArray(ElementType A[], int len)
{
    if(len == 0) return;
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


// 交换函数
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


// 主函数----------------------------------------------------------------------------------------------------------------------------


int main() {
    
    printf("1.插入排序测试：----------------\n");
    ElementType A[] = {34, 8, 64, 51, 32, 21};
    printf("排序前：");
    PrintArray(A, 6);
    
    InsertSort(A, 6);
    printf("排序后：");
    PrintArray(A, 6);
    printf("\n");
    
    printf("2. 希尔排序测试：------------------\n");
    ElementType B[] = {81,94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    printf("排序前：");
    PrintArray(B, 13);
    
    ShellSort(B, 13);
    printf("排序后：");
    PrintArray(B, 13);
    printf("\n");
    
    printf("3. 堆排序测试：------------------\n");
    ElementType C[] = {97, 53, 59, 26, 41, 58, 31};
    printf("排序前：");
    PrintArray(C, 7);
    
    ShellSort(C, 7);
    printf("排序后：");
    PrintArray(C, 7);
    printf("\n");
    
    
    printf("4. 归并排序测试：------------------\n");
    ElementType D[] = {1, 13, 24, 26, 2, 15, 27, 38};
    printf("排序前：");
    PrintArray(D, 8);
    
    MergeSort(D, 8);
    printf("排序后：");
    PrintArray(D, 8);
    printf("\n");
    
    
    printf("5. 快速排序测试：------------------\n");
    ElementType E[] = {8, 1, 4, 9, 6, 3, 5, 2, 7, 0};
    printf("排序前：");
    PrintArray(E, 10);
    
    QuickSort(E, 10);
    printf("排序后：");
    PrintArray(E, 10);
    printf("\n");
    
    
    printf("6. 桶排序测试：------------------\n");
    ElementType F[] = {8, 4, 2, 3, 5, 1, 6, 9, 0, 7};
    printf("排序前：");
    PrintArray(F, 10);
    
    BucketSort(F, 10);
    printf("排序后：");
    PrintArray(F, 10);
    printf("\n");
    
    
    return 0;
}



