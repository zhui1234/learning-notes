# 基础语法与容器

## 输入输出

`input()` 返回字符串，数字输入需转换；转换失败会抛出 `ValueError`。

```python
# 交互示例，需要手动输入
age = int(input("年龄："))
print("age", age, sep="=", end="\n")
```

`print(*objects, sep=" ", end="\n")` 用逗号分隔输出对象，`sep`、`end` 使用关键字参数。

## 循环与分支

```python
print(list(range(5)))        # [0, 1, 2, 3, 4]
print(list(range(1, 6)))     # [1, 2, 3, 4, 5]
print(list(range(1, 10, 2))) # [1, 3, 5, 7, 9]
for char in "Hello":
    print(char, end=" ")
print()

n = 3
while n > 0:
    n -= 1
else:
    print("正常结束")
```

`break` 退出当前循环，`continue` 跳过本轮剩余语句。循环的 `else` 在未被 `break` 终止时执行，`for` 也支持；零次迭代仍可执行 `else`。

## 字符串与切片

```python
text = "Hello World"
assert len(text) == 11
assert text[0] == "H"
assert text[4] == "o"
assert text[-1] == "d"
assert text[0:5] == "Hello"
assert text[6:] == "World"
assert text[:5] == "Hello"
assert text[::2] == "HloWrd"
assert text[::-1] == "dlroW olleH"
```

切片 `[start:stop:step]` 不含 stop；step 不能为 0。字符串不可原地修改，字符串方法通常返回新字符串。

## 列表、元组与集合（补充原稿空节）

```python
values = [3, 1, 3]
values.append(2)                    # 原地添加，返回 None
last = values.pop()                # 返回 2，默认删除末项
assert values == [3, 1, 3]
assert values.count(3) == 2
assert values.index(1) == 1         # 不存在时抛出 ValueError
assert list(dict.fromkeys(values)) == [3, 1] # 保留首次出现顺序去重

point = (2, 5)
single = (2,)                      # 单元素元组要有逗号
x, y = point                       # 解包
ans = 0, ""                        # 一个元组绑定到 ans
score, name = 0, ""                 # 两个变量分别绑定
unique = set(values)               # 去重，不保证原序列顺序
```

列表可变，元组的元素绑定不可变，但元组内部若放列表，该列表仍可修改。`a = b` 不会复制列表；一层复制可用 `b.copy()`，嵌套对象仍共享引用。

## 字典

键必须可哈希，值可为任意对象。字符串、整数和元素均可哈希的元组可作为键；含列表的元组不能作为键。

```python
student = {"name": "Tony", "age": 25}
assert student == dict(name="Tony", age=25)
squares = {x: x ** 2 for x in range(5)}
assert student["name"] == "Tony"
assert student.get("city") is None
assert student.get("city", "未知") == "未知"
student["age"] = 18
student["city"] = "London"
student.update({"name": "Mike", "city": "Beijing"})
del student["city"]
age = student.pop("age")
assert age == 18
for key, value in student.items():
    print(key, value)
student.clear()
```

`d[key]` 在缺键时抛出 `KeyError`；`get` 不会因缺键报错。Python 3.7 起字典保持插入顺序，遍历字典默认得到键。

参考：[Python 内置类型](https://docs.python.org/3/library/stdtypes.html)。
