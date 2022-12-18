# Mandelbrot_set 曼德博集合
Use python openCV and C svpng to show Mandelbrot set.

使用python openCV和C svpng显示曼德博集合。

# Installation 安装方法
git clone https://github.com/miaooo0000OOOO/Mandelbrot_set

cd Mandelbrot_set

git clone https://github.com/miloyip/svpng.git

cp svpng/svpng.inc .    # 将svpng文件夹中的svpng.inc复制到当前目录下

pip install opencv-python


# Usage 使用方法
python mandelbrot.py

Double click the window and the image will be enlarged.

Press esc to exit.

Your runs will be seen in runs dir.

双击窗口以放大图像。

按esc退出。

运行结果保存于images文件夹。

![0_0j](https://user-images.githubusercontent.com/45508696/207787809-d1ef3cc8-73a4-4895-9aaf-9d49ed8b0695.png)
![2_(0 17578125+0 60546875j)](https://user-images.githubusercontent.com/45508696/207806901-ecd696fc-562b-4ca7-8c28-e39251384b0b.png)
![4_(0 1240234375+0 6142578125j)](https://user-images.githubusercontent.com/45508696/207806924-8e8fb2ab-2b7d-47bf-b545-a0d6d1aeab92.png)
![6_(0 107177734375+0 637451171875j)](https://user-images.githubusercontent.com/45508696/207806945-70ae7dfb-fbc8-408e-b801-11b267574554.png)
![8_(0 10675048828125+0 63714599609375j)](https://user-images.githubusercontent.com/45508696/207806964-460e871f-17d5-4d11-817f-f4f77434b5f9.png)
![10_(0 1068878173828125+0 6374053955078125j)](https://user-images.githubusercontent.com/45508696/207806998-ef219110-4070-4c25-ba29-19aa1c51f7fa.png)

# changeLog 更改日志
1. 更改了文件结构

. (work dir)

├── images

│   ├── 0_0j.png

│   ├── 10_(-0.1041107177734375+0.8805694580078125j).png

│   ├── ...

├── mandelbrot.py

├── Mandelbrot_python.c

├── Mandelbrot_python.out (or Mandelbrot_python.exe)

├── README.md

└── svpng.inc

这样相同参数的图片就不会被生成两次

2. 多平台支持

支持Windows和Linux平台

在Ubuntu20.04上测试