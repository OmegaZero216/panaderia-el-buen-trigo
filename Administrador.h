/**
 * @file Administrador.h
 * @brief Definición de la interfaz de la clase Administrador.
 * @details Este archivo contiene la declaración de la clase Administrador, que gestiona
 * la lógica para la generación de reportes del sistema de inventario y stock.
 * @author [Sara Gonzalez, Evan Arregoces, Lissette Patiño, Margareth Gamboa, Luvian Parra]
 * @mail [sara.michelle.gonzalez@correounivalle.edu.co, evan.arregoces@correounivalle.edu.co, lissette.patino@correounivalle.edu.co, margareth.gamboa@correounivalle.edu.co, luvian.parra@correounivalle.edu.co]
 * @date 2025-11-13
 * @version 2.0
 */

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
