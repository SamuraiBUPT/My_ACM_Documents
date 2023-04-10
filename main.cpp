#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

const int N = 10000;

int r[N], l[N];
int seq[N]; // seq数组，用来记录顺序，长度为n+1,第一位不记录东西
int min_l = 1000000;

void baoli(int n)
{
    int cpy_num[n + 1];
    memcpy(cpy_num, seq, n * 4 + 4);
    int max = -1;
    int res[n + 1] = {0};
    do
    {
        memset(res, 0, n + 1);
        max = 0;
        // 开始暴力枚举
        for (int i = 1; i < n + 1; i++)
        {
            // 从seq 排列之后的数组进行读取 ,i表示大臣的number
            //  1 3 2
            int res_l = 1;
            for (int j = 0; j < i; j++)
            {
                // j 是计算每一位大臣时，所推进的数组的下标
                res_l *= r[cpy_num[j]];
            }
            res_l /= l[cpy_num[i]];
            res[i] = res_l;
        }
        for (auto e : res)
        {
            if (e > max)
            {
                max = e;
            }
        }
        if (max < min_l)
        {
            min_l = max;
        }
    } while (next_permutation(cpy_num, cpy_num + n));
}

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

    unsigned long long MAXIMUM = 0;

    // 开始计算
    for (int i = 0; i < n; i++)
    {
        // i 是number为i的大臣
        unsigned long long res_l = king.l;
        for (int j = 0; j < i; j++)
        {
            // 从国王开始进行计算，一直算到这个大臣前面的那一位
            res_l *= dc[j].l;
        }
        res_l /= dc[i].r;
        if (res_l > MAXIMUM)
        {
            MAXIMUM = res_l;
        }
    }

    cout << MAXIMUM;
    return 0;
}