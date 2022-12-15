import os
import cv2
import numpy as np
import time

def getpng(n,c,name):
    try:
        img=cv2.imread(name)
        cv2.imwrite(name,img)
        return img
    except:
        try:
            print('Running...')
            os.system('Mandelbrot_python '+str(n)+' '+str(c.real)+' '+str(c.imag)+' '+name)
            img=cv2.imread(name)
            cv2.imwrite(name,img)
            return img
        except:
            print('No exe!\nCompiling...')
            os.system('gcc -lm Mandelbrot_python.c -o Mandelbrot_python.exe')
            return getpng(n,c,name)

if __name__=='__main__':
    from datetime import datetime

    try:
        os.mkdir('runs/')
    except:
        pass
    dirname='runs/'+datetime.now().strftime('%Y-%m-%d_%Hh%Mm%Ss')+'/'
    os.mkdir(dirname)

    n=0
    c=0.0+0.0j

    def enlarge(event,x,y,flags,param):
        global n,c
        if event==cv2.EVENT_LBUTTONDBLCLK:
            c+=((x-127.5)+(127.5-y)*1j)/64/2**n
            n+=1

    img=getpng(n,c,dirname+str(n)+'_'+str(c)+'.png')
    cv2.namedWindow('image')
    cv2.setMouseCallback('image',enlarge)

    while(True):
        img=getpng(n,c,dirname+str(n)+'_'+str(c)+'.png')
        cv2.imshow('image',img)
        if cv2.waitKey(100)&0xFF==27:
            break

    cv2.destroyAllWindows()