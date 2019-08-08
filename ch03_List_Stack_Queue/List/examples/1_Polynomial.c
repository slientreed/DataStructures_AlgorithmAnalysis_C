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

// 3.2.2. 链表的例子:


// 1.多项式ADT----------------------------------------------------------------------------------------------------------------------------
// 使用链表存储系数，进行多项式运算

//1. 简单数组实现

#define MaxDegree 10
typedef struct Pol
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;


// 辅助函数
int max(int a, int b)
{
    return a > b ? a : b;
}


// 多项式初始化为0
void ZeroPolynomial(Polynomial poly)
{

    for(int i = 0; i < MaxDegree; i++)
        poly->CoeffArray[i] = 0;
    
    poly->HighPower = 0;
    
}

// 两个多项式相加
void AddPolynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polySum)
{
    ZeroPolynomial(polySum);
    polySum->HighPower = max(poly1->HighPower, poly2->HighPower);
    
    for(int i = polySum->HighPower; i >= 0; i--)
        polySum->CoeffArray[i] = poly1->CoeffArray[i] + poly2->CoeffArray[i];
}

// 两个多项式相乘
void MulPolynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polyProd)
{
    int i ,j;
    ZeroPolynomial(polyProd);
    polyProd->HighPower = poly1->HighPower + poly2->HighPower;
    
    if(polyProd->HighPower > MaxDegree)
        printf("Exceeded array size");
    
    for(i = 0; i <= poly1->HighPower; i++)
        for(j = 0; j <= poly2->HighPower; j++)
            polyProd->CoeffArray[i + j] += poly1->CoeffArray[i] * poly2->CoeffArray[j];
}


// 2. 链表实现

struct Node;
typedef struct Node *pNode;
typedef pNode PolynList;

struct Node
{
    int Coefficient;      // 系数
    int Exponent;        // 幂数
    pNode Next;          // 下一项指针
};


// 初始化
void ZeroPoly(PolynList poly)
{
    poly->Coefficient = 0;
    poly->Exponent = 0;
    poly->Next = NULL;
}


// 找到前一个节点
pNode FindPrev(pNode node, PolynList poly)
{
    pNode tempNode;
    tempNode = poly;
    while(tempNode->Next != node)
        tempNode = tempNode->Next;
    
    return tempNode;
}


// 把节点插入合适的位置,在插入过程合并同类项
void InsertNode(pNode InNode, PolynList poly)
{
    
    pNode tempNode;
    pNode insertNode = malloc(sizeof(struct Node));   // 创建节点表示带插入节点
    ZeroPoly(insertNode);
    insertNode->Coefficient = InNode->Coefficient;
    //printf("%d \n", insertNode->Coefficient);
    insertNode->Exponent = InNode->Exponent;
    
    tempNode = poly->Next;
    if(tempNode == NULL)
        poly->Next = insertNode;
    
    while(tempNode != NULL)
    {
        if(InNode->Exponent == tempNode->Exponent)   // 如果带插入节点幂数和当前节点幂数相同
        {
            tempNode->Coefficient += InNode->Coefficient;
            break;
        }
        
        if(InNode->Exponent < tempNode->Exponent)    // 如果当前比较节点大于待插入节点，插入当前节点前面
        {
            tempNode = FindPrev(tempNode, poly);
            insertNode->Next = tempNode->Next;
            tempNode->Next = insertNode;
            break;
        }
        
        if(tempNode->Next == NULL)
        {
            tempNode->Next = insertNode;
            break;
        }
        
        tempNode = tempNode->Next;           // 向后移动，直到找到比待插入节点大的节点
    }
    
}


// 两个多项式相加
PolynList SumPoly(const PolynList poly1, const PolynList poly2)
{
    PolynList sumPoly = malloc(sizeof(struct Node));
    ZeroPoly(sumPoly);
    
    pNode pNode1, pNode2;
    pNode1 = poly1->Next;
    pNode2 = poly2->Next;
    
    while(pNode1 != NULL)
    {
        InsertNode(pNode1, sumPoly);
        pNode1 = pNode1->Next;
    }
    while(pNode2 != NULL)
    {
        InsertNode(pNode2, sumPoly);
        pNode2 = pNode2->Next;
    }
    
    return sumPoly;
}

// 两个多项式相乘
PolynList MultiPoly(const PolynList poly1, const PolynList poly2)
{
    PolynList multiPoly = malloc(sizeof(struct Node));
    ZeroPoly(multiPoly);
    
    pNode node1, node2, tempNode;
    node1 = poly1->Next;
    node2 = poly2->Next;
    tempNode = malloc(sizeof(struct Node));
    
    while(node1 != NULL)
    {
        while (node2 != NULL)
        {
            tempNode->Coefficient = node1->Coefficient * node2->Coefficient;
            tempNode->Exponent = node1->Exponent + node2->Exponent;
            InsertNode(tempNode, multiPoly);
            node2 = node2->Next;
        }
        
        node2 = poly2->Next;   //   再次从头开始相乘一遍
        node1 = node1->Next;
    }
    
    return multiPoly;
}


// 生成多项式.
PolynList makePloy()
{
    int coe, expo;
    PolynList head;   // 记录多项式的头指针
    PolynList cur;    // 记录当前多项式节点指针
    
    head = malloc(sizeof(struct Node));
    head->Next = NULL;
    cur = head;
    
    while(scanf("%d %d", &coe, &expo) == 2)
    {
        PolynList poly = malloc(sizeof(struct Node));
        poly->Coefficient = coe;
        poly->Exponent = expo;
        
        cur->Next = poly;      // cur指向当前插入节点，开始往后连接，行程链表
        cur = poly;
    }
    cur->Next = NULL;
    
    return head;             // 返回最开始的头结点
}

// 打印多项式
void display(PolynList head)
{
    PolynList poly;
    poly = head->Next;
    
    while(poly != NULL)
    {
        printf("%dx^%d + ", poly->Coefficient, poly->Exponent);
        poly = poly->Next;
    }
    
    putchar('\n');
}


// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    /*
     // 1.数组型测试
    Polynomial a = malloc(sizeof(struct Pol));
    ZeroPolynomial(a);
    a->HighPower = 2;
    for(int i = 0; i < 3; i++)
        a->CoeffArray[i] = i;
    
    Polynomial b = malloc(sizeof(struct Pol));
    ZeroPolynomial(b);
    b->HighPower = 2;
    for(int i = 0; i < 3; i++)
        b->CoeffArray[i] = i;
    
    Polynomial sum = malloc(sizeof(struct Pol));
    MulPolynomial(a, b, sum);

    for(int i = 0; i <= a->HighPower + b->HighPower; i++)
        printf("%d ", sum->CoeffArray[i]);
    
    printf("\n");
    */
    
    
    // 2. 链表实现测试
    PolynList poly1,poly2;
    
    poly1 = makePloy();
    printf("第一个多项式是：");
    display(poly1);
    
    while(getchar() != '\n')  // putchar()从标准输入流中读入字符，整个循环目的是清空之前的输入缓冲区，\n换行符之前的字符都被丢弃。
        continue;
    poly2 = makePloy();
    printf("第二个多项式是：");
    display(poly2);
    
    // 多项式相加
    PolynList polySum = malloc(sizeof(struct Node));
    ZeroPoly(polySum);
    polySum = SumPoly(poly1, poly2);
    printf("两个多项式相加是：");
    display(polySum);
    
    // 多项式相乘
    PolynList polyMul = malloc(sizeof(struct Node));
    ZeroPoly(polyMul);
    polyMul = MultiPoly(poly1, poly2);
    printf("多项式相乘是：");
    display(polyMul);
    
    return 0;
}



