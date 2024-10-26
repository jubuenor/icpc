#include <bits/stdc++.h>

using namespace std;

const int N=1e6;
bool bfs(int n, int str, vector<vector<int>> &g, vector<int> &dist){
    if(dist[n]!=-1)return false;
    queue<int> q;
    q.push(n);
    dist[n]=0;

    while(q.size()){
        int u=q.front();
        cout<<u<<endl;
        q.pop();
        if(dist[u]==str)continue;
        for(int v:g[u]){
            cout<<"desde "<<u<<" veo " <<v<<endl;
            if(dist[v]==-1){
                q.push(v);
                dist[v]=dist[u]+1;
            }
        }
    }
    return true;
}
int main(){
    int t;cin>>t;

    while(t--){
        vector<vector<int>> g(N);
        vector<pair<int,int>> str;

        vector<int> dist(N,-1);

        int N,R,M;cin>>N>>R>>M;
        for(int i=0;i<R;i++){
            int a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0;i<M;i++){
            int k,s;cin>>k>>s;
            str.push_back({k,s});
        }
        bool flag;
        for(auto x:str){
            if(bfs(x.first,x.second,g,dist)){

                flag=true;
            }else{
                flag=false;
                break;
            }
        }
        for(int i=1;i<=N;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }

        for(int i=1;i<=N;i++){
            if(dist[i]==-1){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"Yes"<<endl;else cout<<"No"<<endl;
    }

    return 0;
}
