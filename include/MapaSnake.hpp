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
#include <map>
#include "Frutinha.hpp"

class MapaSnake{
private:
    int numCols;
    int numLinhas;
    int tamCelula;
    Gerenciadores::GerenciadorGrafico* pGG;
    float correcaoX;
    float correcaoY;
    std::map<int,sf::Color> cores;
    std::map<int,sf::Color>::iterator it;
    sf::RectangleShape* fundo;
public:
    int mapa[30][30];
    MapaSnake();
    ~MapaSnake();
    
    void inicializar();
    void print();
    
    void criarLimites();
    void criarXadrez();
    void draw();
    
    sf::Color getCor(int id);
    void setFrutinha(Frutinha* f);
    
    
};



#endif /* MapaSnake_hpp */
