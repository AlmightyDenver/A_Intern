#include <iostream>
#include <string>

using namespace std;
int N;

void solve() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '3' || str[j] == '6' || str[j] == '9') {
				cnt++;
				//cout << str << ' ';
			}
		}

	}
	cout << N << "���� �ʿ��� �ڼ� ���� " << cnt << " �Դϴ�.\n\n";
	return;
}

int main() {
	while (true) {
		cout << "���ڸ� �Է����ϼ��� : ";
		cin >> N;
		if (N == 0) {
			cout << "����";
			return false;
		}
		solve();
	}
	return 0;
}