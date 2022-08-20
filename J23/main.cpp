//
//  main.cpp
//  J23
//
//  Created by Belén Sánchez Centeno on 26/11/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "PriorityQueue.h" // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, c, t;
    
    std::cin >> n >> c;
    if (n == 0 and c == 0) return false;
    
    //tiempo ocupada, numero de caja
    PriorityQueue<pair<int,int>> m;
    
    for(int i=1;i<=n;++i){
        m.push({0,i});
    }
    
    for (int i = 0; i < c; ++i) {
        std::cin >> t;
        auto turno = m.top();
        m.pop();
        m.push({turno.first+t,turno.second});
    }
    auto turno = m.top();
    cout<<turno.second<<"\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J23/J23/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
