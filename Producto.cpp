/**
 * @file Producto.cpp
 * @brief Implementación de la clase Producto.
 * @details Este archivo contiene las definiciones de los constructores y métodos de la clase Producto,
 * la cual representa un ítem terminado listo para la venta. Contiene la cantidad en stock,
 * su nombre y una referencia a la receta utilizada para su fabricación, además de métodos
 * para persistencia en archivos.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#include "Producto.h"
#include <fstream>
#include <iomanip>
#include <sstream>

Producto::Producto()
    : nombre(""), recetaBase(), cantidad(0) {}

Producto::Producto(const std::string& n, const Receta& receta, int cant)
    : nombre(n), recetaBase(receta), cantidad(cant) {}

std::string Producto::getNombre() const { return nombre; }
int Producto::getCantidad() const { return cantidad; }
const Receta& Producto::getReceta() const { return recetaBase; }

void Producto::setCantidad(int nuevaCantidad) {
    cantidad = (nuevaCantidad >= 0) ? nuevaCantidad : 0;
}

void Producto::modificarCantidad(int delta) {
    cantidad += delta;
    if (cantidad < 0)
        cantidad = 0;
}

void Producto::mostrar() const {
    std::cout << "\n PRODUCTO: " << nombre
              << "\nCantidad en stock: " << cantidad
              << "\nReceta base:";
    recetaBase.mostrarReceta();
}

bool Producto::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo, std::ios::app);
    if (!archivo.is_open()) {
        std::cout << " No se pudo abrir el archivo de productos: " << rutaArchivo << "\n";
        return false;
    }

    archivo << std::quoted(nombre) << " "
            << cantidad << "\n";

    archivo.close();
    std::cout << " Producto \"" << nombre << "\" guardado en " << rutaArchivo << ".\n";
    return true;
}

bool Producto::cargarDesdeArchivo(const std::string& rutaArchivo, const std::string& nombreProducto) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << " No se pudo abrir el archivo de productos: " << rutaArchivo << "\n";
        return false;
    }

    std::string nombreProd;
    int cant;
    bool encontrada = false;

    while (archivo >> std::quoted(nombreProd) >> cant) {
        if (nombreProd == nombreProducto) {
            nombre = nombreProd;
            cantidad = cant;
            encontrada = true;
            break;
        }
    }

    archivo.close();
    if (encontrada) {
        std::cout << " Producto \"" << nombre << "\" cargado correctamente.\n";
        return true;
    } else {
        std::cout << " No se encontró el producto \"" << nombreProducto << "\" en el archivo.\n";
        return false;
    }
}
