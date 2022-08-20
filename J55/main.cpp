//
//  main.cpp
//  J55
//
//  Created by Belén Sánchez Centeno on 23/12/2019.
//  Copyright © 2019 Belén Sánchez Centeno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

struct hora {
    int horas;
    int minutos;
};

struct pelicula {
    hora inicio;
    hora fin;
    int duracion;
};

hora operator+(hora const& h, int const& m) {
    hora _h = h;
    _h.minutos += m;
    while (_h.minutos >= 60) {
        _h.minutos -= 60;
        ++_h.horas;
    }
    return _h;
}

bool operator<(hora const& x, hora const& y) {
    return (x.horas < y.horas)||(x.horas == y.horas && x.minutos < y.minutos);
}

bool operator==(hora const& x, hora const& y) {
    return x.horas == y.horas&&x.minutos == y.minutos;
}


bool ordenar(pelicula const& p1, pelicula const& p2) {
    return p1.fin < p2.fin || (p1.fin == p2.fin && p2.inicio < p1.inicio);
}

int maxPeliculas(vector<pelicula> const& cartelera){
    pelicula ultimaPelicula= cartelera[0];
    int max = 1;
    for (int i = 1; i < cartelera.size(); ++i){
        if (ultimaPelicula.fin + 9 < cartelera[i].inicio) {
            ultimaPelicula= cartelera[i];
            max++;
        }
    }
    
    return max;
}


bool resuelveCaso() {
    int n;
    cin >> n;
    
    if (n == 0) return false;
    
    vector<pelicula> cartelera(n);
    hora h;
    char aux;
    for (int i = 0; i < n; ++i){
        std::cin >> h.horas >> aux >> h.minutos >> cartelera[i].duracion;
        cartelera[i].inicio = h;
        cartelera[i].fin = cartelera[i].inicio + cartelera[i].duracion;
    }
    
    sort(cartelera.begin(),cartelera.end(),ordenar);
    
    cout << maxPeliculas(cartelera) << '\n';
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/belensanchezcenteno/Library/Mobile Documents/com~apple~CloudDocs/DG Matemáticas y I. Informativa/Tercero/MARP/Juez/J55/J55/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
