//
//  Mapa.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#ifndef Mapa_hpp
#define Mapa_hpp

#include <stdio.h>
#include "Entidade.hpp"
#include "SFML/Graphics.hpp"

class Mapa:public Entidade{
protected:
    CoordF tamanho;
    int numCols;
    int numLinhas;
    int tamanhoCelula;
public:
    int mapa[20][10];
    Mapa();
    ~Mapa();
    void inicializar();
    void print();
    
    
    
};

#endif /* Mapa_hpp */
