cf#390c
cf#390d
cf2016d
cf#391c
cf#391d

#2017年1月26日
- cf#2016c 对于每一次分数变化考虑分数的最大值和最小值，然后再判断是否符合逻辑即可
- cf#390a 只要不是0的数字都分一组，0时分到前面一组，刚开始的连续0先处理一下
- cf#390b 枚举x可能的位置，然后验证是否符合要求就好了。
- cf#393d 线性dp，对于每个时间结点，考虑以当时为买票的最后时间dp，分别处理买20 50 120的票的情况，用lower_bound找出没有被这一次买票所覆盖旅途的最小花费
- cf#383c 处理一下有多少个环，统计每个环的节点数，最后答案是节点为偶数的环/2和奇数环的最小公倍数

#2017年1月25日
- cf#391a 统计
- cf#391b 处理出每一个数的所有因子，找出出现最多因子的个数

#2017年1月24日
- cf#393b 二分+验证
- cf#393c 所有点的要连成一个大的圈，所以输入的图中有几个圈，就要修改几次，然后翻面只需要b数列有奇数个1

#2017年1月23日
- cf#8vc2017c 并查集
- cf#8vc2017d 连线会有一个规律，如果新的线与原来连的n条线相交，那么就会增加n+1。所以每次只要计算出相交直线的数量就可以了。用一下树状数组，统计一下新的直线两端点之间有多少个线段的端点。
- cf#393a 模拟

#2017年1月22日
- cf#392d 贪心，重右往左开始构造，然后特殊考虑0的问题，就是验证一下要不要断开这个0
- cf#8vc2017a 
- cf#8vc2017b 重复的单词，分给两个人之后，比较会单词的数量

#2017年1月20日
- cf#392a 
- cf#392b 枚举4种颜色的排列组合，然后暴力检查一下
- cf#392c 先将前几轮的回答数计算出来，最后一轮直接模拟

#2017年1月18日
- hdu2273 
- hdu2274 
- hdu2275 set使用
- hdu2276 刚开始在找循环节，后来提醒才知道是矩阵快速幂优化dp，矩阵乘法的时候可以优化一下
- hdu2277 找规律 
- hdu2279 最暴力的想法
- hdu2280 状压dp

# 2017年1月17日
- cf#2016a 暴力枚举
- cf#2016b 根据题意分析，你会发现所有的东西移动是没有用的，只需要考虑南北方向的移动