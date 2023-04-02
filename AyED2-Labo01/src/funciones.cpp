#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> conj;
    vector<int> res;
    for (int x: s) {
        conj.insert(x);
    }
    for (int y: conj) {
        res.push_back(y);
    }


    return res;
}

// Ejercicio 2

vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> conj;
    vector<int> res;
    for (int x: s) {
        conj.insert(x);
    }
    for (int y: conj) {
        res.push_back(y);
    }


    return res;

}
// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> ac;
    set<int> bc;
    for(int x: a) {
        ac.insert(x);

    }
    for(int y: b) {
        bc.insert(y);
    }
    if (bc == ac) {
        return true;
    }
    else {
        return false;
    }
}


// Ejercicio 4

bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> ac;
    set<int> bc;
    for(int x: a) {
        ac.insert(x);

    }
    for(int y: b) {
        bc.insert(y);
    }
    if (bc == ac) {
        return true;
    }
    else {
        return false;
    }
}


// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> dicc;
    for(int n: s){
        if (dicc[n] >= 1) {
            dicc[n] = dicc[n] + 1;
        }
        else {
            dicc[n] = 1;
        }
    }
    return dicc;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int,int > repeticiones = contar_apariciones(s);
    vector<int> res;
    for(int x: s){
        if (repeticiones[x] <= 1) {
            res.push_back(x);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int x: a) {
        if (b.count(x) == 1) {
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int,set<int>> dicc;
    for(int x: s) {
        if (dicc[(x % 10)].size() >= 1) {
        dicc[(x % 10)].insert(x) ;


        }
        else {
            dicc[(x % 10)] = {x};
        }
    }
    return dicc;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char,char> dicc;
    for(pair<char,char> p: tr) {
        dicc[p.first] = p.second;
    }
    vector<char> res;
    for(char c: str) {
     if (dicc.count(c) >= 1) {
         res.push_back(dicc[c]) ;
     }
     else {
         res.push_back(c);
     }
    }
    return res ;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    map<LU, int> dicc;
    for (Mail m: s){
        set<LU> conj_de_libretas = m.libretas();
        for (LU j: conj_de_libretas){
            if (dicc[j] == 1) {
                return true;
            }
            else {
                dicc[j] = 1;
            }

        }

    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  map<set<LU>, Mail> res;
  for (Mail m: s){
      set<LU> conj_de_libretas = m.libretas();
      if (res.count(conj_de_libretas) == 1){

          if ((res[conj_de_libretas].fecha() < m.fecha()) && m.adjunto()){
              res[conj_de_libretas] = m;
          }
      }
      else {
      res[conj_de_libretas] = m; }
      }
      return res;
  }

