#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
class Diem
{
    private:
        float x,y;
    public:
        friend istream& operator>>(istream& input, Diem& d);
        friend ostream& operator<<(ostream& output, Diem& d);
        float operator-(Diem& d2);
};
//===chuong trinh chinh===
int main()
{
    //tao moi doi tuong
    Diem A, B;

    //nhap toa do diem A
    cout<<"Nhap toa do diem A: ";
    cin>>A;

    //nhap toa do diem B
    cout<<"Nhap toa do diem B: ";
    cin>>B;

    //xuat ra man hinh toa do cua hai diem
    cout<<"Toa do diem A: "<<A<<endl;
    cout<<"Toa do diem B: "<<B<<endl;

    //tinh khoang cach hai diem
    cout<<"Khoang cach giua diem A va diem B: "<<A - B<<endl;
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
istream& operator>>(istream& input, Diem& d)
{
    input>>d.x>>d.y;
    return input;
}
ostream& operator<<(ostream& output, Diem& d)
{
    output<<"("<<d.x<<","<<d.y<<")";
    return output;
}
float Diem::operator-(Diem &d2)
{
    return sqrt((d2.x-x)*(d2.x-x) + (d2.y-y)*(d2.y-y));
}
