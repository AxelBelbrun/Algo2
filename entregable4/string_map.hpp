template <typename T>
string_map<T>::string_map() : _size(0), claves({}){
    raiz = new Nodo();

}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    for(string s: this->claves){
        erase(s);
    }

    for(string t: d.claves){
        pair<string, T> c = make_pair(t,d.at(t));
        this->insert(c);

    }
    return *this;
}

template <typename T>
string_map<T>::~string_map(){

    delete raiz;
}

template <typename T>
void string_map<T>:: insert(const pair<string, T>& c){
    Nodo* actual = raiz;
    Nodo* padre;
    int i = 0;
    string clave = c.first;
    T* def = new T (c.second);
    while((i < clave.size())){
        if (raiz == nullptr){
            raiz = new Nodo();
            actual = actual->siguientes[int(clave[i])];
            i++;
        }
        else if (actual == nullptr){
           padre->siguientes[int(clave[i-1])] = new Nodo();
           actual = padre->siguientes[int(clave[i-1])];
       }
        else{
        padre = actual;
        actual = actual->siguientes[int(clave[i])];
        i++;}
    }
        if(actual == nullptr){
            padre->siguientes[int(clave[i-1])] = new Nodo();
            padre->siguientes[int(clave[i-1])]->definicion = def;
        }
        else {
            actual->definicion = def;
        }
        claves.insert(clave);
        _size++;

    }



template <typename T>
int string_map<T>::count(const string& clave) const{
  return claves.count((clave));
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    for(char elem: clave){
        actual = actual->siguientes[int(elem)];
    }
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
    Nodo* padre = raiz;
    int indice = 0;
    int i = clave.size();
    while((i >= 0) and ((actual->esNodoFinalEliminable()))){
        padre = raiz;
        actual = raiz;
        indice = 0;
    while ((indice<i)) {
            padre = actual;
            actual = actual->siguientes[int(clave[indice])];
            indice++;
    }
    if (actual->esNodoFinalEliminable()){
        delete padre->siguientes[int(clave[i-1])];
    }
    actual = padre;
    i--;}
    claves.erase(clave);
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