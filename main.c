//
//  main.c
//  mandelbrot
//
//  Created by Arnau Jutglar Puig on 10/06/2021.
//  Copyright © 2021 Arnau Jutglar Puig. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} c;

c quadrat(c);
c suma (c, c);
c fractal(c, int);
c iter(c, int);
double norma(c);

int main() {
    c c1, z;
    FILE *fp1, *fp2;
    double i,j;
    
    c1.re = -0.5;
    c1.im = 0.3;
    /*
    z = fractal(c1, 40);
    z = iter(c1, 2);
    */
    z = quadrat(c1);
    
    printf("%lf %lfi\n", z.re, z.im);
    
    
    /*
    fp1 = fopen("mandSi.txt", "w");
    fp2 = fopen("mandNo.txt", "w");
    
    for (j = -1; j <= 1; j += 0.0001) {
        for (i = -1; i <= 1; i += 0.01) {
            c1.re = j;
            c1.im = i;
            
            z = fractal(c1, 30);
            if (norma(z) < 100) {
                fprintf(fp1, "%lf %lf \n", c1.re, c1.im);
            } else {
                fprintf(fp2, "%lf %lf \n", c1.re, c1.im);
            }
            
        }
    }
    
    
    
    
    
    
    
    
    */
    return 0;
}

c quadrat(c z) {
    c r;
    
    r.re = z.re * z.re - z.im * z.im;
    printf("real = %lf\n", z.re);
    
    z.im = 2 * z.re * z.im;
    printf("imaginari = %lf\n", z.im);
    
    return r;
}

c suma(c c1, c c2) {
    c r;
    
    r.re = c1.re + c2.re;
    r.im = c1.im + c2.im;
    
    return r;
}

c fractal(c c1, int n) {
    c z;
        
    if (n == 0) {
        z.re = 0;
        z.im = 0;
    } else {
        z = suma(quadrat(fractal(c1, n-1)), c1);
    }
    
    return z;
}

double norma(c z) {
    return sqrt(z.re * z.re + z.im * z.im);
}

c iter(c c1, int n) {
    c z;
    int i;
    
    z.re = 0;
    z.im = 0;
    
    for (i=0; i < n; i++) {
        z = suma(quadrat(z), c1);
    }
    
    return z;
}
