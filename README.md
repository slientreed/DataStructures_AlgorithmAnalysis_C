# DataStructures_AlgorithmAnalysis_C
数据结构和算法分析C语言版书的学习代码  - 2019.08.01

## 1. 说明
1. 对该书慕名而来，终于开刷了，总结自己学习用到的书中相关代码和内容，或许不全面，慢慢补充学习
2. C语言实现，Xcode编译器
3. 目的：刷了剑指offer,觉得自己缺乏对数据结构的算法的整体把握，通过这本书能有个全面的总结学习，以后再继续深入。

## 2. 内容
-----
### 第1章 绪论 - 2019.8.1
1. 主要内容
* 大量输入下的程序性能重要性
* 数学基础：给了几个公司，指数，对数，级数，归纳法。主要是为了后面算法分析使用。（具体看书）
* 递归：基准，推进，设计，效益。
2. 大致作为引论的功能，了解

-----
### [第2章 算法分析](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch02_Algorithm_Analysis)  - 2019.8.1
1. 主要内容：
* 数学公式：阐述了几个复杂度的数学概念，四定义，三法则。对时间复杂度，增长率清晰了不少
* 模型：计算机指令
2. 举例：最大子序列和的问题。作者给了四种方法，把时间复杂度从O(n^3) -> O(n),真正明白算法的威力。[具体代码看这里](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch02_Algorithm_Analysis/1.%20MaxSubSeq.c)
3. 给了三个对数复杂度的问题。跟对数相关主要是折半。[代码在这里](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch02_Algorithm_Analysis/2.%E5%AF%B9%E6%95%B0%E5%A4%8D%E6%9D%82%E5%BA%A6%E4%B8%89%E4%B8%AA%E4%BE%8B%E5%AD%90.c)
##### ***总结：这一章对后面的算法复杂度分析会很重要，看明白神清气爽！***

-----
### [第3章 表,栈,队列](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue) 2019.8.8
#### 1.[表](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/List) - 2019.8.8
1. [实现方法：](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/List)
* [1.指针实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/List/1_Construct_with_Pointer.c)
* [2.游标法实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/List/2_Construct_with_Array.c)：使用数组，不使用指针
2. [例子](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/List/examples)
* [1.多项式](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/List/examples/1_Polynomial.c)：代码完成数组和链表两种实现方法。 [参考1](https://www.twblogs.net/a/5b8e29fe2b71771883434237/zh-cn/), [参考2](https://zhuanlan.zhihu.com/p/42940421)
* 2.基数排序：
* 3.多重表：

#### 2.[栈](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/Stack) - 2019.8.8
1. 构造和基本操作实现：链表和数组方式有些不同，结构体也不同，但是对外的结构要是一致的。
* [链表实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Stack/1_Stack_with_List.c)
* [数组实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Stack/2_Stack_with_Array.c)
2. 例子
* [1.平衡符号判断](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Stack/examples/1_Balance_Character.c)：判断一串符号是否匹配。  [参考内容](https://blog.csdn.net/cdl2008sky/article/details/8300249)
* [2.后缀表达式的计算和转换](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Stack/examples/2_Postfix_Operation.c): 这个很经典，彻底实现了，包括对字符串的使用，好好看看。   [参考内容](https://blog.csdn.net/woshinannan741/article/details/50087665)
* 3.函数调用：主调函数的变量，指针等内容都存储在栈中。

#### 3.[队列](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/Queue) - 2019.8.9
1. 队列的构造和实现：链表和数组两种方式，两个结构体不一样，操作一样。 [实现参考](https://blog.csdn.net/song_hui_xiang/article/details/47146503)
* [数组实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Queue/1_Queue_with_Array.c)：两个结构体，队和队中的节点。注意指针
* [链表实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Queue/2_Queue_with_List.c)：主要是判空条件，不同的实现方法。rear和front的关系，或者增加size变量。
2. 例子
* 所有的排队应用，计算机网络等
* 排队理：接线员问题

#### ***总结：这三个是最基础的数据结构，后面高级数据结构以及算法的实现会大量用到它们，要烂熟于心，灵活调用！***

----
### [第4章 树]()  - 2019.8.14
#### 4.1 树的定义实现，遍历和应用
1. 实现：树节点结构体：每个节点存放数据，以及儿子节点的指针。
2. 应用：操作系统目录结构。
* 先序 - 打印文件名
* 后序 - 计算磁盘大小

#### 4.2 二叉树
#### 1. 实现：定义二叉树节点。
```C++
typedef struct TreeNode *pNode;
typedef struct pNode Tree;

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}
```
#### 2. 应用：
1. 表达式树：树叶是操作数，其他节点是操作符。表达式树后序遍历是[后缀表达式](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Stack/examples/2_Postfix_Operation.c)，中序遍历是中序表达式。
2. 实现思路：[参考](https://blog.csdn.net/buaa_shang/article/details/9124075).
* 每次读入一个符号表达式；
* 如果是操作数：生成树节点，压入栈中；
* 如果是操作符：从栈中弹出两个树节点T1,T2，形成一个新树，树根为操作符，左右儿子分别是T2,T1(先出栈的是右孩子),然后压入栈中；

3. [表达式树完整代码实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch04_Tree/1_Express_Tree.c).

## 3. 总结
