/**
 * @file Produccion.cpp
 * @brief Implementación de la clase Produccion.
 * @details Este archivo contiene las definiciones de los métodos de la clase Produccion,
 * encargada de verificar la disponibilidad de ingredientes de una Receta,
 * consumir dichos ingredientes del Inventario y, finalmente, actualizar el Stock
 * con la cantidad de producto terminado.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#include "Produccion.h"

Produccion::Produccion(Inventario* inv, Stock* st)
    : inventario(inv), stock(st) {}

bool Produccion::verificarDisponibilidad(const Receta& recetaBase, int cantidad) const {
    for (const auto& par : recetaBase.getIngredientes()) {
        std::string nombreIng = par.first;
        double requerido = par.second * cantidad;

        Ingrediente* ing = inventario->buscarIngrediente(nombreIng);
        if (!ing) {
            std::cout << " Ingrediente \"" << nombreIng << "\" no existe en inventario.\n";
            return false;
        }
        if (ing->getCantidad() < requerido) {
            std::cout << " No hay suficiente \"" << nombreIng
                      << "\". Se requiere " << requerido
                      << " " << ing->getUnidad()
                      << " y solo hay " << ing->getCantidad() << ".\n";
            return false;
        }
    }
    return true;
}

void Produccion::fabricarProducto(const Receta& recetaBase, int cantidad) {
    std::cout << "\n Iniciando producción de " << cantidad 
              << " unidades de \"" << recetaBase.getNombre() << "\"...\n";

    if (!verificarDisponibilidad(recetaBase, cantidad)) {
        std::cout << " Producción cancelada. Ingredientes insuficientes.\n";
        return;
    }

    // Descontar ingredientes del inventario
    for (const auto& par : recetaBase.getIngredientes()) {
        Ingrediente* ing = inventario->buscarIngrediente(par.first);
        double requerido = par.second * cantidad;
        ing->modificarCantidad(requerido);
    }

    // Crear o actualizar producto en el stock
    Producto* prodExistente = stock->buscarProducto(recetaBase.getNombre());
    if (prodExistente) {
        prodExistente->modificarCantidad(cantidad);
        std::cout << " Stock de \"" << prodExistente->getNombre()
                  << "\" actualizado a " << prodExistente->getCantidad() << " unidades.\n";
    } else {
        Producto nuevo(recetaBase.getNombre(), recetaBase, cantidad);
        stock->agregarProducto(nuevo);
    }

    std::cout << " Producción completada con éxito.\n";
    mostrarResumen(recetaBase, cantidad);
}

void Produccion::mostrarResumen(const Receta& recetaBase, int cantidad) const {
    std::cout << "\n === RESUMEN DE PRODUCCIÓN ===\n";
    std::cout << "Producto: " << recetaBase.getNombre() << "\n";
    std::cout << "Cantidad producida: " << cantidad << "\n";
    std::cout << "Ingredientes utilizados:\n";

    for (const auto& par : recetaBase.getIngredientes()) {
        std::cout << "- " << par.first << ": " << (par.second * cantidad) << std::endl;
    }

    std::cout << "=============================\n";
}
