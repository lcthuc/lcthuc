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
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void MatHang::nhap()
{
    cout<<"Nhap ten hang: ";
    cin>>tenHang;
    cout<<"Nhap so luong mat hang: ";
    cin>>soLuong;
    cout<<"Nhap don gia: ";
    cin>>donGia;
}
void MatHang::xuat() 
{
    cout<<"Ten mat hang: "<<tenHang;
    cout<<"So luong mat hang: "<<soLuong;
    cout<<"Don gia: "<<donGia;
    cout<<"Thanh tien: "<<thanhTien()<<endl;
}
float MatHang::thanhTien()
{
    return soLuong*donGia;
}
