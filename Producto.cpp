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
    std::cout << "\n🥐 PRODUCTO: " << nombre
              << "\nCantidad en stock: " << cantidad
              << "\nReceta base:";
    recetaBase.mostrarReceta();
}

bool Producto::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo, std::ios::app);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo abrir el archivo de productos: " << rutaArchivo << "\n";
        return false;
    }

    archivo << std::quoted(nombre) << " "
            << cantidad << "\n";

    archivo.close();
    std::cout << "💾 Producto \"" << nombre << "\" guardado en " << rutaArchivo << ".\n";
    return true;
}

bool Producto::cargarDesdeArchivo(const std::string& rutaArchivo, const std::string& nombreProducto) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo abrir el archivo de productos: " << rutaArchivo << "\n";
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
        std::cout << "📥 Producto \"" << nombre << "\" cargado correctamente.\n";
        return true;
    } else {
        std::cout << "⚠️ No se encontró el producto \"" << nombreProducto << "\" en el archivo.\n";
        return false;
    }
}
