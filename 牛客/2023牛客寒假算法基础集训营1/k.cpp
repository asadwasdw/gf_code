#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    if(m<=(n+2)/3)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int dy=0;
    if(n>=4){
       dy =(n-1)%3;
       n-=dy;
       m-=dy;
    }
  


    int t=m-(n+2)/3;
   // cout<<t<<endl;
    int z=(n-1)/3;
    cout<<t/2*3+(t%2==1)*2-(n==m)+dy<<endl;
    
}