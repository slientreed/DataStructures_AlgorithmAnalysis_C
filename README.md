# DataStructures_AlgorithmAnalysis_C
数据结构和算法分析C语言版书的学习代码  - 2019.08.01

## 1. 说明
1. 对该书慕名而来，终于开刷了，总结自己学习用到的书中相关代码和内容，或许不全面，慢慢补充学习
2. C语言实现，Xcode编译器
3. 目的：刷了剑指offer,觉得自己缺乏对数据结构的算法的整体把握，通过这本书能有个全面的总结学习，以后再继续深入。

## 2. 内容
### 第1章 绪论 - 2019.8.1
1. 主要内容
* 大量输入下的程序性能重要性
* 数学基础：给了几个公司，指数，对数，级数，归纳法。主要是为了后面算法分析使用。（具体看书）
* 递归：基准，推进，设计，效益。
2. 大致作为引论的功能，了解

### [第2章 算法分析](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch02_Algorithm_Analysis)  - 2019.8.1
1. 主要内容：
* 数学公式：阐述了几个复杂度的数学概念，四定义，三法则。对时间复杂度，增长率清晰了不少
* 模型：计算机指令
2. 举例：最大子序列和的问题。作者给了四种方法，把时间复杂度从O(n^3) -> O(n),真正明白算法的威力。[具体代码看这里](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch02_Algorithm_Analysis/1.%20MaxSubSeq.c)
3. 给了三个对数复杂度的问题。跟对数相关主要是折半。[代码在这里](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch02_Algorithm_Analysis/2.%E5%AF%B9%E6%95%B0%E5%A4%8D%E6%9D%82%E5%BA%A6%E4%B8%89%E4%B8%AA%E4%BE%8B%E5%AD%90.c)
##### 总结：这一章对后面的算法复杂度分析会很重要，看明白神清气爽！

### [第3章 表,栈,队列](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue) 2019.8.8
#### 1.[表](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/List) - 2019.8.8
1. [实现方法：](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/List)
* [1.指针实现](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/List/1_Basic_Operation.c)
* 2.游标法实现：不使用指针
2. [例子](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/tree/master/ch03_List_Stack_Queue/List/examples)
* [1.多项式](https://github.com/slientreed/DataStructures_AlgorithmAnalysis_C/blob/master/ch03_List_Stack_Queue/List/examples/1_Polynomial.c)：代码完成数组和链表两种实现方法。 [参考1](https://www.twblogs.net/a/5b8e29fe2b71771883434237/zh-cn/), [参考2](https://zhuanlan.zhihu.com/p/42940421)
* 2.基数排序：
* 3.多重表：


## 3. 总结
