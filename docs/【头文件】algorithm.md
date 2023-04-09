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