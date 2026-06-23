#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        long long sum=0;

        for(int j=1;j<=7;j++)
        {
            int x;cin>>x;
            sum+=x;
        }
        cout<<sum<<" ";
    }
}