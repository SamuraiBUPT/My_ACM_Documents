#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

const int N = 10000;

int cal_res[N];
int ans[N];

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
    for (int i = N - 2; i >= 0; i--)
    {
        a[i] *= num;
    }
    for (int i = 0; i < N - 1; i++)
    {
        a[i + 1] += (a[i] / 10); // 进位
        a[i] %= 10;              // 处理本位
    }
}

int main()
{

    freopen("in.txt", "r", stdin);
    int n; // 大臣的人数
    cin >> n;

    // 设置国王的左右手
    Node king;
    cin >> king.l >> king.r;

    for (int i = 0; i < n; i++)
    {
        // dc是大臣的左右手，这个数组的大小为n, index 从 0 -> n-1
        cin >> dc[i].l >> dc[i].r;
    }

    // 对这个数组进行排序
    sort(dc, dc + n, cmp);

    // 之前WA了四发，因为是大数，超过longlong的限制了，因此使用高精度
    // 从国王开始计算
    for (int i = 0; i < n; i++)
    {
    }

    return 0;
}