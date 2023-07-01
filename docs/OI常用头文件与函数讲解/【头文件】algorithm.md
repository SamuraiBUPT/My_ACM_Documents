# 简介
这份markdown主要介绍头文件`<algorithm>`中的函数

# `sort()`
sort()函数用于对数组进行排序。

默认从小到大排序，如果需要从大到小或者其他排序方式，可以自行指定。

```cpp
bool cmp(int x,int y){
	return x % 10 > y % 10;
}

int main(){
	int num[10] = {65,59,96,13,21,80,72,33,44,99};
	sort(num,num+10,cmp);
    return 0;
}
```

## 参数
+ 1. 数组
+ 2. 数组末尾的位置，如果数组有10位，就输入num+10
+ 3.【可选】排序规则

# `next_permutation()`与`prev_permutation()`
这是求数组全排列的函数，直接对原数组进行修改。

它的规则如下：

对于集合{a, b, c}，假设有`a<b<c`，这时候可以求next_permutation(),也就是下一个排列，直到其彻底变为{c, b, a}为止。

我们可以有如下代码:
```cpp
int arr1[] = {1,2,3};
cout<<"用next_permutation对1 2 3的全排列"<<endl;
do
{
	cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] <<'\n';
}
while ( next_permutation(arr1,arr1+3) );
```

## 参数
+ 数组
+ 数组+size