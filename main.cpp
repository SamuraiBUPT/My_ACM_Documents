#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

const int N = 10000;

int n; // 大臣的人数
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

int main()
{

    freopen("in.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cin >> r[i] >> l[i];
    }
    // 这个数组中，排头是国王，剩下的按正常下标代表大臣

    // 思路一：暴力枚举
    // 枚举不同的sequence，挨个进行计算

    for (int i = 1; i <= n; i++)
    {
        seq[i] = i;
    }
    baoli(n);
    cout << min_l;
    return 0;
}