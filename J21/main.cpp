//
//  main.cpp
//  J21
//
//  Created by Belén Sánchez Centeno on 26/10/2019.
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
// periodo actual, id, periodo original
void resolver(PriorityQueue<pair<pair<int,int>,int>> ucm, int k) {
    for(int j=1;j<=k;++j){
        int po =ucm.top().second;
        int p =ucm.top().first.first;
        int id =ucm.top().first.second;
              
        cout<<id<<'\n';
        ucm.push({{p+po,id},po});
        ucm.pop();
        }
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, id, p, k;
    std::cin >> n;
    if (n == 0) return false;
    
    PriorityQueue<pair<pair<int,int>,int>> m;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> id >> p;
        m.push({{p,id},p});
    }
    cin>>k;
    
    resolver(m,k);
    
    cout<<"---\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J21/J21/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
