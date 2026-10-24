# 训练工作流

## 1. 赛前 / 平时

```powershell
$d = "problems/codeforces/1090_Div4"
New-Item -ItemType Directory -Force $d | Out-Null
1..7 | ForEach-Object {
    $letter = [char](64 + $_)
    Copy-Item templates/cpp/main.cpp "$d/$letter.cpp"
}
```

## 2. 赛中

- VS Code 通过“文件 → 打开文件夹”打开 `competitive-programming-training`。
- 保存代码并切到要执行的 `.cpp` 标签页；以下操作针对当前活动文件，而不是资源管理器中选中的文件。
- `Ctrl+Shift+B` 编译当前文件（`tasks.json` 里的 `build`），输出到该文件所在目录的 `main.exe`。同目录不同题目会覆盖这个文件，因此切换题目前先停止运行或调试。
- `Ctrl+F5` 先编译再运行；首次需要选择配置时，选择 `C/C++ Debug`。
- `F5` 先编译再调试；点击行号左侧设置断点，`F10` 逐行执行，`F11` 进入函数，`Shift+F5` 停止。未设置断点时不会自动在入口停下。
- 另一种运行入口：命令面板选择 `Tasks: Run Task` → `run`，也会先编译再运行。
- 新模板使用 `#ifdef LOCAL` 控制文件输入输出，编译任务已添加 `-DLOCAL`。从模板新建的题目使用同目录的 `in.txt` 和 `out.txt`；已有题目需自行加入模板中的条件重定向代码才会启用。
- 同一目录放 `A.cpp`、`B.cpp` 时，共用 `in.txt` 和 `out.txt`，切换题目时替换输入。`in.txt` 手动创建并填入数据（最后一行以换行结束）；`out.txt` 自动创建，每次运行覆盖旧内容。运行结束后查看 `out.txt`；运行途中输出可能尚在缓冲区中。
- 没有加入条件重定向的旧题目仍在下方“终端”输入输出。“调试控制台”显示调试器日志；使用文件输出后，`cerr` 和 `perror` 仍显示在终端。
- 编译失败时修正错误再启动，工作区已设为编译出错时中止调试，避免运行旧程序。
- CPH 使用相同的 g++ 和 C++17，采用 `-O2` 测样例且不定义 `LOCAL`，因此照常使用 CPH 的输入输出，不读写这里的 `in.txt` / `out.txt`。CPH 的样例不会自动传给 F5，调试时需复制到 `in.txt`（新模板）或终端（未加入重定向的旧题目）。
- Code Runner 是另一套独立入口，不读取 `tasks.json`；建议平时用 CPH 测样例、F5 调试、Ctrl+F5 运行。
- 提交源码时保留 `#ifdef LOCAL ... #endif`，无需删除 `freopen`：普通在线评测编译不定义 `LOCAL`，这段代码便不会参与编译。不要在源码中写 `#define LOCAL`。手动编译时，加 `-DLOCAL` 启用文件模式，不加则使用标准输入输出。
- `freopen` 使用的是进程工作目录，不会自动查找源文件位置；本项目的运行、调试配置均以 `${fileDirname}` 为工作目录。从其他终端手动运行时，先进入题目目录。
- 本地文件模式运行前需准备好 `in.txt`。`out.txt` 和所有 `.exe` 已被 Git 忽略，`in.txt` 可随代码保存以复现测试。

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
| g++ | `C:/Users/13014/mingw64/bin/g++.exe`，已安装 |
| GDB | `C:/Users/13014/mingw64/bin/gdb.exe`，已安装 |
| clang-format | 已配置 `.clang-format`（Google + Allman） |
| Git | 仓库 `github.com/zhui1234/learning-notes` |

`.vscode` 使用本机工具链的完整路径。换电脑或更换安装位置时，更新 `tasks.json`、`launch.json`、`settings.json` 和 `c_cpp_properties.json` 中的路径。这套配置针对每道题一个独立 `.cpp` 的训练方式，不会把同目录多个 `main()` 一起链接。
