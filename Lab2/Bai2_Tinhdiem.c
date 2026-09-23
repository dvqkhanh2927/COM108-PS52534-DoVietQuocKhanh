#include <stdio.h>
int main() {
    float diemtoan, diemly, diemhoa, diemtb;
    printf("Nhap diem toan: ");
    scanf("%f", &diemtoan);
    printf("Nhap diem ly: ");
    scanf("%f", &diemly);
    printf("Nhap diem hoa: ");
    scanf("%f", &diemhoa);
    diemtb = (diemtoan*3 + diemly*2 + diemhoa*1)/6;
    printf("Diem trung binh: %.2f\n", diemtb);
    return 0;

}