//
//  main.cpp
//  J32
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "Grafo.h"
#include "ConjuntosDisjuntos.h"

// propios o los de las estructuras de datos de clase
#include <stack>

using namespace std;

//void dfsR(Grafo g,int v,vector<bool> &mark, int &sol,int const count,vector<int> &id){
//    mark[v]=true;
//    id[v]=count;
//    sol++;
//
//    for(int w:g.ady(v)){
//
//        if(!mark[w]){
//            dfsR(g, w, mark,sol,count,id);
//        }
//    }
//}
            
            
// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int u, gr, n,x,y;
    
    std::cin >> u >> gr;
    if (!cin) return false;
    
    ConjuntosDisjuntos c(u);
    
    for(int i=0;i<gr;++i){
        cin>>n;
        if(n>0){
            cin>>x;
            x-=1;
            for(int j=0;j<n-1;++j){
                cin>>y;
                y-=1;
                c.unir(x, y);
                x=y;
            }
        }
    }
    
    for(int i=0;i<u;++i){
        cout<<c.tam(i)<<' ';
    }
    cout<<'\n';
    return true;
    
//    Grafo g(u);
//
//    for(int i=0;i<gr;++i){
//        cin>>n;
//        if(n>0){
//            cin>>x;
//            x-=1;
//            for(int j=0;j<n-1;++j){
//                cin>>y;
//                y-=1;
//                g.ponArista(x, y);
//                x=y;
//            }
//        }
//    }
//
//    vector<int> comp;
//    vector<int> id(g.V());
//
//    int count=0;
//
//    vector<bool> mark(g.V(),false);
//
//    for(int i=0;i<g.V();++i){
//        int sol=0;
//        if (!mark[i]) {
//            dfsR(g, i, mark, sol,count,id);
//            ++count;
//            comp.push_back(sol);
//        }
//
//        else sol=comp[id[i]];
//        cout<<sol<<' ';
//    }
//    cout<<'\n';
//    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J32/J32/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
