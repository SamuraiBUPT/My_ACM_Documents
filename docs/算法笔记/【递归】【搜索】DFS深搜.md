DFS（深度优先搜索）是一种常见的算法，大部分的题目都可以用 DFS 解决，但是大部分情况下，这都是骗分算法，很少会有爆搜为正解的题目。因为 DFS 的时间复杂度特别高。（没学过 DFS 的请自行补上这一课）

# 深搜模板
```cpp
int ans = 最坏情况, now;  // now 为当前答案

void dfs(传入数值) {
  if (到达目的地) ans = 从当前解与已有解中选最优;
  for (遍历所有可能性)
    if (可行) {
      进行操作;
      dfs(缩小规模);
      撤回操作;
    }
}
```

这个在之前做题的过程中想到了这个模板，在dfs中通过开辟一个for，来遍历该情况的所有子树。

**问题的难点就在：传入的数值的设置、for循环内的判断逻辑设置**

我们可以看隔壁**选数问题**来看看具体应用。