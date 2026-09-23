#include <stdio.h>
int main() {
    char mssv[] ="PS52534";
    char ten[] = "Do viet quoc khanh";
    float diemtoan =9.0;
    float diemly =8.8;
    float diemhoa = 8.5;
    float diemtb = (diemtoan + diemly + diemhoa)/3;
    printf("MSSV: %s\n", mssv);
    printf("Ho va ten: %s\n", ten);
    printf("diem toan: %.2f\n", diemtoan);
    printf("diem ly: %.2f\n", diemly);
    printf("diem hoa: %.2f\n", diemhoa);
    printf("diem TB: %.2f\n", diemtb);
    return 0;
}