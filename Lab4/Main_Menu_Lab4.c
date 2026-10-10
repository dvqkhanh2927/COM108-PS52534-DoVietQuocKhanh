#include <stdio.h>
#include <math.h>
void trungbinhsochan(){
   int min, max;
   int i;
   int tong = 0;
   int biendem = 0;
   float trungbinh;

   printf("Nhap min: ");
   scanf("%d",&min);

   printf("Nhap max: ");
   scanf("%d",&max);

   if (min>max){
    printf("Khong co so nao chia het cho 2 \n");
    return;
   }
   i = min;
   while (i <= max){
    if (i % 2 ==0){
        tong += i;
        biendem++;
    }
    i++;
   }
   if (biendem == 0){
    printf("Khong co so nao chia het cho 2\n");
   }
   else{
    trungbinh = (float)tong / biendem;

    printf("Tong cac so chia het cho 2: %d\n", tong);
    printf("So luong cac so chia het cho 2: %d\n", biendem);
    printf("Trung binh cong: %.2f\n", trungbinh);
   }
   


}
void KiemTraNguyenTo(){
    int x;
    int i;
    int laNguyenTo =1;

    printf("Nhap x: ");
    scanf("%d",&x);

    if (x < 2){
        laNguyenTo = 0;
    }
    else{
        for ( i = 2; i < x; i++)
        {
            if (x % i ==0){
                laNguyenTo = 0;
                break;
            }
            
        }
        
    }
    if (laNguyenTo ==1){
        printf("%d la so nguyen to\n", x);
    }
    else{
        printf("%d khong phai la so nguyen to\n", x);
    }

}
void kiemTraChinhPhuong() {
    int x;
    int i;

    printf("Nhap x: ");
    scanf("%d", &x);

    if (x == 0) {
        printf("%d la so chinh phuong.\n", x);
    }
    else if (x < 0) {
        printf("%d khong phai la so chinh phuong.\n", x);
    }
    else {
        for (i = 1; i <= x; i++) {
            if (i * i == x) {
                printf("%d la so chinh phuong.\n", x);
                break;
            }
        }

        if (i > x) {
            printf("%d khong phai la so chinh phuong.\n", x);
        }
    }
}

int main() {
    int luaChon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 4             |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2    |\n");
        printf("| 2. Kiem tra So nguyen to                         |\n");
        printf("| 3. Kiem tra So chinh phuong                      |\n");
        printf("| 4. Thoat chuong trinh                            |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                trungbinhsochan();
                break;

            case 2:
                KiemTraNguyenTo();
                break;

            case 3:
                kiemTraChinhPhuong();
                break;

            case 4:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 4);

    return 0;
}