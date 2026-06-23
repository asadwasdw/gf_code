#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin>>n;
    if(n<6&&n%2==0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int gs=(n+1)/2;
    cout<<gs<<endl;
    for(int i=1;i<gs;i++)
    {
        cout<<i-1<<" ";
    }
    if(n%2==0)cout<<gs;
    else cout<<gs-1;
}
