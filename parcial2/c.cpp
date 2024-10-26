#include <bits/stdc++.h>


using namespace std;

typedef pair<int,int> pii;

const int N = 1e6;
vector<pii> g[N];

bool erased[N];

vector<int> path;

void dfs(int u){
    while(!g[u].empty()){
        auto x = g[u].back();
        int id=x.second;
        int v=x.first;
        if(!erased[id]){
            erased[id]=true;
            g[u].pop_back();
            dfs(v);
        }else{
            g[u].pop_back();
        }
    }
    path.push_back(u);
    
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    
    //validacion de grados, se que hay un ciclo euleriano
    int odd=0;
    for(int i=1;i<=n;i++){
        if(g[i].size()%2==1)odd++;
    }
    if(odd!=0){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    dfs(1);
    if(path.size()!=m+1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    reverse(path.begin(),path.end());
    
    for(int x:path)cout<<x<<" ";
    
    return 0;
}