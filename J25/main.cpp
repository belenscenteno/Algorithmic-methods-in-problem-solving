//
//  main.cpp
//  J25
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
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
    int primero,n,x,y;
    
    std::cin >> primero >> n;
    if (primero==0 && n==0) return false;
    
    PriorityQueue<int,greater<int>> izq;
    PriorityQueue<int> der;
    
    for(int i=0;i<n;++i){
        cin>>x>>y;
        if(x<primero && y>primero){
            izq.push(x);
            der.push(y);
        }
        else if(x>primero && y<primero){
            izq.push(y);
            der.push(x);
        }
        else if(x<primero && y<primero){
            izq.push(x);
            izq.push(y);
            der.push(primero);
            primero=izq.top();
            izq.pop();
        }
        else if(x>primero && y>primero){
            der.push(x);
            der.push(y);
            izq.push(primero);
            primero=der.top();
            der.pop();
        }
        cout<<primero<<' ';
    }
    cout<<"\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J25/J25/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
