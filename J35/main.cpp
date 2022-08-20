//
//  main.cpp
//  J35
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

//bool resolver(GrafoValorado<int> g, int v, int const& anchura, int const& fin, vector<bool> &marked) {
//    marked[v]=true;
//    for(Arista<int> e : g.ady(v)){
//        if (e.otro(v) == fin && e.valor()>=anchura) return true;
//    }
//    for(Arista<int> e : g.ady(v)){
////        cout << e.otro(v) <<'\n';
//        if(!marked[e.otro(v)] && e.valor()>=anchura){
//            if (resolver(g, e.otro(v), anchura, fin, marked)) return true;
//        }
//    }
//    return false;
//}

void resolver(GrafoValorado<int> &g, vector<Arista<int>> &aristas, ConjuntosDisjuntos &cd, int anchura) {
    for(Arista<int> a : aristas){
        if(a.valor()>=anchura && !cd.unidos(a.uno(), a.otro(a.uno())))
            cd.unir(a.uno(), a.otro(a.uno()));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int v, e, p, q, n;
    
    std::cin >> v >> e;
    if (!cin) return false;
    
    GrafoValorado<int> gv(v);
    vector<Arista<int>> aristas;
    for(int i=0;i<e;++i){
        cin>>p>>q>>n;
        Arista<int> a(p-1,q-1,n);
        aristas.push_back(a);
        gv.ponArista(a);
    }
    
    int k, ini, fin, anchura;
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>ini>>fin>>anchura;
//        vector<bool> marked(gv.V(), false);
//        bool sol =resolver(gv, ini-1, anchura, fin-1, marked);
        
        ConjuntosDisjuntos cd(gv.V());
        resolver(gv, aristas, cd, anchura);
        if (cd.unidos(ini-1, fin-1)) cout << "SI" <<'\n';
        else cout << "NO" <<'\n';
    }
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J35/J35/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
