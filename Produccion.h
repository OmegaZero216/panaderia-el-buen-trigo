/**
 * @file Produccion.h
 * @brief Definición de la interfaz de la clase Produccion.
 * @details Este archivo contiene la declaración de la clase Produccion, que coordina
 * la lógica de fabricación de productos, verificando recursos en el Inventario,
 * y actualizando el Stock con el producto terminado, basándose en una Receta.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#ifndef PRODUCCION_H
#define PRODUCCION_H

#include <iostream>
#include <string>
#include "Inventario.h"
#include "Stock.h"
#include "Receta.h"
#include "Producto.h"

/**
 * @brief Clase que gestiona el proceso de producción de productos en la panadería.
 * 
 * Usa el inventario y las recetas para fabricar productos, descontando ingredientes y
 * actualizando el stock final.
 */
class Produccion {
private:
    Inventario* inventario; ///< Referencia al inventario general.
    Stock* stock;           ///< Referencia al stock de productos.

public:
    /**
     * @brief Constructor de la clase Produccion.
     * @param inv Puntero al inventario existente.
     * @param st Puntero al stock existente.
     */
    Produccion(Inventario* inv, Stock* st);

    /**
     * @brief Intenta producir una cierta cantidad de un producto.
     * @param recetaBase Receta del producto.
     * @param cantidad Cantidad de unidades a producir.
     */
    void fabricarProducto(const Receta& recetaBase, int cantidad);

    /**
     * @brief Verifica si hay suficientes ingredientes en inventario para fabricar cierta receta.
     * @param recetaBase Receta del producto.
     * @param cantidad Cantidad a producir.
     * @return true si se puede producir.
     */
    bool verificarDisponibilidad(const Receta& recetaBase, int cantidad) const;

    /**
     * @brief Muestra un resumen del proceso de producción (ingredientes utilizados).
     * @param recetaBase Receta utilizada.
     * @param cantidad Cantidad producida.
     */
    void mostrarResumen(const Receta& recetaBase, int cantidad) const;
};

#endif // PRODUCCION_H
