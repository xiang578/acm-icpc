
#### 20171104
- cf879c [暴力] 数字的范围为1-1023，所以用二进制表示需要10位，维护一个长度为10的数组，分别代表每一位，取值一共有三种0，1和未知。
#### 2017年8月18日
- uestc594 [单调队列优化] 推出公式之后直接维护一个最小值即可

#### 2017年5月11日
- cf807d 【枚举+贪心】枚举需要几个账号，再用贪心考虑一下提交哪些题目

#### 2017年5月10日
- cf807c 【二分】 刚开始用扩展欧几里德，改了好久才发现计算过程中会超过long long范围
- cf807b 【模拟】枚举所有的可能

#### 2017年5月9日
- cf807a 【】判断一下有没有改变，以及输入的数据是否有序
- cf757d 【状态压缩】longlong 超过内存限制

#### 2017年5月7日
- hdu6023 【模拟】
- hdu6024 【枚举+dp】dp[i]代表在i点建糖果屋，然后去枚举前一个建在哪里
- hdu6026 【最短路+树型图】以0为起点最短路形成的图上去找，刚好是所以其他点入度的乘积
- hdu6027 【暴力】
- hdu6029 【贪心】对于每一个没有连接的点，找一个后面最近的1的点
- hdu6030 【递推+矩阵快速幂】
- hdu6031 【dfs序+倍增】

#### 2017年5月6日
- cf803d 【二分+验证】 二分最短的长度

#### 2017年5月5日
- cf805d 【规律】最终的字符串左边是b，右边是a
- cf805c 【贪心】
- cf805b 【贪心】
- cf805a 【规律】

#### 2017年5月2日
- cf803c 【枚举+验证】如果有符合题目的答案，那么可以提取一个gcd出来，然后计算一下1到k-1的前缀和，前k-1项为i/*gcd，最后一项为`(n/gcd-1-2-...-k-1)/*gcd`,所以先计算一下n的所有因子，就可以枚举了。
- cf803a 【贪心】先放第一行，如果最后剩下一个，那么就放在对角线上。
- cf801c 【二分+验证】二分最大的时间，然后验证一下能量是否可以完成。
- cf803b 【循环】预处理出来每个数到左右两边0最近的距离，然后求个min就是答案

#### 2017年4月28日
- cf801d 【贪心】：凸包上每三个点一组，然后求三点组成三角形的垂心在哪里，取一个距离最小的即为答案。

#### 2017年4月27日
- cf801b 【贪心】
- cf801a 【枚举】
- cf198d 【分组贪心】：先按A从小到大排序，然后取第一组，之后每两组之间取b大的为结果。
- 
#### 2017年4月25日
- cf798b【枚举】：暴力枚举哪一个字符串是最终的结果，然后取最小值
- cf798c【GCD+猜想】 猜了一下，如果输入的数列gcd已经大于1那么直接输出，否则要去构造，然后发现两个奇数操作一次之后会得到两个偶数，一奇一偶操作2次都是偶数，这样可以找出一个数列gcd值大于等于2。对于每个奇数，看一下后面的那个数的奇偶性，再决定+1还是+2就可以了。

#### 2017年1月26日
- cf#2016c 对于每一次分数变化考虑分数的最大值和最小值，然后再判断是否符合逻辑即可
- cf#390a 只要不是0的数字都分一组，0时分到前面一组，刚开始的连续0先处理一下
- cf#390b 枚举x可能的位置，然后验证是否符合要求就好了。
- cf#393d 线性dp，对于每个时间结点，考虑以当时为买票的最后时间dp，分别处理买20 50 120的票的情况，用lower_bound找出没有被这一次买票所覆盖旅途的最小花费
- cf#383c 处理一下有多少个环，统计每个环的节点数，最后答案是节点为偶数的环/2和奇数环的最小公倍数

#### 2017年1月25日
- cf#391a 统计
- cf#391b 处理出每一个数的所有因子，找出出现最多因子的个数

#### 2017年1月24日
- cf#393b 二分+验证
- cf#393c 所有点的要连成一个大的圈，所以输入的图中有几个圈，就要修改几次，然后翻面只需要b数列有奇数个1

#### 2017年1月23日
- cf#8vc2017c 并查集
- cf#8vc2017d 连线会有一个规律，如果新的线与原来连的n条线相交，那么就会增加n+1。所以每次只要计算出相交直线的数量就可以了。用一下树状数组，统计一下新的直线两端点之间有多少个线段的端点。
- cf#393a 模拟

#### 2017年1月22日
- cf#392d 贪心，重右往左开始构造，然后特殊考虑0的问题，就是验证一下要不要断开这个0
- cf#8vc2017a 
- cf#8vc2017b 重复的单词，分给两个人之后，比较会单词的数量

#### 2017年1月20日
- cf#392a 
- cf#392b 枚举4种颜色的排列组合，然后暴力检查一下
- cf#392c 先将前几轮的回答数计算出来，最后一轮直接模拟

#### 2017年1月18日
- hdu2273 
- hdu2274 
- hdu2275 set使用
- hdu2276 刚开始在找循环节，后来提醒才知道是矩阵快速幂优化dp，矩阵乘法的时候可以优化一下
- hdu2277 找规律 
- hdu2279 最暴力的想法
- hdu2280 状压dp

#### 2017年1月17日
- cf#2016a 暴力枚举
- cf#2016b 根据题意分析，你会发现所有的东西移动是没有用的，只需要考虑南北方向的移动
