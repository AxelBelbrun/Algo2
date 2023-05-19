template <typename T>
string_map<T>::string_map() : _size(0), claves({}){
    raiz = new Nodo();

}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {

    set<string> res = this->claves;
    if (!(claves.empty())) {
        for (string s: res) {
            erase((s));
        }
    }
    delete raiz;
    _size = 0;
    raiz = new Nodo();
    for(string t: d.claves){
        pair<string, T> c = make_pair(t,d.at(t));
        this->insert(c);

    }
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    set<string> res = this->claves;
    if (!(claves.empty())) {
        for (string s: res) {
            this->erase((s));
        }
    }
    delete raiz->definicion;
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
            actual = raiz->siguientes[int(clave[i])];
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
    Nodo* padre;
    int indice = -1;

    for(char c: clave){
        if(!(actual->esNodoEliminable())){
            indice ++;
            padre = actual;
            actual = actual->siguientes[int(c)];
        }
        else {
            padre = actual;
            actual = actual->siguientes[int(c)];
        }
    }
    int i = 0;
    if (actual->esNodoFinalEliminable()){
        actual = raiz;
        for(char c: clave){
            if (i<= indice){
                padre = actual;
                actual = actual->siguientes[int(c)];
                i++;
            }
            else {
                if (i == indice+1){
                    padre->siguientes[int(clave[i])] = nullptr;
                }
                Nodo* temp = actual->siguientes[int(c)];
                delete actual->definicion;
                delete actual;

                actual = temp;
                i++;
            }
        }
        delete actual->definicion;
        delete actual;

    }
    else {
        delete actual->definicion;
        actual->definicion = nullptr;
    }

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