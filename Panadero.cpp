#include "Panadero.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

Panadero::Panadero(Produccion* prod, const std::string& rutaRecetario)
    : produccion(prod), rutaRecetario(rutaRecetario) {}


// ==================================================
//               RECETARIO
// ==================================================

void Panadero::mostrarRecetario() const {
    std::ifstream archivo(rutaRecetario);
    if (!archivo.is_open()) {
        std::cout << " No se pudo abrir el archivo del recetario.\n";
        return;
    }

    std::cout << "\n === RECETARIO ===\n";

    std::string nombreRec, nombreIng;
    double cant;
    std::string ultimo = "";

    while (archivo >> std::quoted(nombreRec) >> std::quoted(nombreIng) >> cant) {
        if (nombreRec != ultimo) {
            std::cout << "\n " << nombreRec << ":\n";
            ultimo = nombreRec;
        }
        std::cout << "   - " << nombreIng << ": " << cant << "\n";
    }

    std::cout << "\n====================\n";
}


// --------------------------------------------------
// AGREGAR RECETA
// --------------------------------------------------
void Panadero::agregarReceta() {
    std::string nombre;
    std::cout << "Nombre de la nueva receta: ";
    std::cin >> nombre;

    Receta r(nombre);

    int numIngredientes;
    std::cout << "¿Cuántos ingredientes tiene?: ";
    std::cin >> numIngredientes;

    for (int i = 0; i < numIngredientes; i++) {
        std::string ing;
        double cant;
        std::cout << "Ingrediente #" << (i+1) << ": ";
        std::cin >> ing;
        std::cout << "Cantidad requerida: ";
        std::cin >> cant;

        r.agregarIngrediente(ing, cant);
    }

    r.guardarEnArchivo(rutaRecetario);
    std::cout << "Receta agregada correctamente.\n";
}


// --------------------------------------------------
// ELIMINAR RECETA
// --------------------------------------------------
void Panadero::eliminarReceta() {
    std::string objetivo;
    std::cout << "¿Qué receta desea eliminar?: ";
    std::cin >> objetivo;

    std::ifstream archivo(rutaRecetario);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }

    std::vector<std::string> lineas;
    std::string nRec, nIng;
    double cant;

    while (archivo >> std::quoted(nRec) >> std::quoted(nIng) >> cant) {
        if (nRec != objetivo) {
            std::ostringstream oss;
            oss << std::quoted(nRec) << " " << std::quoted(nIng) << " " << cant;
            lineas.push_back(oss.str());
        }
    }
    archivo.close();

    std::ofstream out(rutaRecetario);
    for (const auto& l : lineas)
        out << l << "\n";

    std::cout << "Receta \"" << objetivo << "\" eliminada correctamente.\n";
}


// --------------------------------------------------
// MODIFICAR RECETA
// --------------------------------------------------
void Panadero::modificarReceta() {
    std::string receta;
    std::cout << "¿Qué receta desea modificar?: ";
    std::cin >> receta;

    Receta r;
    if (!r.cargarDesdeArchivo(rutaRecetario, receta)) {
        std::cout << "No existe esa receta.\n";
        return;
    }

    std::cout << "Receta actual:\n";
    r.mostrarReceta();

    std::cout << "\n1. Agregar ingrediente\n";
    std::cout << "2. Eliminar ingrediente\n> ";
    int op;
    std::cin >> op;

    if (op == 1) {
        std::string ing;
        double cant;
        std::cout << "Ingrediente a agregar: ";
        std::cin >> ing;
        std::cout << "Cantidad: ";
        std::cin >> cant;

        r.agregarIngrediente(ing, cant);
    }
    else if (op == 2) {
        std::string ing;
        std::cout << "Ingrediente a eliminar: ";
        std::cin >> ing;

        auto& lista = r.getIngredientes();
        std::vector<std::pair<std::string,double>> nueva;

        for (auto& p : lista)
            if (p.first != ing)
                nueva.push_back(p);

        // Sobreescribir lista
        const_cast<std::vector<std::pair<std::string,double>>&>(r.getIngredientes()) = nueva;
    }

    // Sobreescribir recetario completo con la receta modificada
    eliminarReceta(); // elimina anterior
    r.guardarEnArchivo(rutaRecetario);

    std::cout << "Receta modificada correctamente.\n";
}


// ==================================================
//              PRODUCCIÓN
// ==================================================

void Panadero::producir() {
    std::string receta;
    std::cout << "Nombre de la receta a producir: ";
    std::cin >> receta;

    Receta r;
    if (!r.cargarDesdeArchivo(rutaRecetario, receta)) {
        std::cout << "No existe esa receta.\n";
        return;
    }

    int cantidad;
    std::cout << "Cantidad a producir: ";
    std::cin >> cantidad;

    produccion->fabricarProducto(r, cantidad);
}


// ==================================================
//             MENÚ PRINCIPAL DEL PANADERO
// ==================================================

void Panadero::menuPanadero() {
    int op;
    do {
        std::cout << "\n=== MENÚ PANADERO ===\n";
        std::cout << "1. Mostrar recetario\n";
        std::cout << "2. Agregar receta\n";
        std::cout << "3. Eliminar receta\n";
        std::cout << "4. Modificar receta\n";
        std::cout << "5. Producir\n";
        std::cout << "0. Salir\n> ";
        std::cin >> op;

        switch (op) {
            case 1: mostrarRecetario(); break;
            case 2: agregarReceta(); break;
            case 3: eliminarReceta(); break;
            case 4: modificarReceta(); break;
            case 5: producir(); break;
        }

    } while (op != 0);
}
