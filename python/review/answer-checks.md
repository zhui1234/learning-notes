# 自测要点

先做任务再看。这里只提供判断依据，完整解答由自己编写。

## T01

`conda create -n py-review python=3.12`；`conda activate py-review`；`conda env list`；`conda env export > environment.yaml`；`conda env create -f environment.yaml -n py-review-copy`。`python -c "import sys; print(sys.executable)"` 和 `python -m pip --version` 应指向同一环境。

## T02

input 返回 str；负索引末项是 d，隔一取一为 HloWrd，反转为 dlroW olleH。用 `enumerate` 可获得索引。未 break 才执行循环 else，包括零次循环。先 split 后转换，空行得到空列表。

## T03

`(1)` 是整数，`(1,)` 是元组。字典 get 缺键返回默认值，方括号访问缺键抛 KeyError。可用字典累计次数；首次遇到时添加到顺序列表。浅复制仅复制外层容器，嵌套对象仍共享引用。

## T04

strip 的参数是字符集合。isdigit 不识别符号、小数点，有些 Unicode 数字也不能交给 int。sort 原地排序并返回 None，sorted 新建列表。any([]) 为 False，all([]) 为 True。`(a(), b())[condition]` 两个调用都发生；条件表达式只调用被选分支。clean_words 可按 split → strip → lower → 过滤 → sorted → join 实现。

## T05

列表是可迭代对象；iter(list) 得到迭代器，生成器也是迭代器。yield 暂停并保留状态，return 结束函数。对 limit=7 的生成器先 next 得到 0，剩余为 `[4, 16, 36]`，再次收集为空。product 两种值重复 3 次得到 2³ 种组合。

## T06

从 datetime 模块导入 datetime、timedelta；使用 strptime → 加 timedelta(minutes=minutes) → strftime。解析非法日期抛 ValueError。%B 受 locale 影响，数值格式不受月份语言影响。

## T07

w 和 w+ 清空文件；a 追加；x 拒绝覆盖；r+ 不清空但要求文件存在。readlines 推进文件位置，seek(0) 可回到起点。writelines 原样写入字符串，不添加换行。每行先 strip，跳过空行，split 后验证至少有一个成绩，再将成绩转数值；排序 key 可用 `(-平均分, 姓名)`。

## T08

像素数 100×200；三通道元素数再乘 3；uint8 每元素 1 字节，因此 nbytes 等于 size。BGR 的 `[255,0,0]` 为蓝色，坐标为 `img[20,10]`。读取失败返回 None。高斯模糊本任务可用 `(11,11), 0`。灰度仅保留高、宽；保存结果用 imwrite 返回值检查。
