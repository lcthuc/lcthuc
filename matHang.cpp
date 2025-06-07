#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

//khai bao lop doi tuong
class MatHang
{    
    private:
	    string tenHang;
	    int soLuong;
	    float donGia;
    public:
	    void nhap();
        void xuat();
	    float thanhTien();
};

//===chuong trinh chinh===
int main()
{   
    //khai bao bien
    int n;
    cout<<"Nhap vao so luong mat hang: ";
    cin>>n;

    MatHang* danhSach = new MatHang[n];
    float thanhTien = 0;

    //nhap danh sach mat hang
    for(int i=0;i<n;++i)
    {
        cout<<"Nhap mat hang thu "<<i+1<<endl;
        danhSach[i].nhap();
    }

    //xuat danh sach va tinh tien
    cout<<"Danh sach mat hang: \n";
    for(int i=0;i<n;++i)
    {
        danhSach[i].xuat();
        thanhTien += danhSach[i].thanhTien();
    }

    cout<<"Tong tien tat ca mat hang: "<<thanhTien;
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void MatHang::nhap()
{
    cout<<"Nhap ten hang: ";
    cin.ignore();
    getline(cin, tenHang);
    cout<<"Nhap so luong mat hang: ";
    cin>>soLuong;
    cout<<"Nhap don gia: ";
    cin>>donGia;
}
void MatHang::xuat() 
{
    cout<<"Ten mat hang: "<<tenHang;
    cout<<"\nSo luong mat hang: "<<soLuong;
    cout<<"\nDon gia: "<<donGia;
    cout<<"\nThanh tien: "<<thanhTien()<<endl;
}
float MatHang::thanhTien()
{
    return soLuong*donGia;
}
