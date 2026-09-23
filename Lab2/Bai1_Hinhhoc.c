#include <stdio.h>
#define PI 3.14159
int main() {
    float chieudaiHCN, chieurongHCN;
    float chuvi, dientich;
    float r;
    printf("Nhap chieu dai hinh chu nhat: ");
    scanf("%f", &chieudaiHCN);
    printf("Nhap chieu rong hinh chu nhat: ");
    scanf("%f", &chieurongHCN);
    chuvi = (chieudaiHCN + chieurongHCN) * 2;
    dientich = chieudaiHCN * chieurongHCN;
    printf("Chu vi hinh chu nhat: %.2f\n", chuvi);
    printf("Dien tich hinh chu nhat: %.2f\n", dientich);

    //Tinh chu vi va dien tich hinh tron
    printf("Nhap ban kinh hinh tron: ");
    scanf("%f", &r);
    chuvi = 2 * PI * r;
    dientich = PI * r * r;
    printf("chu vi hinh tron: %.2f\n", chuvi);
    printf("dien tich hinh tron: %.2f\n", dientich);
    return 0;
}