#include <stdio.h>
#define PI 3.14159
int main(){
    float chieudai, chieurong;
    float chuvi, dientich;
    float r;
    printf("Nhap chieu dai: ");
    scanf("%f", &chieudai);
    printf("Nhap chieu rong: ");
    scanf("%f", &chieurong);
    chuvi = 2 * (chieudai + chieurong);
    dientich = chieudai * chieurong;
    printf("Chu vi hinh chu nhat: %.2f\n", chuvi);
    printf("Dien tich hinh chu nhat: %.2f\n", dientich);
    

    // Chuvi va dien tich hinh tron
    printf("Nhap ban kinh hinh tron: ");
    scanf("%f", &r);
    chuvi = 2 * PI * r;
    dientich = PI * r *r;
    printf("Chu vi hinh tron: %.2f\n", chuvi);
    printf("Dien tich hinh tron: %.2f\n", dientich);
    return 0;

}






