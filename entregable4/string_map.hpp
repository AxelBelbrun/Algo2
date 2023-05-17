template <typename T>
string_map<T>::string_map() : _size(0), raiz(nullptr){

}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    this-> = string_map<T>(d);
    return this;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
void string_map<T>:: insert(const pair<string, T>& c){

    if (raiz == nullptr){
        raiz = new Nodo();
    }
        Nodo* actual = raiz;
    for(char elem: (c.first)) {
    if (actual->siguientes[int(elem)] == nullptr) {
            actual->siguientes[int(elem)] = new Nodo();
            actual = actual ->siguientes[int(elem)];

        } else {
            actual = actual->siguientes[int(elem)];


        }
    }
        T* def = new T (c.second) ;
        actual->definicion = def;
        _size++;


    }



template <typename T>
int string_map<T>::count(const string& clave) const{
    if (raiz == nullptr){
        return 0;
    }
    Nodo* actual = raiz;
    for(char elem: clave){
        if ((actual != nullptr)) {
            if((actual->siguientes[int(elem)]) == nullptr){
                return 0;
            }
            else{
                actual = actual->siguientes[int(elem)];

            }
        }
        else {
            return 0;
        }
    }
    if (actual->definicion != nullptr){
        return 1;
    }
    else {
        return 0;
    }
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    for(char elem: clave){
        actual = actual->siguientes[int(elem)];
    }
    T* res = actual->definicion;
    T res2 = *res;

    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    for(char elem: clave){
        actual = actual->siguientes[int(elem)];
    }

   return *(actual->definicion);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = raiz;
    Nodo* anterior = raiz;
    Nodo* ultimoNoBorrable = raiz;
    int indice = 0;
    for(char elem: clave){
        if ((actual->esNodoEliminable()) && (actual != raiz)){
            actual = actual->siguientes[int(elem)];

        }
        else {
            actual = actual->siguientes[int(elem)];
            anterior = actual;
            ultimoNoBorrable = actual;
            indice++;

        }
    }
    actual->definicion = nullptr;
    if (actual->esNodoFinalEliminable()){
        delete actual;
    }
    int i = 0;
    actual = raiz;
    for(char elem: clave){
        if(i<=indice){
            actual = actual->siguientes[int(elem)];

        }
        else{
        Nodo* temp = actual->siguientes[int(elem)];
        delete actual;
        actual = temp;
        }
    }

    _size--;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    if (_size == 0){
        return true;
    }

        return false;

}