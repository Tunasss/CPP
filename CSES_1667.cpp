#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<vector<int>> graph;
vector<bool> isvisted;
vector<pair<int,int>> path;

void DFS(int v){
    if (isvisted[v] == true) return;

    isvisted[v] = true;
    for (auto u: graph[v]) if (!isvisted[u]){
        if (path[v].second + 1 < path[u].second){
            path[u].second = path[v].second+1;
            path[u].first = v;
        }
        DFS(u);
    }
//    isvisted[v] = false;
}

void BFS(int v){
    queue<int> myque;
    myque.push(v);
    while (!myque.empty()){
        int v = myque.front();
        myque.pop();
        isvisted[v] = true;
        for (auto u: graph[v]) if (!isvisted[u]){
            if (path[v].second + 1 < path[u].second){
                path[u].second = path[v].second+1;
                path[u].first = v;
            }
            myque.push(u);
        }
    }
}

int main(){
    cin >> m >> n;
    graph.resize(m+1);
    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    path.assign(m+1, {0,INT8_MAX});
    isvisted.assign(m + 1, false);
    path[1] = {0,1};
    //DFS(1);
    BFS(1);
    if (path[m].second == INT8_MAX) cout << "IMPOSSIBLE";
    else{
        stack<int> out;
        cout << path[m].second << endl;
        while(m != 0){
            out.push(m);
            m = path[m].first;
        }
        while(!out.empty()){
            cout << out.top() << " ";
            out.pop();
        }
    }
    return 0;
}
