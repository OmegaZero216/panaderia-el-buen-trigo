#include "Administrador.h"
#include <iostream>
#include <iomanip>
#include <numeric>

Administrador::Administrador(Inventario* inv, Stock* st)
    : inventario(inv), stock(st) {}

void Administrador::reporteInventario() const {
    inventario->mostrarInventario();
    inventario->mostrarAlertas();
}

void Administrador::reporteStock() const {
    stock->mostrarStock();
    stock->mostrarAgotados();
}

void Administrador::reportePorcentualStock() const {
    std::cout << "=== Porcentajes del stock ===\n";

    // const vector<Producto>& getProductos() const;

    auto productos = stock->getProductos();
    int total = 0;

    for (auto& p : productos)
        total += p.getCantidad();

    for (auto& p : productos) {
        double porcentaje = (double)p.getCantidad() / total * 100;
        std::cout << p.getNombre() << " : "
                  << porcentaje << "% (" << p.getCantidad() << " unidades)\n";
    }
}

void Administrador::reporteCierreAnual() const {
    std::cout << "=== REPORTE ANUAL ===\n";
    reporteInventario();
    reporteStock();
    reportePorcentualStock();
}

void Administrador::mostrarMenu() {
    int op;
    do {
        std::cout << "\n--- MENU ADMINISTRADOR ---\n";
        std::cout << "1. Reporte Inventario\n";
        std::cout << "2. Reporte Stock\n";
        std::cout << "3. Reporte porcentual\n";
        std::cout << "4. Reporte anual\n";
        std::cout << "0. Salir\n> ";
        std::cin >> op;

        switch (op) {
            case 1: reporteInventario(); break;
            case 2: reporteStock(); break;
            case 3: reportePorcentualStock(); break;
            case 4: reporteCierreAnual(); break;
        }

    } while (op != 0);
}
