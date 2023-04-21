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
int cnt = 0;
int n, k;

bool judge(int num_)
{
    if (num_ <= 3)
    {
        return num_ > 1;
    }
    if (num_ % 6 != 1 && num_ % 6 != 5)
    {
        // 优化：不是6x+1或者6x-1的数，肯定不是质数
        return false;
    }
    int temp = int(sqrt(num_));
    for (int i = 5; i <= temp; i += 6)
    {
        if (num_ % i == 0 || num_ % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int m, int sum, int startx)
{ // 最重要的递归
    // m代表现在选择了多少个数
    // sum表示当前的和
    // startx表示升序排列，以免算重
    if (m == k)
    {                   // 如果选完了的话
        if (judge(sum)) // 如果和是素数
            cnt++;      // ans加一
        return;
    }
    for (int i = startx; i < n; i++)
        dfs(m + 1, sum + num[i], i + 1); // 递归
    // 步数要加一，和也要加
    // 升序起始值要变成i+1,以免算重
    return; // 这一个步骤下，所有的都枚举完了
    // 直接返回去
}

int main()
{

    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    dfs(0, 0, 0);
    cout << cnt << endl;
    return 0;
}