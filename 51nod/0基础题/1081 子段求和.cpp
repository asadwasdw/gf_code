#include<iostream>
#include<algorithm>

using namespace std;
#define int long long 
const int N=5e4+10;

int tr[N];
int n;
int lowbit(int x)
{
    return x&-x;
}

void add(int x,int c)
{
    for(int i=x;i<=n;i+=lowbit(i)){
        tr[i]+=c;
    }
}

int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        add(i,x);
    }

    int m;
    cin>>m;
    while(m--)
    {
        int l,len;
        cin>>l>>len;
        cout<<sum(l+len-1)-sum(l-1)<<endl;
    }
}

