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
};

#endif // STOCK_H
