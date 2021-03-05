#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int len, wid, hei;
    cin >> len >> wid >> hei;
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i=0 ; i<n ; i++) {
        int a,b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }

    long long ans=0;
    long long before=0;
    for(int i= 20; i>= 0 ; i--) {
        before <<= 3; // before�� ������ 2^3��ŭ �÷��ش�.
        long long pc = (long long) (len >> i) * (wid >> i) * (hei >> i) - before;
        // �ڽ��� 2^i x 2^i x 2^i��ŭ ������ �ְ�, ���� �ڽ��� ä���� ť���� ����(before)��ŭ �� �ش�.
        // ex) 4 x 4 x 8�̱⶧���� 4 x 4 x 4�� �����ϸ� 1 x 1 x 2 = 2���� ��
        long long nc;
        if(i <= n - 1) nc = min((long long) arr[i].second, pc);
        else continue;
        before += nc;
        ans += nc;
    }
    
    if(before == (long long) len * wid * hei) cout << ans;
    else cout << -1;
}