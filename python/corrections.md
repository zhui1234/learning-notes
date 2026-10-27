# 原稿勘误与补充

原稿保存在 [sources](sources/)，下表便于复习时识别旧记忆。

| 来源 | 原记录或遗漏 | 整理结果 |
| --- | --- | --- |
| 第一轮 / Conda | `conda creat`、`conda env creat` | 使用 create；创建环境指定 `python=3.12` 等约束 |
| 第一轮 / 版本 | `conda python --version` | 使用 `python --version`，用 sys.executable 核对解释器 |
| 第一轮 / 镜像 | 直接列旧频道地址 | 仅存档，不作为默认配置；换源前核对当前说明 |
| 第一轮 / 输出 | `print(object,sep,end)` | sep、end 作为关键字参数 |
| 第一轮 / 循环 | `for` 后没有循环体 | 补齐能运行的循环示例与循环 else 触发条件 |
| 第一轮 / 字符串 | `"Hello World"[-1]` 注释为 n | 正确为 d；补齐切片输出 |
| 第一轮 / 图像 | `img.size` 为总像素数 | 是数组元素数；彩色图需区分通道数 |
| 第一轮 / OpenCV | `cv2.waitkey` | 正确为 `cv2.waitKey`；补充读取失败检查和保存结果 |
| 第二轮 / 字典 | `dict(name:"Tony",age:25)` | 正确为 `dict(name="Tony", age=25)` |
| 第二轮 / 字典键 | 键必须不可变 | 准确条件为可哈希，含列表的元组不可用作键 |
| 第二轮 / 日期 | 使用 timedelta 但未导入 | 补齐导入，说明月份名受 locale 影响 |
| 第二轮 / assert | 失败返回 AssertError | 抛出 AssertionError，补充优化模式限制 |
| 第二轮 / 赋值 | 将 `ans = 0, ''` 称为多元赋值 | 这是构造元组；与解包 `score, name = ...` 区分 |
| 第二轮 / 分支 | `(a,b)[条件]` 替代 if-else | 两个值会先求值；优先用条件表达式 |
| 第二轮 / 文件路径 | 写入 test_file，读取 file_path | 统一变量名，示例使用独立临时目录 |
| 第二轮 / 文件模式 | r 模式的句柄随后直接 write | 分离读写模式，说明共享文件位置和 writelines 换行 |
| 第二轮 / isdigit | 是数字则返回 1 | 返回 bool；不是通用数字解析检查 |
| 第二轮 / strip | 去除指定内容 | 参数是字符集合，不是完整前后缀 |
| 第二轮 / 复杂度 | “列表+append 为 O(n)” | append 单次摊还 O(1)，n 次摊还 O(n)；列表加法会复制 |
| 第二轮 / any、all | `any(...,...)`、`all(...,...)` | 接收一个可迭代对象；补充空输入和短路行为 |
| 第二轮 / product | 暗示直接产生完整元组集合 | 返回迭代器，list 才收集结果 |
| 第二轮 / 空标题 | list、tuple、iterator、generator、sum | 补齐最小示例和相关边界 |

技术核对来源链接见各主题笔记；原稿中的空 `_` 标题没有明确知识内容，未独立保留为主题。
