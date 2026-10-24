#include <stdio.h>
#include <string.h>
int main() {
    char ho[30], tenLot[30], ten[30];
    char hoTen[100] = "";

    printf("Nhap ho: ");
    fgets(ho, sizeof(ho), stdin);
    ho[strcspn(ho, "\n")] = '\0';

    printf("Nhap ten lot: ");
    fgets(tenLot, sizeof(tenLot), stdin);
    tenLot[strcspn(tenLot, "\n")] = '\0';

    printf("Nhap ten: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';

    strcat(hoTen, ho);
    strcat(hoTen, " ");
    strcat(hoTen, tenLot);
    strcat(hoTen, " ");
    strcat(hoTen, ten);

    printf("Ho ten: %s\n", hoTen);

    return 0;
}