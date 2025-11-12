#ifndef REPORTES_H
#define REPORTES_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Inventario.h"
#include "Stock.h"

/**
 * @brief Clase que genera reportes de gestión para la panadería "El Buen Trigo".
 * 
 * Permite obtener información resumida del inventario, stock y niveles de producción.
 */
class Reportes {
private:
    Inventario* inventario; ///< Referencia al inventario.
    Stock* stock;           ///< Referencia al stock.

public:
    /**
     * @brief Constructor de la clase Reportes.
     * @param inv Puntero al inventario existente.
     * @param st Puntero al stock existente.
     */
    Reportes(Inventario* inv, Stock* st);

    /**
     * @brief Muestra un reporte general del estado del inventario.
     */
    void reporteInventario() const;

    /**
     * @brief Muestra un reporte del estado actual del stock.
     */
    void reporteStock() const;

    /**
     * @brief Muestra el porcentaje de productos por tipo dentro del stock.
     */
    void reportePorcentualStock() const;

    /**
     * @brief Genera un reporte consolidado de cierre de año.
     */
    void reporteCierreAnual() const;
};

#endif // REPORTES_H
