#include<unistd.h>
#include<iostream>
using namespace std;
#include"color.h"// thư viện in màu
#include"display.h" //thư viện display menu va cac thuat toan  
#include"sort.h" //thu vien chua cac ham sap xep
#include"search.h" //thu vien chua cac ham tim kiem 



int main ()
{
    int *a=new int[0],n; // khai bao mang chinh va n so phan tu
    bool sortCheck=0; // bien kiem tra xem da sort chua
    cout<<endl<<endl<<"*********** ARRAY SEARCHING & SORTING PROGRAM *************** "<<endl;
    
    while (1)
    {   
        mainMenu(); // in ra main menu
        switch (selectInput())  // xu ly tung truong hop 
        {   //nhap du lieu mang
            case 1: 
                    sortCheck=false;
                    arrayInput(a,n);
                    cout<<"Input array:";
                    arrayDisplay(a,n); 
                    break;
            // chuyen qua menu search; 
            case 2: //menu search
                    
                    searchMenu();
                    switch (selectInput())  //xu ly lua chon 
                    {   
                        case 1: //linear search
                                sleep(1); 
                                cout<<linearSearch(a,n)<<" is the location of target value"<<endl;  
                                // chay va in ra ket qua tim kiem 
                                cout<<endl<<"-------end------"<<endl; 
                                PressEnter();
                                break; 
                        case 2: //binary search 
                                if (!sortCheck) //kiem tra xem mang da sap xep chua
                                {
                                        cout<<endl<<"The array is unsorted."
                                            <<endl<<"Can not use binary search!!!"; 
                                        sleep(1);
                                        break;//neu chua sap xep thi thoat ra
                                }
                                cout<<endl<<binarySearch(a,n)<<" is the location of target value"<<endl;
                                PressEnter();
                                break; 
                        case 3: break;  //back
                        case 0:goto OUT; //exit 
                    }
                    break;
            case 3: // menu sort
                    sortMenu();
                    switch (selectInput())
                    {
                            case 1:     sortCheck=true;
                                        //selection sort
                                        selectionSort(a,n);
                                        cout<<endl<<"===========Final result=========:"<<endl;
                                        arrayDisplay(a,n);
                                        cout<<endl<<"-------end------"<<endl;
                                        PressEnter();
                                        break;  
                                        
                            case 2:      sortCheck=true;
                                         //insertion sort
                                        insertionSort(a,n);
                                        cout<<endl<<"===========Final result=========:"<<endl;
                                        arrayDisplay(a,n);
                                        cout<<endl<<"-------end------"<<endl;   
                                        PressEnter();
                                        break;  

                            case 3:     
                                         sortCheck=true;
                                        //bubble sort
                                        bubbleSort(a,n);
                                        cout<<endl<<"============Final result============"<<endl;
                                        arrayDisplay(a,n);
                                        cout<<endl<<"-------end------"<<endl;
                                        PressEnter();
                                        break;

                            case 4:      sortCheck=true;
                                        interchangeSort(a,n);
                                        cout<<endl<<"============Final result============"<<endl;
                                        arrayDisplay(a,n);
                                        cout<<endl<<"-------end------"<<endl;
                                        PressEnter();
                                        break;

                            case 5:      sortCheck=true;
                                        //shell sort
                                        shellSort(a,n);
                                         cout<<endl<<"============Final result============"<<endl;
                                        arrayDisplay(a,n);
                                        cout<<endl<<"-------end------"<<endl;
                                        PressEnter();
                                        break;

                            case 6:      sortCheck=true;
                                        //quick sort
                                        quickSort(a,n,0,n-1);
                                         cout<<endl<<"============Final result============"<<endl;
                                        arrayDisplay(a,n);
                                        cout<<endl<<"-------end------"<<endl;
                                        PressEnter();
                                        break;
                            case 7:break;

                    }
                    break;
            case 0: 
                        cout<<endl<<"-------END---------"<<endl;
                        goto OUT;
        }
        
    } 
    cout<<endl;
    OUT: return 0;
 
}
