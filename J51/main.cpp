//
//  main.cpp
//  J51
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

int voraz(vector<int> const& personas,vector<int> const& esquis){
    int suma=0;
    for (int i = 0; i < personas.size(); ++i) suma += abs(personas[i] - esquis[i]);
    return suma;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    
    if (n == 0) return false;
   
    vector<int> personas(n),esquis(n);
    for (int i = 0; i < n; ++i) cin >> personas[i];
    for (int i = 0; i < n; ++i) cin >> esquis[i];
    sort(personas.begin(),personas.end());
    sort(esquis.begin(),esquis.end());
    cout <<voraz(personas,esquis) <<'\n';
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J51/J51/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
