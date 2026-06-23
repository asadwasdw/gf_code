#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<unordered_map>


using namespace std;
typedef long long ll;
unordered_map<long long,bool>st;
priority_queue<ll, vector<ll> ,greater<ll> > heap;



int main()
{
    int a[15];
    int n;cin>>n;
    int k;cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    heap.push(0);
    st[0]=true;

    for(int i=1;i<=k;i++)
    {
        long long t=heap.top();heap.pop();
        //cout<<t<<endl;

        for(int j=1;j<=n;j++)
        {
            if(!st[t+a[j]]){
                st[t+a[j]]=true;
                heap.push(t+a[j]);
            }
        }
    }

    cout<<heap.top()<<endl;



}