# 日期、路径与文件

## 日期时间

`date` 表示日期，`time` 表示一天中的时刻，`datetime` 表示日期与时刻，`timedelta` 表示时长（补充原稿标题中未展开的类型）。

```python
from datetime import date, datetime, time, timedelta

day = date(2023, 12, 25)
clock = time(14, 30, 45)
moment = datetime.combine(day, clock)
assert str(moment) == "2023-12-25 14:30:45"
parsed = datetime.strptime("2025-12-08 18:29:30", "%Y-%m-%d %H:%M:%S")
assert parsed.strftime("%Y-%m-%d %H:%M") == "2025-12-08 18:29"
tomorrow = moment + timedelta(days=1)
next_hour = moment + timedelta(hours=1)
assert moment < tomorrow
assert (tomorrow - moment).total_seconds() == 86400

def date_time(text: str) -> str:
    dt = datetime.strptime(text, "%d.%m.%Y %H:%M")
    return (f"{dt.day} {dt.strftime('%B')} {dt.year} year "
            f"{dt.hour} hours {dt.minute} minutes")
```

`strptime` 是字符串 → 时间对象；`strftime` 方向相反。`%B` 的月份语言受系统 locale 影响，不能假设必为英文。示例都是不带时区的时间；实际跨时区数据应统一时区后处理，不直接混合带时区和不带时区的对象。

## 路径

```python
import os

path = os.path.join("folder", "subfolder", "file.txt")
dirname = os.path.dirname(path)
basename = os.path.basename(path)
absolute = os.path.abspath(path)
assert basename == "file.txt"
```

相对路径以进程当前工作目录为基准。`abspath` 不要求文件存在，也不会创建文件。路径分隔符和解析行为依运行平台而定。补充：`pathlib.Path` 可提供更直观的路径组合接口。

## 文件模式与读写

| 模式 | 行为 |
| --- | --- |
| `r` | 只读，文件必须存在 |
| `w` | 写入，不存在则创建，存在则清空 |
| `a` | 追加，不存在则创建 |
| `x` | 独占创建，存在则报错 |
| `b` / `t` | 二进制 / 文本，和前述模式组合 |
| `+` | 允许读写，如 `r+`、`w+`；不取消 w 的清空行为 |

`with open(path, mode, encoding="utf-8") as f:` 离开代码块自动关闭文件，即使块中发生异常也会关闭。二进制模式不指定 encoding。

`read()` 读剩余全部内容；`read(n)` 在文本模式按字符、二进制模式按字节读取；`readline()` 读一行；`readlines()` 返回剩余行列表。连续读取会共享当前位置，读到末尾后需要 `seek(0)` 才能重读。逐行遍历适合大文件。

```python
import os
import tempfile

# 独立临时目录，示例退出后自动清理，不覆盖已有文件。
with tempfile.TemporaryDirectory() as temp_dir:
    file_path = os.path.join(temp_dir, "scores.txt")
    with open(file_path, "w", encoding="utf-8") as f:
        f.write("Alice,90,85,95\n")
        f.writelines(["Bob,80,70,88\n", "Charlie,100,90,98\n"])
    with open(file_path, "r", encoding="utf-8") as f:
        lines = f.readlines()
        assert f.read() == ""
        f.seek(0)
        assert f.readline().startswith("Alice,")
    assert len(lines) == 3
```

`writelines` 不自动添加换行。原稿中使用 r 模式打开后直接调用 write 的示例已拆分到不同的 `with` 块。

## 临时资源

`tempfile.gettempdir()` 返回系统临时目录的路径字符串；`TemporaryDirectory()` 返回管理临时目录的对象，配合 `with` 时绑定的是路径字符串。`NamedTemporaryFile` 创建具有可见名字的文件；设置 `delete=False` 后需自行删除。Windows 下重新打开仍处于打开状态的临时文件可能受到共享限制，学习练习优先采用上面的临时目录方案。

参考：[datetime](https://docs.python.org/3/library/datetime.html)、[open](https://docs.python.org/3/library/functions.html#open)、[tempfile](https://docs.python.org/3/library/tempfile.html)。
