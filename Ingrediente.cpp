/**
 * @file Ingrediente.cpp
 * @brief Implementación de la clase Ingrediente.
 * @details Este archivo contiene las definiciones de los constructores y métodos de la clase Ingrediente,
 * la cual representa un ítem individual dentro del inventario, gestionando su cantidad, unidad,
 * nombre y el nivel mínimo para alertar sobre la necesidad de reposición.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

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
