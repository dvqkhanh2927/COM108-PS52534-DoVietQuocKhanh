#include <stdio.h>
int main(){
    int a=5;
    int b=10;

    //in gia tri truoc khi hoan vi
    printf("Truoc khi hoan vi: a=%d, b=%d\n", a, b);

    //hoan vi khong dung bien trung gian 
    a=a+b;
    b=a-b;
    a=a-b;

    //in gia tri sau hoan vi
    printf("Sau khi hoan vi: a=%d, b=%d\n", a, b);
    return 0;
    
}