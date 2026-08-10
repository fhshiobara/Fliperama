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
#include "GerenciadorGrafico.hpp"

#include <map>

class Mapa:public Entidade{
protected:
    CoordF tamanho;
    int numCols;
    int numLinhas;
    int tamanhoCelula;
    std::map <int,sf::Color> cores;
    std::map <int,sf::Color>::iterator it;
    Gerenciadores::GerenciadorGrafico* pGG;
    
    
    
    
    
public:
    int mapa[20][10];
    Mapa();
    ~Mapa();
    void inicializar();
    void print();
    void draw();
    sf::Color getCor(int id);
    
    float correcaoX;
    float correcaoY;
    
    
    
};

#endif /* Mapa_hpp */
