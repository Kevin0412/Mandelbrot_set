import cv2
import numpy as np
from mandelbrot import getpng

variety=0
n=6
varieties=['mandelbrot','tri','boat','duck','bell','fish','vase','bird','mask','ship']
img=np.zeros((256*2**n,256*2**n,3),np.uint8)
if variety in [2,3,7,8]:
    for x in range(2**n):
        for y in range(2**n):
            print(x,y,2**n)
            img[256*y:256*y+256,256*x:256*x+256]=getpng(n,(x+0.5)*4/2**n-2+(-(y+0.5)*4/2**n+2)*1j,'1.png',variety=variety,regenerate=True)
else:
    for x in range(2**n):
        for y in range(2**(n-1)):
            print(x,y,2**n)
            img[256*y:256*y+256,256*x:256*x+256]=getpng(n,(x+0.5)*4/2**n-2+(-(y+0.5)*4/2**n+2)*1j,'1.png',variety=variety,regenerate=True)
    img[256*2**(n-1):256*2**n]=cv2.flip(img[0:256*2**(n-1)],0)
cv2.imwrite(varieties[variety]+'_'+str(256*2**n)+'.png',img)
