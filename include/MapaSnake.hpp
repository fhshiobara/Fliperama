//
//  MapaSnake.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 17/08/26.
//

#ifndef MapaSnake_hpp
#define MapaSnake_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.hpp"

class MapaSnake{
private:
    int numCols;
    int numLinhas;
    int tamCelula;
    Gerenciadores::GerenciadorGrafico* pGG;
public:
    int mapa[30][30];
    MapaSnake();
    ~MapaSnake();
    
    void inicializar();
    void print();
    
    void criarLimites();
    void draw();
    
};



#endif /* MapaSnake_hpp */
