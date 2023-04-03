#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {}

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

float Rectangulo::area() {
    return ancho_ * alto_;
}

// Ejercicio 2

class Elipse {
public:
    Elipse(uint a,uint b);
    uint r_a();
    uint r_b();
    float area();
private:
    uint radio_a;
    uint radio_b;
    float PI = 3.14;
};
Elipse::Elipse(uint a, uint b): radio_a(a), radio_b(b){};
uint Elipse::r_a(){
    return radio_a;
}
uint Elipse::r_b(){
    return radio_b;
}
float Elipse::area() {
    return radio_b*radio_a*PI;

}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
   return r_.ancho();
}

float Cuadrado::area() {
    return r_.area();
}

// Ejercicio 4

class Circulo {
public:
    Circulo(uint ra);
    float area();
    uint radio();
private:
    Elipse e;
};

Circulo::Circulo(uint ra): e(ra,ra) {}
uint Circulo::radio(){
    return e.r_a();

};
float Circulo::area(){
    return e.area();
};


ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

ostream& operator << (ostream& os, Elipse e){
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

