/**
 * @file GestorInventario.cpp
 * @brief Implementación de la clase GestorInventario.
 * @details Este archivo contiene las definiciones de los métodos de la clase GestorInventario,
 * utilizados para manejar las operaciones del Inventario (agregar, eliminar, reabastecer)
 * y para mostrar la información del Inventario y del Stock.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 2.0
 */

#include "GestorInventario.h"
#include <iostream>

GestorInventario::GestorInventario(Inventario* inv, Stock* st)
    : inventario(inv), stock(st) {}


// ------------------------------------
// INVENTARIO
// ------------------------------------
void GestorInventario::mostrarInventario() const {
    inventario->mostrarInventario();
}

void GestorInventario::mostrarAlertas() const {
    inventario->mostrarAlertas();
}

void GestorInventario::agregarIngrediente() {
    std::string nombre, unidad;
    double cantidad, minimo;

    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Unidad: ";
    std::cin >> unidad;
    std::cout << "Cantidad inicial: ";
    std::cin >> cantidad;
    std::cout << "Nivel mínimo: ";
    std::cin >> minimo;

    inventario->agregarIngrediente(
        Ingrediente(nombre, unidad, cantidad, minimo)
    );

    std::cout << "Ingrediente agregado correctamente.\n";
}

void GestorInventario::eliminarIngrediente() {
    std::string nombre;
    std::cout << "Ingrediente a eliminar: ";
    std::cin >> nombre;

    inventario->eliminarIngrediente(nombre);
}

void GestorInventario::reabastecerIngrediente() {
    std::string nombre;
    double cant;

    std::cout << "Ingrediente a reabastecer: ";
    std::cin >> nombre;
    std::cout << "Cantidad a agregar: ";
    std::cin >> cant;

    Ingrediente* ing = inventario->buscarIngrediente(nombre);
    if (!ing) {
        std::cout << "No existe el ingrediente.\n";
        return;
    }

    ing->agregar(cant);
    std::cout << "Reabastecido correctamente.\n";
}


// ------------------------------------
// STOCK
// ------------------------------------
void GestorInventario::mostrarStock() const {
    stock->mostrarStock();
}

void GestorInventario::mostrarAgotados() const {
    stock->mostrarAgotados();
}


// ------------------------------------
// MENÚ INTERNO DEL GESTOR DE INVENTARIO
// ------------------------------------
void GestorInventario::menuInventario() {
    int op;

    do {
        std::cout << "\n=== MENU GESTOR DE INVENTARIO ===\n";
        std::cout << "1. Mostrar inventario\n";
        std::cout << "2. Mostrar alertas\n";
        std::cout << "3. Agregar ingrediente\n";
        std::cout << "4. Eliminar ingrediente\n";
        std::cout << "5. Reabastecer ingrediente\n";
        std::cout << "6. Mostrar stock\n";
        std::cout << "7. Mostrar productos agotados\n";
        std::cout << "0. Volver\n";
        std::cout << "> ";
        std::cin >> op;

        switch (op) {
            case 1: mostrarInventario(); break;
            case 2: mostrarAlertas(); break;
            case 3: agregarIngrediente(); break;
            case 4: eliminarIngrediente(); break;
            case 5: reabastecerIngrediente(); break;
            case 6: mostrarStock(); break;
            case 7: mostrarAgotados(); break;
            case 0: std::cout << "Volviendo...\n"; break;
            default: std::cout << "Opción invalida.\n"; break;
        }

    } while (op != 0);
}
