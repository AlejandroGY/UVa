#include <iostream>
#include <vector>

constexpr int MAX = 200000;

class fenwick_tree {
public:
	fenwick_tree(int n)
	: mem_(n + 1) {
	}

	void actualiza(int i, int v) {
		for (++i; i < mem_.size( ); i += (i & -i)) {
			mem_[i] += v;
		}
	}

	int cuenta(int i) {
		int res = 0;
		for (i += 1; i != 0; i -= (i & -i)) {
			res += mem_[i];
		}
		return res;
	}

private:
	std::vector<int> mem_;
};

int main( ) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, tc = 1;
	while (std::cin >> n, n) {
		fenwick_tree arbol(n + 1);
		std::vector<int> v(n + 1);
		for (int i = 1; i <= n; ++i) {
			int t;
			std::cin >> t;
			
			v[i] = t;
			arbol.actualiza(i, t);
		}
		
		if (tc > 1) {
			std::cout << "\n";
		}
		std::cout << "Case " << tc++ << ":\n";

		std::string op;
		std::cin >> op;
		while (op != "END") {
			if (op == "M") {
				int ini, fin;
				std::cin >> ini >> fin;
				std::cout << arbol.cuenta(fin) - arbol.cuenta(ini - 1) << "\n";
			} else {
				int s, t;
				std::cin >> s >> t;

				arbol.actualiza(s, t - v[s]);
				v[s] = t;
			}
			std::cin >> op;
		}
	}
}