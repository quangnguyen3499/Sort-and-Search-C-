//main menu
//file header display.h chứa các hàm hiển thị menu, hàm nhập, xuất mảng đầu vào 
// display.h chứa các hàm xuất giá trị ứng với mỗi thuật toán tìm kiếm và sắp xếp

//in menu chính 
void mainMenu()
{
 cout<<endl<<"-------------------"<<endl;
 cout<<"1.Input"<<endl;
 cout<<"2.Searching algorithm"<<endl;
 cout<<"3.Sorting algorithm"<<endl;
 cout<<"0.Exit"<<endl;   
 cout<<endl<<"-------------------"<<endl;
}
// menu tìm kiếm
void searchMenu()
{
    cout<<endl<<"-------------------"<<endl;
    cout<<"1.Linear search"<<endl;
    cout<<"2.Binary search"<<endl;
    cout<<"3.Back"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<endl<<"-------------------"<<endl;
}

// menu sắp xếp
void sortMenu()
{   cout<<endl<<"-------------------"<<endl;
    cout<<"1.Selection sort"<<endl;
    cout<<"2.Insertion sort"<<endl;
    cout<<"3.Bubble sort"<<endl;
    cout<<"4.Interchange sort"<<endl;
    cout<<"5.Shell sort"<<endl;
    cout<<"6.Quick sort"<<endl;
    cout<<"7.Back"<<endl;
    cout<<"0.exit";
    cout<<endl<<"-------------------"<<endl;
}


//ham trả về giá trị được nhập vào từ bàn phím (dùng để lựa chọn công việc)
int  selectInput()
{
    cout<<endl<<"Choose an action:";
    int x;  
    cin>>x;  // luu gia tri
    return x;
}

//nhấn bất kì phím gì để tiếp tục
void PressEnter()
{   
    //char x;
    fflush(stdin);
    cout<<endl<<endl<<"Press any key to continue";
    cin.get();

}

//nhập giá trị mảng đầu vào input array
void arrayInput(int* &a,int &n)
{   
    cout<<"---------Array input ---------"<<endl;
    cout<<"Array length: n="; //nhập số phần tử n của mảng 
    cin>>n;     // input n
    delete[] a; //xoá mảng cũ  
    a=new int[n]; //cấp phát động mảng mới
    for (int i=0;i<n;i++)
    {
        cout<<"a["<<i<<"]="; //nhập từng phần tử của mảng
        cin>>a[i];
    }    
}

//display array
//hiển thị mảng
void arrayDisplay(int* &a,const int& n)
{   cout<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;    
}

//hàm hiển thị mảng cho Linear Search
void linearDisplay(int* &a,const int &n, const int &key) 
{   
    for (int i=0;i<n;i++)
        {
            if (i==key) yellowcout(a[i]); //key la phan tu dang so sanh 
            //nếu phần tử đang được so sánh thì sẽ in ra màu vàng
            //không thì in ra màu trắng như bình thường
            else cout<<a[i]<<"\t";
        }
}

//hàm hiển thị mảng cho Binary Search
//params: mang a, so phan tu n, vi tri trai,vi tri mid, vi tri phai
void binaryDisplay(int* &a,const int &n, const int &left, const int &mid,const int &right)
{   
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        //in mau xanh ca gia tri nam trong khoang left va right
        if ((i>=left) && (i<=right) && (i!=mid)) bluecout(a[i]);
            //in mau do gia tri o vi tri mid 
           else   if (i==mid) redcout(a[i]);
                    else cout<<a[i]<<"\t";
    }
}

//selectionDisplay(mang a, so phan tu, gia tri nn, dich de swap, trang thai da kiem tra)
//trang da kiemtra mark mau xanh la 
//vi tri de swap mau xanh bien 
//gia tri nn mau do 
//dung chung cho insertion sort
void selectionDisplay(int* &a,const int &n,const int &min,const  int &swaptarget, bool *mark ) 
{
    for (int i=0;i<n;i++)
    {
        //phan tu mang mark mang gia tri 1 tuc la da sap xep 
        //in ra mau xanh la 
        if (mark[i]) greencout(a[i]);
        //in mau xanh va mau do cho 2 phan tu chuan bi hoan doi 
        else if (i==swaptarget) bluecout(a[i]);
        else if (i==min) redcout(a[i]);
        else cout <<a[i]<<"\t";  
    }
}

void quickDisplay(int* &a,const int &n,const int &left,const int &mid,const int &right)
{
    for (int i=0;i<n;i++)
    {
        if (i==left || i==right) bluecout(a[i]);
            else if (i==mid) redcout(a[i]);
                else cout<<a[i]<<"\t"; 
    }
}

//void insertionDisplay(int *a,int n,int swap,int target,bool *mark)
