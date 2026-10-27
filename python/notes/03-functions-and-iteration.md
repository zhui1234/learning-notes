# 函数、常用方法与迭代

## 函数与断言

```python
def square(x: int) -> int:
    return x * x

assert square(3) == 9, "平方计算错误"
```

类型注解提供提示，不自动检查或转换参数。`assert 条件, 错误信息` 失败时抛出 `AssertionError`；优化模式可移除断言，必需的输入校验应使用 `if` 和异常。

## 常用字符串方法

| 方法 | 含义与边界 |
| --- | --- |
| `s.split()` / `s.split(",")` | 前者按连续空白分词；后者按指定分隔符拆分，可能出现空串 |
| `s.strip(chars)` | 两端移除 chars 中的任意字符，chars 是字符集合，不是完整前后缀；省略时去空白 |
| `s.isdigit()` | 返回 bool；不等于“能被 int 转换”，例如负号、小数点不被接受，部分 Unicode 数字也有差异 |
| `s.upper()` / `s.lower()` | 返回转为大写 / 小写的字符串 |
| `s.capitalize()` | 首字符大写，其余小写 |
| `s.title()` / `s.swapcase()` | 按单词边界转换 / 大小写互换 |
| `s.index(sub)` | 首次出现位置，不存在时抛出 ValueError |
| `s.find(sub, start)` | 从 start 起查找；不存在时返回 -1 |
| `s.replace(old, new)` | 返回替换结果，不改变原字符串 |
| `sep.join(parts)` | 用 sep 连接字符串序列；元素必须是字符串 |
| `s.partition(sep)` / `s.rpartition(sep)` | 从左 / 右切一次，返回三元组，含分隔符本身 |

```python
assert " a  b\t c ".split() == ["a", "b", "c"]
assert "a,,b".split(",") == ["a", "", "b"]
assert "abbaXba".strip("ab") == "X"
assert "123".isdigit() is True
assert not "-12".isdigit()
assert "²".isdigit()                # int("²") 会失败
assert ":".join(["A", "1", "cd"]) == "A:1:cd"
assert "a.b.txt".rpartition(".") == ("a.b", ".", "txt")
assert "README".rpartition(".") == ("", "", "README")
assert "README".partition(".") == ("README", "", "")
```

## 聚合、排序与条件表达式

```python
data = [3, 1, 3, 2]
assert max(data) == 3
assert max(data, key=data.count) == 3
assert sum(data) == 9              # 补充原稿空节
assert sum([]) == 0
assert sorted(data) == [1, 2, 3, 3]
assert data == [3, 1, 3, 2]        # sorted 不修改原列表
assert data.sort(reverse=True) is None
assert data == [3, 3, 2, 1]
students = [("Alice", 90), ("Bob", 80)]
assert sorted(students, key=lambda item: item[1])[0][0] == "Bob"
assert any(ch.isdigit() for ch in "abc1")
assert all(n > 0 for n in [1, 2, 3])
assert any([]) is False
assert all([]) is True
age = 18
label = "成年" if age >= 18 else "未成年"
```

`max` 空输入且未给 default 时报错；同 key 最大值取首次遇到的元素。排序是稳定的。`max(data, key=data.count)` 简洁，但对 n 个元素反复计数可能为 O(n²)；大量计数可用 `collections.Counter`。

`any` / `all` 接收一个可迭代对象并短路求值。原稿 `(a, b)[condition]` 会先计算 a、b 两个表达式；条件表达式只计算被选分支，通常更清晰。

列表 `append` 单次摊还 O(1)，构造 n 项总计摊还 O(n)；不要把 `list + [item]` 与 `append` 混为一谈。多次拼接不可变字符串可能反复复制，批量拼接优先收集片段再 `join`。

## 可迭代对象、迭代器与生成器（补充原稿空节）

可迭代对象能传给 `iter()`；迭代器能用 `next()` 逐项取值，耗尽后抛出 `StopIteration`。列表可反复遍历，同一个迭代器通常只能消耗一次。

```python
items = [1, 2]
it = iter(items)
assert next(it) == 1
assert list(it) == [2]
assert list(it) == []
assert list(items) == [1, 2]

mapped = map(int, ["1", "2", "3"])
assert list(mapped) == [1, 2, 3]
assert list(mapped) == []

def squares(n: int):
    for i in range(n):
        yield i * i

assert list(squares(4)) == [0, 1, 4, 9]
assert list(i * i for i in range(3)) == [0, 1, 4]

from itertools import product
assert list(product([1, 2], ["a", "b"])) == [
    (1, "a"), (1, "b"), (2, "a"), (2, "b")
]
assert len(list(product((True, False), repeat=3))) == 8
```

生成器函数含 `yield`，调用时返回生成器，按需计算。`map`、`product` 返回迭代器；`product` 会先保存各输入池，不适合无限输入。

参考：[内置函数](https://docs.python.org/3/library/functions.html)、[字符串与容器](https://docs.python.org/3/library/stdtypes.html)、[断言](https://docs.python.org/3/reference/simple_stmts.html#the-assert-statement)、[itertools](https://docs.python.org/3/library/itertools.html)。
