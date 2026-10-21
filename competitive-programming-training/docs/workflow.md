# 训练工作流

## 1. 赛前 / 平时

```powershell
# 新建一场比赛（示例：Codeforces Round 1090 Div.4）
$d = "problems/codeforces/1090_Div4"
New-Item -ItemType Directory -Force $d | Out-Null
1..7 | ForEach-Object {
    $letter = [char](64 + $_)
    Copy-Item templates/cpp/main.cpp "$d/$letter.cpp"
}
```

## 2. 赛中

- `Ctrl+Shift+B` 编译当前文件（`tasks.json` 里的 `build`）。
- `F5` 调试（`launch.json`，断点在入口）。
- 本地样例放 `in.txt`，在 `main.cpp` 里临时打开 `freopen`，提交前注释掉。

## 3. 赛后

1. 删掉 `.exe`（`.gitignore` 已忽略，一般不会进库）。
2. 该场目录移入 `problems/codeforces/<场次号>_Div<级别>/`。
3. 只保留有意义的题号文件；空模板和 `test.cpp` 不要留。
4. 值得复盘的题，建目录：

```
problems/codeforces/1059_Div3/C/
├── main.cpp
├── solution.md
└── in.txt        # 可选，放样例/构造数据
```

## 4. 更新索引

`index.csv` 由 Codeforces 公开 API 生成，字段含义见根目录 `README.md`。
更新方式（需要联网）：

```powershell
# 拉取本人提交记录
Invoke-RestMethod "https://codeforces.com/api/user.status?handle=zhui__&from=1&count=10000"
```

`status = AC-未存档` 的行表示：CF 上 AC 了，但代码没进仓库。
点 `url` 打开提交页，复制源码到对应路径即可转为 `AC`。

> 说明：Codeforces 网页有 Cloudflare 人机验证，脚本无法直接抓取提交源码，
> 只能手动复制。API 本身可用。

## 5. 每周 / 每月复盘

- `reviews/weekly/2026-W16.md`：本周打了哪些场、AC 率、典型错误。
- `reviews/monthly/2026-04.md`：专题覆盖情况、下月计划。
- 复盘只写"可迁移的经验"，不抄题解。

## 6. 工具链

| 工具 | 状态 |
|---|---|
| VS Code | 已配置 `.vscode/`（编译、调试、C++17） |
| g++ | **未安装**，需装 MinGW-w64 并加入 PATH |
| clang-format | 已配置 `.clang-format`（Google + Allman） |
| Git | 仓库 `github.com/zhui1234/learning-notes` |

安装 MinGW-w64 后，`.vscode/tasks.json` 里的 `g++` 会自动从 PATH 解析。
