#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    // ��ü ������ �Դ� �ð����� k�� ũ�ų� ���ٸ� -1
    long long summary = 0;
    for (int i = 0; i < food_times.size(); i++) {
        summary += food_times[i];
    }
    if (summary <= k) return -1;
    
    // �ð��� ���� ���ĺ��� ���� �ϹǷ� �켱���� ť�� �̿�
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < food_times.size(); i++) {
        // (���� �ð�, ���� ��ȣ) ���·� �켱���� ť�� ����
        pq.push({-food_times[i], i + 1});
    }
    
    summary = 0; // �Ա� ���� ����� �ð�
    long long previous = 0; // ������ �� ���� ���� �ð�
    long long length = food_times.size(); // ���� ������ ����

    // summary + (������ ���� �ð� - ���� ���� �ð�) * ���� ���� ������ k ��
    while (summary + ((-pq.top().first - previous) * length) <= k) {
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length -= 1; // �� ���� ���� ����
        previous = now; // ���� ���� �ð� �缳��
    }

    // ���� ���� �߿��� �� ��° �������� Ȯ���Ͽ� ���
    vector<pair<int, int> > result;
    while (!pq.empty()) {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({food_time, num});
    }
    sort(result.begin(), result.end(), compare); // ������ ��ȣ �������� ����
    return result[(k - summary) % length].second;
}