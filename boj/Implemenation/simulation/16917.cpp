#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,y,ans;
int arr[2];
int main(){
    //a : ���, b : �ĸ��̵�, c : �ݹ�
    cin >> a >> b >> c >> x >> y;
    int c1 = a * x + b * y; //����
    int c2 = max(x,y)*2*c; //�ݹݸ�
    int c3 = min(x,y) *2 * c; //�ݹݸ����� �� ����
    int m = min(x,y);
    x-=m;
    y-=m;
    c3 += a * x + b * y;
    cout << min({c1,c2,c3}) <<'\n';
}