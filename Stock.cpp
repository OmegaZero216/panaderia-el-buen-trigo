#include "Stock.h"
#include <fstream>
#include <iomanip> // std::quoted

Stock::Stock() {}

// --- Gestión de productos ---

void Stock::agregarProducto(const Producto& producto) {
    // Si ya existe, solo actualizamos su cantidad
    for (auto& p : productos) {
        if (p.getNombre() == producto.getNombre()) {
            p.modificarCantidad(producto.getCantidad());
            std::cout << "🔄 Producto \"" << producto.getNombre() 
                      << "\" actualizado en el stock.\n";
            return;
        }
    }

    productos.push_back(producto);
    std::cout << "✅ Producto \"" << producto.getNombre() << "\" agregado al stock.\n";
}

bool Stock::eliminarProducto(const std::string& nombre) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->getNombre() == nombre) {
            productos.erase(it);
            std::cout << "🗑️ Producto \"" << nombre << "\" eliminado del stock.\n";
            return true;
        }
    }
    std::cout << "⚠️ Producto \"" << nombre << "\" no encontrado.\n";
    return false;
}

Producto* Stock::buscarProducto(const std::string& nombre) {
    for (auto& p : productos) {
        if (p.getNombre() == nombre)
            return &p;
    }
    return nullptr;
}

void Stock::mostrarStock() const {
    if (productos.empty()) {
        std::cout << "📦 No hay productos en stock.\n";
        return;
    }

    std::cout << "\n=== STOCK DE PRODUCTOS ===\n";
    for (const auto& p : productos) {
        std::cout << "- " << p.getNombre() 
                  << " | Cantidad: " << p.getCantidad() << std::endl;
    }
    std::cout << "==========================\n";
}

void Stock::mostrarAgotados() const {
    bool hayAgotados = false;
    std::cout << "\n🚨 PRODUCTOS AGOTADOS 🚨\n";
    for (const auto& p : productos) {
        if (p.getCantidad() == 0) {
            std::cout << "- " << p.getNombre() << std::endl;
            hayAgotados = true;
        }
    }

    if (!hayAgotados)
        std::cout << "✅ No hay productos agotados.\n";

    std::cout << "--------------------------\n";
}

// --- Persistencia ---

bool Stock::cargarDesdeArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo abrir el archivo de stock: " << rutaArchivo << "\n";
        return false;
    }

    productos.clear();
    std::string nombre;
    int cantidad;

    while (archivo >> std::quoted(nombre) >> cantidad) {
        Producto p(nombre, Receta(nombre), cantidad); // receta vacía momentánea
        productos.push_back(p);
    }

    archivo.close();
    std::cout << "📥 Stock cargado correctamente desde \"" << rutaArchivo << "\".\n";
    return true;
}

bool Stock::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "⚠️ No se pudo guardar el archivo de stock: " << rutaArchivo << "\n";
        return false;
    }

    for (const auto& p : productos) {
        archivo << std::quoted(p.getNombre()) << " "
                << p.getCantidad() << "\n";
    }

    archivo.close();
    std::cout << "💾 Stock guardado correctamente en \"" << rutaArchivo << "\".\n";
    return true;
}
