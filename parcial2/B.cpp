

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int N=1e4;


int main(){
    int t;cin>>t;
    int sce=1;
    while(sce<=t){
        vector<vector<int>> g(N);
        vector<int> in_degree(N);
        vector<pii> ranks;
        bool erased[N]={false};

        int N,R;cin>>N>>R;
        for(int i=0;i<R;i++){
            int a,b;cin>>a>>b;
            g[b].push_back(a);
            in_degree[a]++;
        }

        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int i=0;i<N;i++){
            if(!in_degree[i]){
                q.push({i,1});
                erased[i]=true;
            }
        }
        cout<<"Scenario #"<<sce<<":"<<endl;
        while(q.size()){
            int u=q.top().first;
            int r=q.top().second;
            ranks.push_back({r,u});
            q.pop();
            for(int v:g[u]){
                if(erased[v])continue;
                in_degree[v]--;
                if(!in_degree[v]){
                    erased[v]=true;   
                    q.push({v,r+1});
                }
            }
        }

        sort(ranks.begin(),ranks.end());
        for(auto x:ranks){
            cout<<x.first<<" "<<x.second<<endl;
        }
        sce++;
    }


    return 0;
}
