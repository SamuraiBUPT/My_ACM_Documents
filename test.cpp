#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

int main()
{

    freopen("test_in.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    int len1 = a.length();
    int len2 = b.length();
    int len_l;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            b = "0" + b;
        }
        len_l = len1;
    }
    else if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            a = "0" + a;
        }
        len_l = len2;
    }
    else
    {
        len_l = len1;
    }

    // 高精度加法:
    string res;
    int temp;
    int cf = 0;
    for (int i = len_l - 1; i >= 0; i--)
    {
        temp = a[i] - '0' + b[i] - '0' + cf;
        cf = temp / 10; // 进位
        temp %= 10;
        res = char(temp + '0') + res;
    }
    if (cf != 0)
    {
        res = char(cf + '0') + res;
    }
    cout << res;

    return 0;
}