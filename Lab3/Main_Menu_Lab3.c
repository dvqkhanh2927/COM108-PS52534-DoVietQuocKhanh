#include <stdio.h>
#include <math.h>
void tinhhocluc(){

    printf("Tinh hoc luc sinh vien\n");
    float diem;
    do
    {
        printf("Nhap diem: ");
        scanf("%f",&diem);
    } while (diem <0 || diem > 10);

    
    if (diem>=9.0){
        printf("Xuat sac\n");
    }else if (diem>=8.0){
        printf("Gioi\n");
    }else if (diem>=6.5){
        printf("Kha\n");
    }else if (diem>=5.0){
        printf("Trung Binh\n");
    }else if (diem>=3.5){
        printf("Yeu\n");
    }else{
      printf("Kem\n");
    }
}
void giaiPTbachai(){
    printf("Giai phuong trinh bac hai\n");
    float a,b,c,x1,x2,Delta;
    printf("Nhap a,b,c: ");
    scanf("%f%f%f",&a,&b,&c);
    printf("Phuong trinh %.0fx2 + %.0fx + %.0f = 0\n",a,b,c);
    if (a==0){
      if (b==0){
        if (c==0){
          printf("Phuong trinh vo so nghiem\n");

        }else{
          printf("Phuong trinh vo nghiem");
        }
      }else{
        x1 = -c/b;
        printf("Nghiem x = %.2f\n",x1);
      } 
      
    }else{
      Delta = b*b - 4*a*c;
      if (Delta < 0)
      {
        printf("Phuong trinh vo nghiem\n");
      }else if (Delta == 0)
      {
        x1 = -b / (2*a);
        printf("Phuong trinh co nghiem kep x1 = x2 = %.2f",x1);
      }else{
        x1 = (-b + sqrt(Delta)) / (2*a);
        x2 = (-b - sqrt(Delta)) / (2*a);
      printf("Phuong trinh co 2 nghiem: x1 = %.2f x2 = %.2f\n",x1,x2);
      }
      
      
    }
    
}
void tinhtiendien(){
  float b1 = 1.678;
  float b2 = 1.734;
  float b3 = 2.014;
  float b4 = 2.536;
  float b5 = 2.834;
  float b6 = 2.927;
  float tongtien=0;
  int soKW;
    printf("Tinh tien dien tieu thu\n");
    printf("Nhap so KW tieu thu: ");
    scanf("%d",&soKW);
    if (soKW <= 50)
    {
      tongtien = soKW*b1;
    }else if (soKW <= 100)
    {
      tongtien = 50*b1 + (soKW - 50)*b2;
    }else if (soKW <= 200)
    {
      tongtien = 50*b1 + 50*b2 + (soKW -100)*b3;
    }else if (soKW <= 300)
    {
      tongtien = 50*b1 + 50*b2 + 100*b3 +(soKW -200)*b4;
    }else if (soKW <= 400)
    {
      tongtien = 50*b1 + 50*b2 + 100*b3 + 100*b4 +(soKW -300)*b5;
    }else{
      tongtien = 50*b1 + 50*b2 + 100*b3 + 100*b4 + 100*b5 +(soKW -400)*b6;
    }
    printf("Tong tien dien cho %d KW tieu thu la: %.2f\n",soKW, tongtien);
    
    

}
int main(){
int chon;
do
{
      printf("===== MENU CHUONG TRINH LAB 3 =====\n");
      printf("0. Thoat chuong trinh\n");
      printf("1. Tinh hoc luc sinh vien\n");
      printf("2. Giai phuong trinh bac hai\n");
      printf("3. Tinh tien dien tieu thu\n");
      printf("Nhap lua chon cua ban:");
      scanf("%d",&chon);
      switch (chon)
      {
      case 0:
        printf("Thoat chuong trinh\n");
        break;
      case 1:
        
        tinhhocluc();
        break;
      case 2:
        giaiPTbachai();
        
        break;
      case 3:
      tinhtiendien();
        
        break;

      default:
      printf("Lua chon khong hop le!\n");
        break;
      }
} while (chon !=0);
    
return 0;    
}
