import os
import cv2
import numpy as np
import time
import sys

LINUX = True if 'linux' in sys.platform else False
WINDOWS = True if 'win' in sys.platform else False
if (not (LINUX ^ WINDOWS)):
    raise "{} platform is not supported".format(sys.platform)

def getpng(n,c,name, compiled=False):
    workDir = os.getcwd()
    if os.path.exists(os.path.join(workDir, name)):
        # 已生成图像
            img = cv2.imread(name)
            cv2.imwrite(name,img)
            return img
    else:
        # 未生成图像
        if compiled:
            # 可执行文件已编译
            if os.path.exists(os.path.join(workDir, 'Mandelbrot_python.out')) or os.path.exists(os.path.join(workDir, "Mandelbrot_python.exe")):
                # 已编译且存在可执行文件
                if WINDOWS:
                    # os.system('Mandelbrot_python '+str(n)+' '+str(c.real)+' '+str(c.imag)+' '+name)
                    cmd = 'Mandelbrot_python {} {} {} {}'
                if LINUX:
                    # os.system('./Mandelbrot_python.out '+str(n)+' '+str(c.real)+' '+str(c.imag)+' '+name)
                    cmd = './Mandelbrot_python.out {} {} {} "{}"'
                print(cmd.format(n, c.real, c.imag, name))
                print('Running...')
                os.system(cmd.format(n, c.real, c.imag, name))
                img = cv2.imread(name)
                cv2.imwrite(name,img)
                return img
            else:
                raise "编译失败"
        else:
            # 可执行文件未编译
            print('No executable file!\nCompiling...')
            if LINUX:
                cmd = 'gcc Mandelbrot_python.c -o Mandelbrot_python.out -lm'
            elif WINDOWS:
                cmd = 'gcc -lm Mandelbrot_python.c -o Mandelbrot_python.exe'
            print(cmd)
            os.system(cmd)
            return getpng(n ,c, name, True)



if __name__=='__main__':
    from datetime import datetime

    # try:
    #     os.mkdir('runs/')
    # except:
    #     pass
    # dirname='runs/'+datetime.now().strftime('%Y-%m-%d_%Hh%Mm%Ss')+'/'
    dirname = 'images/'
    try:
        os.mkdir(dirname)
    except:
        pass
    n=0
    c=0.0+0.0j

    def enlarge(event,x,y,flags,param):
        global n,c
        if event==cv2.EVENT_LBUTTONDBLCLK:
            c+=((x-127.5)+(127.5-y)*1j)/64/2**n
            n+=1
            print(str(n)+','+str(c+((x-127.5)+(127.5-y)*1j)/64/2**n))

    img=getpng(n,c,dirname+str(n)+'_'+str(c)+'.png')
    cv2.namedWindow('image')
    cv2.setMouseCallback('image',enlarge)

    while(True):
        img=getpng(n,c,dirname+str(n)+'_'+str(c)+'.png', True)
        cv2.imshow('image',img)
        if cv2.waitKey(100)&0xFF==27:
            break

    cv2.destroyAllWindows()
