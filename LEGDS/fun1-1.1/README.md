# BinSearch分析

## 前言
- 二分法是一种在有序集中查找特定元素的算法，它的有效性建立在目标集合的有序之上。  
- 它的思路是初始化两个边界索引分别指向当前集合的左右边界，因此，其初始值分别为0与length-1，length是目标及和的长度。  
- 接着通过左右索引计算中间索引middle，
- 然后，只需要比较middle索引指向的元素与查找项match，根据比较的结果，更新不同的索引就可以了。  

## 非递归实现
1. 函数的声明是`int BinSearch(int *arr,int length,int match)；`。  
```c
    int re = -1;
    int left = 0,right = length - 1;
```
2. 定义与初始化了返回值与左右边界。  
```c
    int middle = (left + right) / 2;
```
3. 根据left与right的数值求出middle索引， 
```c
    if(arr[middle] > match) {
        right = middle - 1;
    } else if(arr[middle] < match) {
        left = middle + 1;
    } else {
        re = middle;
        break;
    }
``` 
4. 接着根据middle索引元素与match的大小关系，更新不同的索引值。  
```c
	while(left <= right) {
		int middle = (left + right) / 2;
		if(arr[middle] > match) {
			right = middle - 1;
		} else if(arr[middle] < match) {
			left = middle + 1;
		} else {
			re = middle;
			break;
		}
	}
```
5. 现在的问题只有再循环查找的过程中，什么时候停止循环了？根显然，当找到match时，可以停止循环。但是，如果match不再目标集合中，我们不可能一直找下去，因此，当left和right满足怎样的关系时，说明在目标集合中没有match呢？
6. 现在我们要讨论match不再目录集合中时，随着迭代此书的增加会发生什么？先可以从个例出发：  
集合：`0 1 2 3 4`  
查找项： `5`  
然后，在原有的程序中插入`printf`俩打印left与right的变化。  
```help
    Please enter a length
    5
    Please enter a ordered array
    0 1 2 3 4
    Please enter match
    5
    left = 0,right = 4
    left = 3,right = 4
    left = 4,right = 4
    left = 5,right = 4
```
7. 我们注意到最后，left与right的数值在最后会满足`left + 1 == right`的关系，那么，在此时我们可以得出结论，match不在目标集合中。随之而来的问题是：这是偶然还是必然呢？我们可以用数学公式推倒一下，设：distance = (right - left);即：$d_0 = r_0 - l_0$，然后，继续迭代，$d_1 = \frac{ (r_0 - l_0) }{ 2 }$，以此类推：$d_n = \frac{ (r_0 - l_0) }{2^n}$，因为，$r_0 - l_0$是一个定值，因此，总存在一个最小的k使得$2^k > (r_0-l_0)$，所以，经过k轮，有`left == right`。
综上，在第k+1轮，就会出现`left + 1 == right`，所以，设置的循环条件是`left <= right`。  

## 递归实现
1. 上面介绍了非递归实现，那么接下来，我们来聊聊递归实现。  
2. 我们先考虑递归接口的实现，我们的目标是用递归的使用二分法查找元素，那么要使用二分法的需要知道哪些信息？首先，我们是不是需要知道目标集合和其的长度，然后，还有查找项match，那么，还有其他的吗？因为，递归调用是反复的调用自己，因此，在新的函数调用中，它需要上一次调用告诉它，它要处理的集合的边界是什么？不然的话，新的函数调用就只能从最开始的边界`left = 0,right = length - 1`开始，但这不是我们所期望的，我们期望新的调用能处理一个新的宽度更小的一对边界。因此，要有两个参数`right`与`le
t`，让上一次调用告诉新一次调用要处理的边界。  
最后，总结一下，接口需要`int *arr`目标集合的指针、`int length`目标集合的长度、`int match`匹配项、`int left,int right`要处理的边界。  
2. 函数声明:`int BinSearch0(int *arr,int left,int right,int match):`接下来，我们来看具体实现：  
```c
    int re = -1;
```
3. 定义并初始化返回值。  
```c
    int middle = (left + right) / 2;
```
4. 使用边界索引`left`与`right`的值计算中间值索引`middle`。  
```c
    if(arr[middle] < match) {
        re = BinSearch0(arr, middle + 1, right, match);
    } else if(arr[middle] > match) {
        re = BinSearch0(arr, left, middle - 1, match);
    } else {
        re = middle;
    }
```
5. 更具中间值与`match`的比较结果，确定不同的边界值，并调用自身进行下一轮查找，  
```c
    if(left <= right) {
        int middle = (left + right) / 2;
        if(arr[middle] < match) {
            re = BinSearch0(arr, middle + 1, right, match);
        } else if(arr[middle] > match) {
            re = BinSearch0(arr, left, middle - 1, match);
        } else {
            re = middle;
        }
    } else {
        re = -1;
    }
```
6. 现在我们还有一个问题没解决，那就是我们还没给这个递归过程设置一个终点。当这个`match`不在目标集合中时，这个程序会一直在分支0与分支1中反复执行，而不会从分支2返回，因此，在怎样的条件下，可以确定`match`不在目标集合中呢？这个问题我们已经在非递归实现中给出答案了。这里就不重复了。
