#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<cstring>
#include<set>
using namespace std;

unordered_map<int,set<int>>kp;
unordered_map<int,multiset<int>>box;


void solve()
{
    int n;cin>>n;
    int q;
    cin>>q;
    while(q--)
    {
        int op,x,y;
        cin>>op>>x;
        if(op==1){
            cin>>y;
            box[y].insert(x);
            kp[x].insert(y);
        }
        else if(op==2){
            for(auto t:box[x]){
                cout<<t<<" ";
            }
            cout<<endl;
        }
        else{
             for(auto t:kp[x]){
                cout<<t<<" ";
            }
            cout<<endl;
        } 
    }
    
}


int main()
{
  //  int t;cin>>t;while(t--)
    solve();
}