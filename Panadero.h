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

