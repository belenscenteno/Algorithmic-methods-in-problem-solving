//
//  main.cpp
//  J11
//
//  Created by Belén Sánchez Centeno on 26/10/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h" // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// <es avl, <altura, <min,max>>>
pair<bool, pair<int, pair<int,int>>> avl(bintree<int> arbol) {
    if (arbol.empty()){
        return {true,{0,{0,0}}};
    }
    
    auto left = avl(arbol.left());
    auto right = avl(arbol.right());
    
    bool busqueda= true;
    if (!arbol.left().empty())
        busqueda=(arbol.root() > left.second.second.second);
    if(busqueda && !arbol.right().empty())
        busqueda=(arbol.root() < right.second.second.first);
    
    int Min,Max;
    if (arbol.left().empty()) Min=arbol.root();
    else Min=min(arbol.root(),left.second.second.first);
    if (arbol.right().empty()) Max =arbol.root();
    else Max=max(arbol.root(),right.second.second.second);
    
    return{busqueda && left.first && right.first && (abs(left.second.first-right.second.first) <= 1), {max(left.second.first, right.second.first) + 1, {Min,Max}}};
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol;
    arbol = leerArbol(-1);
    auto sol = avl(arbol);
    if (sol.first) cout << "SI" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J11/J11/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
