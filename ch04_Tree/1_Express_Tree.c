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



// 定义树节点结构

struct BinaryTreeNode;
typedef struct BinaryTreeNode* pTreeNode;

struct BinaryTreeNode
{
    union     // 可以存储运算符和数字
    {
        char operation;
        int num;
    };
    
    pTreeNode Left;
    pTreeNode Right;
};



// 栈结构和操作定义----------------------------------------------------------------------------------------------------------------------------

#define ElementType pTreeNode
struct Node;
typedef struct Node* pNode;
typedef pNode Stack;

int IsEmpty(Stack s);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void pop(Stack s);


// 定义树栈，存放树节点
struct Node
{
    ElementType Element;
    pNode Next;
}*pN;


// 判空
int IsEmpty(Stack s)
{
    return s->Next == NULL;
}

// 创建一个空栈
Stack CreateStack(void)
{
    Stack s;
    s = malloc(sizeof(struct Node));
    if(s == NULL)
        printf("Out of Space!");
    
    s->Next = NULL;
    MakeEmpty(s);
    return s;
}


// 清空栈
void MakeEmpty(Stack s)
{
    if(s == NULL)
        return;
    else
        while (!IsEmpty(s)) {
            pop(s);
        }
}

// 压栈
void Push(ElementType x, Stack s)
{
    pNode tempNode = malloc(sizeof(struct Node));
    if(tempNode == NULL)
    {
        printf("Out of Space!");
        return;
    }
    else
    {
        tempNode->Element = x;
        tempNode->Next = s->Next;
        s->Next = tempNode;           // 每次入栈，放入头节点的下一个
    }
}

// 返回栈顶元素
ElementType Top(Stack s)
{
    if(!IsEmpty(s))
    {
        return s->Next->Element;
    }
    else
    {
        printf("Empty Stack!");
        return 0;
    }
}

// 出栈
void pop(Stack s)
{
    pNode tempNode;
    if(IsEmpty(s))
    {
        printf("Empty Stack!");
        return;
    }
    else
    {
        tempNode = s->Next;
        s->Next = s->Next->Next;
        free(tempNode);
    }
}



// 生成树实现----------------------------------------------------------------------------------------------------------------------------


// 创建后缀表达式
// 当前字符是操作数：生成树节点，入栈；
// 操作符：作为根，从栈弹出两个节点，生成新树，入栈。

pTreeNode CreateExpressTree(char* str, Stack s)     // 参数为后缀字符串和栈
{
    int i = 0;
    pTreeNode temp, left, right;
    
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            temp = (pTreeNode)malloc(sizeof(struct BinaryTreeNode));
            temp->num = str[i] - '0';
            temp->Left = NULL;
            temp->Right = NULL;
            Push(temp, s);
        }
        else
        {
            temp = (pTreeNode)malloc(sizeof(struct BinaryTreeNode));
            temp->operation = str[i];
            right = Top(s);            // 先出栈的是右孩子
            pop(s);
            left = Top(s);
            pop(s);
            temp->Left = left;
            temp->Right = right;
            Push(temp, s);
        }
        
        i++;
    }
    
    return Top(s);
}


// 树的辅助函数----------------------------------------------------------------------------------------------------------------------------

// 访问节点
void visit(pTreeNode p)
{
    if(p->Left == NULL && p->Right == NULL)
        printf("%d", p->num);
    else
        printf("%c", p->operation);
}

// 树的后序遍历
void PostOrder(pTreeNode p)
{
    if(p!=NULL)
    {
        PostOrder(p->Left);
        PostOrder(p->Right);
        visit(p);
    }
}

// 中序遍历
void InOrder(pTreeNode p)
{
    if(p!=NULL)
    {
        PostOrder(p->Left);
        visit(p);
        PostOrder(p->Right);
    }
}

// 先序遍历
void PreOrder(pTreeNode p)
{
    if(p!=NULL)
    {
        visit(p);
        PostOrder(p->Left);
        PostOrder(p->Right);
    }
}




// 主函数----------------------------------------------------------------------------------------------------------------------------

int main() {
    
    
    pTreeNode express_tree;
    Stack s;
    
    char str[100];
    printf("请输入字符串：");
    scanf("%s", str);
    //printf("%s \n", str);
    
    s = CreateStack();
    express_tree = CreateExpressTree(str, s);
    
    
    printf("前缀表达式是：");
    PreOrder(express_tree);
    printf("\n");
    
    printf("中缀表达式是：");
    InOrder(express_tree);
    printf("\n");
    
    
    printf("后缀表达式是：");
    PostOrder(express_tree);
    printf("\n");
    
    return 0;
}



