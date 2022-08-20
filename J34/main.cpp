//
//  main.cpp
//  J34
//
//  Created by Belén Sánchez Centeno on 02/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

static vector<int> rowNbr = {-1, -1, -1, 0, 0, 1, 1, 1};
static vector<int> colNbr= {-1, 0, 1, -1, 1, -1, 0, 1};

template<typename T>
void printMatrix(Matriz<T> mat) {
    cout<<"\n Printing Matrix : \n";
    for(int i=0 ; i<mat.numfils(); i++) {
        for(int j=0 ; j<mat.numcols(); j++)
            cout<< mat[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

void bfs(Matriz<bool> &M, int row, int col, Matriz<bool> &visited, int const& mancha_original, ConjuntosDisjuntos &cd) {
    visited[row][col] = true;
    for (int k = 0; k < 8; ++k) {
        if (M.posCorrecta(row + rowNbr[k], col + colNbr[k]) && (M[row+ rowNbr[k]][col + colNbr[k]] && !visited[row + rowNbr[k]][col + colNbr[k]])) {
            int mancha = (col + colNbr[k]) + (row + rowNbr[k])*M.numcols();
            cd.unir(mancha_original, mancha);
            bfs(M, row + rowNbr[k], col + colNbr[k], visited, mancha_original, cd);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, f, c, nf, nc;
    
    std::cin >> f >> c;
    if (!cin) return false;
    
    ConjuntosDisjuntos cd(f*c);
    
    //leer matriz
    Matriz<bool> M(f,c, false);
    cin.ignore();
    for(int i=0;i<f;++i) {
        string fila = "";
        getline(cin, fila);
        for(int j=0;j<c;++j){
            if (fila[j]=='#') M[i][j]=true;
        }
    }
    
    //buscar regiones
    int br=0; // bigger region
    Matriz<bool> visited(M.numfils(),M.numcols(),false);
    for (int i = 0; i < M.numfils(); ++i) {
        for (int j = 0; j < M.numcols(); ++j) {
            if (M[i][j] && !visited[i][j]) {
                int mancha = j + i*M.numcols();
                bfs(M, i, j, visited, mancha, cd);
                br = max(br , cd.tam(mancha));
            }
        }
    }
    cout << br <<' ';
    
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> nf >> nc;
        nf -=1;
        nc -=1;
        int mancha = nc+nf*M.numcols();
        M[nf][nc]=true;
        for (int k = 0; k < 8; ++k) {
            if (M.posCorrecta(nf + rowNbr[k], nc + colNbr[k]) && M[nf + rowNbr[k]][nc + colNbr[k]]) {
                cd.unir(mancha, (nc + colNbr[k])+(nf + rowNbr[k])*M.numcols());
            }
        }
        br = max(br , cd.tam(mancha));
        cout << br <<' ';
    }
    cout <<'\n';
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J34/J34/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
