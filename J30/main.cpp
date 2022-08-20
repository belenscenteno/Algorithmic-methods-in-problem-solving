//
//  main.cpp
//  J31
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "Grafo.h" // propios o los de las estructuras de datos de clase
#include <stack>

using namespace std;

bool dfsR(Grafo g,int v,vector<bool> &mark1,vector<bool> &mark2,bool c){
    bool sol=true;
    
    if (c) mark1[v]=true;
    else mark2[v]=true;
    
    if(mark1[v] && mark2[v]) return false;
    
    for(int w:g.ady(v)){
        
        if((mark1[v] && !mark2[w]) || (mark2[v] && !mark1[w]))
            if (!dfsR(g, w, mark1, mark2, !c)) sol=false;
    }
    
    return sol;
}
            
            
// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int v, a, e1, e2;
    
    std::cin >> v >> a;
    if (!cin) return false;
    
    Grafo g(v);
    
    for(int i=0;i<a;++i){
        cin>>e1>>e2;
        g.ponArista(e1,e2);
    }
    
    vector<bool> mark1(g.V(),false);
    vector<bool> mark2(g.V(),false);
    bool sol=true;
    for(int i=0;i<g.V();++i){
        if(!mark1[i] && !mark2[i]){
            if(!dfsR(g, i, mark1, mark2, true)) sol=false;
        }
    }
    
    if(sol) cout<<"SI\n";
    else cout<<"NO\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J30/J30/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
