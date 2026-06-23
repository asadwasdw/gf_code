#include<iostream>
#include<algorithm>

using namespace std;


void solve()
{
    int n;cin>>n;
    int k;cin>>k;
    if(k==n-1&&n==4){
        cout<<"-1"<<endl;
        return;
    }

    if(k==n-1)
    {
        cout<<n-1<<" "<<n-2<<endl;
        cout<<"1"<<" "<<n-3<<endl;
        cout<<"0 2"<<endl;

        for(int i=3;i<n/2;i++){
        int t=n-1-i;
        if(t==n-3)break;
 
            cout<<i<<" "<<t<<endl;
    }
    return;

    }

    cout<<k<<" "<<n-1<<endl;
    if(k!=0)
    cout<<0<<" "<<n-1-k<<endl;

    for(int i=1;i<n/2;i++){
        int t=n-1-i;
        if(i!=k&&t!=k){
            cout<<i<<" "<<t<<endl;
        }
    }

    return;
}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}