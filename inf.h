//main menu
void mainMenu()
{
 cout<<endl<<"-------------------"<<endl;
 cout<<"1.Input"<<endl;
 cout<<"2.Searching algorithm"<<endl;
 cout<<"3.Sorting algorithm"<<endl;
 cout<<"0.Exit"<<endl;   
 cout<<endl<<"-------------------"<<endl;
}
    //search menu
void searchMenu()
{
    cout<<endl<<"-------------------"<<endl;
    cout<<"1.Linear search"<<endl;
    cout<<"2.Binary search"<<endl;
    cout<<"3.Back"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<endl<<"-------------------"<<endl;
}

//sort menu
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

int  selectInput()
{
    cout<<endl<<"Choose an action:";
    int x;  
    cin>>x;  // luu gia tri
    return x;
}

void PressEnter()
{   
    //char x;
    fflush(stdin);
    cout<<endl<<endl<<"Press any key to continue";
    cin.get();

}

//input array
void arrayInput(int *a,int &n)
{   
    cout<<"---------Array input ---------"<<endl;
    cout<<"Array length: n=";
    cin>>n;     // input n
    for (int i=0;i<n;i++)
    {
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }    
}

//display array
void arrayDisplay(int* &a,const int& n)
{   cout<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;    
}
void linearDisplay(int *a,int n, int key) //ham in ra mang cho linearSearch 
{   
    for (int i=0;i<n;i++)
        {
            if (i==key) yellowcout(a[i]); //key la phan tu dang so sanh 
            else cout<<a[i]<<"\t";
        }
}

void binaryDisplay(int *a,int n,int left,int mid,int right)
{   cout<<endl;
    for (int i=0;i<n;i++)
    {
        if ((i>=left) && (i<=right) && (i!=mid)) bluecout(a[i]);
           else   if (i==mid) redcout(a[i]);
                    else cout<<a[i]<<"\t";
            
      
    }
     
}

//selectionDisplay(mang a, so phan tu, gia tri nn, dich de swap, trang thai da kiem tra)
//trang da kiemtra mark mau xanh la 
//vi tri de swap mau xanh bien 
//gia tri nn mau do 
//dung chung cho insertion sort
void selectionDisplay(int *a,int n,int min, int swaptarget, bool *mark) 
{
    for (int i=0;i<n;i++)
    {
        if (mark[i]) greencout(a[i]);
        else if (i==swaptarget) bluecout(a[i]);
        else if (i==min) redcout(a[i]);
        else cout <<a[i]<<"\t";  
    }
}


//void insertionDisplay(int *a,int n,int swap,int target,bool *mark)
