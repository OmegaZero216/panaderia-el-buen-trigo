/**
 * @file Inventario.h
 * @brief Definición de la interfaz de la clase Inventario.
 * @details Este archivo contiene la declaración de la clase Inventario, que se encarga
 * de almacenar y gestionar la colección de objetos Ingrediente, incluyendo
 * funcionalidades de manipulación (adición, eliminación, modificación y consulta),
 * búsqueda y persistencia en archivos.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <vector>
#include <string>
#include "Ingrediente.h"

/**
 * @brief Clase que administra la lista de ingredientes del sistema.
 * 
 * Permite agregar, eliminar, buscar, mostrar y verificar alertas de stock bajo.
 */
class Inventario {
private:
    std::vector<Ingrediente> ingredientes; ///< Lista de ingredientes registrados.

public:
    /**
     * @brief Constructor por defecto.
     */
    Inventario();

    // --- Gestión de ingredientes ---
    
    /**
     * @brief Agrega un nuevo ingrediente al inventario.
     * @param ingr Objeto de tipo Ingrediente.
     */
    void agregarIngrediente(const Ingrediente& ingr);

    /**
     * @brief Elimina un ingrediente por nombre.
     * @param nombre Nombre del ingrediente a eliminar.
     * @return true si se eliminó correctamente.
     */
    bool eliminarIngrediente(const std::string& nombre);

    /**
     * @brief Busca un ingrediente por nombre.
     * @param nombre Nombre del ingrediente.
     * @return Puntero al ingrediente si lo encuentra, nullptr si no.
     */
    Ingrediente* buscarIngrediente(const std::string& nombre);

    /**
     * @brief Muestra todo el inventario.
     */
    void mostrarInventario() const;

    /**
     * @brief Muestra los ingredientes que requieren reposición.
     */
    void mostrarAlertas() const;

    // --- Persistencia ---

    /**
     * @brief Carga los ingredientes desde un archivo de texto.
     * @param rutaArchivo Ruta del archivo.
     * @return true si la carga fue exitosa.
     */
    bool cargarDesdeArchivo(const std::string& rutaArchivo);

    /**
     * @brief Guarda el inventario en un archivo de texto.
     * @param rutaArchivo Ruta del archivo.
     * @return true si se guardó correctamente.
     */
    bool guardarEnArchivo(const std::string& rutaArchivo) const;
};

#endif // INVENTARIO_H
