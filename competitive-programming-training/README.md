# Competitive Programming Training

个人算法竞赛训练仓库：Codeforces 日常训练、牛客/校内训练赛、专题练习与赛后复盘。

**不追求每道题都写题解，但要求每个 AC 都能被找回、每个错误都能被复盘。**

## 目录结构

```
competitive-programming-training/
├── problems/                  # 题目代码，按平台 → 比赛/专题 分层
│   ├── codeforces/<场次>/      # 例：1059_Div3、Edu_184、Global_31
│   ├── luogu/<专题>/<题号>/    # 例：递归与递推/P1002
│   ├── school/                # 校内赛、NWPU、天梯赛、CACC
│   └── other/                 # 训练赛、CF group、临时题目
├── notes/                     # 算法与思维笔记（只写方法，不复制题目代码）
│   ├── algorithms/
│   └── thinking/
├── reviews/                   # 周复盘 / 月复盘
│   ├── weekly/
│   └── monthly/
├── templates/                 # 新建题目时复制的模板
│   ├── cpp/main.cpp
│   └── markdown/solution.md
├── docs/workflow.md           # 训练流程与工具链说明
├── .vscode/                   # 全仓库唯一一份 VS Code 配置
├── .clang-format
└── index.csv                  # 全部题目的索引（由 Codeforces API 生成）
```

## 命名规范

| 对象 | 规则 | 示例 |
|---|---|---|
| CF 常规场 | `<场次号>_Div<级别>` | `1059_Div3`、`1062_Div4` |
| Educational | `Edu_<场次号>` | `Edu_184` |
| Global | `Global_<场次号>` | `Global_31` |
| 联合场次 | `<contestId>_Div1+2` | `1088_Div1+2` |
| 题目文件 | 题号大写，多版本用 C1/C2 | `A.cpp`、`C1.cpp` |
| 需要复盘的题 | 建同名目录 + `main.cpp` + `solution.md` | `C/main.cpp` |

- 空格一律用 `_` 代替，不出现中文目录名（校内赛题面除外）。
- 禁止 `test.cpp`、`project_1.cpp`、`副本`、`output/`、`*.exe` 入库。
- 简单题只放代码；值得复盘的题才建目录写 `solution.md`。

## 一次训练怎么存

1. 复制 `templates/cpp/main.cpp` 到新场次目录，命名为 `A.cpp`、`B.cpp`…
2. 比赛结束后把该场目录放进 `problems/codeforces/`。
3. 在 `index.csv` 追加（或重新生成）索引行。
4. 值得复盘的题，补一个 `solution.md`（模板见 `templates/markdown/solution.md`）。

## 索引

`index.csv` 列：`date, platform, contest, problem, name, rating, tags, status, submissions, path, url`

- `status = AC`：已通过且代码在库。
- `status = AC-未存档`：CF 上通过了，但代码没存进来，`url` 直达提交页。
- `status = 未通过 / 未提交`：代码在库但当时没 AC。

## 环境

- 编译标准：**C++17**（`-O2 -Wall -Wextra`）
- 本机目前**没有可用的 g++**（旧的 GCC 3.4.5 随 GUIDE 一起移到了 `D:\Git\_local\GUIDE`），
  需要安装 MinGW-w64 并加入 PATH，`tasks.json` 才能工作。详见 `docs/workflow.md`。
