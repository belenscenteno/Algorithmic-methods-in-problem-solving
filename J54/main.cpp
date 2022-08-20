//
//  main.cpp
//  J54
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

struct hotel{
    int inicio,fin;
};

bool ordenar(hotel const& h1, hotel const& h2) {
    return h1.fin < h2.fin||(h1.fin == h2.fin && h1.inicio < h2.inicio);
}

int tuneles(vector<hotel> hoteles){
    int tuneles = 0, inicio = 0, fin = 0;
    
    int i=0;
    while (i < hoteles.size()){
        inicio = hoteles[i].inicio;
        fin = hoteles[i].fin;
        ++i;
        while (hoteles[i].inicio < fin && i < hoteles.size()){
            if (inicio < hoteles[i].inicio) inicio = hoteles[i].inicio;
            if (fin > hoteles[i].fin) fin = hoteles[i].fin;
            ++i;
        }
        tuneles++;
    }
    
    return tuneles;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    
    if (n == 0) return false;
    
    vector<hotel> hoteles(n);
    for (int i = 0; i < n; ++i) std::cin >> hoteles[i].inicio >> hoteles[i].fin;
    sort(hoteles.begin(),hoteles.end(),ordenar);
    
    cout << tuneles(hoteles) << '\n';
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J54/J54/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
