#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e5+10;
bool st[N];
int a[N];
int mx,mn;
int n;

void jsmx()
{
    for(int i=mx;i;i--){
        if(!st[i]){
            mx=i;
            return ;
        }
    }
    mx=0;
}

void jsmn()
{
    for(int i=mn;i<=n;i++){
        if(!st[i]){
            mn=i;
            return;
        }
    }
    mn=n+1;
}


void solve()
{
    memset(st,0,sizeof st);
    
    cin>>n;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1;
    int r=n;
    mx=n;
    mn=1;
    st[a[l]]=st[a[r]]=true;

    while(l<r)
    {
        jsmx();
        jsmn();
       // cout<<mx<<" "<<mn<<endl;
        if(mx>a[l]&&mx>a[r]&&mn<a[l]&&mn<a[r]){

            cout<<l<<" "<<r<<endl;
            return ;
        }
        if(a[l]>mn&&a[l]<mx){
            r--;
            st[a[r]]=true;
        }
        else{
            l++;
            st[a[l]]=true;
        }
    }

    cout<<"-1"<<endl;
}

int main()
{
    int t;cin>>t;while (t--)
    {
        solve();
    }
    
}