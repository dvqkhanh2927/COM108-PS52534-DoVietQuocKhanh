#include <stdio.h>
int main() {
    float diemtb;
    int hanhkiem;
    printf("Nhap diemTB: ");
    scanf("%f", &diemtb);
    printf("Nhap hanh kiem (1: Tot, 0: khac): ");
    scanf("%d", &hanhkiem);
    printf("Dieu kien diemTB >=8: %d\n", diemtb>=8);
    printf("Dieu kien hanh kiem tot: %d\n", hanhkiem ==1);
    printf("Ket qua xet hoc bong (1:Dat, 0:Khong dat): %d\n", (diemtb>=8) && (hanhkiem==1));
    return 0;


}