#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<typeinfo>
#include<iostream>
using namespace std;
class CanBo{
private:
char hoten[50], ngaysinh[15], khoa[30];
int sogiolam;
public:
//Thuoc tinh loai can bo:
int loai;
CanBo(){sogiolam = 0;}
CanBo(char *ht, char *ns, char *k, int sgl){
strcpy(hoten,ht);
strcpy(ngaysinh,ns);
strcpy(khoa,k);
sogiolam = sgl;
}
void Nhap(){
fflush(stdin);
cout<<"\nNhap ho ten: ";
gets(hoten);
fflush(stdin);
cout<<"\nNhap ngay sinh: ";
gets(ngaysinh);
fflush(stdin);
cout<<"\nNhap khoa: ";
gets(khoa);
fflush(stdin);
cout<<"\nNhap so gio lam viec: ";
cin>>sogiolam;
fflush(stdin);
} 
void Xuat(){
cout<<"Ho ten: "<<hoten<<" | Ngay sinh: "<<ngaysinh<<" | Khoa: "<<khoa<<" | So gio lam viec: "<<sogiolam<<endl;
}
virtual int getnckh(){
return 0;
}
int getsogiolam(){
return sogiolam;
}
void setloai(int l){
loai=l;
}
virtual int loaicb(){
return 0;
}
};
class CBGD:public CanBo{
private:
int nghiencuukh;
public:
CBGD(){}
CBGD(char *ht, char *ns, char *k, int sgl, int nckh):CanBo(ht,ns,k,sgl){
nghiencuukh = nckh;
}
void Nhap(){
CanBo::Nhap();
cout<<"\nTham gia nghien cuu khoa hoc ( 1-co | 2-khong )? ";
cin>>nghiencuukh;
}
void Xuat(){
CanBo::Xuat();
if(nghiencuukh == 1)
cout<<"\nCo tham gia nghien cuu khoa hoc\n";
else
cout<<"\nKhong co tham gia nghien cuu khoa hoc\n"; 
}
int getnckh(){
return nghiencuukh;
}
virtual int loaicb(){
return 1;
}
};
class CBHC:public CanBo{
public:
CBHC(){}
CBHC(char *ht, char *ns, char *k, int sgl):CanBo(ht,ns,k,sgl){
}
void Nhap(){
CanBo::Nhap();
}
void Xuat(){
CanBo::Xuat();
}
virtual int loaicb(){
return 2;
}
};
int main(){
int n,l;
CanBo *ds[100];
cout<<"\nNhap so luong can bo: ";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\nNhap chon loai can bo: (1-can bo giang day | 2-can bo hanh chinh) ";
cin>>l;
if(l==1)
{
CanBo *gd = new CBGD;
gd->Nhap();
gd->setloai(1);
ds[i] = gd;
}
else if(l==2){
CBHC hc;
hc.Nhap();
hc.setloai(2);
ds[i] = &hc;
}
else
i--;
}
cout<<"\nDanh sach can bo cua truong duoc lao dong tien tien loai A:\n ";
for(int i=0;i<n;i++)
if((ds[i]->loaicb() == 1 && ds[i]->getsogiolam()>=280 && ds[i]->getnckh() == 1)||(ds[i]->loaicb() == 2 && ds[i]->getsogiolam()>=700))
ds[i]->Xuat(); 
getch();
return 0;
}
