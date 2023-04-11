#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <queue>

using namespace std;

const unsigned int N = 1000000;

struct Node
{
    unsigned int end;
    unsigned int begin;
} race[N];

int cmp(Node a, Node b)
{
    return a.end < b.end;
}

int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> race[i].begin >> race[i].end;
    }
    sort(race, race + n, cmp);
    queue<Node> res;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            res.push(race[0]);
            continue;
        }
        else
        {
            if (race[i].begin >= res.back().end)
            {
                res.push(race[i]);
            }
        }
    }
    cout << res.size();

    return 0;
}