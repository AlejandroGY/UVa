#include <bits/stdc++.h>

std::array<int, 3> bin[3];
std::string cad = "BGC";
int permutaciones[6][3] = {
	{ 0, 1, 2 }, { 0, 2, 1 },
	{ 1, 0, 2 }, { 1, 2, 0 },
	{ 2, 0, 1 }, { 2, 1, 0 }
};

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	while (std::cin >> bin[0][0] >> bin[0][1] >> bin[0][2] >> bin[1][0] >> bin[1][1] >> bin[1][2] >> bin[2][0] >> bin[2][1] >> bin[2][2]) {
		int costo = INT_MAX;
		std::string sol = "   ";
		for (int i = 0; i < 6; ++i) {
			int temp = 0;
			std::string sol_temp = "   ";
			for (int j = 0; j < 3; ++j) {
				int idx = permutaciones[i][j];
				sol_temp[j] = cad[idx];
				for (int k = 0; k < 3; ++k) {
					if (j != k) {
						temp += bin[k][idx];
					}
				}
			}
			if (temp < costo) {
				costo = temp;
				for (int t = 0; t < 3; ++t) {
					sol[t] = cad[permutaciones[i][t]];
				}
			} else if (temp == costo) {
				sol = std::min(sol, sol_temp);
			}
		}
		std::cout << sol << " " << costo << "\n";
	}
}
