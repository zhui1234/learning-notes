# 双指针与尺取法学习路径

创建日期：2026-10-24。共 17 道题；完成情况尚未确认，统一标为“未记录”。

## 文件怎么保存

代码按平台和题号保存，题单只引用代码路径。同一道题参加多个专题时，复用原来的代码，不再复制。已有比赛目录里的题目继续留在原处。

```text
competitive-programming-training/
├── problem-lists/two-pointers/
│   ├── README.md                  # 学习路径与保存规则
│   └── checklist.csv              # 17 道题及进度记录
├── problems/
│   ├── codeforces/practice/279B/
│   │   ├── main.cpp               # 开始做题时再创建
│   │   ├── solution.md            # 有卡点才写
│   │   └── in.txt                 # 可选：保留能复现错误的数据
│   ├── luogu/two-pointers/P1638/main.cpp
│   └── qoj/practice/13165/main.cpp
├── notes/algorithms/two-pointers.md
└── templates/markdown/practice-solution.md
```

以上题目目录是命名示例，尚未预建代码文件。开始某题时创建对应目录，从 `templates/cpp/main.cpp` 复制代码模板；需要复盘时再复制 `templates/markdown/practice-solution.md`。

## 题单与导出

- [题单与进度 CSV](checklist.csv)：作为仓库内的进度记录，可用 Excel/WPS 打开；采用 UTF-8 BOM 编码。
- [Excel 导出版](../../../outputs/two-pointers-20261024/two-pointers-checklist.xlsx)：有筛选、冻结表头和状态下拉选项，是本次导出的副本。
- 两份文件不会自动同步。建议长期维护 CSV；如果主要使用 Excel，就以 Excel 为准，更新后另存 CSV 覆盖本目录的题单。
- 每次做题后填写状态、卡点、用时、首次通过日期和下次复习日期。日期填写 `YYYY-MM-DD`，用时填写分钟数。
- 状态使用：未记录、未做、尝试中、看题解 AC、看提示 AC、独立 AC、已复做。
- 题单中的代码路径均相对 `competitive-programming-training/`；它们是建议保存位置，已有代码时改成实际路径。
- 根目录 `index.csv` 记录实际提交与存档情况；本题单用于计划与掌握程度。尚未做的推荐题先放在本题单，通过并存档后再登记到总索引。

## 第一阶段：基础双指针（2～3 天）

1. [洛谷 P1094 纪念品分组](https://www.luogu.com.cn/problem/P1094)：排序后首尾配对，理解贪心。
2. [CF 6C Alice, Bob and Chocolate](https://codeforces.com/problemset/problem/6/C)：两端扫描，处理相遇和同时完成。
3. [洛谷 P1102 A-B 数对](https://www.luogu.com.cn/problem/P1102)：排序后同向扫描，统计重复值。

过关标准：能够解释每次移动排除了哪些不可能的答案。扫描为线性时间时，也要算上排序成本。

## 第二阶段：最长合法窗口（3～4 天）

4. [CF 279B Books](https://codeforces.com/problemset/problem/279/B)：正数数组中总和不超过预算的最长区间。
5. [洛谷 P1147 连续正整数和](https://www.luogu.com.cn/problem/P1147)：根据区间和扩张或收缩，枚举所有解。
6. [CF 1133C Balanced Team](https://codeforces.com/problemset/problem/1133/C)：排序后限制最大值与最小值之差。
7. [CF 580B Kefa and Company](https://codeforces.com/problemset/problem/580/B)：排序、窗口权值和与严格不等号。
8. [CF 660C Hard Process](https://codeforces.com/problemset/problem/660/C)：把最多修改 k 次转化为窗口内零的数量限制。
9. [CF 616D Longest k-Good Segment](https://codeforces.com/problemset/problem/616/D)：频次、种类数、最长合法区间。

过关标准：右端加入元素，不合法就收缩，恢复合法后更新最长答案。能够说明为什么边界不必回退。

## 第三阶段：最短覆盖与时间窗口（3 天）

10. [洛谷 P1638 逛画展](https://www.luogu.com.cn/problem/P1638)：最短覆盖全部种类，处理并列答案。
11. [CF 701C They Are Everywhere](https://codeforces.com/problemset/problem/701/C)：先确定目标种类，再求最短覆盖。
12. [洛谷 P1381 单词背诵](https://www.luogu.com.cn/problem/P1381)：字符串映射与覆盖目标。
13. [洛谷 P2058 海港](https://www.luogu.com.cn/problem/P2058)：按时间淘汰过期乘客，维护国籍种类数。

过关标准：最短覆盖在满足条件时先更新答案，再尝试收缩；频次 0→1 时增加种类，1→0 时减少种类。

## 第四阶段：计数与综合（4～5 天）

先做自拟练习：将 CF 616D 改为统计“至多含 k 种不同数字”的子数组个数。固定右端点 r，若最小合法左端点为 l，则贡献 r-l+1。继续推导“恰好 k 种 = 至多 k 种 - 至多 k-1 种”。

14. [CF 190D Non-Secret Cypher](https://codeforces.com/problemset/problem/190/D)：统计存在某个值出现至少 k 次的区间，练习补集计数。
15. [洛谷 P3143 Diamond Collector S](https://www.luogu.com.cn/problem/P3143)：尺取与前后缀最优值，组合两个不重叠区间。
16. [CF 1358D The Best Vacation](https://codeforces.com/problemset/problem/1358/D)：环形序列与边界部分的计算。
17. [QOJ 13165 Gift Boxes](https://qoj.ac/problem/13165)：删除一段使剩余元素互异；先练每个队伍恰好出现两次的子任务，再挑战完整数据。[官方题解](https://qoj.ac/download.php?id=13165&type=solution)。

## 每道题怎么练

先独立思考 25～40 分钟，明确维护信息、收缩条件和更新时机。卡住后先看提示，通过后用三句话解释单调性、不漏解的原因和复杂度。

看题解通过的题隔天复做；独立通过但不熟练的题隔几天再做。根据实际学习日填写复习日期，不预设固定日历。

时间有限时优先：P1094 → P1102 → 279B → 660C → 616D → P1638 → P2058 → 190D → P3143 → QOJ 13165。
