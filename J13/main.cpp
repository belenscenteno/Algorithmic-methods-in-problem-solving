
// J13
// Belen Sanchez

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

#include "TreeMap_AVL3.h"

//Para mantener en cada nodo un nuevo atributo tam_i que almacene el numero de nodos en el hijo izquierdo mas uno
//he modificado los métodos en TreeMap_AVL : rotaDer, rotaIzq e inserta.

bool resuelveCaso() {
    int n,m,x;
    cin>>n;
    if (n==0) return false;
    map<int,int> arbol;
    for (int i=0; i<n; ++i) {
        cin>>x;
        arbol.insert(x);
    }
    cin>>m;
    for (int i=0; i<m; ++i) {
        cin>>x;
        int sol = arbol.findK(x);
        if (sol==0) cout<<"??";
        else cout<<sol;
        cout<<'\n';
    }
     cout<<"---"<<'\n';
    
    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J13/J13/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
