
//thuat toan hoan doi 2 gia tri 
//params: 2 bien nguyen x,y 
//hoan thanh thuan toan 2 bien x,y duoc hoan doi gia tri
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}


//thuat toan sap xep chon truc tiep
//params: mang a, va so phan tu n 
// thuc hien sap xep chon truc tiep cho mang a gom n phan tu
// sap xep tang dan
void  selectionSort(int*& a,const int& n)
{   
    sleep(1);
    cout<<endl<<"-------------- Start insertion sort --------------"<<endl<<endl;
    bool mark[n]; // mang danh so phan tu da sap xep
    for (int i=0;i<n;i++) mark[i]=0;  //cho mark[]=0
    int swapped=0,step=0;   //bien luu vi tri cb hoan doi va step

    for (int left=0;left<n;left++) //left dem tu 0 den n-1
    {   
        step++;   
        cout<<endl<<endl<<"-------------Step "<<step<<"-------------"<<endl<<endl;
        sleep(1);
        int min=left; // cho min = left 

        //vong for de tim min tu left:n-1
        for (int i=left+1;i<n;i++)  // i chay tu left den n-1
            if (a[min]>a[i]) min=i;  


        cout<<"Unsorted array:";  //in ra mang chua swap
        if (min==left)  //kiem tra de neu khong can swap thi nhay den jmp
        {
            selectionDisplay(a,n,-1,-1,mark); //in nhu bt khong co mau
            cout<<endl<<endl<<"no need to swap";
            goto jmp;  //khong swap thi nhay xuong jmp
        }
        // neu van can swap thi lam cai nay ne 
        selectionDisplay(a,n,min,left,mark);
        cout<<endl<<endl<<"  Min value:"; redcout(a[min]); //in ra gia tri min
        cout<<endl<<"Swap target:"; bluecout(a[left]);  //in ra gia de swap
        swap(a[left],a[min]); //swap
        jmp: 
        sleep (1);
        mark[left]=1;
        cout<<endl<<endl<<"  Sorted array:";
        selectionDisplay(a,n,min,left,mark);
        sleep(1);
    }
    //sleep(2);
}

//thuat toan sap xep chen truc tiep
//params: mang a, va so phan tu n 
// thuc hien sap xep chen truc tiep cho mang a gom n phan tu
// sap xep tang dan
void insertionSort (int* &a,const int& n)
{
    int step=0; //khai bien step
    bool mark[n]; //mark de danh dau cac phan tu can da sap xep
    for (int i=0;i<n;i++) mark[i]=0;

    for (int i=1;i<n;i++)
    {   
        //chon 1 gia tri de chen, khai bao vi tri chen la vi tri lien truoc
         int insertValue=a[i],insertHole=i-1;
         // so sanh gia tri chen voi gia tri lien truoc no 
         if (insertValue>=a[insertHole]) //neu gia tri chen lon thi chi in ra, khong swap
         {
             //in ra ket qua, khong co swap
            cout<<endl<<"Step "<<++step<<":"; //in ra step
            cout<<endl<<"Unsorted array:"<<endl; //in ra mang 
            selectionDisplay(a,n,i,insertHole,mark); 
            cout<<endl<<"Compare a["<<insertHole<<"]="; bluecout(a[insertHole]);
            cout<<"with a["<<i<<"]=";redcout(a[i]);
            cout<<endl<<"Do nothing!"<<endl; //thong bao khong lam gi
         }  

         //neu gia tri chen nho hon gia tri lien truoc no 
        while (insertValue<a[insertHole] && insertHole>=0) 
        { 
            cout<<endl<<"Step "<<++step<<":"; //in ra step
            cout<<endl<<"Unsorted array:"<<endl; // in ra mang chua sap xep 
            selectionDisplay(a,n,insertHole+1,insertHole,mark); 
            //in ra so sanh gia tri chen
            cout<<endl<<"Compare a["<<insertHole<<"]="; bluecout(a[insertHole]); 
            cout<<"with a["<<insertHole+1<<"]=";redcout(a[insertHole+1]);
            //hoan doi gia tri chen voi gia tri lien truoc
            swap(a[insertHole+1],a[insertHole]);    
            sleep(1);

            //in ra mang sau khi hoan doi 
            cout<<endl<<"Sorted array:"<<endl;
           selectionDisplay(a,n,insertHole+1,insertHole,mark);
           cout<<endl;
           insertHole--; //giam gia tri chen di 1 va tiep tuc so sanh 
                        // den khi nao thoa man dieu kien o while
           sleep(1);
        }
        sleep(2);
    }
    //selectionDisplay(a,n,-1,-1,mark);
}
//
void interchangeSort(int* &a,const int& n)
{
    arrayDisplay(a,n);
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
        if (a[i]>a[j])
        {
            swap(a[i],a[j]);
            arrayDisplay(a,n);
            sleep(1);
        } 
}


//bubbleSort
void bubbleSort(int*& a,const int& n)
{   
    int step=0;//khai bao bien step 
    bool mark[n]; //mang mark de danh dau phan tu da sap xep
    for (int i=0;i<n;i++) mark[i]=0; // cho tat ca bang 0 

    for (int i=n-1;i>0;i--)
    {   
        
        for (int j=0;j<i;j++)
            {
                //in ra step
                cout<<endl<<endl<<endl<<"Step "<<++step<<":";
                 sleep(1);
                 //in ra mang chua sap xep
                cout<<endl<<"Unsorted array:"<<endl;
                selectionDisplay(a,n,j+1,j,mark);
                sleep(1);
                //in ra so sanh 2 phan tu lien ke
                cout<<endl<<"Compare a["<<j<<"]="; bluecout(a[j]);
                cout<<"with a["<<j+1<<"]=";redcout(a[j+1]);
                sleep(1);
                //a[j]>a[j+1] thi hoan doi 2 gia tri
                if (a[j]>a[j+1]) swap(a[j],a[j+1]);
                //in ra mang sau khi hoan doi 
                cout<<endl<<endl<<"Sorted array:"<<endl;
                selectionDisplay(a,n,j+1,j,mark);
            }
        //PressEnter();    
        sleep(1);
        mark[i]=true; //sau khi da sap xep thi gan mark = true
    }
}

void shellSort(int* &a,int &n)
{
    int interval=n/2,tempValue,tempLocat;
    //interval = khoang cach bat cap 
    //thuc hien 
    while (interval >0)
    {
        cout<<endl<<"interval="<<interval<<endl;
        for (int i=interval;i<n;i++)
        {
            tempValue=a[i];
            tempLocat=i;
            //insertion sort neu interval =1
            cout<<endl;
            while (tempLocat>interval-1 && a[tempLocat-interval]>tempValue)
            {
                a[tempLocat] = a[tempLocat-interval];
                tempLocat=tempLocat-interval; 
            }
            if (tempLocat!=i)
            {
                a[tempLocat]=tempValue;
                arrayDisplay(a,n);
                sleep(1);
            } 
            
            cout<<endl;
        }
        interval/=2;
    }

}

void quickSort(int* &a,const int &n,const int &l,const int &r)
{
    int step=1;
    int key=(l+r)/2; //gia tri key nam chinh giua
    int i = l, j = r; 
    
    
    while(i <= j) 
    {
        //in ra step
        cout<<endl<<endl<<endl<<"---------Step "<<step<<"----------"; sleep(1);
        //in ra mang chua sap xep
        cout<<endl<<"Unsorted array:"<<endl;
        quickDisplay(a,n,0,key,0); sleep(1);
        while( a[i] < a[key] ) i++; //chon vi tri ben trai cua key     
        while( a[j] > a[key] ) j--; //chon vi tri ben phai cua key 
        //in ra thong tin cac vi tri
        cout<<endl<<endl<<"key = a["<<key<<"] = "<<a[key];
        cout<<endl<<"Choose a["<<i<<"] = "<<a[i]<<" on the left";    
        cout<<endl<<"Choose a["<<j<<"] = "<<a[j]<<" on the right"<<endl;
        sleep (1);  
        //in ra mang da danh dau vi tri can swap   
        quickDisplay(a,n,i,key,j);
        if(i <= j)
        {
            // neu i>=j thi khong lam gi
            if (i>=j) cout<<endl<<endl<<"left >= right"<<"=>> no need swapping"<<endl;
            if (i < j)
                {
                    //neu i<j thi swap 
                    swap(a[i], a[j]);
                    //in ra mang sau khi swap
                    cout<<endl<<endl<<"Sorted Array:"<<endl;
                    quickDisplay(a,n,i,key,j);
                }  
            i++;
            j--;
        }
        step++;
        sleep(2);
    }
    if (l < j) quickSort(a,n, l, j);   // lam lai voi mang a[l]....a[j]
    if (i < r) quickSort(a,n, i, r); // lam lai voi mang a[i]....a[r]
}
