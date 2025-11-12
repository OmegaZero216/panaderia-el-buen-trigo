#ifndef RECETA_H
#define RECETA_H

#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::pair
#include "Ingrediente.h"

/**
 * @brief Clase que representa una receta para un producto de panadería.
 * 
 * Cada receta tiene un nombre y una lista de ingredientes con sus cantidades requeridas.
 */
class Receta {
private:
    std::string nombre; ///< Nombre de la receta (ej. Pan Blanco)
    std::vector<std::pair<std::string, double>> ingredientesNecesarios;
    // (nombre del ingrediente, cantidad requerida)

public:
    /**
     * @brief Constructor por defecto.
     */
    Receta();

    /**
     * @brief Constructor parametrizado.
     * @param nombreReceta Nombre de la receta.
     */
    Receta(const std::string& nombreReceta);

    /**
     * @brief Agrega un ingrediente con la cantidad requerida a la receta.
     * @param nombreIng Nombre del ingrediente.
     * @param cantidad Cantidad requerida.
     */
    void agregarIngrediente(const std::string& nombreIng, double cantidad);

    /**
     * @brief Muestra los ingredientes necesarios de la receta.
     */
    void mostrarReceta() const;

    /**
     * @brief Obtiene el nombre de la receta.
     */
    std::string getNombre() const;

    /**
     * @brief Devuelve la lista de ingredientes y cantidades requeridas.
     */
    const std::vector<std::pair<std::string, double>>& getIngredientes() const;

    /**
     * @brief Guarda la receta en un archivo de texto.
     * @param rutaArchivo Ruta del archivo.
     * @return true si se guardó correctamente.
     */
    bool guardarEnArchivo(const std::string& rutaArchivo) const;

    /**
     * @brief Carga una receta desde un archivo de texto.
     * @param rutaArchivo Ruta del archivo.
     * @param nombreReceta Nombre de la receta a cargar.
     * @return true si se encontró y cargó correctamente.
     */
    bool cargarDesdeArchivo(const std::string& rutaArchivo, const std::string& nombreReceta);
};

#endif // RECETA_H
