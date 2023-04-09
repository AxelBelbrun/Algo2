#include <iostream>
#include <list>
using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int día);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();

  private:
    int mes_;
    int dia_;

};
Fecha::Fecha(int mes, int dia): mes_(mes),dia_(dia) {}
int Fecha::mes() {
    return mes_;
};
int Fecha::dia() {
    return  dia_;
};
ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;

}
void Fecha::incrementar_dia() {
    if (dia_ < dias_en_mes(mes_)) {
        dia_ = dia_ + 1;
    }
    else {
        dia_ = 1;
        if (mes_ < 12){
            mes_ = mes_ + 1;
        }
        else {
            mes_ = 1;

        }
    }
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = (this->dia() == o.dia()) && (this->mes() == o.mes());
    // Completar iguadad (ej 9)
    return igual_dia;
}
#endif

// Ejercicio 11, 12
 class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint  min();
    bool operator==(Horario h);
    bool operator<(Horario h);
 private:
    uint hora_;
    uint min_;

};
Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {};
uint Horario::hora(){
    return hora_;
};
uint Horario::min() {
    return min_;
};
ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}
bool Horario:: operator==(Horario h) {
    return (h.min() == min_) && (h.hora() == hora_);
}
bool Horario::operator<(Horario h) {
    if (hora_ < h.hora()) {
        return true;
    }
    else if (hora_ == h.hora() ) {
        return (min_ < h.min());
    }
    else {
        return false;
    }
}
// Clase Horario


// Ejercicio 13

class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string s);
    Fecha fecha();
    Horario horario();
    string mensaje();
    bool operator<(Recordatorio r);


private:
    Fecha fecha_;
    Horario horario_;
    string mensaje_;
};
Recordatorio::Recordatorio(Fecha f, Horario h, string s): fecha_(f), horario_(h),
mensaje_(s){}
string Recordatorio::mensaje(){
    return mensaje_;
}

Fecha Recordatorio::fecha() {
    return fecha_;
}
Horario Recordatorio::horario() {
    return horario_;
}
ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
bool Recordatorio:: operator<(Recordatorio r){
    return horario_ < r.horario();
}


// Ejercicio 14

class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
private:
    Fecha fecha_inic;
    Fecha fecha_actual;
    list<Recordatorio> recordatorios_del_dia;
    list<Recordatorio> recordatorios_;

};

Agenda::Agenda(Fecha f): fecha_inic(f), fecha_actual(f){}


void Agenda::agregar_recordatorio(Recordatorio rec) {


       recordatorios_.push_back(rec);


}


void Agenda::incrementar_dia() {
    fecha_actual.incrementar_dia();
    recordatorios_del_dia.clear();

}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    for (Recordatorio r: recordatorios_) {
        if (r.fecha() == fecha_actual) {
            recordatorios_del_dia.push_back(r);
        }
    }
    return recordatorios_del_dia;
}
Fecha Agenda::hoy() {
    return fecha_actual;
}

ostream& operator<<(ostream& os, Agenda a) {

    os << a.hoy() << endl;
    os << "=====" << endl;
    list<Recordatorio> recordatorios = a.recordatorios_de_hoy();
    recordatorios.sort();
    for(Recordatorio r : recordatorios){
        os << r << endl;
    }
}