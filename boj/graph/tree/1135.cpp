#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, maxDepth;
vector <vector<pii>> graph;
//graph[a][b] : a�� �θ��, b�� �ڽ����� ���� �� {�ִ񰪰�,�ڽĳ��}�� ����

int dfs(int cur){
    int ret = 0;
    for(auto &next : graph[cur]){
        next.first = 1 + dfs(next.second);
    }
    sort(graph[cur].rbegin(), graph[cur].rend());

    //������ ���ϴ� ������ ���� �ɸ��� �ð��� �޶�����.
    for(int i = 0; i < graph[cur].size(); i++){
        ret = max(ret, graph[cur][i].first + i);
    }
    
    return ret;
}
int main(){
    int node;
    cin >> n >> node;
    graph = vector<vector<pii>>(n);

    for(int i = 1; i < n; i++){
        cin >> node;
        graph[node].push_back({0,i});
    }
    cout << dfs(0);
}