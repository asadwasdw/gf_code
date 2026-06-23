#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
typedef pair<int,int>PII;

map<PII,int>st;

void solve()
{
    int n;
    cin>>n;
    int x=0,y=0;
    bool ky=false;
    st[{x,y}]++;
    for(int i=1;i<=n;i++)
    {
        char a;cin>>a;

        if(a=='R')x++;
        if(a=='L')x--;
        if(a=='U')y++;
        if(a=='D')y--;
        st[{x,y}]++;
        if(st[{x,y}]>1)ky=true;
    }

    if(ky)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}

int main()
{
    //int t;cin>>t;while(t--)
    solve();
}