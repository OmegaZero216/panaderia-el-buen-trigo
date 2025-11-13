#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Inventario.h"
#include "Stock.h"

class Administrador {
private:
    Inventario* inventario;
    Stock* stock;

public:
    Administrador(Inventario* inv, Stock* st);

    // Reportes
    void reporteInventario() const;
    void reporteStock() const;
    void reportePorcentualStock() const;
    void reporteCierreAnual() const;

    // Vista
    void mostrarMenu();
};
    
#endif //ADMINISTRADOR_H
