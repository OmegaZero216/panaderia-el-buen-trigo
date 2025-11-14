/**
 * @file Stock.h
 * @brief Definición de la interfaz de la clase Stock.
 * @details Este archivo contiene la declaración de la clase Stock, que modela
 * la colección de productos terminados, permitiendo su gestión (adición,
 * eliminación, búsqueda) y la persistencia de los datos en archivos.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <vector>
#include <string>
#include "Producto.h"

/**
 * @brief Clase que administra el stock de productos terminados.
 * 
 * Permite agregar, eliminar, buscar, modificar y mostrar productos.
 */
class Stock {
private:
    std::vector<Producto> productos; ///< Lista de productos en stock.

public:
    /**
     * @brief Constructor por defecto.
     */
    Stock();

    // --- Gestión de productos ---

    /**
     * @brief Agrega un nuevo producto al stock.
     * @param producto Objeto Producto.
     */
    void agregarProducto(const Producto& producto);

    /**
     * @brief Elimina un producto por nombre.
     * @param nombre Nombre del producto.
     * @return true si se eliminó correctamente.
     */
    bool eliminarProducto(const std::string& nombre);

    /**
     * @brief Busca un producto por nombre.
     * @param nombre Nombre del producto.
     * @return Puntero al producto si existe, nullptr si no.
     */
    Producto* buscarProducto(const std::string& nombre);

    /**
     * @brief Muestra el listado completo de productos.
     */
    void mostrarStock() const;

    /**
     * @brief Muestra los productos que están agotados (cantidad == 0).
     */
    void mostrarAgotados() const;

    // --- Persistencia ---

    /**
     * @brief Carga el stock desde un archivo.
     * @param rutaArchivo Ruta del archivo .txt.
     * @return true si la carga fue exitosa.
     */
    bool cargarDesdeArchivo(const std::string& rutaArchivo);

    /**
     * @brief Guarda el stock actual en un archivo.
     * @param rutaArchivo Ruta del archivo .txt.
     * @return true si se guardó correctamente.
     */
    bool guardarEnArchivo(const std::string& rutaArchivo) const;

    const std::vector<Producto>& getProductos() const { return productos; }
};

#endif // STOCK_H
