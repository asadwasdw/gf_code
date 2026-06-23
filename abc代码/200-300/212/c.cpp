#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e5+10;
int a[N], b[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int i=1,j=1;
    int ans=999999999;
    while(i<=n&&j<=m)
    {
        if(a[i]>=b[j]){
            ans=min(ans,a[i]-b[j]);
            j++;
        }
        else {
            ans=min(ans,b[j]-a[i]);
            i++;
        }
    }

    while(i<=n){
        ans=min(ans,a[i++]-b[m]);
    }

    while(j<=m){
        ans=min(ans,b[j++]-a[n]);
    }


    cout<<ans<<endl;
}