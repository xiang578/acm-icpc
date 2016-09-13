190

#### 2016年9月13日
- patA1116 按题意输出即可
- patA1117 排序，然后对于每个ai，看一下后面是否有ai-1个数，如果有的话，就是一个符合条件的答案， 最后取ai-1最大。
- patA1118 并查集应用
- patA1119 已知前序和后序遍历，求一种中序遍历，这里只要递归建树就可以了，然后中序遍历不唯一的情况是有一个结点只有一个子结点，特判一下就可以了。


#### 2016年9月12日
- cf#370c 刚开始想从(x,x,x)进过一些方法得到(y,y,y)，但是想了好多方法都不行。后来发现反过来想比较简单从(y,y,y)开始，按照三角形的要求得到下一个为(2*y-1,y,y)，然后一直这样做下去。最后当三角形边最小的长度大于x时，就可以结束了。

#### 2016年9月11日
- cf#370a 
- cf#370b 每一个走一个u必须要再走一个d，走一个l必须要再走一个r，反之也成立，所以统计一下就可以了。
- hdu5874 找规律
- hdu5877  dfs+离散化+树状数组，树状数组维护不同的值有多少个，访问某一个点先计算，然后再将这个点的值加进去，回溯是减去。
- hdu5876 维护两个set，一个表示补图已经与s直接或间接连接了的点集合，另一个表示还没有连接的，所以每一次从第一个集合中取出一个点，然后与第二个集合中没有原来链接的点，都可以在补图中连一条边，一直重复这样的操作不断减少第二个集合点的数量，-1的情况是某个点原来和剩下的其他点都有边相连。

#### 2016年9月10日
- hdu5873
- hdu5876 bfs+set

#### 2016年9月8日
- patA1048 对于输入x<=m,看一下前面时候出现过m-x，如果有那么有解。在标记一下x出现了。

#### 2016年9月6日
- cf#338a
- cf#338b 找一条上升的链，美丽值为链的长度乘以序号最大的点连的边数量。所以反过来想，找出每一点可以组成的最长下降的链的长度，然后比较一下。
- cf#339c 贪心，预处理a[i][j]为t从i开始和s从j开始最多匹配多少个字母，同理处理出来s翻转之后的值，之后就是贪心，遍历每一个t中的字母，一直从已经匹配的里面加上去。
- patA1019 计算出d进制下n的值，然后判定一下是否是回文数。
- patA1021 并查集+树形dp，用并查集判断一下是否是树，然后dfs以1为根计算出最大的深度，第i个点的答案一定是与它相连的父结点那块的最大深度或者是自己的子树的最大深度+1，然后如果是最大肯定有一个是0的，所以也可以用树的直径去做。

#### 2016年9月5日
- patA1014 模拟，有几个窗口就开几个队列，然后考虑一下每次处理完成任务时间最早的那一个，如果还有排队的就加到这个队列去。最后注意，只要某个人在17点之前被服务到，都不用输出Sorry。
- patA1015 先将n转化为d进制下的数x，然后获得相反的数y，将y转化为10进制下的数m，最后看一下n和m是否为素数。
- poj3367 线段树，每个结点维护从左开始最大有多少个连续的0、从右开始最大有多少个连续的0，两个子树合并时中间有多少个连续的0。根据维护的信息查询即可。

#### 2016年9月4日
- patA1012 对每一门课程分别排序，最后比较输出。
- patA1013 对于每一个被询问的城市，删除与其相连的边，再进行dfs搜索，统计出有多少连通块，答案为连通块数量减一。

#### 2016年9月3日
- patA1010

#### 2016年9月2日
- patA1011

#### 2016年9月1日
- poj2484
- poj3111 01分数规划
- poj3414 搜索
- poj1118 枚举

#### 2016年8月31日
- poj1952 nlogn求最长下降子序列，对于每个数字遍历之间大小大于它的并且可以放置在它前一个位置的，累计答案，不能用树状数组之类的保存。
- cf#363a
- cf#363b 随便取一个点，枚举全部n+m的点为放置炸弹的点，检查一下。
- cf#363c dp

#### 2016年8月30日
- cf#346f 将所有点按从大到小排序，然后用并查集维护相邻并不小于a的，如果有某个并查集内的最小值乘以点的个数大于k，并且k能整除a，就用bfs找到一组合适的解输出。
- cf#369d 图比较特殊，找出图中有多少个环就可以了，每一个环对答案的贡献为乘上2^n-2，其中n为环中顶点的个数，最后乘上2^m，m为不在任何一个环上的点的数。
- poj2774 后缀数组
- poj1035 暴力
- poj2231 计算任意点之间的距离和
- hdu3466 排序之后01背包

#### 2016年8月29日
- cf#346b 排序
- cf#346c 暴力+二分
- cf#346d 找出四种会掉入水里的情况
- cf#346e 贪心，从某一没有访问过的点出发，如果找到一个环，那么出发的点也可以访问到。
- cf#349a 
- cf#349b 计算出要填的数字，然后在验证一下是不是幻方。
- cf#349c dp，n^4，dp[i][j][k]，i代表第i棵树，j代表涂的颜色，k代表前i个分成的段数。

#### 2016年8月28日
- AIM Tech Round 3e 树形DP，对于一个点u，如果没有一个子树的大小大于n/2，那么这个点就是重心。另外最多只有一个子树v的大小大于n/2，这时候要考虑在v中删除最大的一个节点数不超过n/2的子树，如果删去后子树v的节点数还是大于n/2，那么u不可能成为重心。维护两个数组，down和up，down代表以u为根的树里面的子树节点数不超过n/2的最大值，up代表u的搜索过程中不包含u为根的树中子树节点数不超过n/2的最大值。up值计算需要注意一下。

#### 2016年8月27日
- cf#364a 
- cf#364b 简单容斥,维护一下每行每列有没有放置过，已经放了几个，然后容斥计算一下。
- cf#364c two points，题意就是找一个包含全面出现过的字符的最短子串长度，维护左右端点取一下就好了。
- cf#364d 贪心加二分验证，将n分成每组最多k个人的小组来考虑，问题中要求的就是最后一组什么时候到达，然后可以想到的一点是，汽车最好在所有的时间里面都在运行，所以我们枚举第一组坐车多少米，之后他们就是步行到终点，计算一下这样的时间，并且假设这个是答案，在去验证剩下的小组能不能在这个时间内达到终点。
- cf#365e 两次dfs，从1开始搜索，son[x]记为以x为根的子树里有多少所大学，然后找到第一个son[x]>=m的做为下一次dfs的起点。第二次dfs以x为起点，计算到每一所大学的距离，然后在累加一下。另一种做法就是考虑每一条边取左右最小的大学数作为对答案的贡献。
- hdu5772 最大权闭合子图，注意一下建图。

#### 2016年8月26日
- AIM Tech Round 3a 模拟
- AIM Tech Round 3b 分别考虑第1个点不走或者第n个点不走，那一段路走两遍，还要考虑起点是在这些点的中间、左边还是右边。
- AIM Tech Round 3c 改变从左到右遇到的第一个可以改变的字符串，特别注意一下如果给定的串全部由a组成要改变最后一个a。
- AIM Tech Round 3d 00和11的个数可以推测出0和1的个数，设00为n个，0为m个，有n=(m-1)*m/2。如果00和11的个数为0的话，如果有10和01的，那么0和1的个数为1。假设0为x个，1为y个，那么10和01的个数必要符合等于x * y。最后构造答案，假设有一个x个0的字符串，那么我们去构造10的这种组合，只需要在字符串中插入1，然后统计一下这个1后面有几个0，如果刚好有符合题目个10组合，那么把1全部放在最后一个0的后面。这样子01会自动符合条件的。

#### 2016年8月25日
- poj1835 每一个状态维护face、head、right分别是哪边
- poj3087 模拟
- poj3254 状态压缩dp
- poj3083  第三问的答案直接bfs即可。前两问本质相同，对于到达每一个点维护一个方向，先走左边的就是从左边的开始顺时针走，另外一种情况从右边的开始逆时针走。
- hdu4911 数列如果有逆序对，那么肯定存在交换一对相邻的减少一个逆序对。所以只需要求出所有逆序对的个数，与k比较大小就可以了。求逆序对可以先用离散化或者排序，之后在用树状数组来统计。排序的时候要采用稳定排序stable_sort()。
- hdu4907 

#### 2016年8月24日
- cf#366b n为奇数2胜利，为偶数1胜利，每一个都这样考虑，再考虑如何合并即可。
- cf#366c queue模拟，注意是前t个生成的信息而不是前t个操作。
- cf#366d 贪心，最后形成的链一定是s为起点，t为终点，对于每一个i遍历前面已经生成的链找一个最优点插进去，一直这样操作找到的一定是最优的。

#### 2016年8月23日
- cf#368d bitset+dfs,构建一棵树来，每一个输入与前一个相连结，对于操作四与第k个链接，注意搜索的时候回溯。
- cf#edu16a 
- cf#edu16b 找中间的一个数
- cf#edu16c 最中间一行全部放奇数，之后向上向下每一行减少放两个奇数，最后剩下的位置放偶数。
- cf#edu16e dp，n的范围在1e7以内，所以可以保留全部答案，也可以从n开始往下搜索。
  
#### 2016年8月22日
- cf#368e 二维树状数组+暴力更新。

#### 2016年8月21日
- cf#365d 自己只想到莫队算法，但是这次居然数据范围有1e6个，所以毫无疑问的超时。根据这道题目的特点，当加入某一个数字时，第一次出现不用统计，第二次出现才要统计。所以将所有查询离线，然后对查询区间按r排序，之后对于比较当前查询的r与已经求的的r的关系，如果小了，将前一个出现这个数的位子上异或上对应的这个数字。然后再查询l开始的值。可以放在树状数组上维护。
- cf#368a 
- cf#368b 找出一条两端点分别可以建仓库和建面包店的权值最小的边即可
- cf#368c 根据勾股定理，a*a=(c-b)*(c+b),如果输入的n为奇数，那么把它当成a带入到式子中，把c-b当成1解出b和c，如果输入n能整除4，那么用3、4、5构造出一个解来，最后剩下的可以整除2的先除以2剩下的一定是一个奇数，按第一种构造就可以了。特判1和2为不可能。