/**
 * @file GestorInventario.h
 * @brief Definición de la interfaz de la clase GestorInventario.
 * @details Este archivo contiene la declaración de la clase GestorInventario, que actúa
 * como un intermediario para todas las operaciones de modificación y consulta
 * del Inventario, así como para la consulta del Stock.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#ifndef GESTOR_INVENTARIO_H
#define GESTOR_INVENTARIO_H

#include "Inventario.h"
#include "Stock.h"

class GestorInventario {
private:
    Inventario* inventario;
    Stock* stock;

public:
    GestorInventario(Inventario* inv, Stock* st);

    // Funciones relacionadas a inventario
    void mostrarInventario() const;
    void mostrarAlertas() const;
    void agregarIngrediente();
    void eliminarIngrediente();
    void reabastecerIngrediente();

    // Funciones relacionadas al stock
    void mostrarStock() const;
    void mostrarAgotados() const;

    // Vista / menú interno
    void menuInventario();
};

#endif //GESTOR_INVENTARIO_H
