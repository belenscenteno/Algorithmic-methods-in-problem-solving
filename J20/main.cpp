//
//  main.cpp
//  J20
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
long long int resolver(PriorityQueue<long long int> m) {
    long long int sol=0;
    while(!m.empty() && m.size()>1) {
        long long int sum= m.top();
        m.pop();
        sum=sum+m.top();
        m.pop();
        if(!m.empty()) m.push(sum);
        sol=sol+sum;
    }
        
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numS;
    std::cin >> numS;
    if (numS == 0) return false;
    
    PriorityQueue<long long int> m;
    
    long long int n;
    for (int i = 0; i < numS; ++i) {
        std::cin >> n;
        m.push(n);
    }
    
    long long int sol = resolver(m);
    cout<<sol<<'\n';
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J20/J20/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
