# 环境管理

## Conda 常用命令

下面是命令速查，按需执行；`py-review` 是示例环境名，Python 3.12 是学习示例版本。

```powershell
conda create -n py-review python=3.12
conda activate py-review
python --version
python -c "import sys; print(sys.executable)"
conda env list
conda install numpy
conda list
conda update numpy
conda env export > environment.yaml
conda env create -f environment.yaml -n py-review-copy
conda deactivate
```

`create` 不能写成 `creat`；查看解释器版本使用 `python --version`。导出的完整环境文件可能含本机路径和平台依赖；跨平台分享前检查 `prefix` 和包约束。

## pip 与镜像

```powershell
python -m pip --version
python -m pip install opencv-python
python -m pip config list
conda config --show channels
```

`python -m pip` 将 pip 绑定到当前 Python。先激活环境，再安装依赖；同一环境混用 Conda 和 pip 时，先完成 Conda 依赖安装，再安装必要的 pip 包。

原稿中的清华镜像地址见存档。镜像配置会影响后续下载，且可用频道可能变化，故不把原稿中的 `pkgs/free` 等地址作为默认配置。需要换源时先查镜像站当前说明，并记录修改前配置。

## 安装与解释器排查（补充）

1. 安装 Conda 后先在其提供的终端中验证 `conda --version`。
2. 普通 PowerShell 中无法激活时，检查 shell 初始化状态；不要随意向 PATH 堆叠多个 Python 路径。
3. PyCharm 中选择已有 Conda 环境对应的解释器，在项目终端和运行配置中分别核对 `sys.executable`。
4. 若下载或缓存损坏，先记录报错、检查网络与磁盘，再考虑清理缓存并重建环境。`conda clean --all` 会清除缓存，不作为每次排错的第一步。

参考：[Conda create](https://docs.conda.io/projects/conda/en/stable/commands/create.html)、[从配置文件创建环境](https://docs.conda.io/projects/conda/en/stable/commands/env/create.html)。
