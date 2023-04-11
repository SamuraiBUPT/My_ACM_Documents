#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

const int N = 10000;

int cal_res[N]; // 乘法运算的数组
int div_res[N]; // 除法运算的数组
int ans[N];     // 答案数组

// 解法二：贪心

struct Node
{
    int r;
    int l;
} dc[N];

// r*l积最大即是最佳排序

int cmp(Node A, Node B)
{
    return A.r * A.l < B.r * B.l;
}

void times(int *a, int num)
{
    // 乘法计算，首先算每一位的乘法
    for (int i = 0; i < N - 1; i++)
    {
        // 数组的下标到了N-1就到头了，因为要预留一位，所以是N-2就退出循环
        a[i] *= num;
    }
    for (int i = 0; i < N; i++)
    {
        // 这里要注意，这里的进位是往数组扩充的方向进行计算的。
        a[i + 1] += (a[i] / 10);
        a[i] %= 10;
    }
}

void div(int *aa, int *bb, int num)
{                              // 除法
    memset(bb, 0, sizeof(bb)); // 赋为0
    int x = 0;
    for (int i = N - 1; i >= 0; i--)
    {                       // 从高位到低位
        x = x * 10 + aa[i]; // 挪位再加
        bb[i] = x / num;    // 记录
        x %= num;           // 模上
    }
}

bool more(int *aa, int *bb)
{ // 比较, 从最右侧，也就是反向数组的最高位开始比较
    for (int i = N - 1; i >= 0; i--)
    {
        if (aa[i] > bb[i])
            return 1;
        if (aa[i] < bb[i])
            return 0;
    }
    return 0; // 注意这里也要写上，写0写1随便
}

void copy(int *a, int *b)
{
    for (int i = 0; i < N; i++)
    {
        a[i] = b[i];
    }
}

int main()
{

    freopen("in.txt", "r", stdin);
    int n; // 大臣的人数
    cin >> n;

    // // 设置国王的左右手
    // Node king;
    // cin >> king.l >> king.r;

    for (int i = 0; i <= n; i++)
    {
        // dc是大臣的左右手，这个数组的大小为n, index 从 0 -> n-1
        cin >> dc[i].l >> dc[i].r;
    }

    // 对这个数组进行排序, 注意第一个是国王，不能参与排序
    sort(dc + 1, dc + n + 1, cmp);

    // 之前WA了四发，因为是大数，超过longlong的限制了，因此使用高精度
    // 从国王开始计算
    // 注意cal_res[0]=1;
    cal_res[0] = 1;

    // 这里有一个思想：
    // 因为那个乘法，第二遍始终会乘第一遍，所以就不用开两个循环乘了，要在一个循环之内完成处理。
    for (int i = 0; i <= n; i++)
    {
        div(cal_res, div_res, dc[i].r);
        if (more(div_res, ans))
            copy(ans, div_res);
        times(cal_res, dc[i].l); // 乘以左手的数字
    }

    // 输出
    int t = N - 1;
    while (!ans[t])
    {
        t--;
    }
    for (int i = t; i >= 0; i--)
    {
        cout << ans[i];
    }

    return 0;
}