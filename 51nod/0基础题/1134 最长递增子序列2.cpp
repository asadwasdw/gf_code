#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int a[N],q[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    q[0]=-1e9;
   
   long long ans=0;
    for(int i=1;i<=n;i++){

        auto t=upper_bound(q+1,q+ans+1,a[i])-(q+1);
      //  cout<<t<<endl;
        q[t+1]=a[i];
        ans=max(t+1,ans);

       // for(int i=1;i<=ans;i++)cout<<q[i]<<" ";cout<<endl;
    }

    cout<<ans<<endl;
}