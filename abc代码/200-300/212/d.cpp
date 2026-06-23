#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


int main()
{
     priority_queue<long long,vector<long long>,greater<long long>>heap;
     long long n;
     cin>>n;
     long long bh=0;
     while(n--)
     {
        long long a;
        long long b;
        cin>>a;
        if(a==1)
        {
            cin>>b;
            heap.push(b-bh);
        }
        else if(a==2){
            cin>>b;
            bh+=b;
        }
        else{
            cout<<heap.top()+bh<<endl;
            heap.pop();
        }
     }

     return 0;

}