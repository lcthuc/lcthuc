#include <iostream>
#include <fstream>

using namespace std;

// Khai bao lop danh sach lien ket kep
class LinkedList 
{
    private:
        struct node
        {
            int infor;
            node *prev;
            node *next;
        }   *head, *tail;

    public:
        LinkedList();
        ~LinkedList();
        void insertTail(int x);         
        void insertHead(int x);         
        void displayForward();          
        void displayBackward();         
        int count();                    
        void deleteByValue(int x);      
        node *search(int x);
    };

// === Chuong trinh chinh ===
int main() 
{
    //tao moi danh sach LKK
    LinkedList list;

    //doc vao tep
    ifstream fin("daysonguyen-bai34.txt");
    
    //khai bao bien
    int x;

    // Doc tep va dua vao cuoi danh sach LKK
    cout<<"Doc day so tu tep: ";
    while(fin>>x) {
        cout<<x<<"  ";
        list.insertTail(x);
    }

    cout<<"\n\nDanh sach theo thu tu tu trai sang phai:\n";
    list.displayForward();

    cout<<"\nDanh sach theo thu tu tu phai sang trai:\n";
    list.displayBackward();

    int sl=list.count();
    cout<<"\nSo phan tu trong DSLK kep: "<<sl<<endl;

    // Chen x vao dau danh sach
    cout<<"\nNhap x can chen vao dau danh sach: ";
    cin>>x;
    list.insertHead(x);
    cout<<"Danh sach sau khi chen:\n";
    list.displayForward();

    // Xoa nut co gia tri x
    cout<<"\nNhap x can xoa: ";
    cin>>x;
    list.deleteByValue(x);
    cout<<"Danh sach sau khi xoa:\n";
    list.displayForward();

    return 0;
}

// === Dinh nghia cac ham ===

LinkedList::LinkedList() 
{
    head=tail=NULL;
}

LinkedList::~LinkedList() 
{
    node *p=head;
    while(p){
        node *pTmp=p;
        p=p->next;
        delete pTmp;
    }
}

void LinkedList::insertTail(int x) 
{
    node *n=new node;
    n->infor=x;
    n->next=NULL;
    n->prev=tail;

    if (!tail)head=n;
    else tail->next=n;

    tail=n;
}

void LinkedList::insertHead(int x) 
{
    node *n = new node;
    n->infor=x;
    n->prev=NULL;
    n->next=head;

    if(!head)tail=n;
    else head->prev=n;

    head=n;
}

void LinkedList::displayForward()
{
    node *p=head;
    while(p)
    {
        cout<<p->infor<<" ";
        p=p->next;
    }

    cout<<endl;
}

void LinkedList::displayBackward() 
{
    node* p=tail;
    while(p){
        cout<<p->infor<<" ";
        p=p->prev;
    }

    cout<<endl;
}

int LinkedList::count() 
{
    int cnt=0;
    node* p=head;
    while(p){
        cnt++;
        p=p->next;
    }

    return cnt;
}

void LinkedList::deleteByValue(int x) 
{
    node* p=head;
    while(p)
    {
        if(p->infor==x) 
        {
            if(p == head)head=p->next;
            if(p == tail)tail=p->prev;
            if(p->prev)p->prev->next=p->next;
            if(p->next)p->next->prev=p->prev;

            delete p;
            cout<<"Da xoa phan tu x: " <<x<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Khong tim thay phan tu "<<x<<" de xoa!\n";
}

LinkedList::node* LinkedList::search(int x) 
{
    node* p=head;
    while(p){
        if(p->infor==x)return p;
        p=p->next;
    }
    return NULL;
}
