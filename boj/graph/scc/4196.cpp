#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int n,m,t;
int scc[MAX];
int indegree[MAX];
bool ck[MAX];

vector <int> graph[MAX];
vector <int> revGraph[MAX];
vector <int> sccStat[MAX];

stack <int> st;

//dfs �����ϸ� //������ �������ϸ鼭 ���� ����
void dfs(int cur){
    ck[cur] = true;
    for(auto &g : graph[cur]){
        int next = g;
        if(ck[next]) continue;
        dfs(next);
    }
    st.push(cur); 
}

void updateSCC(int cur, int idx){
    scc[cur] = idx; //���� scc��ȣ ����

    for(auto &rg : revGraph[cur]){
        int next = rg;
        if(scc[next] == 0) updateSCC(next,idx); //���� �� next�� �ش��ϴ� scc���� ���ٸ� ���� SCC ��ȣ�� ���ϰ�����
        else if(scc[next] != scc[cur]) { //���� �ٸ� ����̶��
            indegree[scc[cur]]++;
            //SCC������ ���� ���� ���� 
            //*������*  revGraph�� ������ �׷����̹Ƿ�
            //            SCC������ ������¸� ������ �� ����SCC -> �ٸ� SCC�� ������¸� �����ϸ� �ȵǰ�
            //            ���� ������¸� �����ؼ� �ٸ� SCC -> ���� SCC �� ������¸� ����������Ѵ�.
            sccStat[scc[next]].push_back(scc[cur]);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            revGraph[v].push_back(u); //������ �׷���
        }

        for(int i = 1; i <= n; i++){
            if(ck[i]) continue;
            dfs(i);
        }

        int idx = 1;
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            if(scc[cur]) continue; //�̹� SCC�� ���� ����̶�� pass
            scc[cur] = idx; //������ �ʾҴٸ�  �ش� ��Ͽ� scc ��ȣ ����
            updateSCC(cur,idx); //���� ������ ���� scc update
            idx++; //���� scc��ȣ�� ���� ����
        }

        int result = 0;
        for(int i  = 1; i < idx; i++) if(!indegree[i]) result++; //���������� 0�� ������ �հ������� �о�����Ѵ�.
        cout << result << '\n';

        //�ʱ�ȭ
        for(int i = 1; i <= n; i++){
            scc[i] = 0;
            indegree[i] = 0;
            ck[i] = false;
            graph[i].clear();
            revGraph[i].clear();
            sccStat[i].clear();
        }
    }
}