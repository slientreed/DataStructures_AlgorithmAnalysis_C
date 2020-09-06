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

#### [4 左式堆](https://www.cnblogs.com/zhangbaochong/p/5243463.html):(代码未实现，实现可参考[该博客](https://blog.csdn.net/yw8355507/article/details/47449817))
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

#### 6 二项式队列：（代码未实现，要实现可参考[该博客](https://blog.csdn.net/yw8355507/article/details/47450895)）
- [ ] 完全未看且没有实现，以后补充。

#### **总结：1.最重要的是二叉堆，要烂熟于心这个，后面排序要用。2.左式堆，斜堆，二项队列都没实现，抽时间再来补充**
----

### [第7章 排序](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch07_Sort). - 2019.8.29
#### 1. 每种排序的介绍：[具体实现代码参看这里](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch07_Sort/1_Insert_Shell_Merge_Heap_QuickSort_BuckteSort.c)
1. 插入排序：遍历N-1趟数组，每一趟向前面已经有序的数组插入一个元素，并保证插入之后有序。
2. 希尔排序：每一趟选取一定间隔，使得一定间隔的元素有序；最后间隔为1，整体有序
3. 堆排序：对数组创建成为最大堆O(n)，每次执行DeteleMin操作log(n)，把最大值放到数组最后；完成排序
4. 归并排序：分治思路，把要排序数组分成两快，然后对每块进行排序，然后把排序完成的合并成一个。其中合并主要用对两个有序数组合并成一个有序数组。分O(logN) + 合并O(N)
5. 快速排序：分治递归思路。首先选取枢纽，然后根据枢纽把数组分成两块，使得枢纽在有序后的位置上；最后对两块分别递归，完成排序。(这还可以运用到找第k大值中)
6. 桶排序：最快的排序，不基于比较。首先选取固定数量桶，桶是从小到大的；然后把数组元素放入对应桶中，并排序；最后按照顺序连接桶即可。[代码网上参考](https://blog.csdn.net/hitwhylz/article/details/9987367)。[参考2](https://blog.csdn.net/liaoshengshi/article/details/47320023)
7. 外部排序：排序-归并策略。先读入内存能装下数量元素进行排序，输出到外部存储中保存；然后再讲这些一个一个合并（类似归并，把两个有序数组合并成一个有序），放到外村中。
8. [其他排序算法补充参考](https://waliblog.com/other/2019/02/14/arraySort.html#11%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8Fradixsort)

#### 2. 每种排序的分析，最好/最坏/平均复杂度
1. 对于基于比较的方法，复杂度有下届是 O(NlogN),就是说最好情况下要进行log(N!)上取整次比较，平均需要O(NlogN)次比较
2. 每种排序的具体好坏，复杂度分析具体看书中说明，要了然于胸。

| 复杂度     | 最好情况   | 最差情况   | 平均                 |
| ---------- | ---------- | ---------- | -------------------- |
| 1.插入排序 | O(n)     | O(n^2)   | O(n^2)             |
| 2.希尔排序 | O(n)     | O(n^2)   | O(n^3/2 |
| 3.堆排序   | O(nlogn) | O(nlogn) | O(nlogn)           |
| 4.归并排序 |            | O(nlogn) | O(nlogn)          |
| 5.快速排序 | O(n^2)  | O(nlogn) | O(nlogn)           |
| 6.桶排序   | O(N)     |            | O(M + N)           |


#### **总结： 现在只有这几种，对于思路，代码，还要复杂度分析，包括改进方法，一定要清清楚楚，对答如流才行！**
----

### [第8章 不相交集（并查集）](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch08_Union_Find/1_Union_Find.c). - 2019.8.29
#### 1. 等价关系
1. 对于a,b验证a,b是否包含在同等价关系中。
2. 等价类：a对于S的等价类表示包含所有与a有关系的集合。
3. 初始元素都是不相交的，通过Union运算，使得对应元素有关系；通过Find()运算查找元素所在集合。
#### 2. 基本数据结构
1. 数组：对每个数组内的元素维护一个id号，表示所属的集合；
2. 树：不断判断root节点，表示所属的集合；
#### [3. 操作](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch08_Union_Find/1_Union_Find.c)
1. Find: 返回树根 -> 路径压缩优化
2. Union: 随机求并 -> 按大小求并 -> 按深度求并。 
3. 复杂度：对N个元素进行M次Find-Union操作 - O(MlogN)。
#### [4. 之前C++学习对并查集的实现,可参考](https://github.com/slientreed/Mooc_Algorithm/tree/master/6%E7%AB%A0_%E5%B9%B6%E6%9F%A5%E9%9B%86)

#### **总结： 要清晰思虑，写算法题中要会自己很快实现，并会用**

---

### 9章. 图论 - (未用代码实现，抽时间一定要实现它)  - (2020.1.4)

1. 若干定义：
   1. 基本定义：
      * 图：一个图G(V,E)由定点集V和边集E组成。
      * 有向图和无向图：边是有方向的称作有向图；无方向成为无向图；
      * 路径：是一个顶点的序列$w_1,…,w_N$,使得($w_i$,$w_{i+1}$)属于边集E；
      * 度：图中与某个顶点相关联的边的数目，称为该顶点的度；
      * 环：图包含一条从一个顶点到它自身的边(u，v)，路径u,v也叫做一个环；除了第一个顶点和最后一个顶点之外，其余顶点不重复出现的回路，称为简单回路
      * 连通图：一个无向图中从每个顶点到每个其他顶点都有一条路径，则该无向图是连通的；
      * 完全图：每个顶点间都存在一条边的图；
   2. 图的表示方法：
      1. 邻接矩阵：使用一个二维数组，对于每条边(u，v)，置A\[u][v] = 1;否则数组元素为0；
         * 邻接表简单，方便表示，容易查看边和顶点的度；但是如果用来表示稀疏图非常浪费O(n^2);
      2. 邻接表：对于每个顶点，使用一个表存放所有邻接的顶点；该表表示以该顶点为起点的所有边的信息(终点序号，权值，连接域)。
         * 图的邻接表便于查找任一顶点的关连边和邻接点，O(E/V)；对于有向图容易查找后继节点，但是不容易查找前继，需要扫描整个表，所以对于经常查找入度或者以顶点为终点的运算，可以建立逆向邻接表；
      3. 在图中，不能使用名字作为索引，所以需要提供名字到数字的映射；可以使用散列表(存储一个名字对应的1到|V|的编号)；
   3. 图的具体实现：
      1. [邻接表表示图的代码实现]()：使用开放定址法构建哈希表(使得每个节点对应一个顶点)。
      2. [邻接矩阵实现]()：

2. 拓扑排序： - (2020.1.4)

   * 说明：对有向无圈图顶点的一种排序，使得如果存在一条从$v_i$到$v_j$的路径，那么在排序中$v_j$出现在$v_i$后面;

   * 实现：(找到任意一个没有入边的顶点，记录并把它和其边一起从图中删除；然后对其他部分同样处理)
     1. 图使用邻接表存储，计算图中所有定点的入度存入Indegree数组中(对邻接表每条边的顶点进行统计)
     2. 扫描indegree数组，找所有入度为0的顶点(如果不存在，则有环)；把顶点入队(该队是专门存放入度为0的顶点)；
     3. 出队一个顶点（记录该顶点作为结果）；然后在Indegree数组中把与该顶点相连的顶点入度减1；
     4. 重复2，3直到队列为空，结束；

3. ***最短路径算法***： - (2020.1.4)

   1. **有向无权图最短路径**：BFS方法，(在一个有向无权图中，找某个顶点s到其他所有顶点的最短路径)

      * 解决：BFS方法如下

        1. 选取顶点s作为起点，得出起点到s的距离为0，记录该信息；
        2. 选取与s相连的顶点v，距离为1，记录所有顶点信息；
        3. 选取所有与v相连的顶点，距离为2，记录信息，重复这个步骤，直至所有顶点都被考察过；

      * 数据结构：(为了实现BFS，需要记录3个信息)

        1. 顶点是否被考察过：使用know数组标记；

        2. 顶点到起点s的距离：用$d_v$记录；

        3. 实际的路径信息：就是到达该顶点的上一个顶点，用$p_v$记录；

      * 算法步骤：(使用邻接表实现图，复杂度为O(V+E)，复杂度最低)

        1. 初始化know数组为false；距离$d_v$为无穷大；路径$p_v$为None；
        2. 把初始距离置为0，然后入队初始节点；
        3. 出队一个节点，把该节点在know中置为true已访问；把和他相邻的未知顶点距离$d_v$设为该顶点距离加1；路径$p_v$设为该顶点，然后相邻顶点入队；
        4. 重复3，直到队列为空；

   2. **有向带权图最短路径：Dijkstra算法**

      * 解决：Dijkstra算法，大名鼎鼎的贪婪算法，每次在未知顶点中选取最小的$d_v$
        1. 选择一个起始点v1，得出从起始点到v1长为0，记录信息；
        2. 考察所有和v1相连的顶点，并记录v1到他们的距离；
        3. 选择和v1距离最短的顶点为v4，起始点到v4的距离被固定下来；**然后考察该顶点(v4)的所有相邻顶点，如果从该顶点到相邻顶点的路径小于之前路径，则更新路径,调整他们在表中信息**（这里调整的意思是在后面访问过程中有可能会出现比通过v2顶点更短的情况，具体来说就是去数据结构表中扫描$d_v$的值，找到最小距离值进行往后访问）；
        4. 选择余下未被访问顶点中最短的顶点，为v2，重复3过程，直到确定所有顶点的最短距离信息；
      * 数据结构：(同样记录3个信息）
        1. 顶点是否已经被访问确定过最短路径：使用known数组；
        2. 顶点到起点的距离：用$d_v$记录；
        3. 路径信息：$p_v$记录，该顶点的上一个顶点；
      * 算法步骤：(使用最小堆降低查找最小$d_v$的复杂度，每次查找O(logV),查找V次，总复杂度O(E+VlogV));
        1. 初始化表结构数组；初始Known所有元素为false；距离$d_v$无穷大；路径$p_v$为None；
        2. 初始顶点距离置为0，插入最小堆中（这里用最小堆，就是为了降低查找$d_v$最小值的复杂度）；
        3. 获取堆的最小值，如果该值对应的顶点未访问，则访问，并更新该顶点相邻顶点的路径长度$d_v$；把更新值插入最小堆中；
        4. 重复3，直到所有边被访问过，即可找出最短路径；

   3. 具有负权值：

      1. Dijkstra不再有效，因为负值可能使得$d_v$最小值无限循环下去；可以认为设置某一定点出队|V|+1次后停止，避免负权值顶点不断入队；

   4. 无圈图：

      1. 可以使用拓扑排序进行改进Dijkstra算法；

4. 网络流问题：

   1. 定义：在给定容量的有向图中，找到从发点到收点之间可以存着的最大网络流；
   2. **Edmond-Karp算法**：
      1. 建立一个空的$G_f$图作为流图；
      2. 建立一个残余图$G_r$，残余图初始化和给定的网络流图相同；
      3. 在残余图上用BFS寻找增广途径，如果找到，则用该路径上的最小流值修改$G_f$和$G_r$;
      4. 重复3，直到无法找出从发点到收点的增广路径（就是该通路上每条边还能增加多少流的量的和）；则此次$G_f$即为所求；

5. **最小生成树：**(连接图中所有顶点的边构成的树，且边的总权值最小)  - (2020.1.4)

   1. Prim算法：(不断寻找与当前已构的树相连且权最小的边)，复杂度：O(ElogV)，实现和Dijkstra算法一样，logV是对最小权值堆的调整复杂度，具体思路是：在所有节点中，寻找和当前最小生成树MST集合中的节点相连的最小权值边，加入MST中，直到有V-1条边或者BST中有V个顶点；具体实现类似Dijkstra算法，步骤如下：
      1. 图中所有顶点的集合为V；初始集合为u = {s}, v = V  - u;
      2. 在两个集合u,v能够组成的边中，选择一条权值最小的$(u_0,v_0)$边（注意这里用一个最小堆维护最小权值边，降低复杂度），加入最小生成树，并把v0加入u中；
      3. 重复步骤2，直到最小生成树有V个顶点或者V-1条边；
   2. Kruskal算法：(分别找最小的权边互相合并，不形成环即可)，复杂度最坏为O(ElogE)，有可能把所有边都查找了一遍，具体步骤如下：
      1. 把每条边权值非降序排列；
      2. 每次挑选一个权值最小的边，检查把它加入最小生成树中是否会形成环（这里可以用并查集来检测）；如果不会就加入，会就舍弃;
      3. 重复步骤2，直到最小生成树中有V-1条边；

6. DFS应用：(没看忘了)

   1. 首先要实现DFS：
   2. 应用1：判断双连通性求割点（割点就是去了这个点图就不连通了）；
   3. 应用2：欧拉回路；

7. 参考：[1.代码实现](https://github.com/zhuli19901106/Data-Structures-and-Algorithm-Analysis-in-C),[2.代码实现](https://github.com/YinWenAtBIT/Data-Structure).[3. 实现博客讲解](https://blog.csdn.net/yw8355507/article/list/3?)

---

### 10章. 算法设计技巧

1. ***贪婪算法：***
2. ***分治算法***：
3. ***动态规划***：
4. ***随机算法：***
5. ***回溯算法：***

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
5. 9章中图的代码都没实现，抽时间系统实现他们；[可以参考这个大佬](https://blog.csdn.net/yw8355507/article/list/3?)



