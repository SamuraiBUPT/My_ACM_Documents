#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <queue>
#include <math.h>

using namespace std;

const unsigned int N = 5000001;

int num[N];
int num_sum = 0; // sum先置为0
int bu;
int cnt;

bool judge(int num_)
{
    if (num_ <= 3)
    {
        return num_ > 1;
    }
    if (num_ % 6 != 1 || num_ % 6 != 5)
    {
        // 优化：不是6x+1或者6x-1的数，肯定不是质数
        return false;
    }
    int temp = pow(num_, 2);
    for (int i = 5; i <= temp; i += 6)
    {
        if (num_ % i == 0 || num_ % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> choose;

void dfs()
{
    // dfs思路：先确定有没有全部压栈，如果压栈完成则开始处理，否则继续压栈
    choose.push_back();
    // 压栈思路：
    if (choose.size() < bu)
    {
        dfs();
    }
    // 开始处理
    int temp_sum = num_sum;
    for (int i = 0; i < bu; i++)
    {
        temp_sum -= choose[i];
    }
    if (judge(temp_sum))
    {
        cnt++;
    }
    // 开始回溯
    choose.pop_back();
    return;
}

int main()
{
    int n, k;
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    bu = n - k;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        num_sum += num[i];
    }

    // 逆向思考，先计算sum，然后减去挑出来的数字，这样能够将递归的stack深度大大降低

    return 0;
}