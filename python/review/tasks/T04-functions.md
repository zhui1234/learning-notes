# T04：字符串与常用函数

目标：能组合常用 API，并解释边界行为。预计 25～35 分钟。

参考：[函数与常用方法](../../notes/03-functions-and-iteration.md)。前置条件：Python 3。

## 闭卷问题

1. `"abbaXba".strip("ab")` 为什么得到 X？
2. `isdigit()` 能否判断任意整数或浮点数字符串？
3. `sort()` 和 `sorted()` 如何影响输入？any、all 的空输入结果是什么？
4. `(a(), b())[condition]` 会调用几次函数？与条件表达式有何差异？

## 练习

建议产物：`python/practice/T04-functions.py`。

实现 `clean_words(text)`：按任意空白分词；对每个词去两端的逗号、句号；转小写；过滤空词；保留重复，按“长度升序、同长字典序”排序，最后用 `|` 连接。

输入 `"  Banana, apple. FIG  , . "`，结果 `"fig|apple|banana"`。边界：空串、纯空白、`", ."`、`"B a b"`（应为 `"a|b|b"`）。再分别演示 find 查不到、rpartition 无分隔符的结果。

## 验收

- [ ] 所有样例和边界结果符合约定，不丢重复词。
- [ ] 能写出 `key=lambda word: (len(word), word)` 并解释顺序。
- [ ] 正确说明 append 返回值与复杂度。
- [ ] 能解释为什么不能把 assert 作为必需的输入校验。

## 完成记录

- 状态：未开始
- 验收日期：
- 证据 / 产物：
- 本次卡点：
- 下次重测输入或问题：
