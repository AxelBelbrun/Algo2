#include "Lista.h"
#include <cassert>

Lista::Lista() : _primero(nullptr), _ultimo(nullptr), size(0) {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);

    return *this;
}
void Lista::agregarAdelante(const int& elem){
    Nodo* actual = new Nodo(elem, nullptr, nullptr);


    if (size == 1) {
        actual->anterior = nullptr;
        actual->siguiente = _primero;
        _ultimo = _primero;
        _primero = actual;
    }
    else if ( size == 0) {
        _primero = actual;

    }



    else {
        actual-> siguiente = _primero;
        actual-> anterior = nullptr;
        _primero->anterior = actual;
        _primero = actual;
    }
    size++;
}

void Lista::agregarAtras(const int& elem){
    Nodo* actual = new Nodo(elem, nullptr, nullptr);

    if (size == 1) {
        actual->anterior = _primero;
        _ultimo = actual;
        _primero->siguiente = _ultimo;


    }
    else if ( size == 0) {
        _primero = actual;

    }
    else {
        actual -> siguiente = nullptr;
        actual-> anterior = _ultimo;
        _ultimo-> siguiente = actual;
        _ultimo = actual;
    }
    size++;
}

void Lista::eliminar(Nat i) {
    int c = 0;
    Nodo* actual = _primero;
    while (c < i) {
        actual = actual->siguiente;
        c++;
    }
    if ((actual == _primero) && (size != 1)){
        _primero->siguiente->anterior = nullptr;
        _primero = _primero->siguiente;

        delete actual;


    }
    else if(actual == _primero){
        _primero = nullptr;
        delete actual;
    }
    else if ( actual == _ultimo ) {
        _ultimo->anterior->siguiente = nullptr;
        _ultimo = _ultimo->anterior;

        delete actual;
    }
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        delete actual;
    }
    size--;

}

int Lista::longitud() const {

    return size;
}

const int& Lista::iesimo(Nat i) const {
    int c = 0;
    Nodo* actual = _primero;
    while (c < i) {
        actual = actual->siguiente;
        c++;
    }

    return actual->valor;


}

int& Lista::iesimo(Nat i) {
    int c = 0;
    Nodo* actual = _primero;
    while (c < i) {
        actual = actual->siguiente;
        c++;
    }

    return actual->valor;

}

void Lista:: copiarNodos(const Lista &l) {
    if (l.size ==0) {
        return;

    }
    else{
    Nodo* actual = l._primero;
    while (actual != l._ultimo) {
        agregarAtras(actual->valor);
        actual = actual->siguiente;
    }
    agregarAtras(actual->valor);}

}
void Lista::destruirNodos() {
    Nodo* actual = _primero;
    while (actual != nullptr) {
        Nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    _primero = nullptr;
    _ultimo = nullptr;
    size = 0;
}

