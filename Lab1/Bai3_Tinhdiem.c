#include <stdio.h>

int main(){
    char mssv[] = "PS52534";
    char hovaten[] = "Do Viet Quoc Khanh";
    float diemtoan = 8.5;
    float diemly = 7.5;
    float diemhoa = 9.0;
    float diemtrungbinh = (diemtoan + diemly + diemhoa) / 3;

    printf("MSSV: %s\n", mssv);
    printf("Ho va ten: %s\n", hovaten);
    printf("Diem toan: %.2f\n", diemtoan);
    printf("Diem ly: %.2f\n", diemly);
    printf("Diem hoa: %.2f\n", diemhoa);
    printf("Diem trung binh: %.2f\n", diemtrungbinh);
    return 0;
}