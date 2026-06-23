#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>a;

int main()
{
    int n;cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a.push_back(x);
    }

    sort(a.begin(),a.end());


    while(q--)
    {
        int x;cin>>x;
        int t=lower_bound(a.begin(),a.end(),x)-a.begin();
        cout<<a.size()-t<<endl;
    }

}