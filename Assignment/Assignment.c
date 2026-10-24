#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 100

// Ham tim UCLN
long long UCLN(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 1. Kiem tra so nguyen, so nguyen to, so chinh phuong
void chucNang1() {
    int x;
    printf("Nhap so nguyen x: ");
    if (scanf("%d", &x) != 1) {
        printf("Du lieu khong hop le!\n");
        return;
    }

    printf("%d la so nguyen.\n", x);

    if (x < 2) {
        printf("%d khong phai so nguyen to.\n", x);
    } else {
        int laNguyenTo = 1;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                laNguyenTo = 0;
                break;
            }
        }

        if (laNguyenTo)
            printf("%d la so nguyen to.\n", x);
        else
            printf("%d khong phai so nguyen to.\n", x);
    }

    if (x >= 0) {
        int can = (int)sqrt((double)x);
        if (can * can == x)
            printf("%d la so chinh phuong.\n", x);
        else
            printf("%d khong phai so chinh phuong.\n", x);
    } else {
        printf("%d khong phai so chinh phuong.\n", x);
    }
}

// 2. Tim UCLN va BCNN
void chucNang2() {
    long long a, b;

    printf("Nhap hai so nguyen a, b: ");
    if (scanf("%lld%lld", &a, &b) != 2) {
        printf("Du lieu khong hop le!\n");
        return;
    }

    long long u = UCLN(a, b);
    long long bcnn = 0;

    if (u != 0)
        bcnn = llabs((a / u) * b);

    printf("UCLN = %lld\n", u);
    printf("BCNN = %lld\n", bcnn);
}

// 3. Tinh tien Karaoke
void chucNang3() {
    int batDau, ketThuc;

    printf("Nhap gio bat dau (12-23): ");
    if (scanf("%d", &batDau) != 1) {
        printf("Du lieu khong hop le!\n");
        return;
    }

    printf("Nhap gio ket thuc (12-23): ");
    if (scanf("%d", &ketThuc) != 1) {
        printf("Du lieu khong hop le!\n");
        return;
    }

    if (batDau < 12 || batDau >= 23 ||
        ketThuc > 23 || ketThuc <= batDau) {
        printf("Gio khong hop le!\n");
        return;
    }

    int soGio = ketThuc - batDau;
    double tien;

    if (soGio <= 3)
        tien = soGio * 150000.0;
    else
        tien = 3 * 150000.0 + (soGio - 3) * 150000.0 * 0.7;

    if (batDau >= 14 && batDau <= 17)
        tien *= 0.9;

    printf("So gio hat: %d\n", soGio);
    printf("Tong tien Karaoke: %.0f VND\n", tien);
}

// 4. Tinh tien dien theo 6 bac
void chucNang4() {
    double kwh, tien = 0;

    printf("Nhap so kWh dien tieu thu: ");
    if (scanf("%lf", &kwh) != 1 || kwh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }

    double conLai = kwh;
    double bac[6] = {50, 50, 100, 100, 100, 1e18};
    double gia[6] = {1678, 1734, 2014, 2536, 2834, 2927};

    for (int i = 0; i < 6 && conLai > 0; i++) {
        double soDien = conLai < bac[i] ? conLai : bac[i];
        tien += soDien * gia[i];
        conLai -= soDien;
    }

    printf("Tong tien dien: %.0f VND\n", tien);
}

// 5. Doi tien
void chucNang5() {
    long long tien;
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    printf("Nhap so tien can doi (nghin dong): ");
    if (scanf("%lld", &tien) != 1 || tien < 0) {
        printf("So tien khong hop le!\n");
        return;
    }

    for (int i = 0; i < 9; i++) {
        int soTo = (int)(tien / menhGia[i]);
        tien %= menhGia[i];

        if (soTo > 0)
            printf("%d nghin: %d to\n", menhGia[i], soTo);
    }
}

// 6. Tinh lai vay ngan hang trong 12 thang
void chucNang6() {
    double vay;

    printf("Nhap so tien muon vay (VND): ");
    if (scanf("%lf", &vay) != 1 || vay <= 0) {
        printf("So tien vay khong hop le!\n");
        return;
    }

    double gocThang = vay / 12.0;
    double conLai = vay;

    printf("\n%-6s %-18s %-18s %-18s %-18s\n",
           "Thang", "Tien lai", "Tien goc",
           "Tong tra", "Con lai");

    for (int i = 1; i <= 12; i++) {
        double lai = conLai * 0.05;
        double goc = (i == 12) ? conLai : gocThang;
        double tong = lai + goc;

        conLai -= goc;
        if (conLai < 0.01) conLai = 0;

        printf("%-6d %-18.0f %-18.0f %-18.0f %-18.0f\n",
               i, lai, goc, tong, conLai);
    }
}

// 7. Vay tien mua xe
void chucNang7() {
    double phanTram;

    const double giaXe = 500000000.0;
    const int soThang = 24 * 12;
    const double laiNam = 0.072;

    printf("Nhap phan tram vay (0-100): ");
    if (scanf("%lf", &phanTram) != 1 ||
        phanTram < 0 || phanTram > 100) {
        printf("Phan tram vay khong hop le!\n");
        return;
    }

    double tienVay = giaXe * phanTram / 100.0;
    double traTruoc = giaXe - tienVay;
    double gocThang = tienVay / soThang;
    double laiThang = tienVay * laiNam / 12.0;
    double traThang = gocThang + laiThang;

    printf("Gia xe: %.0f VND\n", giaXe);
    printf("Tien tra truoc: %.0f VND\n", traTruoc);
    printf("Tien vay: %.0f VND\n", tienVay);
    printf("Tien tra hang thang (uoc tinh): %.0f VND\n",
           traThang);
    printf("Luu y: Lai duoc tinh tren so tien vay ban dau.\n");
}

// 8. Nhap va sap xep sinh vien theo diem giam dan
typedef struct {
    char hoTen[100];
    double diem;
} SinhVien;

const char *xepLoai(double diem) {
    if (diem >= 9.0) return "Xuat sac";
    if (diem >= 8.0) return "Gioi";
    if (diem >= 6.5) return "Kha";
    if (diem >= 5.0) return "Trung binh";
    return "Yeu";
}

void chucNang8() {
    SinhVien sv[MAX], tam;
    int n;

    printf("Nhap so sinh vien (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("So luong khong hop le!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap ho ten sinh vien %d: ", i + 1);
        scanf(" %99[^\n]", sv[i].hoTen);

        printf("Nhap diem: ");
        if (scanf("%lf", &sv[i].diem) != 1 ||
            sv[i].diem < 0 || sv[i].diem > 10) {
            printf("Diem khong hop le!\n");
            return;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                tam = sv[i];
                sv[i] = sv[j];
                sv[j] = tam;
            }
        }
    }

    printf("\n%-25s %-10s %-15s\n", "Ho ten", "Diem", "Hoc luc");
    for (int i = 0; i < n; i++) {
        printf("%-25s %-10.2f %-15s\n",
               sv[i].hoTen, sv[i].diem, xepLoai(sv[i].diem));
    }
}

// 9. Tro choi FPOLY-LOTT 2/15
void chucNang9() {
    int a, b, x, y;

    printf("Nhap hai so khac nhau tu 1 den 15: ");
    if (scanf("%d%d", &a, &b) != 2 ||
        a < 1 || a > 15 || b < 1 || b > 15 || a == b) {
        printf("Du lieu khong hop le!\n");
        return;
    }

    x = rand() % 15 + 1;
    do {
        y = rand() % 15 + 1;
    } while (y == x);

    printf("Hai so may man: %02d va %02d\n", x, y);

    int trung = (a == x || a == y) + (b == x || b == y);

    if (trung == 0)
        printf("Chuc ban may man lan sau!\n");
    else if (trung == 1)
        printf("Chuc mung ban da trung giai nhi!\n");
    else
        printf("Chuc mung ban da trung giai nhat!\n");
}

// 10. Tinh toan va rut gon phan so
typedef struct {
    long long tu;
    long long mau;
} PhanSo;

int nhapPhanSo(PhanSo *p) {
    printf("Nhap tu so va mau so: ");
    if (scanf("%lld%lld", &p->tu, &p->mau) != 2 ||
        p->mau == 0)
        return 0;
    return 1;
}

PhanSo rutGon(PhanSo p) {
    if (p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }

    long long u = UCLN(p.tu, p.mau);
    if (u != 0) {
        p.tu /= u;
        p.mau /= u;
    }
    return p;
}

void inPhanSo(const char *ten, PhanSo p) {
    p = rutGon(p);
    printf("%s: %lld/%lld\n", ten, p.tu, p.mau);
}

void chucNang10() {
    PhanSo a, b, kq;

    printf("Phan so thu nhat:\n");
    if (!nhapPhanSo(&a)) {
        printf("Phan so khong hop le!\n");
        return;
    }

    printf("Phan so thu hai:\n");
    if (!nhapPhanSo(&b)) {
        printf("Phan so khong hop le!\n");
        return;
    }

    kq.tu = a.tu * b.mau + b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    inPhanSo("Tong", kq);

    kq.tu = a.tu * b.mau - b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    inPhanSo("Hieu", kq);

    kq.tu = a.tu * b.tu;
    kq.mau = a.mau * b.mau;
    inPhanSo("Tich", kq);

    if (b.tu == 0) {
        printf("Khong the chia cho phan so bang 0!\n");
    } else {
        kq.tu = a.tu * b.mau;
        kq.mau = a.mau * b.tu;
        inPhanSo("Thuong", kq);
    }
}

// MENU CHINH
int main() {
    int chon;
    srand((unsigned int)time(NULL));

    do {
        printf("\n========== MENU ASSIGNMENT LTCB ==========\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai vay ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. Tro choi FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("==========================================\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &chon) != 1) {
            printf("Vui long nhap so!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            chon = -1;
            continue;
        }

        switch (chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0: printf("Ket thuc chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}
