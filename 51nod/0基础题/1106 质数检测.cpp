#include<iostream>
#include<algorithm>

using namespace std;


bool pd(int x)
{

    for(int i=2;i<=x/i;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(pd(x))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}