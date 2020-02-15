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
	cout << N << "까지 필요한 박수 수는 " << cnt << " 입니다.\n\n";
	return;
}

int main() {
	while (true) {
		cout << "숫자를 입력하하세요 : ";
		cin >> N;
		if (N == 0) {
			cout << "종료";
			return false;
		}
		solve();
	}
	return 0;
}