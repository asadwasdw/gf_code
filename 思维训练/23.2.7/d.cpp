#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int>a;
priority_queue<int>b;

int f(int x)
{
    int num=0;
    while(x){
        num++;
        x/=10;
    }
    return num;
}

void solve(){

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push(x);
    }

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        b.push(x);
    }
    int num=0;
    while(a.size()){
    

        while(a.top()!=b.top()){
            if(a.top()>b.top()){
                int x=f(a.top());
                a.pop();
                a.push(x);
                num++;
            }
            else{
                int x=f(b.top());
                b.pop();
                b.push(x);
                num++;
            }
        }
        a.pop();b.pop();
    }

    cout<<num<<endl;
}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}