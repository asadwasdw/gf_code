#include<algorithm>
#include<iostream>

using namespace std;

int solve()
{
    int n,m;
    cin>>n>>m;
    bool ym=false,yqt=false;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==m)ym=true;
        else yqt=true;
        sum+=x;
    }

    if(ym&&!yqt)return 0;
    if(sum==n*m){
        return 1;
    }
    if(ym)return 1;
    else return 2;  
}

int main()
{
    int t;cin>>t;while(t--)
    cout<<solve()<<endl;
}