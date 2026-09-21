#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    // In giá trị trước khi hoán vị
    printf("Truoc khi hoan vi: a = %d, b = %d\n", a, b);

    // Hoán vị không dùng biến trung gian
    a = a + b;
    b = a - b;
    a = a - b;

    // In giá trị sau khi hoán vị
    printf("Sau khi hoan vi: a = %d, b = %d\n", a, b);

    return 0;
}