#include<iostream>
#include<algorithm>

using namespace std;

const int N=55;
int a[N],s[N];

void solve()
{
    int n,k;cin>>n>>k;

    for(int i=0;i<=50;i++)a[i]=s[i]=0;

    for(int i=1;i<=n;i++)
    {
        int l,r;cin>>l>>r;

        if(l<=k&&k<=r){
            s[l]++;
            s[r+1]--;
        }
    }

    for(int i=1;i<=50;i++)
    {
        a[i]=s[i]+a[i-1];

       // cout<<a[i]<<" ";
    }


    for(int i=1;i<=50;i++){
        if(i==k)continue;
        if(a[i]==a[k]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;



}



int main()
{
    int t;cin>>t;while(t--)
    solve();
}