#include "Ingrediente.h"

// Constructor por defecto
Ingrediente::Ingrediente()
    : nombre(""), unidad(""), cantidad(0.0), nivelMinimo(0.0) {}

// Constructor parametrizado
Ingrediente::Ingrediente(const std::string& n, const std::string& u, double c, double min)
    : nombre(n), unidad(u), cantidad(c), nivelMinimo(min) {}

// --- Getters ---
std::string Ingrediente::getNombre() const { return nombre; }
std::string Ingrediente::getUnidad() const { return unidad; }
double Ingrediente::getCantidad() const { return cantidad; }
double Ingrediente::getNivelMinimo() const { return nivelMinimo; }

// --- Setters ---
void Ingrediente::setCantidad(double nuevaCantidad) {
    cantidad = (nuevaCantidad >= 0) ? nuevaCantidad : 0;
}

void Ingrediente::setNivelMinimo(double nuevoMinimo) {
    nivelMinimo = (nuevoMinimo >= 0) ? nuevoMinimo : 0;
}

// --- Funciones de lógica ---
void Ingrediente::modificarCantidad(double delta) {
    cantidad += delta;
    if (cantidad < 0)
        cantidad = 0; // evitar valores negativos
}

bool Ingrediente::necesitaReposicion() const {
    return cantidad <= nivelMinimo;
}

void Ingrediente::mostrar() const {
    std::cout << "- " << nombre
              << " (" << cantidad << " " << unidad << ")"
              << " | Nivel mínimo: " << nivelMinimo << " " << unidad;

    if (necesitaReposicion())
        std::cout << " [BAJO STOCK]";
    std::cout << std::endl;
}
