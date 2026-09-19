#include <stdio.h>

int main() {
    char mssv[] = "PS52534";
    char hovaten[] = "Do Viet Quoc Khanh";
    float diemToan = 8.0;
    float diemLy = 8.0;
    float diemHoa = 8.0;
    float diemTrungBinh = (diemToan + diemLy + diemHoa) / 3;

    printf("MSSV: %s\n", mssv);
    printf("Ho va Ten: %s\n", hovaten);
    printf("Diem Toan: %.2f\n", diemToan);
    printf("Diem Ly: %.2f\n", diemLy);
    printf("Diem Hoa: %.2f\n", diemHoa);
    printf("Diem trung binh: %.2f\n", diemTrungBinh);

    return 0;
}