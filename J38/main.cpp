//
//  main.cpp
//  J38
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;

void relax(AristaDirigida<int> &ad, vector<int> &dist, vector<AristaDirigida<int>> &aristaA, IndexPQ<int> &pq){
    int v=ad.from();
    int w=ad.to();
    if(dist[w]==-1 || dist[w]>dist[v] + ad.valor()){
        dist[w]=dist[v] + ad.valor();
        aristaA[w]=ad;
        pq.update(w, dist[w]);
    }
}

int dijkstra(GrafoDirigidoValorado<int> &gv, int salida, int t) {
    int sol=0;
    vector<int> dist(gv.V(),-1);
    vector<AristaDirigida<int>> aristaA(gv.V());
    IndexPQ<int> pq(gv.V());
    
    dist[salida]=0;
    pq.push(salida,0);
    
    while(!pq.empty()){
        int v=pq.top().elem;
        pq.pop();
        for(AristaDirigida<int> ad : gv.ady(v)){
            relax(ad,dist,aristaA,pq);
        }
    }
    for (int i =0;i<dist.size();++i){
        if(i!=salida && dist[i]<=t && dist[i]!=-1) sol++;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, salida, tiempo, p, a, b, t;
    
    std::cin >> n >> salida >> tiempo >> p;
    if (!cin) return false;
    salida-=1;
    
    GrafoDirigidoValorado<int> gv(n);
    
    for(int i=0;i<p;++i){
        cin>>a>>b>>t;
        AristaDirigida<int> ad(b-1,a-1,t);
        gv.ponArista(ad);
    }
//    int sol=0;
//    for(int i=0;i<gv.V();++i){
//        int x=dijkstra(gv,i,salida);
//        if (i!=salida && x<=tiempo && x!=-1) ++sol;
//    }
    int sol=dijkstra(gv,salida,tiempo);

    
    cout << sol << '\n';

    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J38/J38/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
