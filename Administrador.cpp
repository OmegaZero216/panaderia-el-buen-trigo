/**
 * @file Administrador.cpp
 * @brief Implementación de la clase Administrador.
 * @details Este archivo contiene las definiciones de los métodos de la clase Administrador,
 * utilizados para generar diversos reportes sobre el estado del Inventario y el Stock
 * (Reporte de inventario, Reporte de stock, Reporte porcentual y Reporte de cierre anual).
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

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
