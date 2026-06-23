#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int d1=0;int d2=0;
    int w1=0;int w2=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>=d1){
            d2=d1;
            w2=w1;
            d1=x;
            w1=i;
        }
        else if(x>d2){
            d2=x;
            w2=i;
        }
    }

    cout<<w2;
}