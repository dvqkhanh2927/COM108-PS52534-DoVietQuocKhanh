
#include <stdio.h>
#include <string.h>

struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

struct SinhVien ds[50];
int n = 0;

// Khai bao nguyen mau ham
void nhapXuatDanhSach();
void sapXepTheoDiem();
void timKiemTheoMSSV();
void xuatHocBongTheoNganh();
void xuatMotSinhVien(int i);
void xoaXuongDong(char s[]);

int main() {
    int chon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 8              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien               |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan           |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV                   |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh        |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                nhapXuatDanhSach();
                break;
            case 2:
                sapXepTheoDiem();
                break;
            case 3:
                timKiemTheoMSSV();
                break;
            case 4:
                xuatHocBongTheoNganh();
                break;
            case 5:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);

    return 0;
}

// Xoa ky tu xuong dong sau khi dung fgets
void xoaXuongDong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

// Xuat thong tin mot sinh vien
void xuatMotSinhVien(int i) {
    printf("Sinh vien thu %d:\n", i + 1);
    printf("MSSV: %s\n", ds[i].mssv);
    printf("Ten SV: %s\n", ds[i].tenSV);
    printf("Nganh hoc: %s\n", ds[i].nganhHoc);
    printf("Diem TB: %.2f\n\n", ds[i].diemTB);
}

// BAI 1: Nhap va xuat danh sach
void nhapXuatDanhSach() {
    int i;

    do {
        printf("Nhap so luong sinh vien (1-50): ");
        scanf("%d", &n);
        getchar();

        if (n < 1 || n > 50) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 50);

    for (i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);

        printf("MSSV: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        xoaXuongDong(ds[i].mssv);

        printf("Ten SV: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        xoaXuongDong(ds[i].tenSV);

        printf("Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        xoaXuongDong(ds[i].nganhHoc);

        do {
            printf("Diem TB (0-10): ");
            scanf("%f", &ds[i].diemTB);
            getchar();

            if (ds[i].diemTB < 0 || ds[i].diemTB > 10) {
                printf("Diem khong hop le! Vui long nhap lai.\n");
            }
        } while (ds[i].diemTB < 0 || ds[i].diemTB > 10);
    }

    printf("\n===== DANH SACH SINH VIEN =====\n");
    for (i = 0; i < n; i++) {
        xuatMotSinhVien(i);
    }
}

// BAI 2: Sap xep diem tang dan
void sapXepTheoDiem() {
    int i, j;
    struct SinhVien svTemp;

    if (n == 0) {
        printf("Vui long nhap danh sach sinh vien truoc!\n");
        return;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ds[i].diemTB > ds[j].diemTB) {
                svTemp = ds[i];
                ds[i] = ds[j];
                ds[j] = svTemp;
            }
        }
    }

    printf("\n===== DANH SACH SAU KHI SAP XEP =====\n");
    for (i = 0; i < n; i++) {
        xuatMotSinhVien(i);
    }
}

// BAI 3: Tim kiem theo MSSV
void timKiemTheoMSSV() {
    char maCanTim[50];
    int i, timThay = 0;

    if (n == 0) {
        printf("Vui long nhap danh sach sinh vien truoc!\n");
        return;
    }

    printf("Nhap MSSV can tim: ");
    fgets(maCanTim, sizeof(maCanTim), stdin);
    xoaXuongDong(maCanTim);

    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, maCanTim) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("MSSV: %s\n", ds[i].mssv);
            printf("Ten SV: %s\n", ds[i].tenSV);
            printf("Nganh hoc: %s\n", ds[i].nganhHoc);
            printf("Diem TB: %.2f\n", ds[i].diemTB);
            timThay = 1;
            break;
        }
    }

    if (timThay == 0) {
        printf("Khong tim thay sinh vien co MSSV: %s\n", maCanTim);
    }
}

// BAI 4: Xuat hoc bong theo nganh
void xuatHocBongTheoNganh() {
    int i, j, daInNganh, coHocBong = 0;

    if (n == 0) {
        printf("Vui long nhap danh sach sinh vien truoc!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            coHocBong = 1;
            daInNganh = 0;

            // Kiem tra nganh nay da duoc in chua
            for (j = 0; j < i; j++) {
                if (ds[j].diemTB >= 8.0 &&
                    strcmp(ds[j].nganhHoc, ds[i].nganhHoc) == 0) {
                    daInNganh = 1;
                    break;
                }
            }

            if (daInNganh == 0) {
                printf("\nNganh: %s\n", ds[i].nganhHoc);

                // Liet ke sinh vien dat hoc bong cua nganh
                for (j = 0; j < n; j++) {
                    if (ds[j].diemTB >= 8.0 &&
                        strcmp(ds[j].nganhHoc, ds[i].nganhHoc) == 0) {
                        printf("- %s - %s - Diem TB: %.2f\n",
                               ds[j].mssv,
                               ds[j].tenSV,
                               ds[j].diemTB);
                    }
                }
            }
        }
    }

    if (coHocBong == 0) {
        printf("Khong co sinh vien nao dat hoc bong.\n");
    }
}
