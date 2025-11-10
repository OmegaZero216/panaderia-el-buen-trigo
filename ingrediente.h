#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <iostream>
#include <string>

/**
 * @brief Clase que representa un ingrediente del inventario.
 * 
 * Cada ingrediente tiene un nombre, una unidad de medida (kg, litros, etc.),
 * una cantidad disponible, y un nivel mínimo que activa una alerta.
 */
class Ingrediente {
private:
    std::string nombre;       ///< Nombre del ingrediente (ej. Harina)
    std::string unidad;       ///< Unidad de medida (ej. kg, litros)
    double cantidad;          ///< Cantidad disponible en inventario
    double nivelMinimo;       ///< Cantidad mínima antes de activar alerta

public:
    /**
     * @brief Constructor por defecto.
     */
    Ingrediente();

    /**
     * @brief Constructor parametrizado.
     * @param n Nombre del ingrediente
     * @param u Unidad de medida
     * @param c Cantidad disponible
     * @param min Nivel mínimo antes de alerta
     */
    Ingrediente(const std::string& n, const std::string& u, double c, double min);

    // --- Getters ---
    std::string getNombre() const;
    std::string getUnidad() const;
    double getCantidad() const;
    double getNivelMinimo() const;

    // --- Setters ---
    void setCantidad(double nuevaCantidad);
    void setNivelMinimo(double nuevoMinimo);

    /**
     * @brief Agrega o descuenta cantidad del inventario.
     * @param delta Cantidad a modificar (puede ser negativa).
     */
    void modificarCantidad(double delta);

    /**
     * @brief Indica si el ingrediente está por debajo del nivel mínimo.
     * @return true si la cantidad <= nivelMinimo.
     */
    bool necesitaReposicion() const;

    /**
     * @brief Muestra la información del ingrediente en consola.
     */
    void mostrar() const;
};

#endif // INGREDIENTE_H
