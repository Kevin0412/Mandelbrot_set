#include<stdio.h>
#include<stdlib.h>
#include<complex.h>
#include<math.h>
#include"svpng/svpng.inc"
#include<time.h>

int color_r(double n){
    double a;
    a=128.0-128.0*cos(53.0*n*3.141592653589793);
    if(a<256.0){
        return((int)a);
    }
    else{
        return(255);
    }
}

int color_g(double n){
    double a;
    a=128.0-128.0*cos(27.0*n*3.141592653589793);
    if(a<256.0){
        return((int)a);
    }
    else{
        return(255);
    }
}

int color_b(double n){
    double a;
    a=128.0-128.0*cos(139.0*n*3.141592653589793);
    if(a<256.0){
        return((int)a);
    }
    else{
        return(255);
    }
}

int mandelbrot(complex double c,int max){
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=n*n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

void test_rgb(int m,complex double c,char str[256]){
    unsigned char rgb[256*256*3],*p=rgb;
    unsigned x,y;
    FILE *fp=fopen(str,"wb");
    for(y=0;y<256;y++){
        for(x=0;x<256;x++){
            double n=((double)mandelbrot(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
            unsigned char r=(unsigned char)color_r(n);
            unsigned char g=(unsigned char)color_g(n);
            unsigned char b=(unsigned char)color_b(n);
            *p++=(unsigned char)r;  /* R */
            *p++=(unsigned char)g;  /* G */
            *p++=(unsigned char)b;  /* B */
        }
    }
    svpng(fp,256,256,rgb,0);
    fclose(fp);
}

int main(int argc, char *argv[]){
    clock_t begintime=clock();
    int n;
    double real, imag;
    char* filename;
    if (argc == 1){
        n = 0;
        real = 0.0;
        imag = 0.0;
        filename = "DefaultArgumentTestImage.png";
    }else if (argc == 5){
        n=atof(argv[1]);
        real=atof(argv[2]);
        imag=atof(argv[3]);
        filename=argv[4];
    }else{
        printf("Invalid Argument");
        return 0;
    }
    test_rgb(n,real+imag*I,filename);
    clock_t endtime=clock();
    printf("\nRunning Time:%fs\n", ((double)(endtime-begintime))/CLOCKS_PER_SEC);
    return(0);
}
