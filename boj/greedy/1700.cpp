#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int schedule[101], multiTap[101];

int main(void){
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> schedule[i];
    for (int i = 0; i < k; i++){
        bool isPlugged = false; //�ش� ��Ⱑ �����ִ��� Ȯ��

        //���������� continue;
        for (int j = 0; j < n; j++){
            if (multiTap[j] == schedule[i]){ 
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;
        
        //�������� �ʴٸ� �� ���ۿ� �ȱ�
        for (int j = 0; j < n; j++){
            if (!multiTap[j]){
                multiTap[j] = schedule[i];
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;

        //���� ���߿� �ٽ� ���ǰų� ������ ������ �ʴ� ��� ã�´�.
        int idx, deviceIdx = -1;

        for (int j = 0; j < n; j++){
            int lastUsedIdx= 0;
            int next = i + 1;
            //������ ������ �ʴ� ���� lastUsedIdx�� ���� ũ�� �ǹǷ� ���� ���� ������ ��.
            //������ ���Ǵ� ���� �� ���� ���߿� ���̴� ����� lastUsedIdx�� ã�Ե�.
            while(next < k && multiTap[j] != schedule[next]){
                lastUsedIdx++;
                next++;
            }
            
            if (lastUsedIdx > deviceIdx){
                idx = j;
                deviceIdx = lastUsedIdx;
            }
        }

        ans++;
        //���� ���߿� ���̴� ���� ���ְ� ���� ��Ƽ�� ����
        multiTap[idx] = schedule[i];

    }
    cout << ans << "\n";
}


