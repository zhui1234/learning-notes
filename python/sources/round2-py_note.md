# python笔记

## 数据类型

### _

### dict--字典

+ 结构:键值对,用`:`分隔
+ 注意:键必须是不可变类型,值可以是任意类型
  
```python
#创建
student={"name":"Tony","age":25}

student=dict(name:"Tony",age:25)

squares={x:x**2 for x in range(5)}

#访问
print(student["name"])

print(student.get("name")) # 避免KeyError

#添加&修改

student["age"]=18
student["city"]="London"

student.update({"name":"Mike","city":"Beijing"})

#删除
del student["city"]

age=student.pop("age") # 返回被删除的值

student.clear() # 清空字典
```

### list--列表

### tuple--元组

### lterator--迭代器

### generator--生成器

### datetime/date/time/timedelta

+ `datetime`来自`datetime`模块 `from datetime import datetime`
+ 用于表示具体的日期和时间点

```python
# 创建一个datetime对象
from datetime import datetime

now = datetime(2023, 12, 25, 14, 30, 45)  # 2023年12月25日 14:30:45
print(now)  # 输出: 2023-12-25 14:30:45

#与字符串转换关系
date_str="2025-12-8 18:29:30"
now=datetime.strptime(date_str,"%Y-%m-%d %H:%M:%S")

now = datetime(2023, 7, 15, 14, 30)
date_str = now.strftime("%Y年%m月%d日 %H:%M")

# 时间加减
tomorrow = now + timedelta(days=1)  # 加1天
next_hour = now + timedelta(hours=1)  # 加1小时

# 时间比较
next = datetime(2023, 7, 16, 10, 0)
print(now < next)  # True，比较先后

#格式转化
from datetime import datetime
def date_time(time: str) -> str:
    dt=datetime.strptime(time,"%d.%m.%Y %H:%M")
    return f"{dt.day} {dt.strftime('%B')} {dt.year} year {dt.hour} hours {dt.minute} minutes"

```

## 关键字

### def--定义函数

> `def 函数名(参数名:参数类型) -> 返回类型`

### assert--调试和测试

> `assert 判断调节,错误信息 #若不满足,则会返回AssertError`

### with--上下文管理器

> ```python
> with expression [as variable]:
>     with-block
> with open("file.txt", "r", encoding="utf-8") as file:
>     content = file.read()
>     print(content)
> ```
>
> 常用于文件操作,离开with块后文件自动关闭

## 语法

### 遍历list

> `for fruit in fruits: #按照原顺序遍历整个list`
> `for fruit in set(fruits) #不一定按原顺序遍历去重后的list`

### 多元赋值

> `ans = 0,''`(即ans = (0,''),此时ans[0]=0,ans[1]='')

### `(a,b)[index]`

> index可以用一个条件语句设置,用于替代if-else

### 文件调用

#### tempfile 创建临时文件和目录

```python
import tempfile

# 1. 获取系统临时目录
temp_dir = tempfile.gettempdir()
# Windows: C:\Users\用户名\AppData\Local\Temp
# Linux/macOS: /tmp

# 2. 创建临时文件（自动生成唯一名称）
temp_file = tempfile.NamedTemporaryFile(mode='w+', delete=False, suffix='.txt')
# 自动生成类似：/tmp/tmp12345abc.txt

# 3. 创建临时目录
temp_dir = tempfile.TemporaryDirectory()
```

### os 提供与操作系统交互的功能

```python
import os

# 路径拼接（跨平台兼容）
path = os.path.join('folder', 'subfolder', 'file.txt')
# Windows: folder\subfolder\file.txt
# Linux/macOS: folder/subfolder/file.txt

# 路径分割
dirname = os.path.dirname('/home/user/file.txt')  # '/home/user'
basename = os.path.basename('/home/user/file.txt')  # 'file.txt'

# 获取绝对路径
abs_path = os.path.abspath('file.txt')
```

```python
import tempfile, os

test_file = os.path.join(tempfile.gettempdir(), "scores.txt")
# 示例结果：C:\Users\Tom\AppData\Local\Temp\scores.txt
# test_file是一个存储了这个路径的字符串
with open(test_file, "w", encoding="utf-8") as f:
    f.write("Alice,90,85,95\nBob,80,70,88\nCharlie,100,90,98\n")
    
with open(file_path, "r", encoding="utf-8") as f:
    lines = f.readlines() 
```

## 函数

### max()

> `max(data)`返回列表中元素最大值(非数字按字典序)
> `max(data,key=函数)`例如key=data.count,返回列表中出现频率最高的元素
> `max(列表,key=lambda x:表达式)`

### count()

> `list.count(list中的元素)`返回列表中指定元素的个数

### split()

> `str.split(char)`把字符串按指定符号分隔,默认为空格,返回一个列表`for i in str.split():`

### isdigit()

> `str.isdigit()`判断字符串是否为数字,若字符串为数字则返回1

### strip()

> `str.strip(char)`去除字符串前导和末尾的指定字符,返回操作后的字符串

### upper()&lower()

> `str.upper()`讲字符串中的字母转换为大写字母,返回操作后的字符串
> `str.lower()`讲字符串中的字母转换为小写字母,返回操作后的字符串

### index()

> `序列类型.index(该类型中元素)`可以在序列/元组/字符串中查找首个指定元素位置,返回表示其索引位置的整数(注意判断是否存在)

### find()

> `str.find(str,int)`从指定位置起查找子串位置,返回首次出现的索引,找不到返回-1

### pop()和append()

> `list.pop(位置)`移除指定位置上的元素
> `list.append(元素)`在列表末尾添加一个元素
> 列表+append的效率为o(n),而字符串的拼接效率为o(n^2)

### map()

> `map(函数,列表)`对列表中每一个元素应用指定函数

### sum()

### replace()

> `str.replace(被替换内容,替换内容)`替换,返回替换后的字符串

### join()

> `":".join(["A","1","cd"])=="A:1:cd"`

### sort()&sorted()

> 用法与max类似
> `sorted(列表)`返回排序后的列表
> `列表.sort()`对原列表排序,返回None

### capitalize()/title()/swapcase()

> `str.capitalize()`将字符串的首字母转为大写,其余字母转为小写,返回修改后的字符串
> `str.title()`将字符串每个单词的首字母转为大写,返回修改后的字符串
> `str.swapcase()`将字符串的每个字母大小写互换,返回修改后的字符串

### any()/all()

> `any(...,...)`如果序列中任何元素是true,则返回true
> `all(...,...)`如果序列中全部元素是true,则返回true
> `any(map(str.isdigit,text))`判断text中是否有数字

### partition()/rpartition()

> `name,_,ext=str.rpartition(arg)`从最右边起按arg把字符串分为arg之前,arg,arg之后三个部分

### product()

> `from itertools import product`
> `product((True,False),repeat=len(input))`生成长度为len(input),由True和False组成的所有元组
> `product([1,2],['a','b'])`生成((1,'a'),(1,'b'),(2,'a'),(2,'b'))

### open()

> `open(file, mode='r', buffering=-1, encoding=None, errors=None, newline=None, closefd=True, opener=None)`返回一个文件对象
> file是存储文件路径的字符串,绝对/相对地址
>
> mode为模式  
>> 'r' 只读 默认模式，文件必须存在
>> 'w' 只写 创建新文件，如文件存在则清空内容
>> 'a' 追加 创建新文件，如文件存在则在末尾追加
>> 'x' 创建 创建新文件，如文件存在则报错
>> 'b' 二进制 与上述组合：'rb', 'wb'等
>> 't' 文本 默认模式，与上述组合：'rt', 'wt'等
>> '+' 读写 与上述组合：'r+', 'w+'等  
>
> ecoding为文件的编码格式,None表示使用系统默认编码
>
```python
f = open("file.txt", "r", encoding="utf-8")

content = f.read()           # 读取全部内容
line = f.readline()          # 读取一行
lines = f.readlines()        # 读取所有行（返回列表）
chunk = f.read(1024)         # 读取1024个字符
for line in f:               # 迭代读取（推荐）
    print(line)

f.write("Hello World\n")     # 写入字符串
f.writelines(["Line1\n", "Line2\n"])  # 写入多行

f.close()
```
