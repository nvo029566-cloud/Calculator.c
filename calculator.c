#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "calculator.h"


double Tong(double a, double b){
    return a + b;
}

double Hieu(double a, double b){
    return a - b;
}

double Tich(double a, double b){
    return a * b;
}

double Thuong(double a, double b){
    if(b == 0){
        return 0;
    }
    else{
        return (double) a / b;
    }
}

