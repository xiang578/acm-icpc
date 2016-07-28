67

#### 2016年7月28日
- hdu3392 dp,想的仔细一点
- hdu5722 矩形面积并，先对元素进行大小位置排序，然后得到取值范围。

#### 2016年7月27日
- hdu5753 考虑每一位对结果的贡献
- hdu5754 王需要打表，车为巴什博弈，后为威佐夫博弈，马先预处理最大的情况。
- hdu5762 Manhattan距离，注意的是根据鸽巢原理会在O(M）的时间内退出循环。
- hdu2177 威佐夫博弈
- hdu1542 矩形面积求并，离散化之后用扫描线+线段树做，注意一下每次更新端点的值

#### 2016年7月26日
- hdu4539 状压dp，poj1185的变形，考虑曼哈顿距离即可
- hdu2188 博弈
- hdu1527 威佐夫博弈

#### 2016年7月25日
- hdu5719

#### 2016年7月24日
- poj1185 状压DP，从二维到三维的建立模型，以及通过分析降低复杂度。
- hdu5729 dp，转换成二分匹配问题

#### 2016年7月23日
- hdu5718 

#### 2016年7月22日
- hdu5726 一个整数n的约数个数在logn以内，所以先对输入的数列建立rmq，又有所有的gcd值是递减的，然后预处理所有(l,r)值，存放在map中，具体是固定l，二分下界，统计个数。对与所有的输入直接查询就可以了。
- hdu5727 全排列+二分图匹配，枚举阴宝石的位置，一个有(n-1)!种可能，对于每一种可能如果不会影响阳宝石，建边，然后去跑二分图。

#### 2016年7月21日
- L2-016. 愿天下有情人都是失散多年的兄妹 对长辈进行性别标注
- L2-013. 红色警报 字母写错了……
- L2-014. 列车调度 导弹拦截问题中的本质是求一个序列的最长上升子序列（nlogn），只有这样才会新开导弹组。也就是本问题中的铁轨。
- hdu5724 sg函数，注意计算方法
- hdu5723 最小生成树，边的权值不同保证最小生成树唯一。求数学期望时，用dfs找出规律，但是10w个点中，5w乘以5w也会爆int
- poj2296 2sat

#### 2016年7月20日
- hdu1816 poj2723升级版，poj的题目可以把一组钥匙看做2-sat值，这道题目可以考虑值为选用某把钥匙，和不选用某把钥匙，从而来限制关系

#### 2016年7月19日
- hdu4115 2sat，建边的关键不是通过已知的信息连接，而是连限制的边。第一次建边时，将相同情况连了边，而没有考虑相同情况时导致的限制条件

#### 2016年7月18日
- poj2723 2sat，二分门的数量，然后判断
- poj3905

#### 2016年7月17日
- cf#362A

#### 2016年7月16日
- uvalive3713 2sat

#### 2016年7月15日
- poj3648 2sat,强连通+拓扑排序
- poj3678 2sat,强连通，注意建边关系即可：
 1. A,B不能同时取 < A,B' >< B,A' >
 2. A,B不能都不取 < A',B >< B',A >
 3. A,B必须都取或者都不取 < A,B > < B,A >< A',B' >< B',A' >
 4. 必须取A　<A',A>

#### 2016年7月14日
- poj2749 2sat+二分，两个点之间的距离超过二分值，连接不同的点
- patA1058

#### 2016年7月13日
- poj3683 2-sat
- cf#357C 用优先队列模拟堆，cout效率很低，会超时
- poj3207 2-sat，注意建边，这里和之前题目不同的之处在于，不选择的点也不能冲突。

#### 2016年7月12日
- hdu3622 2sat，注意建边
- cf#edu13D 矩阵优化
- cf#edu13E 状压DP，反过来想这个问题，假设dp[i][j]代表存活的人的状态为i，擂台上的人是j时，主人公获胜的概率。dp[i][j]=max(dp[i][j],p[j][k]*dp[i^(1<<k)][j]+p[k][j]*dp[i^(1<<j)][k]);

#### 2016年7月11日
- cf#edu13C 容斥原理

#### 2016年7月10日
- cf#361D rmq+二分搜索
- cf#57A 异或运算
- cf#57B 字符串处理
- cf#57D 贪心
- hdu1861
- poj1102
- poj1573
- poj2251
- poj3140 树形dp

#### 2016年7月9日
- hdu1426 搜索
- hdu1814 2-sat输出字典序最小的方案，注意建边的顺序

#### 2016年7月8日
- cf#361B 搜索
- cf#361C 二分+验证
- UVALive3211 2-sat问题入门
 
#### 2016年7月7日
- hdu5636 最短路floyd
- cf#361A
- hdu1732 搜索

#### 2016年7月6日
- cf#358C dfs，树形dp
- hdu2821 搜索
- cf#358D dp
- patA1006

#### 2016年7月5日
- cf#360D 数论
- patA1027

#### 2016年7月4日
- hdu1254 搜索

#### 2016年7月3日
- cf#360A
- cf#360B
- cf#360C 黑白染色问题
- hdu2822 优先队列
- hdu1372 搜索

#### 2016年7月2日
- poj3107 树的重心
- cf#359D 子树的重心

#### 2016年7月1日  
- cf#359B 冒泡排序变形题
- cf#359C 题目较难理解，搜索
- poj1655 树的重心
