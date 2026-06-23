#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e4+10;
int a[N];
int num[N];

bool cmp(int a,int b)
{
    return a>b;
}
bool cmp2(int a,int b)
{
    if(num[abs(a)]!=num[abs(b)])
    return num[abs(a)]>num[abs(b)];

    if(abs(a)!=abs(b))
    {
        return abs(a)>abs(b);
    }
    return a>b;

}

void solve()
{
    memset(num,0,sizeof num);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[abs(a[i])]++;

    }
    sort(a+1,a+n+1,cmp);

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)sum++;
        else sum--;
        cout<<sum<<" ";
    }
    cout<<endl;

    sort(a+1,a+n+1,cmp2);
     sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)sum++;
        else sum--;
        cout<<sum<<" ";
    }
    cout<<endl;

}

int main()
{
   int t;cin>>t;while(t--)
    {
        solve();
    }
    
}
