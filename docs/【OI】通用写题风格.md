# 全局数组

一般来说会看到：

```cpp
//这里是头文件区，一般有一万个头文件
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//这里是定义一些大数区
const int N = 10000;

//这里是定义一些全局数组区
int num[N];

int func(){
    //一般都直接对数组进行处理，而不去搞数组传参之类的奇怪玩意
    num[1] = 1;
    return 0;
}

int main()
{
    cout << "Hello World" << endl;

    return 0;
}
```

而且一般来说，只会有一份main.cpp

# freopen()
为了避免重复输入测试点带来的困扰，一般会用freopen()函数来重定向输入输出流

+ 参数一：文件名
+ 参数二：读写模式
+ 参数三：重定向形式

```cpp