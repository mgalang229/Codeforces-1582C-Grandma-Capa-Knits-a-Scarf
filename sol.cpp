#include <bits/stdc++.h>
using namespace std;

bool is_present(char letter, string s) {
	for (int i = 0; i < (int) s.size(); i++) {
		if (letter == s[i]) {
			return true;
		}
	}
	return false;
}

void test_cases() {
	int n;
	string s;
	cin >> n >> s;
	int mn = 1e5 + 1;
	for (int i = 0; i < 26; i++) {
		char letter = 'a' + i;
		if (is_present(letter, s)) {
			int cnt = 0;
			int from = 0, to = n - 1;
			bool valid = true;
			while (from <= to) {
				if (s[from] == s[to]) {
					from++;
					to--;
				} else {
					if (s[from] == letter) {
						from++;
						cnt++;
					} else if (s[to] == letter) {
						to--;
						cnt++;
					} else {
						valid = false;
						break;
					}
				}
			}
			if (valid) {
				mn = min(mn, cnt);
			}
		}
	}
	cout << (mn != (1e5 + 1) ? mn : -1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_cases();
	}
}
