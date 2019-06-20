#include <bits/stdc++.h>

int main( ) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n, tc = 1;
    while (std::cin >> n, n) {
        std::vector<int> previo(n + 1, -1);
        std::vector<int> distancia(n + 1, 1e9);
        std::vector<bool> visitado(n + 1, false);
        std::vector<std::pair<int, int>> adyacencia[n + 1];

        for (int i = 1; i <= n; ++i) {
            int k;
            std::cin >> k;
            for (int j = 0; j < k; ++j) {
                int vecino, costo;
                std::cin >> vecino >> costo;
                adyacencia[i].push_back({ costo, vecino });
            }
        }

        int ini, fin;
        std::cin >> ini >> fin;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> cola;
        cola.push({ 0, ini });
        distancia[ini] = 0;

        do {
            auto actual = cola.top( );
            cola.pop( );

            if (visitado[actual.second]) continue;
            visitado[actual.second] = true;

            for (auto p : adyacencia[actual.second]) {
                int v = p.second, w = p.first + actual.first;
                if (!visitado[v] && (w < distancia[v])) {
                    distancia[v] = w;
                    previo[v] = actual.second;
                    cola.push({ w, v });
                }
            }
        } while (!cola.empty( ));

        int act = fin;
        std::vector<int> camino;
        while (act != -1) {
            camino.push_back(act);
            act = previo[act];
        }
        std::reverse(camino.begin( ), camino.end( ));
        std::cout << "Case " << tc++ << ": Path =";
        for (auto c : camino) {
            std::cout << " " << c;
        }
        std::cout << "; " << distancia[fin] << " second delay\n";
    }
}
