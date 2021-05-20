cpp:
1.为什么基类析构函数用virtual？ (使基类的指针指向派生类对象，用基类的指针删除派生类对象)
    如果实例化时:Base *derived = new Derived;
		delete derived;
    会出现:
	constructor base
	constructor derived
	(destructor derived)
	destructor base
    派生类没有析构(即第三行没有执行)

    如果一个类要使用多态(即Animal父类将会派生出Dog Cat等)，那么Animal的析构函数必须加virtual
    (不主动写virtual是不会加virtual的)
    (自己初步理解：delete基类时会递归根据析构函数虚函数的表进行递归，找到最子类的析构函数开始一层层地delete)

2. 抽象类与接口的区别？
    一般接口只有成员函数，而抽象类还具有成员变量
    但是cpp好像一般不区分
    抽象类是成员函数至少有一个为虚函数
    从抽象类中派生出的子类要重写父类virtual函数时，加不加virtual关键字都可以

3. 当Base类中有virtual void a()，和void b()时，子类void a(), void b()
    声明Base *aaa = new Foo; 和声明Foo *bbb = new Foo;
    分别调用a，b会有什么不同？
    aaa->a();
    aaa->b();
    结果为：
    foo a
    base b

    bbb->a();
    bbb->b();
    结果为：
    foo a
    foo b
    即父类的虚函数调用时应该会优先找子类是否实现

4. public, protected, private继承区别
    个人理解,public几乎是将父类的权限直接赋值到子类
    protected是为了派生类的派生类还可以用基类的方法,但是又不想让对象访问
    private是只派生类自己用父类的方法，同时对象也不允许访问

5. 树与图的区别
    树只有根节点没有入度，而其他所有节点的入度为1
6. 并查集可以用来判断图是不是树
7. 对有向图删一条边使其变为树
    (1) 如果有入度为2的节点，入度为2的节点一定只存在一个，其对应两条边，看删哪一条边可以变为树
    (2) 否则就一定存在有向环

8. 二分查找
    查找左边界的意义: {1, 2, 3, 7} target = 8, 会返回4，即left可能会等于nums.size(), 含义为小于target的数字个数
    右边界：{1, 2, 2, 4} target = 0, 会返回-1, 
    注意：{1, 2, 5, 7, 9} target = 8, left_bound会返回4, right_bound会返回3

9. priority_queue
    less<int> 大顶堆(默认) 弹出大元素
    greater<int> 
    如果想排pair:(要声明vector<pair<>>)
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> q;
    自己写cmp:(不能lambda)
    struct cmp {
	// p2大的优先返回，即p2是右面项，右面项优先返回
	bool operator()(pair<string, int> &p1, pair<string, int> &p2)->bool{
	    return p1.second < p2.second;
	}
    };

10. 位操作
    1.	('a' | ' ') = 'a'
	('A' | ' ') = 'a'
    2.	('a' & '_') = 'A'
	('A' & '_') = 'A'
    3.	('a' ^ ' ') = 'A'
	('A' ^ ' ') = 'a'

    4. 判断异号: ((x ^ y) < 0)
    5. 消除二进制中最后一个1: n&(n - 1) (0b110100 & 0b110011)
    6. 判断一个数是不是2的指数: 因为2的指数在二进制中只有一位1，所以rst = !(n & (n - 1))
	
11. upper_bound返回第一个大于target的下标
    lower_bound返回第一个大于等于target的下标

12. set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set, set.end()));	// 使用前两个set必须先排序，而且还可以用于vector等容器
    set_union	    // 可以对unordered_multiset

13. dp完全背包两重for顺序问题：
// 01背包
for (int coin : coins) {
    for (int i = amount; i >= coin; i--) {
	dp[i] += dp[i - coin];
    }
}
// 完全背包求组合
for (int coin : coins)
    for (int i = coin; i <= amount; i++) {
	dp[i] += dp[i - coin];
    }
}
// 完全背包求排列
for (int i = 0; i <= n; i++) {
    for (int coin : coins) {
	if (i - coin >= 0) dp[i] += dp[i - coin];
    }
}
一般情况下组合小于排列数
例如：1, 1, 2和1, 2, 1是同一种组合，但却是两种排列

14. 如果一组数的gcd不是1，那么他们能凑出的数只能是gcd的倍数，即有无限多不能凑出的数。

15. 二分找峰值
    int left = 0, right = n - 1;
    while (left <= right) {
	int mid = left + (right - left) / 2;
	if (nums[mid] > nums[mid + 1])
	    right = mid - 1;
	else
	    left = mid + 1;
    }
    return left;

16. 确保取余之后是正数，即-2 % 5 == 3
    (a % mod + mod) % mod;

17. 杨辉三角对每个值对2求余，每行1的个数为Sn = (n & (-n)) << (g(n) - 1) g(n)是n这个数二进制含有1的个数
    例如S5(0101)  = (0001) << (2 - 1)  =  (0010) 即两个1

18. (n / k) % 2 == 0与n % (2 * k) 是否一样

19. 判断两个有序数组中最接近的值(自己想的，不知道是否有复杂度更低的方法):
    // 可以先判断选择元素少的当v1
    // 复杂度为O(min(nlogm, mlogn)) n = v1.size(), m = v2.size()
    int rst = INT_MAX;
    for (int i : v1) {
	auto it = upper_bound(v2.begin(), v2.end(), i);
	if (it != v2.end())
	    rst = min(rst, abs(i - *it));
	if (it != v2.begin())
	    rst = min(rst, abs(i - *--it));
    }
    return rst;

20. 分堆问题
    5个球分3堆，每堆至少一个
    C(5 - 1, 3 - 1) // 4个缝隙，2个挡板
    每堆可以为空
    C(5 - 1 + 3, 3 - 1) // 只是相当于多了3个空隙

21. 求两个矩形相交的面积: 矩形1左下、右上顶点分别为(a, b), (c, d) 矩形2(e, f), (g, h) (自己在图上画一下)
    topx = min(c, g) topy = min(d, h) bottomx = max(a, e) bottomy = max(b, f);

22. 一个数的约数个数=所有质因子的次数+1的乘积
    例：48 = 2 ** 4 + 3，所以48的约数个数为：(4 + 1) * (1 + 1) = 10

23. 树状数组是省掉一半空间的线段树加上中序遍历

24. lis(最长递增子序列):
    O(nlogn), O(n), 用到了(二分查找和贪心),同时也改变了原来dp的含义
    lcs(最长公共子序列)	    // (如果两个序列为同一排列，例如v1 = {3, 2, 1, 4, 5}, v2 = {1, 2, 3, 4, 5}, 那么可将v1离散化{3:1, 2:2, 1:3, 4:4, 5:5}, 然后将v2反离散化得{3, 2, 1, 4, 5}, 求这个序列的lis即可将时间复杂度降低到O(nlogn))
    O(n2), O(n), 采用了滚动dp，将二维空间压缩为一维，代码见leetcode1143

25. 判断无向图是不是树：只要判断该图是一个包含n个顶点的连通子图，且边数为n - 1

26. dilworth定理：偏序集的最少反链划分长度等于最长链的长度
    luogu(1020)
    v = {389 207 155 300 299 170 158 65}, 求最少可以划分为多少个降序子序列(不是严格，即>=),答案等于严格升序子序列长度(>)
    (最长不上升子序列的个数==最长上升子序列的长度)

27. s1 = "11112", s2 = "21111"，求最少需要多少次邻位交换使s1变为s2？(leetcode 1850)
    int n = s1.length();
    int rst = 0;
    for (int i = 0; i < n; i++) {
	if (s1[i] != s2[i]) {
	    int j = i + 1;
	    while (s1[j] != s2[i]) j++;
	    rst += j - i;
	    while (j > i) {
		swap(s1[j], s1[j - 1]);
		j--;
	    }
	}
    }
    return rst;

    更优解法见min_adj_swap.cpp 
    (使数列升序(或不降序)所需要的邻位交换次数就是求其逆序对个数)

28. 离线处理，(leetcode 1851还有这周上一周的周赛D题)

29. 连通：无向图两个点互相可达
    连通分量：至少一条回路包含分量内所有顶点
    连通图：无向图中任意两个顶点都连通(存在路径)
    强连通：有向图两个点互相可达
    强连通分量：至少一条回路包含分量内所有顶点，非强连通有向图的极大强连通子图(scc: strongly connected components)
    强连通图：有向图中任意两个顶点都强连通
    kosaraju, tarjan(复杂度更小)
    
30. 找无向图不在环内的所有点：将图反向，对反图进行拓扑排序(讲解：https://leetcode-cn.com/problems/find-eventual-safe-states/solution/zhao-dao-zui-zhong-de-an-quan-zhuang-tai-by-leetco/)

31. 有向图每个点能到达的最大编号？(反向建图，从最大的点开始反向遍历，能到达的点最大值就是这个点)

32. 单调队列luogu 2251

33. 想保留排序数组之前的下标：v = {5, 4, 2, 6, 3, 1}
    vector<int> order(v.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
	return v[i] < v[j];
    });

    order = {6, 3, 5, 2, 1, 4};

    for (int i : order) {
	int val = v[i];	    // i就是下标，val就是值
    }

34. 求有向图最小环(权为1)：并查集
    见luogu 2661

35. 顺序*顺序>=乱序*乱序>=逆序*逆序(换成加法也一样)
    {1, 3, 5, 7} * {2, 4, 6, 8} >= {1, 7, 3, 5} * {6, 2, 4, 8};

36. luogu 1972
    离线(sort query进行处理)，线段数组(单点修改，区间查询)

37. 费马小定理：a为任意自然数，p为质数，则a ** p % mod == a % mod(同余符号不会打)

38. 整除和除尽不同(除尽是值结果小数为有限位)
    a | b，即b是a的倍数

39. 费马平方和定理：奇质数a能表示为两个平方数之和充要条件是a % 4 == 1

40. dij最短路计数：luogu 1144
    dij最短路计数和记录最大权值路径 l2 1001

41. 次短路：luogu 2865(严格次短路(有回路))
