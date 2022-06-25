#include <bits/stdc++.h>

using namespace std;

struct Tree {
	int sum;
	Tree* left;
	Tree* right;

	Tree() : sum(), left(), right() { }

	void update(int l, int r, int p, int v) {
		if (l + 1 == r) {
			sum = v;
			return;
		}
		int m = (l + r) / 2;
		if (p < m) {
			left = left ? new Tree(*left) : new Tree();
			left->update(l, m, p, v);
		} else {
			right = right ? new Tree(*right) : new Tree();
			right->update(m, r, p, v);
		}
		sum = 0;
		if (left) {
			sum += left->sum;
		}
		if (right) {
			sum += right->sum;
		}
	}

	int query(int l, int r, int from, int to) const {
		if (to <= l || r <= from) {
			return 0;
		}
		if (from <= l && r <= to) {
			return sum;
		}
		int m = (l + r) / 2;
		int res = 0;
		if (left) {
			res += left->query(l, m, from, to);
		}
		if (right) {
			res += right->query(m, r, from, to);
		}
		return res;
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}

	map<int, int> last;
	vector<Tree> trees(n);
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			trees[i] = trees[i - 1];
		}
		Tree& tree = trees[i];
		if (last.count(a[i])) {
			tree.update(0, n, last[a[i]], 0);
		}
		tree.update(0, n, last[a[i]] = i, 1);
	}

	int ans = 0;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l = (l + ans) % n;
		r = (r + ans) % n;
		if (l > r) swap(l, r);
		ans = trees[r].query(0, n, l, n);
		cout << ans << '\n';
	}
	return 0;
}