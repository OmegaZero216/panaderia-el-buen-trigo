/**
 * @file Producto.h
 * @brief Definición de la interfaz de la clase Producto.
 * @details Este archivo contiene la declaración de la clase Producto, que modela
 * los ítems terminados en stock. Gestiona la cantidad disponible, su receta base
 * y provee métodos para la persistencia de sus datos en archivos.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include "Receta.h"

/**
 * @brief Clase que representa un producto final elaborado en la panadería.
 * 
 * Cada producto tiene un nombre, una receta base y una cantidad en stock.
 */
class Producto {
private:
    std::string nombre; ///< Nombre del producto (ej. Pan Blanco)
    Receta recetaBase;  ///< Receta utilizada para producirlo
    int cantidad;       ///< Cantidad disponible en stock

public:
    /**
     * @brief Constructor por defecto.
     */
    Producto();

    /**
     * @brief Constructor parametrizado.
     * @param n Nombre del producto.
     * @param receta Receta base asociada.
     * @param cant Cantidad inicial en stock.
     */
    Producto(const std::string& n, const Receta& receta, int cant = 0);

    // --- Getters ---
    std::string getNombre() const;
    int getCantidad() const;
    const Receta& getReceta() const;

    // --- Setters ---
    void setCantidad(int nuevaCantidad);

    /**
     * @brief Incrementa la cantidad en stock.
     * @param delta Cantidad a sumar (puede ser negativa para restar).
     */
    void modificarCantidad(int delta);

    /**
     * @brief Muestra la información del producto en consola.
     */
    void mostrar() const;

    /**
     * @brief Guarda el producto en un archivo de texto.
     * @param rutaArchivo Ruta del archivo.
     * @return true si se guardó correctamente.
     */
    bool guardarEnArchivo(const std::string& rutaArchivo) const;

    /**
     * @brief Carga un producto específico desde un archivo.
     * @param rutaArchivo Ruta del archivo.
     * @param nombreProducto Nombre del producto a cargar.
     * @return true si se encontró y cargó correctamente.
     */
    bool cargarDesdeArchivo(const std::string& rutaArchivo, const std::string& nombreProducto);
};

#endif // PRODUCTO_H
