//
//  main.cpp
//  J31
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int voraz(vector<int> const& s, int l){
    int acumula = 0, parches = 1;
    for (int i = 0; i < s.size() - 1; ++i){
        if (acumula + (s[i + 1] - s[i]) <= l) acumula += s[i + 1] - s[i];
        else {
            acumula = 0;
            parches++;
        }
    }
    return parches;
}
            
// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, l, x;
    
    std::cin >> n >> l;
    if (!cin) return false;
   
    vector<int> s(n);
    for(int i=0;i<n;++i){
        cin>>x;
        s[i]=x;
    }
    
    cout << voraz(s,l) << '\n';
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J50/J50/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
