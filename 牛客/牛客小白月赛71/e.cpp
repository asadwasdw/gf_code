#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

   long long  a,b;
  long long ans=0x3f3f3f3f3f3f3f3f;


void check(long long i)
{
    if(i==1)return ;
    if(a%i==0)ans=min(ans,0ll);
    else ans=min(ans,i-a%i);

}


int main()
{
 
    cin>>a>>b;

    if(a<b)swap(a,b);
    
    long long  d=a-b;
   // cout<<a<<b<<d<<endl;
    if(d==1){
        cout<<"-1";
        return 0;
    }

    if(d==0)
    {
        if(a==1)cout<<"1";
        else cout<<"0";
        return 0;
    }

 

    for(int i=1;i<=sqrt(d)+1;i++){

        if(d%i==0)
        {
            check(i);
            check(d/i);

        }

    }


    cout<<ans<<endl;

}