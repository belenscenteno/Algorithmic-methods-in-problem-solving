//
//  main.cpp
//  J53
//
//  Created by Belén Sánchez Centeno on 22/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int voraz(vector<int> pilas,int V){
    int coches = 0, Vactual = 0;
    int i = 0, j = pilas.size() - 1;
    while (j > i){
        Vactual = pilas[i] + pilas[j];
        while (Vactual < V && j > i){
            i++;
            Vactual = pilas[i] + pilas[j];
        }
        if (Vactual >= V && j > i) coches++;
        i++; j--;
    }
    return coches;
}

void resuelveCaso() {
    int n, v;
    cin >> n >>v;
    
    vector<int> pilas(n);
    for (int i = 0; i < n; ++i) cin >> pilas[i];

    sort(pilas.begin(),pilas.end());

    cout <<voraz(pilas,v) <<'\n';

}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J53/J53/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        resuelveCaso();
    }
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
