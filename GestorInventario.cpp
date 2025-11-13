#include "GestorInventario.h"
#include <iostream>

GestorInventario::GestorInventario(Inventario* inv, Stock* st)
    : inventario(inv), stock(st) {}

void GestorInventario::mostrarInventario() const {
    inventario->mostrarInventario();
}

void GestorInventario::mostrarAlertas() const {
    inventario->mostrarAlertas();
}

void GestorInventario::agregarIngrediente() {
    std::string nombre, unidad;
    double cantidad, minimo;

    std::cout << "Nombre: "; std::cin >> nombre;
    std::cout << "Unidad: "; std::cin >> unidad;
    std::cout << "Cantidad inicial: "; std::cin >> cantidad;
    std::cout << "Nivel mínimo: "; std::cin >> minimo;

    inventario->agregarIngrediente( Ingrediente(nombre, unidad, cantidad, minimo) );
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
}

void GestorInventario::mostrarStock() const {
    stock->mostrarStock();
}

void GestorInventario::mostrarAgotados() const {
    stock->mostrarAgotados();
}
