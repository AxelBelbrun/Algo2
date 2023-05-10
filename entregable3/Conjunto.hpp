
template <class T>
Conjunto<T>::Conjunto() {
    cardinal_ = 0;
    _raiz = nullptr;

}

template <class T>
Conjunto<T>::~Conjunto() { 
    while (_raiz->izq != nullptr) {
        remover(this->minimo());
    }
    while (_raiz->der != nullptr) {
        remover(this->maximo());
    }
    delete _raiz;

}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    while (actual != nullptr) {
        if (clave == actual->valor) {
            return true;
        }
        else if (clave < actual->valor) {
            actual = actual->izq;
        }
        else {
            actual = actual->der;
        }

    }

    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (pertenece(clave)) {
        return;
    }
    else if (_raiz == nullptr) {
        _raiz = new Nodo(clave);
        cardinal_++;
        return;
    }
    else {

        Nodo* actual = _raiz;
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (clave < actual->valor) {
                anterior = actual;
                actual = actual->izq;
            } else {
                anterior = actual;
                actual = actual->der;
            }
        }

        if (clave < anterior->valor) {
            anterior->izq = new Nodo(clave);
        } else {
            anterior->der = new Nodo(clave);
        }
        cardinal_++;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* actual = _raiz;
    Nodo* anterior;

    if (!(pertenece(clave))) {
        return;
    }
    else if ((clave == _raiz->valor) && (cardinal_ == 1)){
        delete actual;
        _raiz = nullptr;
        cardinal_--;
    }

    else {

        while (actual->valor != clave) {
            if (clave < actual->valor) {
                anterior = actual;
                actual = actual->izq;

            }
            else {
                anterior = actual;
                actual = actual->der;

            }
        }
        if ((actual -> der == nullptr) && (actual -> izq == nullptr)){
            if (anterior -> der == actual) {
                anterior -> der = nullptr;
                delete actual;

            }
            else {
                anterior -> izq = nullptr;
                delete actual;

            }

        }

        else if ((actual -> der == nullptr) && (actual -> izq != nullptr)){
            if (anterior -> der == actual) {
                anterior -> der = actual->izq;
                delete actual;

            }
            else {
                anterior -> izq = actual->izq;
                delete actual;

            }

        }
        else if ((actual -> izq == nullptr) && (actual -> der != nullptr)){
            if (anterior -> der == actual) {
                anterior -> der = actual->der;
                delete actual;

            }
            else {
                anterior -> izq = actual->der;
                delete actual;

            }

        }
        else {
            T siguiente_ = siguiente((actual->valor));
            this->remover(siguiente(actual->valor));
            actual->valor = siguiente_;



        }
        cardinal_--;
    }




}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    Nodo* anterior = nullptr;
    while (actual-> valor != clave) {
        if (clave < actual->valor) {
            anterior = actual;
            actual = actual->izq;

        }
        else {
            anterior = actual;
            actual = actual->der;

        }
        
    }
    if (actual->der != nullptr){
        actual = actual->der;
        T minimo_;
        while (actual->izq != nullptr) {
            minimo_ = actual->valor;
            actual = actual->izq;
        }
        return minimo_;

    }
    else {
        Nodo* anterior_ = anterior;
        while (anterior_->der != actual) {
            while (actual != nullptr) {
                if (clave < actual->valor) {
                    anterior_ = actual;
                    actual = actual->izq;
                } else {
                    anterior_ = actual;
                    actual = actual->der;
                }
            }
        }
        return actual->valor;
        
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {

    Nodo* actual = _raiz;
    Nodo* anterior = _raiz;
    if (_raiz->izq != nullptr) {
        while (actual != nullptr) {
            anterior = actual;
            actual = actual->izq;
        }
        return anterior->valor;
    }
    else {
        return _raiz-> valor;
    }

}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    Nodo* anterior = _raiz;
    while (actual != nullptr) {
        anterior = actual;
        actual = actual->der;
    }
    return anterior->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cardinal_;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}
