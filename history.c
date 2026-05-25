#include <stdio.h>
#include "history.h"

#define FILE_LICH_SU "lichSu.txt"

void luuLichSu(const char *phepTinh, double ketQua){

    FILE *f = fopen(FILE_LICH_SU, "a");
    if(f == NULL){
        return;
    }

    fprintf(f, "%s = %.2lf\n", phepTinh, ketQua);
    fclose(f);
}

void hienThiLichSu(){

    FILE *f = fopen(FILE_LICH_SU, "r");
    if(f == NULL){
        printf("File chua co lich su !\n");
        return;
    }

    char dong[300];
    printf("============= LICH SU TINH TOAN ============\n");
    while(fgets(dong, sizeof(dong), f) != NULL){
        printf("%s", dong);
    }
    printf("============================================\n");
    fclose(f);

}

void xoaLichSu(){

    FILE *f = fopen(FILE_LICH_SU, "w");
    if(f == NULL){
        return;
    }
    fclose(f);
    printf("Da xoa lich su !\n");

}


