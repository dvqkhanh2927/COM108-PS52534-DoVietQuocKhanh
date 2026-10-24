
#include <stdio.h>
#include <string.h>
#include <conio.h>

// Khai bao nguyen mau ham
void bai1();
void bai2();
void bai3();
void bai4();
void xoaXuongDong(char s[]);
void nhapMatKhau(char password[]);
void daoChuoi(char s[]);

int main() {
    int chon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 7              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi              |\n");
        printf("| 2. Dang nhap bang Username va Password            |\n");
        printf("| 3. Sap xep chuoi theo chu cai                     |\n");
        printf("| 4. Doi so thap phan sang thap luc phan            |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        // Xoa ky tu con lai trong bo dem ban phim
        while (getchar() != '\n');

        switch (chon) {
            case 1:
                bai1();
                break;
            case 2:
                bai2();
                break;
            case 3:
                bai3();
                break;
            case 4:
                bai4();
                break;
            case 5:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 5);

    return 0;
}

// Xoa ky tu xuong dong cuoi chuoi
void xoaXuongDong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

// BAI 1: Dem nguyen am va phu am
void bai1() {
    char s[200];
    int nguyenAm = 0, phuAm = 0;
    int i;

    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    xoaXuongDong(s);

    for (i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }

        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n",
           s, nguyenAm, phuAm);
}

// Nhap mat khau, hien dau * va xu ly Backspace
void nhapMatKhau(char password[]) {
    int i = 0;
    char c;

    while (1) {
        c = getch();

        if (c == '\r') {
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (c >= 32 && c <= 126) {
            if (i < 49) {
                password[i++] = c;
                printf("*");
            }
        }
    }

    password[i] = '\0';
    printf("\n");
}

// BAI 2: Dang nhap
void bai2() {
    char username[50];
    char password[50];

    printf("Nhap username: ");
    fgets(username, sizeof(username), stdin);
    xoaXuongDong(username);

    printf("Nhap password: ");
    nhapMatKhau(password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "12345") == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

// BAI 3: Sap xep 5 chuoi theo thu tu chu cai
void bai3() {
    char s[5][20];
    char temp[20];
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("Nhap chuoi thu %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        xoaXuongDong(s[i]);
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("Cac chuoi sau khi sap xep:\n");

    for (i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

// Dao nguoc chuoi
void daoChuoi(char s[]) {
    int i, j;
    char temp;

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

// BAI 4: Doi so thap phan sang thap luc phan
void bai4() {
    int n, soGoc;
    int du;
    char hexa[20];
    char kyTuHexa[] = "0123456789ABCDEF";
    int i = 0;

    printf("Nhap so nguyen khong am: ");

    if (scanf("%d", &n) != 1) {
        printf("So nhap vao khong hop le!\n");

        // Xoa du lieu sai trong bo dem
        while (getchar() != '\n');
        return;
    }

    // Kiem tra so am
    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    soGoc = n;

    if (n == 0) {
        hexa[i++] = '0';
    } else {
        while (n > 0) {
            du = n % 16;
            hexa[i++] = kyTuHexa[du];
            n = n / 16;
        }
    }

    hexa[i] = '\0';

    daoChuoi(hexa);

    printf("So thap luc phan cua %d la: %s\n", soGoc, hexa);
}
