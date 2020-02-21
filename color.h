//cac ham in mau cho so nguyen 
//params: 1 so nguyen 


//in ra mau do cho so x dau vao
void redcout(const int &x)
{
    cout<<"\x1B[41m"<<x<<"\033[0m\t";
}

//in ra xanh la do cho so x dau vao
void greencout(const int &x)
{
    cout<<"\x1B[42m"<<x<<"\033[0m\t";
}

//in ra mau vang cho so x dau vao
void yellowcout(const int &x)
{
    cout<<"\x1B[43m"<<x<<"\033[0m\t";
}

//in ra mau xanh cho so x dau vao
void bluecout(const int &x)
{
    cout<<"\x1B[44m"<<x<<"\033[0m\t";
}