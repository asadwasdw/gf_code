#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=0;i<10;i++){
        if(((a>>i)&1)!=((b>>i)&1))
        {
            ans+=pow(2,i);
           // cout<<i<<" "<<ans<<endl;
        }
    }

    cout<<ans;
   
}