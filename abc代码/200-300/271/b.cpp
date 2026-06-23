#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 2e5+10;
vector<int> a[N];

int main()
{
    int n,q;cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            int t;cin>>t;
            a[i].push_back(t);
        }
    }

    while(q--)
    {
        int x,y;cin>>x>>y;
        cout<<a[x][y-1]<<endl;
    }

}