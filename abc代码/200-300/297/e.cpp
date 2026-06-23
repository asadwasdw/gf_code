#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;
ll a[15];
set<ll>s;

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)cin>>a[i];
    s.insert(0);
    for(int i=1;i<=k;i++)
    {
        for(int i=1;i<=n;i++)
        s.insert(*s.cbegin()+a[i]);

        s.erase(*s.cbegin());
    }

    cout<<*s.cbegin()<<endl;

}