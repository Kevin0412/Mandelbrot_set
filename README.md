# Mandelbrot_set 曼德博集合
Use python openCV and C svpng to show Mandelbrot set.

使用python openCV和C svpng显示曼德博集合。

# Installation 安装方法
git clone https://github.com/Kevin0412/Mandelbrot_set.git -b Kevin0412-patch-1

cd Mandelbrot_set

git clone https://github.com/miloyip/svpng.git

pip install opencv-python

# Varieties 类型
Variety 0: mandelbrot (mandelbrot set) 曼德勃罗集

![mandelbrot](https://user-images.githubusercontent.com/45508696/210026242-baf302f3-8c5f-4bc8-b4bf-3e62186630fb.png)

Variety 1: tri (triangular fractal) 三角分形

![tri](https://user-images.githubusercontent.com/45508696/210026255-416d237e-2e87-464d-8b4f-1f3ace06d5ff.png)

Variety 2: boat (burning boat fractal) 燃烧船分形

![boat](https://user-images.githubusercontent.com/45508696/210026262-2729b8de-46a0-4c1b-aa42-8ee56ece1666.png)

Variety 3: duck (duck fractal) 鸭子分形

![duck](https://user-images.githubusercontent.com/45508696/210026268-322cde99-d1ab-48fb-98d5-68ef57e5bc8c.png)

Variety 4: bell (bell fractal) 铃铛分形

![bell](https://user-images.githubusercontent.com/45508696/210026283-ce4aca2e-d0ac-4904-9078-2b794b26310b.png)

Variety 5: fish (tropical fish fractal) 热带鱼分形

![fish](https://user-images.githubusercontent.com/45508696/210026296-de79a518-0e30-470e-9b12-07d5e58ace9f.png)

Variety 6: vase (vase fractral) 花瓶分形

![vase](https://user-images.githubusercontent.com/45508696/210026312-726fbf15-2ae9-4759-af86-3fd60d5a07a1.png)

Variety 7: bird (bird fractral) 小鸟分形

![bird](https://user-images.githubusercontent.com/45508696/210026324-1743586d-3cf9-42bc-b2ba-13e81a6fc675.png)

Variety 8: mask (mask fractral) 面具分形

![mask](https://user-images.githubusercontent.com/45508696/210026333-a644f913-4f9d-4d9d-a016-9084affd03f5.png)

Variety 9: ship (ship fractral) 轮船分形

![ship](https://user-images.githubusercontent.com/45508696/210026347-efa42d9b-45db-427c-8132-ea38b95c17cc.png)


# Usage 使用方法

# mandelbrot.py
python mandelbrot.py

Double click the window and the image will be enlarged.
Press esc to exit.
Your runs will be seen in runs dir.
Alter variety in line 62.

双击窗口以放大图像。
按esc退出。
运行结果保存于runs文件夹。
可在第62行修改类型。

![0_0j](https://user-images.githubusercontent.com/45508696/207787809-d1ef3cc8-73a4-4895-9aaf-9d49ed8b0695.png)
![2_(0 17578125+0 60546875j)](https://user-images.githubusercontent.com/45508696/207806901-ecd696fc-562b-4ca7-8c28-e39251384b0b.png)
![4_(0 1240234375+0 6142578125j)](https://user-images.githubusercontent.com/45508696/207806924-8e8fb2ab-2b7d-47bf-b545-a0d6d1aeab92.png)
![6_(0 107177734375+0 637451171875j)](https://user-images.githubusercontent.com/45508696/207806945-70ae7dfb-fbc8-408e-b801-11b267574554.png)
![8_(0 10675048828125+0 63714599609375j)](https://user-images.githubusercontent.com/45508696/207806964-460e871f-17d5-4d11-817f-f4f77434b5f9.png)
![10_(0 1068878173828125+0 6374053955078125j)](https://user-images.githubusercontent.com/45508696/207806998-ef219110-4070-4c25-ba29-19aa1c51f7fa.png)

# big_png.py
python big_png.py

You can get a big picture of fractral.
Alter value n in line 6 can change size. size=256*2^n.
Alter variety in line 5.

获得一张大的分形图片。
改变第6行n的值可以改变图像尺寸。尺寸=256*2^n.
可在第5行修改类型。

# Mandelbrot_python.c
Windows:

gcc -lm Mandelbrot_python.c -o Mandelbrot_python.exe

Mandelbrot_python 0 0.0 0.0 test.png 0

Linux:

gcc -lm Mandelbrot_python.c -o Mandelbrot_python.out

./Mandelbrot_python.out 0 0.0 0.0 "test.png" 0

argv[1]: enlarge size 放大尺寸

argv[2]: real part of enlarge center 放大中心实部

argv[3]: imaginary part of enlarge center 放大中心虚部

argv[4]: file name 文件名

argv[5]: varieties (default 0) 类型 （默认0）
