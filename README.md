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
### [第4章 树](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch04_Tree)  - 2019.8.14
#### 4.1 树的定义实现，遍历和应用
1. 实现：树节点结构体：每个节点存放数据，以及儿子节点的指针。
2. 应用：操作系统目录结构。
* 先序 - 打印文件名
* 后序 - 计算磁盘大小

#### 4.2 二叉树
##### 1. 实现：定义二叉树节点。
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
##### 2. 应用：
1. 表达式树：树叶是操作数，其他节点是操作符。表达式树后序遍历是[后缀表达式](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/Stack/examples/2_Postfix_Operation.c)，中序遍历是中序表达式。
2. 实现思路：[参考](https://blog.csdn.net/buaa_shang/article/details/9124075).
* 每次读入一个符号表达式；
* 如果是操作数：生成树节点，压入栈中；
* 如果是操作符：从栈中弹出两个树节点T1,T2，形成一个新树，树根为操作符，左右儿子分别是T2,T1(先出栈的是右孩子),然后压入栈中；

3. [表达式树完整代码实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch04_Tree/1_Express_Tree.c).

#### 4.3 二叉查找树
1. 性质：每个节点X，左子树的关键值小于X,右子树的关键值大于X;查找复杂度为O(logn)
2. 二叉查找树的构造和使用:[完整代码](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch04_Tree/2_Binary_Search_Tree.c).
* MakeEmpty(),Find()
* FindMin(),FindMax():递归左右子树即可
* Insert
* Delete:三种情况：待删节点是树叶，有1个孩子，有2个孩子(用右子树最小值代替，然后删除右子树最小值)。

#### 4.4 AVL平衡二叉树   - 2019.8.19
1. 性质：**每个节点**的左子树和右子树的高度最多差1的**二叉查找树**。在插入和删除时，要使用保持平衡性质。（单旋转，双旋转）
2. [AVL平衡二叉树的构造和使用,完整实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch04_Tree/3_AVL_Tree.c)。
* MakeEmpty(), Find(), SingleRotateWithLeft(), SingleRotateWithRight(), DoubleRotateWithLeft(), DoubleRotateWithRight(),Insert(), Delete().
* [参考代码](https://blog.csdn.net/men_wen/article/details/68937187)

#### 4.5. 伸展树   - 2019.8.19
1. 基本思想：当一个节点被访问后，它要经过一系列AVL树的旋转被放到跟上。（当前被操作的节点很有很能在最近一段时间频繁访问）。
2. [实现参考](https://blog.csdn.net/xiaohusaier/article/details/76173199)

#### 4.6 B-树（M值为3，2—3树）
1. 性质：
* 树的根要么是树叶，要么其儿子说在[2,M]之间。
* 除根外，所有非叶节点的儿子树在[M/2, M]之间。
* 所有树叶都在相同深度上，且所有数据存在树叶上。
* 有 k 个子节点的非叶子节点拥有 k − 1 个键，每一个内部节点的键将节点的子树分开，每个键值表示后一个叶子节点的最小值。
2. 操作：
* 插入：搜索树找到叶子节点，如果可以容纳，直接插入；该叶子节点没有空间，通过分裂，插入
* 删除：删除之后，如果不满足空间条件，可以通过合并兄弟，更新父节点键值完成。
3. [实现参考](https://blog.csdn.net/xiaohusaier/article/details/76708490).

#### 附加
1. B+树：在B-tree的基础上，为叶子节点增加链表指针。[参考](https://blog.csdn.net/xiaohusaier/article/details/77101640)
2. 红黑树：不完全的平衡，避免想AVL树一样每次插入都要调整。[参考](https://blog.csdn.net/v_july_v/article/details/6114226)

#### **总结：树很重要，要清清楚楚，要能从二叉树开始讲，遍历，二叉查找树，AVL，B-，红黑树。都什么特点，怎么操作，为什么不断延伸，解决什么问题能说的清楚明白。**
----
### [第5章 散列Hash表](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch05_Hash)  - 2019.8.23
#### 1. Hash构成：关键字+数组
* 1 散列函数：根据关键字的值，把关键字映射为0~TableSize-1中的某个数，然后放到固定单元中。这个映射就是散列函数
* 2 解决冲突：当两个关键字通过散列函数映射到相同值时，如何解决放到不同的位置。

#### 2. [散列函数：有多种不同的函数。](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch05_Hash/1_Separate_Chaining_Methond.c)
* 尽量根据关键字特性，进行映射，分布越均匀越好。Hash大小为素数。
* 其他参考书中内容。

#### 3. 解决冲突：[分离连接](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch05_Hash/1_Separate_Chaining_Methond.c)，[开放定址](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch05_Hash/2_Open_Addressing_Hashing.c)。[参考网上代码](https://www.kancloud.cn/digest/datastructures/195134)
* 分离连接：把Hash中散列到同一个位置的元素保留到一个表中。[代码参考](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch05_Hash/1_Separate_Chaining_Methond.c)
* 开放定址：有冲突，尝试另外的单元。H(X) = (Hash(X) + F(i) mod TableSize). 线性探测 - F(i) = i. 平方探测 - F(i) = i^2。[代码参考](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch05_Hash/2_Open_Addressing_Hashing.c).
* 再散列：开辟更大的散列表（当前散列大小2倍的素数），然后复制旧的到新的散列中。

#### 4. 可扩散列
* 增加散列关键字，增加可访问散列大小

#### **总结：明白散列函数+解决冲突方法，就对散列清楚了，多看代码，画图分析！**
----

### [6 优先队列（堆）](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch06_Heap). - 2019.8.25
#### 1. 模型讲解
1. 返回优先级最高的数据结构，最大最小堆。有Insert，DeleteMin操作等
2. 实现方法极其复杂度

实现方法 | Insert | DeleteMin
--- | --- | --- |
链表 | O(1) | O(n)
二叉查找树 | log(n) | log(n)
二叉堆 | log(n) | O(1)

#### [2. 二叉堆的及其实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch06_Heap/1_Min_Heap.c) - 2019.8.25
1. 性质
* 结构性质：是完全二叉树（完全二叉树的第i个节点的父节点是i/2,左子节点是2i,右子节点是2i+1）。
* 堆序性质：父节点小于左右子节点。
2. [操作以及代码实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch06_Heap/1_Min_Heap.c)
* Insert:上滤
* DeleteMin：下滤
3. [实现的网上参考代码](https://blog.csdn.net/u012796139/article/details/41603987)。

#### [3 d-堆]()  - 2019.8.26
* 二叉堆的推广，每个树可以有d个儿子

#### [4 左式堆](https://www.cnblogs.com/zhangbaochong/p/5243463.html)
1. 性质
* 同样以二叉树构建，但不是完全二叉树了
* 任一节点的零路径长（节点到一个没有两个儿子节点的最短路径）比其儿子零路径长的最小值大1.
* 父节点的属性值小于子节点属性值。
* 堆中的任何节点，其左儿子的零路径长>=右儿子的零路径长的二叉树。
2. 操作
* 合并，删除，插入

#### [5 斜堆](https://www.cnblogs.com/skywang12345/p/3638493.html)
1. 左式堆的自调节形式。同样具有堆序，但是对树的结构没有什么限制。
- [ ] 2. 没有看且没有实现，以后补充实现。

#### 6 二项式队列
- [ ] 完全未看且没有实现，以后补充。

#### **总结：1.最重要的是二叉堆，要烂熟于心这个，后面排序要用。2.左式堆，斜堆，二项队列都没实现，抽时间再来补充**
----

### [第7章 排序](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch07_Sort). - 2019.8.29
#### 1. 每种排序的介绍：[具体实现代码参看这里](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch07_Sort/1_Insert_Shell_Merge_Heap_QuickSort_BuckteSort.c)
##### 1. 插入排序：遍历N-1趟数组，每一趟向前面已经有序的数组插入一个元素，并保证插入之后有序。
##### 2. 希尔排序：每一趟选取一定间隔，使得一定间隔的元素有序；最后间隔为1，整体有序
##### 3. 堆排序：对数组创建成为最大堆O(n)，每次执行DeteleMin操作log(n)，把最大值放到数组最后；完成排序
##### 4. 归并排序：分治思路，把要排序数组分成两快，然后对每块进行排序，然后把排序完成的合并成一个。其中合并主要用对两个有序数组合并成一个有序数组。分O(logN) + 合并O(N)
##### 5. 快速排序：分治递归思路。首先选取枢纽，然后根据枢纽把数组分成两块，使得枢纽在有序后的位置上；最后对两块分别递归，完成排序。(这还可以运用到找第k大值中)
##### 6. 桶排序：最快的排序，不基于比较。首先选取固定数量桶，桶是从小到大的；然后把数组元素放入对应桶中，并排序；最后按照顺序连接桶即可。[代码网上参考](https://blog.csdn.net/hitwhylz/article/details/9987367)。[参考2](https://blog.csdn.net/liaoshengshi/article/details/47320023)
##### 7. 外部排序：排序-归并策略。先读入内存能装下数量元素进行排序，输出到外部存储中保存；然后再讲这些一个一个合并（类似归并，把两个有序数组合并成一个有序），放到外村中。

#### 2. 每种排序的分析，最好/最坏/平均复杂度
##### 1.复杂度分析方法：
1. 对于基于比较的方法，复杂度有下届是 $O(NlogN)$,就是说最好情况下要进行$\left \lfloor log(N!) \right \rfloor$次比较，平均需要$O(NlogN)$次比较
2. 每种排序的具体好坏，复杂度分析具体看书中说明，要了然于胸。

| 复杂度     | 最好情况   | 最差情况   | 平均                 |
| ---------- | ---------- | ---------- | -------------------- |
| 1.插入排序 | $O(n)$     | $O(n^2)$   | $O(n^2)$             |
| 2.希尔排序 | $O(n)$     | $O(n^2)$   | $O(n^{\frac{3}{2}})$ |
| 3.堆排序   | $O(nlogn)$ | $O(nlogn)$ | $O(nlogn)$           |
| 4.归并排序 |            | $O(nlogn)$ | $O(nlogn)$           |
| 5.快速排序 | $O(n^2)$   | $O(nlogn)$ | $O(nlogn)$           |
| 6.桶排序   | $O(N)$     |            | $O(M + N)$           |


#### **总结： 现在只有这几种，对于思路，代码，还要复杂度分析，包括改进方法，一定要清清楚楚，对答如流才行！**
----

## 3. 总结

## 4. 参考
1. [Mooc的算法学习代码](https://github.com/slientreed/Mooc_Algorithm).
* 里面有一些基础的算法C++实现，以及算法改进，可以看一看。
2. [个人剑指offer刷题记录](https://github.com/slientreed/Point2OfferCode)。
* 里面是《剑指offer》书的全部实现代码，有大量实现和测试，对我收获颇多，常看。
3. [跟人对C++的一些练习](https://github.com/slientreed/Cplusplus_Learning)
* 这里是对C++的练习，以后会慢慢加深的，包括语法，STL实现等等。
4. [网上大佬对数据结构和算法的总结分析](https://www.cnblogs.com/skywang12345/p/3603935.html)



