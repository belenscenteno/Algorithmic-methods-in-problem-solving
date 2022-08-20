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

bool dfsR(Grafo g,int v,vector<bool> &markG,vector<bool> &marknoG,int &cG, int &cnoG,bool c){
    bool sol=true;
    
    if (c) {
        markG[v]=true;
        cG++;
    }
    else {
        marknoG[v]=true;
        cnoG++;
    }
    
    if(markG[v] && marknoG[v]) return false;
    
    for(int w:g.ady(v)){
        
        if((markG[v] && !marknoG[w]) || (marknoG[v] && !markG[w]))
            if (!dfsR(g, w, markG, marknoG, cG, cnoG, !c)) sol=false;
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
        g.ponArista(e1-1,e2-1);
    }
    
    vector<bool> markG(g.V(),false);
    vector<bool> marknoG(g.V(),false);
    
    
    int countSol=0;
    bool sol=true;

    for(int i=0;i<g.V()&&sol;++i){
        if(!markG[i] && !marknoG[i]){
            int countG=0;
            int countnoG=0;
            if(!dfsR(g, i, markG, marknoG,countG,countnoG, true)) sol=false;
            else countSol+=min(countG,countnoG);
        }
    }
    
    if(sol) cout<<countSol<<"\n";
    else cout<<"IMPOSIBLE\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J31/J31/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
