//Ho va ten: Le Chi Thuc
//MaSV: 6661839
//Lop: K66CNPMC
//De:
/*
Tệp văn bản "matran.txt" chứa ma trận số nguyên A kích thước m x n.

Đọc vào ma trận A từ tệp.

Tính trung bình cộng các phần tử của ma trận A.

Nhân ma trận A với một số nguyên x nhập từ bàn phím để được ma trận B (B = A * x).

Đưa ma trận A và B ra màn hình theo định dạng hàng cột.

Yêu cầu:

Sử dụng toán tử nhập/xuất (>>, <<) để đọc/ghi ma trận từ tệp.

Sử dụng toán tử xuất << để đưa ra màn hình theo định dạng hàng cột.

Sử dụng toán tử nhân * để nhân ma trận với một số.

Ma trận được động hóa theo kích thước m, n bằng 0
*/

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;
//khai bao lop doi tuong
class MaTran
{
    private:
        int hang, cot;
        int **duLieu;
    public:
        MaTran(int h = 0, int c = 0);
        ~MaTran();
        friend istream& operator>>(istream& fin, MaTran& mt);
        friend ostream& operator<<(ostream& cout, const MaTran& mt);
        MaTran operator *(int x);
        double trungBinhCong();

};

//===chuong trinh chinh===
int main()
{
    //khai bao bien
    MaTran A;

    //khai bao tep doc vao 
    ifstream fin("matran.txt");
    if(!fin)
    {
        cout<<"Ma tran khong hop le";
        return 1;
    }

    fin>>A;
    fin.close();

    cout<<"MaTran A la: \n"<<A;
    cout<<"Trung binh cong: "<<A.trungBinhCong()<<endl;

    int x;
    cout<<"Nhap vao x : ";
    cin>>x;

    MaTran B = A * x;
    cout<<"Ma tran B = A * "<<x<<"la: \n"<<B;
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
MaTran::MaTran(int h, int c)
{
    hang = h;
    cot = c;
    if(hang==0||cot==0)
    {
        duLieu = nullptr;
        return;
    }
    duLieu = new int*[hang];
    for(int i=0;i<hang;i++)
        duLieu[i] = new int[cot];

}

MaTran::~MaTran()
{
    if(duLieu)
    {
        for(int i=0;i<hang;i++)
        delete[] duLieu[i];
        delete[] duLieu;
    }

}
istream& operator>>(istream& fin, MaTran& mt)
{
    fin>>mt.hang>>mt.cot;
    mt.duLieu = new int *[mt.hang];
    for(int i=0;i<mt.hang;i++)
    {
        mt.duLieu[i] = new int[mt.cot];
        for(int j=0;j<mt.cot;j++)
        fin>>mt.duLieu[i][j];
    }
    return fin;

}

ostream& operator<<(ostream& cout, const MaTran& mt)
{
    for(int i=0;i<mt.hang;i++)
    {
        for(int j=0;j<mt.cot;j++)
        cout<<mt.duLieu[i][j]<<"\t";
        cout<<endl;
    }
    return cout;

}

MaTran MaTran::operator *(int x)
{
    MaTran kq(hang, cot);
    for(int i=0;i<hang;i++)
    for(int j=0;j<cot;j++)
    kq.duLieu[i][j]=duLieu[i][j] * x;
    return kq;

}

double MaTran::trungBinhCong()
{
    int tong=0, dem=0;
    for(int i=0;i<hang;i++)
    for(int j=0;j<cot;j++)
    {
        tong += duLieu[i][j];
        ++dem;
    }
        
    if(dem>0)
        return (double) tong/dem;
    else
        return 0;

}
