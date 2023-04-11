# 1. 数组的拷贝
在蓝桥杯中遇到了这样的问题：

```cpp
int func(int num[], int n){
    for(int i=0;i<n;i++){
        num[n]++;
    }
}
```

执行完这个函数之后，传入的数组发生了改变。也就是说**以这样的传参方式传入的数组，是传入的数组本身，而不是其拷贝。**所以在外部会发生改变。

无论是传入num[]，还是传入*num，实际上都是传入的地址，在函数里面所做的事情，会对数组造成影响。

数组的拷贝：

```cpp
int a[5] = {1, 2, 3, 4, 5};
int b[5];
int n = 5;           // sizeof(a)/sizeof(a[0])
memcpy(b, a, 5 * 4); // length * int
for (auto e : b)
    cout << e << " ";
cout << endl;
cout << "bit of a:" << sizeof(a) << endl;   //20
cout << "length of a:" << sizeof(a) / sizeof(a[0]) << endl;  // 5
```

`memcpy()`函数同样也是三个参数：
+ 需要拷贝到的数组是什么
+ 被拷贝的数组是什么
+ `bytes`数。也就是`长度`*`类型的字节`

比如在这里就是： `len*sizeof(int)`

当然，也可以`sizeof(a)`，求出来的也是字节数。

# queue
c++自带的`include <queue>`库提供了队列相关的方法

```cpp
queue<int> a;
a.push(1);
a.push(2);
a.push(3);
for (auto it = a.front(); it != a.back(); it++)
{
    cout << it << endl;
}
```

需要注意的是，queue.back()返回的就是3，也就是，他并不是一个空指针，而是带有元素的节点