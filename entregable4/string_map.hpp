template <typename T>
string_map<T>::string_map() : _size(0), raiz(nullptr){

}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {

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
        T def =  (c.second);
        actual->definicion = &def;
        _size++;


    }



template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* actual = raiz;
    for(char elem: clave){
        if (actual->siguientes[int(elem)] == nullptr) {
            return 0;
        }
        else {
            actual = actual->siguientes[int(elem)];
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
    return actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    for(char elem: clave){
        actual = actual->siguientes[int(elem)];
    }


   return *&actual->definicion ;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    if (size() == 0){
        return true;
    }
    else {
        return false;
    }
}