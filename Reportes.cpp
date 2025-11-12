#include "Reportes.h"
#include <map>
#include <numeric>

Reportes::Reportes(Inventario* inv, Stock* st)
    : inventario(inv), stock(st) {}

void Reportes::reporteInventario() const {
    std::cout << "\n📦 === REPORTE DE INVENTARIO ===\n";
    inventario->mostrarInventario();
    inventario->mostrarAlertas();
    std::cout << "================================\n";
}

void Reportes::reporteStock() const {
    std::cout << "\n🥐 === REPORTE DE STOCK ===\n";
    stock->mostrarStock();
    stock->mostrarAgotados();
    std::cout << "=============================\n";
}

void Reportes::reportePorcentualStock() const {
    std::cout << "\n📊 === DISTRIBUCIÓN DE STOCK POR PRODUCTO ===\n";

    // Accedemos al stock interno mediante una copia segura
    std::vector<std::string> nombres;
    std::vector<int> cantidades;

    // Para obtener los datos, generamos un archivo temporal con Stock
    // No tenemos un getter del vector, así que sugerimos agregar en Stock:
    // const std::vector<Producto>& getProductos() const { return productos; }

    extern const std::vector<Producto>& obtenerProductosStock(const Stock&); 
    // Nota: Esta línea es conceptual; más abajo te mostraré la versión correcta si deseas agregarla directamente.

    // Pero para el ejemplo, simularemos con pseudo datos.
    std::cout << "⚠️ (Simulación de porcentajes: implementar getter en Stock si se requiere real)\n";

    // Ejemplo simulado:
    std::map<std::string, int> datosSimulados = {

    const auto& lista = stock->getProductos();
    int total = 0;
    for (const auto& p : lista) total += p.getCantidad();

    for (const auto& p : lista) {
        double porcentaje = (static_cast<double>(p.getCantidad()) / total) * 100;
        std::cout << std::setw(15) << std::left << p.getNombre()
                  << " | " << p.getCantidad() << " unidades"
                  << " (" << std::fixed << std::setprecision(1)
                  << porcentaje << "%)\n";
}
    std::cout << "===========================================\n";
}

void Reportes::reporteCierreAnual() const {
    std::cout << "\n📅 === REPORTE DE CIERRE ANUAL ===\n";
    std::cout << "Este informe resume el estado de inventario y stock al cierre del año fiscal.\n";

    reporteInventario();
    reporteStock();
    reportePorcentualStock();

    std::cout << "\n✅ Fin del reporte de cierre anual.\n";
}
