
//ham tim kiem tuyen tinh 
//params: mang a, phan tu n cua mang 
//returns: vi tri cua gia tri can tim trong mang
//          neu khong tim thay tra ve gia tri -1
int linearSearch(int* &a,const int &n)
{   
    //nhap vao target de tim kiem
    cout<<endl<<"------Start linear search-----"<<endl; //bat dau tim kiem
    int target,step=1; 
    cout<<"Target value to search:"; //nhap vao gia tri can tim
    cin>>target;


    for (int i=0;i<n;i++)
    {   //in ra so buoc
        cout<<endl<<"-----step:"<<step<<"------"<<endl; sleep(1);

         //in ra mang linearSearch 
        cout<<"array: "; linearDisplay(a,n,i); sleep(1); 

        //in ra gia tri can so sanh 
        cout<<endl<<"Compare target value "<<target<<" to "<<"a["<<i<<"]="; 
        yellowcout(a[i]); sleep(1);
    
        if (a[i]== target) //neu so sanh bang nhau
        {   
            cout<<"\t"<<"\x1B[42m*match*\033[0m"<<endl;
            //in ra tim kiem thanh cong
            cout<<"\x1B[42m---Searching sucess-----\033[0m"<<endl;
            sleep(1);
            return i; //tra ve ket qua tim kiem
        }
        else 
        {   
            sleep(1);
            //tim kiem that bai
            cout<<"\t"<<"\x1B[41m*no match*\033[0m"<<endl;
        //arrayDisplay(a,n);
        }
        step++; //tang step len 1 don vi
        //PressEnter();
        sleep(1);
    } 
        //neu den cuoi mang khong tim thay thi tra ve -1
        cout<<endl<<"Finding fail"<<endl;
        return -1;
}


//ham tim kiem nhi phan  
//params: mang a, phan tu n cua mang
//returns: vi tri cua gia tri can tim trong mang
//          neu khong tim thay tra ve gia tri -1
int binarySearch(int* &a,const int &n)
{
    cout<<endl<<"------Start binary search-----"<<endl; //bat dau
    int target; 
    cout<<"target value to search:"; //nhap vao gia tri can tim
    cin>>target;
    //gan gia tri ban dau low o dau mang, high o cuoi mang    
    int low=0,high=n-1,step=1;
    do
    {   
        int mid=(low+high)/2;
       //mid nam o giua low va high

        cout<<endl<<"--------step:"<<step<<"--------"<<endl; //in ra step
        cout<<"Array been working:"<<endl; //in ra mang ban dau
        binaryDisplay(a,n,low,mid,high);  sleep(1); 
        //in ra cac gia tri left poin, right point va mid point
        cout<<endl<<"Left point:"<<"a["<<low<<"]="<<a[low]<<endl;sleep(1);
        cout<<"Right point:"<<"a["<<high<<"]="<<a[high]<<endl;sleep(1);
        cout<<"Mid point:"<<"a["<<mid<<"]="<<a[mid]<<endl; sleep(1);

        //tien hanh so sanh gia tri mid point voi gia tri can tim
        cout<<"Compare Mid point with target"; sleep(1);
        //neu khong bang nhau thi in ra "no match"
        if (a[mid]!=target) cout<<"\t"<<"\x1B[41m*no match*\033[0m"<<endl;

        //neu mid point< gia tri can tim thi thay doi gia tri left point
        if (a[mid] <target) 
        {
            cout<<"mid point<target"<<endl;
            cout<<"now change low point=mid point+1"<<endl;
            low=mid+1;

        }  
        else
        // nguoc lai thay doi gia tri right point
            if (a[mid]>target)  
                {   
                    cout<<"mid>target"<<endl;
                cout<<"now change high point location=mid point location-1"<<endl;
                    high=mid-1;
                } 
                else 
                {
                    //neu bang nhau thi in ra tim kiem thanh cong
                     cout<<"\t"<<"\x1B[42m*match*\033[0m"<<endl;
                    //in ra tim kiem thanh cong
                    cout<<"\x1B[42m---Searching sucess-----\033[0m"<<endl;
                    return mid; //tra ve gia tri vi tri cua gia tri 
                }
        if (low>high) //neu left point > right point thi ket thuc 
        {
            cout<<"finding fail"<<endl;
            return -1; //tra ve gia tri -1 vi khong tim duoc
        }  
        step++;  // tang step len 1 don vi 
        sleep(2);
       // PressEnter();
    }
    while (1);
}
