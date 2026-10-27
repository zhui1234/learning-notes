# OpenCV 入门

安装命令：`python -m pip install opencv-python`。下列图像示例需要额外依赖及图片文件；本次整理不自动安装。

## 图像数组与像素

| 属性 | 含义 |
| --- | --- |
| `img.shape` | 彩色图通常为 `(高, 宽, 通道数)`；灰度图通常为 `(高, 宽)` |
| `img.size` | 数组元素总数；三通道时为 `高 × 宽 × 3` |
| `img.dtype` | 元素类型，常见 uint8，取值 0～255 |
| `img.nbytes` | 数组元素占用字节数，不包含所有对象管理开销 |

像素数是 `高 × 宽`。三通道图像的一个像素含三个通道值，不能把 `size` 一律解释为像素数。默认读取彩色图像通常是 BGR 顺序，坐标访问是 `img[y, x]`，不是 `img[x, y]`。

## 读取、转换、保存

```python
# 依赖示例：先安装 opencv-python，并准备 input.jpg。
from pathlib import Path
import cv2

input_path = Path("input.jpg")
img = cv2.imread(str(input_path))
if img is None:
    raise FileNotFoundError(f"无法读取图像：{input_path.resolve()}")

height, width = img.shape[:2]
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(img, (11, 11), 0)
assert gray.shape == (height, width)
assert blur.shape == img.shape
if not cv2.imwrite("gray.png", gray):
    raise OSError("灰度图保存失败")
if not cv2.imwrite("blur.png", blur):
    raise OSError("模糊图保存失败")
```

`GaussianBlur` 本例显式指定正奇数核尺寸；sigmaX 为 0 时由核尺寸推导。核尺寸和标准差共同影响效果，不应只背“数字越大越模糊”。

## 显示窗口

```python
# 依赖前一段代码中的 img，需要图形桌面环境。
try:
    cv2.imshow("image", img)
    cv2.waitKey(0)  # 0 表示等待按键；1000 表示至少约 1000 毫秒，或按键返回
finally:
    cv2.destroyAllWindows()
```

函数名为 `waitKey`，K 大写。显示操作需要窗口事件处理；无图形界面的环境优先保存图片后查看。

参考：[图像基本操作](https://docs.opencv.org/4.x/d3/df2/tutorial_py_basic_ops.html)、[读取与显示图像](https://docs.opencv.org/4.13.0/db/deb/tutorial_display_image.html)。
