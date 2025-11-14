/**
 * @file Panadero.h
 * @brief Definición de la interfaz de la clase Panadero.
 * @details Este archivo contiene la declaración de la clase Panadero, que actúa
 * como el gestor principal de las recetas y el inicio de los procesos
 * de producción, interactuando con las clases Receta y Produccion.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 1.0
 */

#ifndef PANADERO_H
#define PANADERO_H

#include <string>
#include <vector>
#include "Receta.h"
#include "Produccion.h"

class Panadero {
private:
    Produccion* produccion;  // conexión con la lógica de producción
    std::string rutaRecetario; // archivo de recetas

public:
    Panadero(Produccion* prod, const std::string& rutaRecetario);

    // --- Funciones para el recetario ---
    void mostrarRecetario() const;
    void agregarReceta();
    void eliminarReceta();
    void modificarReceta();

    // --- Funciones de producción ---
    void producir();
    void menuPanadero();  // vista/menu interactivo
};

#endif //PANADERO_H

