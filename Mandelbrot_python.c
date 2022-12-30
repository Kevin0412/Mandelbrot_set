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
    // variety 0
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

int tri(complex double c,int max){
    // variety 1
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=conj(n*n)+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int boat(complex double c,int max){
    // variety 2
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=cabs(creal(n))+cabs(cimag(n))*I;
        n=n*n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int duck(complex double c,int max){
    // variety 3
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=creal(n)+cabs(cimag(n))*I;
        n=n*n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int bell(complex double c,int max){
    // variety 4
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=cabs(creal(n))-cimag(n)*I;
        n=n*n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int fish(complex double c,int max){
    // variety 5
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=n*n;
        n=cabs(creal(n))+cimag(n)*I;
        n=n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int vase(complex double c,int max){
    // variety 6
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=n*n;
        n=cabs(creal(n))-cimag(n)*I;
        n=n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int bird(complex double c,int max){
    // variety 7
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=n*n;
        n=cabs(creal(n))+cabs(cimag(n))*I;
        n=n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int mask(complex double c,int max){
    // variety 8
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=creal(n)+cabs(cimag(n))*I;
        n=n*n;
        n=cabs(creal(n))+cimag(n)*I;
        n=n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

int ship(complex double c,int max){
    // variety 9
    complex double n=0.0+0.0*I;
    int z;
    for(z=0;z<max;z++){
        n=cabs(creal(n))+cimag(n)*I;
        n=n*n;
        n=cabs(creal(n))-cimag(n)*I;
        n=n+c;
        if(cabs(n)>2){
            return(z);
        }
    }
    return(max);
}

void test_rgb(int m,complex double c,char str[256],int variety){
    unsigned char rgb[256*256*3],*p=rgb;
    unsigned x,y;
    FILE *fp=fopen(str,"wb");
    if(variety==0){
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
    }else if(variety==1){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)tri(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==2){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)boat(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==3){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)duck(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==4){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)bell(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==5){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)fish(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==6){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)vase(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==7){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)bird(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==8){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)mask(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else if(variety==9){
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                double n=((double)ship(((((double)x+0.5)/64.0-2.0)*pow(2.0,-m)-((((double)y+0.5)/64.0-2.0)*pow(2.0,-m))*I+c),5184)+1.0)/5186.0;
                unsigned char r=(unsigned char)color_r(n);
                unsigned char g=(unsigned char)color_g(n);
                unsigned char b=(unsigned char)color_b(n);
                *p++=(unsigned char)r;  /* R */
                *p++=(unsigned char)g;  /* G */
                *p++=(unsigned char)b;  /* B */
            }
        }
    }else{
        for(y=0;y<256;y++){
            for(x=0;x<256;x++){
                *p++=(unsigned char)(rand()%256);  /* R */
                *p++=(unsigned char)(rand()%256);  /* G */
                *p++=(unsigned char)(rand()%256);  /* B */
            }
        }
    }
    svpng(fp,256,256,rgb,0);
    fclose(fp);
}

int main(int argc, char *argv[]){
    clock_t begintime=clock();
    int n,variety;
    double real, imag;
    char* filename;
    if (argc == 1){
        n = 0;
        real = 0.0;
        imag = 0.0;
        filename = "DefaultArgumentTestImage.png";
        variety = 0;
    }else if (argc == 5){
        n=atof(argv[1]);
        real=atof(argv[2]);
        imag=atof(argv[3]);
        filename=argv[4];
        variety=0;
    }else if (argc == 6){
        n=atof(argv[1]);
        real=atof(argv[2]);
        imag=atof(argv[3]);
        filename=argv[4];
        variety=atof(argv[5]);
    }else{
        printf("Invalid Argument");
        return 0;
    }
    test_rgb(n,real+imag*I,filename,variety);
    clock_t endtime=clock();
    printf("\nRunning Time:%fs\n", ((double)(endtime-begintime))/CLOCKS_PER_SEC);
    return(0);
}
