
// Belen Sanchez

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

#include "TreeMap_AVL2.h"

vector<int> rango(map<int,int> arbol, int p, int u) {
    vector<int> v;
    if (arbol.empty()) return v;
    if (arbol.begin()->clave > p) {
        auto w=rango(arbol., p,u);
        v.insert(v.end(),w.begin(),w.end());
        raiz=aux;
    }
    if (p<= raiz->cv.clave && u>= raiz->cv.clave)
        v.push_back(raiz->cv.clave);
    if (raiz->cv.clave < u) {
        auto aux=raiz;
        raiz=raiz->dr;
        auto w=rango(p,u);
        v.insert(v.end(),w.begin(),w.end());
        raiz=aux;
    }
    return v;
}

bool resuelveCaso() {
    int n,x,prim,ult;
    cin>>n;
    if (n==0) return false;
    map<int,int> arbol;
    for (int i=0; i<n; ++i) {
        cin>>x;
        arbol.insert(x);
    }
    cin>>prim>>ult;
    
    vector<int> v = arbol.rango(prim,ult);
    
    for(int i=0;i<v.size();++i) cout<<v[i]<<' ';
    cout<<'\n';
    
    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J12/J12/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
