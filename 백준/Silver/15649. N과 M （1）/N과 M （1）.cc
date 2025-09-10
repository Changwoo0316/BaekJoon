#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> selected;
vector<bool> used;


void backtrack(int depth) {
	//탈출 조건
	if (depth == M) {
		for (int num : selected) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (used[i]) continue;
		used[i] = true;
		selected.push_back(i);
		backtrack(depth + 1);
		selected.pop_back();
		used[i] = false;
	}

}

int main() {
	cin >> N >> M;
	used.resize(N + 1);
	backtrack(0);
}