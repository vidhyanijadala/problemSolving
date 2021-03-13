// d[i][j] = i��° ����� j�� �������� �ö� �� �ִ밪
// d[i][1] => 1�� �������� �ö����Ƿ� i-2��° ����� �ö󰡰ų� �ǳʶٰų� ��������ϴ�. ���� ���� ��ȭ���� �����ϴ�.
// d[i][1] = max(d[i-2][1], d[i-2][2]) + stair[i] 
// d[i][2] => 2�� �������� �ö����Ƿ� �Ųٷ� �������� �� i-2��° ����� �ö����� �ȵǹǷ�.
// d[i][2] = d[i-1][1] + stair[i] �Դϴ�.
#include <bits/stdc++.h>
using namespace std;
int stair[301];
int d[301][3];
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> stair[i];
    d[1][1] = stair[1];
    for(int i = 2; i <= n; i++){
        d[i][1] = max(d[i-2][1],d[i-2][2]) + stair[i];
        d[i][2] = d[i-1][1] + stair[i];
    }
    cout << max(d[n][1],d[n][2]);
}
