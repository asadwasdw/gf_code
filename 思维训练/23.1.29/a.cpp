#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    long long n,m,k;
   scanf("%lld%lld%lld",&n,&m,&k);

    long long  mi=n-1;
    long long  mx=n*(n-1)/2;

    if(k<2){
        cout<<"NO"<<endl;
    }
    else if(m>=mi&&m<mx&&k>3)
    {
        //非完全连通图 ，直径最小是2
        cout<<"YES"<<endl;
    }
    else if(m==mx&&k>2)
    {
        //完全图，直径是1
        cout<<"YES"<<endl;
    }
    else if(n==1&&m==0)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;





    }
}