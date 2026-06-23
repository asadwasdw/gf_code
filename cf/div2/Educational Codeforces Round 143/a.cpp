#include<iostream>
#include<algorithm>

using namespace std;

char a[50];
char b[25];
void solve()
{
    int n,m;cin>>n>>m;


    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }

    for(int i=m;i;i--){
        a[n+(m-i)+1]=b[i];
    }

    int ans=0;

    for(int i=2;i<=n+m;i++){
        if(a[i]==a[i-1])ans++;
    }

    if(ans>=2)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;


}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}