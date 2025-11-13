#include <iostream>
#include "Inventario.h"
#include "Stock.h"
#include "Produccion.h"
#include "Panadero.h"
#include "GestorInventario.h"
#include "Administrador.h"

int main() {
    // ================================
    //     CREACIÓN DE LOS MODELOS
    // ================================
    Inventario inventario;
    Stock stock;
    Produccion produccion(&inventario, &stock);

    // Archivo maestro del recetario
    std::string rutaRecetario = "data/recetas.txt";

    // ================================
    //     CREACIÓN DE LAS VISTAS
    // ================================
    Panadero panadero(&produccion, rutaRecetario);
    GestorInventario gestor(&inventario, &stock);
    Administrador admin(&inventario, &stock);

    // ================================
    //     MENÚ PRINCIPAL DEL SISTEMA
    // ================================
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n====================================\n";
        std::cout << "       SISTEMA 'EL BUEN TRIGO'      \n";
        std::cout << "====================================\n";
        std::cout << "1. Módulo Panadero\n";
        std::cout << "2. Módulo Gestor de Inventario\n";
        std::cout << "3. Módulo Administrador\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                panadero.menuPanadero();
                break;

           case 2:
                gestor.menuInventario();
                break;
            
            case 3:
                admin.mostrarMenu();
                break;

            case 0:
                std::cout << "Gracias por usar el sistema. ¡Hasta pronto!\n";
                break;

            default:
                std::cout << "Opción inválida.\n";
        }
    }

    return 0;
}

