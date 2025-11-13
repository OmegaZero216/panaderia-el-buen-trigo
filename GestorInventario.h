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

    // Funciones relacionadas a stock de productos
    void mostrarStock() const;
    void mostrarAgotados() const;
};

#endif //GESTOR_INVENTARIO_H
