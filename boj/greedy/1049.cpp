#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;
int n,m,case1,case2,case3;
int packageMin = INF, eachMin = INF;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int six,one;
        cin >> six >> one;
        packageMin = min(six,packageMin);
        eachMin = min(one, eachMin);
    }
    //n�� �̻����� ���� ��Ű�� �� ��
    if(n % 6 == 0) case1 = n / 6 * packageMin;
    else case1 = (n / 6 + 1) * packageMin;
    
    //2. n�� �̻� ���� 1���� �� ��
    case2 = eachMin * n;

    //3. n�� �̸����� �ִ��� 6���� �� �� �������� 1���� �� ��
    case3 = n / 6 * packageMin + n % 6 * eachMin;
    cout << min({case1,case2,case3});
}