#include <iostream>
using namespace std;
int x[100];
int n, k;
void print() // in to hop 
{ 
    for(int i=1;i<=k;i++)
       cout<<x[i];
  	  cout<<endl;
}
void Try(int i) // hàm quay lui
{ 
    for(int j=x[i-1]+1;j<=n-k+i;j++)
	 {
            x[i]=j;
            if(i==k)
                 print();
            else    
                 Try(i+1);
    }
}
int main ()
{
	
	cout<<"Nhap n = ";
    cin>>n;
    cout<<"Nhap k = ";
    cin>>k; 
//    x[0]=0;
    Try(1);
}
