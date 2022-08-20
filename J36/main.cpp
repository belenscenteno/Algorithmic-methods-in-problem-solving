//
//  main.cpp
//  J36
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
#include "PriorityQueue.h"

using namespace std;

void visitar (GrafoValorado<int> &g, PriorityQueue<Arista<int>> &aristas, vector<bool> &marcados, int v){
    marcados[v]=true;
    for (Arista<int> a : g.ady(v))
        if (!marcados[a.otro(v)]) aristas.push(a);
}

int lazyprim(GrafoValorado<int> &g, PriorityQueue<Arista<int>> &aristas, vector<bool> &marcados){
    int sol=0;
    int count =0;
    visitar(g, aristas, marcados, 0);
    for(int i=0;i<g.V()&&!aristas.empty();++i){
        Arista<int> a=aristas.top();
        aristas.pop();
        int v=a.uno();
        int w=a.otro(v);
        if (!marcados[v] || !marcados[w]){
            sol+=a.valor();
            if (!marcados[v]) {
                visitar(g,aristas,marcados,v);
                ++count;
            }
            if (!marcados[w]){
                visitar(g,aristas,marcados,w);
                ++count;
            }
        }
    }
    if (count==g.V() - 1) return sol;
    else return -1;
}

int kruskal(GrafoValorado<int> &g, PriorityQueue<Arista<int>> &aristas) {
    ConjuntosDisjuntos cd(g.V());
    int sol=0;
    int count =0;
    while(count<g.V() && !aristas.empty()){
        Arista<int> a=aristas.top();
        aristas.pop();
        if(!cd.unidos(a.uno(), a.otro(a.uno()))){
            cd.unir(a.uno(), a.otro(a.uno()));
            sol+=a.valor();
            ++count;
        }
    }
    if (count==g.V() - 1) return sol;
    else return -1;
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int i, p, x, y, coste;
    
    std::cin >> i >> p;
    if (!cin) return false;
    
    GrafoValorado<int> gv(i);
    PriorityQueue<Arista<int>> aristas;
    vector<bool> marcados(gv.V(),false);
    for(int i=0;i<p;++i){
        cin>>x>>y>>coste;
        Arista<int> a(x-1,y-1,coste);
        aristas.push(a);
        gv.ponArista(a);
    }
    
    int sol=kruskal(gv, aristas);
//    int sol=lazyprim(gv, aristas, marcados);
    
    if (sol != -1) cout << sol << '\n';
    else cout << "No hay puentes suficientes" << '\n';
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J36/J36/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
