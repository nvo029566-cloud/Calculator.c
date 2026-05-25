#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "advanced.h"

double Can(double a){
    if(a < 0){
        printf("Loi! Khong co can voi so am !\n");
        return -1;
    }
    else{

        return sqrt(a);

    }

}

long long gt(int n){
    int fact = 1;
    if(n < 0){
        printf("Loi! Khong co giai thua voi so am !\n");
        return -1;
    }
    else{
        for(int i = 1; i < n; i++){
            fact *= i;
        }
    }
    return fact; 
}

double lt(double a, double b){

    return pow(a, b);

}

int snt(int n){
    if(n < 2){

        return 0;

    }
    else{
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){

                return 0;

            }
        }
    }

    return 1;

}

int gcd(int a, int b){
    if(a < 0) a = - a;
    if(b < 0) b = - b;
    if(b == 0){

        return a;

    }
    else{

        return gcd(b, a % b);

    }
}

int lcm(int a, int b){
    if(a == 0 || b == 0){

        return 0;

    }

    return a / gcd(a, b) * b;

}

double degToRad(double deg){

    return deg * M_PI / 180.0;

}

double sine(double a){

    return sin(degToRad(a));

}

double cosine(double a){

    return cos(degToRad(a));

}

double tangent(double a){

    return tan(degToRad(a));

}

double lam_tron(double a){

    return round(a);

}

double lam_tron_len(double a){

    return ceil(a);

}

double lam_tron_xuong(double a){

    return floor(a);

}

double log_tu_nhien(double a){

    return log(a);

}

double log10_co_so(double a){

    return log10(a);

}

void check(int n){
    if(n % 2 == 0){

        printf("%d la so chan !\n", n);

    }
    else{

        printf("%d la so le !\n", n);

    }
    return;
}

int soHoanHao(int n){

    int tong = 0;

    for(int i = 1; i <= n / 2; i ++){
        if(n % i == 0){
            tong += i;
        }
    }

    return tong == n;
}









