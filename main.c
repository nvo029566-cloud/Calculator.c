#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include "calculator.h"
#include "advanced.h"
#include "history.h"


void clearBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    return;
}

int nhapDouble(double *x){
    return scanf("%lf", x) == 1; 
}

int nhapInt(int *x){
    return scanf("%d", x) == 1;
}

int main(){

    SetConsoleOutputCP(65001);

    double a, b, res;
    int x, n, kq;
    int choice;
    do{
        printf("╔════════════════ MAY TINH CAM TAY ═══════════════╗\n");
        printf("║                                                 ║\n");
        printf("║    ---------------- Co ban -------------------  ║\n");
        printf("║                                                 ║\n");
        printf("║    1. Cong                    2. Tru            ║\n");
        printf("║    3. Nhan                    4. Chia           ║\n");
        printf("║                                                 ║\n");
        printf("║    --------------- Toan hoc ------------------  ║\n");
        printf("║                                                 ║\n");
        printf("║    5. Can bac 2               6. Giai thua      ║\n");
        printf("║    7. Luy thua                8. So nguyen to   ║\n");
        printf("║    9. GCD                     10. LCM           ║\n");
        printf("║                                                 ║\n");
        printf("║    --------- Luong giac (don vi: do) ---------  ║\n");
        printf("║                                                 ║\n");
        printf("║    11. Sine                   12. Cosine        ║\n");
        printf("║    13. Tangent                                  ║\n");
        printf("║                                                 ║\n");
        printf("║    --------------- Lam tron ------------------  ║\n");
        printf("║                                                 ║\n");
        printf("║    14. Lam tron               15. Lam tron len  ║\n");
        printf("║    16. Lam tron xuong                           ║\n");
        printf("║                                                 ║\n");
        printf("║    --------------- Logarithm -----------------  ║\n");
        printf("║                                                 ║\n");
        printf("║    17. Log tu nhien           18. Log co so 10  ║\n");
        printf("║                                                 ║\n");
        printf("║    --------------- Kiem tra ------------------  ║\n");
        printf("║                                                 ║\n");
        printf("║    19. Kiem tra chan, le      20. So hoan hao   ║\n");
        printf("║                                                 ║\n");
        printf("║    ----------------- File --------------------  ║\n");
        printf("║                                                 ║\n");
        printf("║    21. Xem lich su            22. Xoa lich su   ║\n");
        printf("║                                                 ║\n");
        printf("║    0. Thoat chuong trinh !                      ║\n");
        printf("║                                                 ║\n");
        printf("╚═════════════════════════════════════════════════╝\n");


        printf("Nhap lua chon: ");
        if(!nhapInt(&choice)){
            clearBuffer();
            printf("Vui long nhap so !\n");
            continue;
        }

        switch(choice){

            case 1:

                printf("Nhap a: "); nhapDouble(&a);
                printf("Nhap b: "); nhapDouble(&b);

                printf("Tong cua: %.0lf + %.0lf = %.0lf\n", a, b, Tong(a, b));
                luuLichSu("Cong", Tong(a, b));
                break;

            case 2: 

                printf("Nhap a: "); nhapDouble(&a);
                printf("Nhap b: "); nhapDouble(&b);

                printf("Hieu cua: %.0lf - %.0lf = %.0lf\n", a, b, Hieu(a, b));
                luuLichSu("Tru", Hieu(a, b));
                break;

            case 3:

                printf("Nhap a: "); nhapDouble(&a);
                printf("Nhap b: "); nhapDouble(&b);

                printf("Tich cua: %.0lf * %.0lf = %.0lf\n", a, b, Tich(a, b));
                luuLichSu("Nhan", Tich(a, b));
                break;

            case 4: 

                printf("Nhap a: "); nhapDouble(&a);
                printf("Nhap b: "); nhapDouble(&b);

                if(b == 0){
                    printf("Loi! khong chia duoc cho so 0 !\n");
                }
                else{

                printf("Thuong cua: %.2lf / %.2lf = %.2lf\n", a, b, Thuong(a, b));
                luuLichSu("Chia", Thuong(a, b));

                }
                break;

            case 5:
                
                printf("Nhap a: "); nhapDouble(&a);

                res = Can(a);
                if(res >= 0){

                    printf("Can bac 2 cua: %.0lf = %.0lf\n", a, res);
                    luuLichSu("Can bac 2", Can(a));

                }
                break;

            case 6:

                printf("Nhap n: "); nhapInt(&n);

                kq = gt(n);
                if(kq >= 0){

                    printf("Ket qua giai thua cua: %d = %lld\n", n, kq);
                    luuLichSu("Giai thua", gt(n));

                }

                break;

            case 7:

                printf("Nhap a: "); nhapDouble(&a);
                printf("Nhap b: "); nhapDouble(&b);

                printf("Luy thua cua: %.0lf ^ %.0lf = %.0lf\n", a, b, lt(a, b));
                luuLichSu("Luy Thua", lt(a, b));
                break;

            case 8:

                printf("Nhap n: "); nhapInt(&n);
                if(snt(n)){
                    printf("%d LA so nguyen to !\n", n);
                }
                else{
                    printf("%d KHONG LA so nguyen to !\n", n);
                }

                break;

            case 9:

                printf("Nhap n: "); nhapInt(&n);
                printf("Nhap x: "); nhapInt(&x);

                printf("GCD(%d,%d) = %d\n", n, x, gcd(n, x));
                luuLichSu("GCD", gcd(n, x));

                break;

            case 10:

                printf("Nhap n: "); nhapInt(&n);
                printf("Nhap x: "); nhapInt(&x);

                printf("LCM(%d,%d) = %d\n", n, x, lcm(n, x));
                luuLichSu("LCM", lcm(n ,x));

                break;

            case 11:

                printf("Nhap goc do: "); nhapDouble(&a);
                printf("Sin(%.2lf) = %.2lf\n", a, sine(a));
                luuLichSu("Sin", sine(a));

                break;

            case 12: 

                printf("Nhap goc do: "); nhapDouble(&a);
                printf("Cos(%.2lf) = %.2lf\n", a, cosine(a));
                luuLichSu("Cos", cosine(a));

                break;

            case 13:

                printf("Nhap goc do: "); nhapDouble(&a);
                printf("Tan(%.2lf) = %.2lf\n", a, tangent(a));
                luuLichSu("Tan", tangent(a));

                break;

            case 14:

                printf("Nhap so: "); nhapDouble(&a);
                printf("Lam tron(%.4lf) = %.0lf\n", a, lam_tron(a));
                luuLichSu("Lam tron", lam_tron(a));

                break;

            case 15:

                printf("Nhap so: "); nhapDouble(&a);
                printf("Ceil(%.4lf) = %.0lf\n", a, lam_tron_len(a));
                luuLichSu("Ceil", lam_tron_len(a));

                break;

            case 16:

                printf("Nhap so: "); nhapDouble(&a);
                printf("Floor(%.4lf) = %.0lf", a, lam_tron_xuong(a));
                luuLichSu("Floor", lam_tron_xuong(a));

                break;

            case 17:

                printf("Nhap so: "); nhapDouble(&a);
                if(a <= 0){

                    printf("Loi! Khong co log voi so am !\n");

                }
                else{

                    printf("Log(%.2lf) = %.2lf\n", a, log_tu_nhien(a));
                    luuLichSu("Ln", log_tu_nhien(a));

                }

                break;

            case 18:

                printf("Nhap so: "); nhapDouble(&a);
                if(a <= 0){

                    printf("Loi! Khong co lo10 voi so am !\n");

                }
                else{

                    printf("Log10(%.2lf) = %.2lf\n", a, log10_co_so(a));
                    luuLichSu("log10", log10_co_so(a));


                }

                break;

            case 19:

                printf("Nhap so: "); nhapInt(&n);
                if(n < 0){

                printf("Loi! so am khong la so le, khong la so chan !\n");
            
                }

                check(n);

                break;

            case 20:

                printf("Nhap so: "); nhapInt(&n);
                if(soHoanHao(n)){

                    printf("%d la so hoan hao !\n", n);

                }
                else{

                    printf("%d khong phai la so hoan hao !\n", n);

                }

                break; 


            case 21:

                hienThiLichSu();
                break;

            case 22:

                xoaLichSu();
                break;


            case 0: 

                printf("Da thoat chuong trinh !\n");
                return 0;
                
            default:

                printf("Lua chon khong hop le ! Vui long chon lai. \n");
        }


    }while(choice != 0);

    return 0;
}