#include <iostream>
#include "Ingrediente.h"
#include "Inventario.h"
#include "Receta.h"
#include "Producto.h"
#include "Stock.h"
#include "Produccion.h"
#include "Reportes.h"

using namespace std;

int main() {
    system("clear"); // En Windows puedes usar system("cls");
    cout << "=============================\n";
    cout << "🌾 PANADERÍA EL BUEN TRIGO 🌾\n";
    cout << "=============================\n\n";

    // --- Inicialización de componentes ---
    Inventario inventario;
    Stock stock;

    // Cargar datos iniciales desde archivos
    inventario.cargarDesdeArchivo("data/inventario.txt");
    stock.cargarDesdeArchivo("data/stock.txt");

    // Cargar receta desde archivo
    Receta recetaPanBlanco;
    recetaPanBlanco.cargarDesdeArchivo("data/recetas.txt", "Pan Blanco");

    // --- Mostrar datos iniciales ---
    cout << "\n📋 Estado inicial del sistema:\n";
    inventario.mostrarInventario();
    stock.mostrarStock();

    // --- Producción ---
    Produccion produccion(&inventario, &stock);

    int cantidad;
    cout << "\n👨‍🍳 ¿Cuántos panes blancos desea producir hoy?: ";
    cin >> cantidad;

    produccion.fabricarProducto(recetaPanBlanco, cantidad);

    // --- Guardar cambios ---
    inventario.guardarEnArchivo("data/inventario.txt");
    stock.guardarEnArchivo("data/stock.txt");

    // --- Reportes finales ---
    Reportes reportes(&inventario, &stock);
    reportes.reporteCierreAnual();

    cout << "\n🌾 ¡Gracias por usar El Buen Trigo! 🌾\n";
    cout << "=======================================\n";

    return 0;
}
