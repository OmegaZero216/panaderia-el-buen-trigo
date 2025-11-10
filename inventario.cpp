#include "Inventario.h"
#include <fstream>
#include <iomanip>  // para formatear salida

Inventario::Inventario() {}

// --- Gestión de ingredientes ---

void Inventario::agregarIngrediente(const Ingrediente& ingr) {
    ingredientes.push_back(ingr);
    std::cout << "✅ Ingrediente \"" << ingr.getNombre() << "\" agregado al inventario.\n";
}

bool Inventario::eliminarIngrediente(const std::string& nombre) {
    for (auto it = ingredientes.begin(); it != ingredientes.end(); ++it) {
        if (it->getNombre() == nombre) {
            ingredientes.erase(it);
            std::cout << "🗑️ Ingrediente \"" << nombre << "\" eliminado.\n";
            return true;
        }
    }
    std::cout << "⚠️ Ingrediente \"" << nombre << "\" no encontrado.\n";
    return false;
}

Ingrediente* Inventario::buscarIngrediente(const std::string& nombre) {
    for (auto& ingr : ingredientes) {
        if (ingr.getNombre() == nombre) {
            return &ingr;
        }
    }
    return nullptr;
}

void Inventario::mostrarInventario() const {
    if (ingredientes.empty()) {
        std::cout << "📦 Inventario vacío.\n";
        return;
    }

    std::cout << "\n=== INVENTARIO DE INGREDIENTES ===\n";
    for (const auto& ingr : ingredientes) {
        ingr.mostrar();
    }
    std::cout << "==================================\n";
}

void Inventario::mostrarAlertas() const {
    bool hayAlertas = false;
    std::cout << "\n🚨 INGREDIENTES CON BAJO STOCK 🚨\n";
    for (const auto& ingr : ingredientes) {
        if (ingr.necesitaReposicion()) {
            ingr.mostrar();
            hayAlertas = true;
        }
    }
    if (!hayAlertas)
        std::cout << "✅ Todos los ingredientes están en niveles adecuados.\n";
    std::cout << "----------------------------------\n";
}

// --- Persistencia ---

bool Inventario::cargarDesdeArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo abrir el archivo de inventario: " << rutaArchivo << "\n";
        return false;
    }

    ingredientes.clear();
    std::string nombre, unidad;
    double cantidad, minimo;

    while (archivo >> std::quoted(nombre) >> std::quoted(unidad) >> cantidad >> minimo) {
        Ingrediente ingr(nombre, unidad, cantidad, minimo);
        ingredientes.push_back(ingr);
    }

    archivo.close();
    std::cout << "📥 Inventario cargado correctamente desde \"" << rutaArchivo << "\".\n";
    return true;
}

bool Inventario::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo guardar el archivo de inventario: " << rutaArchivo << "\n";
        return false;
    }

    for (const auto& ingr : ingredientes) {
        archivo << std::quoted(ingr.getNombre()) << " "
                << std::quoted(ingr.getUnidad()) << " "
                << ingr.getCantidad() << " "
                << ingr.getNivelMinimo() << "\n";
    }

    archivo.close();
    std::cout << "💾 Inventario guardado correctamente en \"" << rutaArchivo << "\".\n";
    return true;
}
