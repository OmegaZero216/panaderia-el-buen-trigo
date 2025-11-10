#include "Receta.h"
#include <fstream>
#include <iomanip>   // std::quoted
#include <sstream>

Receta::Receta() : nombre("") {}

Receta::Receta(const std::string& nombreReceta)
    : nombre(nombreReceta) {}

void Receta::agregarIngrediente(const std::string& nombreIng, double cantidad) {
    ingredientesNecesarios.push_back({nombreIng, cantidad});
    std::cout << "🧾 Ingrediente \"" << nombreIng
              << "\" agregado a la receta \"" << nombre << "\" ("
              << cantidad << " unidades requeridas).\n";
}

void Receta::mostrarReceta() const {
    std::cout << "\n=== RECETA: " << nombre << " ===\n";
    if (ingredientesNecesarios.empty()) {
        std::cout << "⚠️ No hay ingredientes en esta receta.\n";
        return;
    }

    for (const auto& par : ingredientesNecesarios) {
        std::cout << "- " << par.first << ": " << par.second << std::endl;
    }
    std::cout << "==============================\n";
}

std::string Receta::getNombre() const {
    return nombre;
}

const std::vector<std::pair<std::string, double>>& Receta::getIngredientes() const {
    return ingredientesNecesarios;
}

bool Receta::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo, std::ios::app); // modo append para no sobrescribir
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo abrir el archivo de recetas: " << rutaArchivo << "\n";
        return false;
    }

    // Guardamos formato: "nombreReceta" "nombreIngrediente" cantidad
    for (const auto& par : ingredientesNecesarios) {
        archivo << std::quoted(nombre) << " "
                << std::quoted(par.first) << " "
                << par.second << "\n";
    }

    archivo.close();
    std::cout << "💾 Receta \"" << nombre << "\" guardada en " << rutaArchivo << ".\n";
    return true;
}

bool Receta::cargarDesdeArchivo(const std::string& rutaArchivo, const std::string& nombreReceta) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo abrir el archivo de recetas: " << rutaArchivo << "\n";
        return false;
    }

    ingredientesNecesarios.clear();
    std::string nombreRec, nombreIng;
    double cantidad;
    bool encontrada = false;

    while (archivo >> std::quoted(nombreRec) >> std::quoted(nombreIng) >> cantidad) {
        if (nombreRec == nombreReceta) {
            ingredientesNecesarios.push_back({nombreIng, cantidad});
            encontrada = true;
        }
    }

    archivo.close();
    if (encontrada) {
        nombre = nombreReceta;
        std::cout << "📥 Receta \"" << nombre << "\" cargada correctamente.\n";
        return true;
    } else {
        std::cout << "⚠️ No se encontró la receta \"" << nombreReceta << "\" en el archivo.\n";
        return false;
    }
}
