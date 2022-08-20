//
//  main.cpp
//  J33
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
#include "queue_eda.h"

using namespace std;

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

int minDistance(Matriz<bool> visited, pair<int,int> puerta, pair<int,int> s) {
    pair<pair<int,int>,int> entrada={puerta,0};

    queue<pair<pair<int,int>,int>> q;
    q.push(entrada);
    visited[entrada.first.first][entrada.first.second] = true;
    while (!q.empty()) {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
  
        // Destination found;
        if (p.first.first==s.first && p.first.second==s.second)
            return p.second;
        
        if(visited.posCorrecta(p.first.first-1, p.first.second) && !visited[p.first.first-1][p.first.second]) {
            q.push({{p.first.first-1, p.first.second},p.second+1});
            visited[p.first.first-1][p.first.second]=true;
        }
        
        if(visited.posCorrecta(p.first.first+1, p.first.second) && !visited[p.first.first+1][p.first.second]) {
            q.push({{p.first.first+1, p.first.second},p.second+1});
            visited[p.first.first+1][p.first.second]=true;
        }
        
        if(visited.posCorrecta(p.first.first, p.first.second-1) && !visited[p.first.first][p.first.second-1]) {
            q.push({{p.first.first, p.first.second-1},p.second+1});
            visited[p.first.first][p.first.second-1]=true;
        }
        
        if(visited.posCorrecta(p.first.first, p.first.second+1) && !visited[p.first.first][p.first.second+1]) {
            q.push({{p.first.first, p.first.second+1},p.second+1});
            visited[p.first.first][p.first.second+1]=true;
        }
    }
    return -1;
}
            
// Resuelve un caso de prueba, leyendo de la entrada la // configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, f, c;
    char x;
    
    std::cin >> n;
    if (!cin) return false;
    
    for(int i=0;i<n;++i){
        std::cin >> c >> f;
        
        Matriz<char> m(f,c,'.');
        Matriz<bool> aux(f,c,false);
        
        pair<int,int> puerta, salida;
        vector<pair<pair<int,int>,int>> camaras;
        
        for(int j=0;j<f;++j){ //fila
            for(int k=0;k<c;++k){ //columna
                cin>>x;
                if(x!='.') m[j][k]=x;
                if(x=='#') aux[j][k]=true;
                else if (x=='E') puerta={j,k};
                else if (x=='P') salida={j,k};
                if(x!='.'&&x!='#'&&x!='P'&&x!='E') camaras.push_back({{j,k},(int)x - 48});
            }
        }
        
        for(auto y : camaras){
            bool stopArriba=false, stopDer=false, stopIzq=false, stopAbajo=false;
            int j=y.first.first;
            int k=y.first.second;
            int x= y.second;
            
            for(int h=0;h<=x;++h){
                if(aux.posCorrecta(j, k-h) && m[j][k-h]=='#') stopArriba=true;
                else if (!stopArriba && aux.posCorrecta(j, k-h)) aux[j][k-h]=true;
                
                if(aux.posCorrecta(j+h, k) && m[j+h][k]=='#') stopDer=true;
                else if (!stopDer && aux.posCorrecta(j+h, k)) aux[j+h][k]=true;
                
                if(aux.posCorrecta(j-h, k) && m[j-h][k]=='#') stopIzq=true;
                else if (!stopIzq && aux.posCorrecta(j-h, k)) aux[j-h][k]=true;
                
                if(aux.posCorrecta(j, k+h) && m[j][k+h]=='#') stopAbajo=true;
                else if (!stopAbajo && aux.posCorrecta(j, k+h)) aux[j][k+h]=true;
            }
        }
//        printMatrix(m);
//        printMatrix(aux);
        int sol;
        if (aux[puerta.first][puerta.second] || aux[salida.first][salida.second]) sol=-1;
        else sol=minDistance(aux, puerta, salida);
        if(sol==-1 ) cout<<"NO"<<"\n";
        else cout<<sol<<"\n";
    }
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J33/J33/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
