//
//  main.cpp
//  J24
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
    int d, a, b, horas;
    
    std::cin >> d >> a >> b;
    if (!cin) return false;
    
    //tiempo ocupada, numero de caja
    PriorityQueue<int,greater<int>> pilasA, pilasB;
    
    for(int i=0;i<a;++i){
        cin>>horas;
        pilasA.push(horas);
    }
    for(int i=0;i<b;++i){
        cin>>horas;
        pilasB.push(horas);
    }
    
    while (!pilasA.empty() && !pilasB.empty()){
        int sol=0;
        vector<int> auxA;
        vector<int> auxB;
        for (int i=0;i<d && !pilasA.empty() && !pilasB.empty();++i){
            int pilaA=pilasA.top();
            int pilaB=pilasB.top();
            pilasA.pop();
            pilasB.pop();
            
            if(pilaA==pilaB) {
                sol+=pilaA;
            }
            else if (pilaA>pilaB){
                auxA.push_back(pilaA-pilaB);
                sol+=pilaB;
            }
            else {
                auxB.push_back(pilaB-pilaA);
                sol+=pilaA;
            }
        }
        cout<<sol<<' ';
        for(int x:auxA){
            pilasA.push(x);
        }
        for(int x:auxB){
            pilasB.push(x);
        }
    }
    
    cout<<"\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J24/J24/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
