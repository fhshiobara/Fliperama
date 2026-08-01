//
//  Poderes.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 01/08/26.
//

#ifndef Poderes_hpp
#define Poderes_hpp

#include <stdio.h>
#include "Entidade.hpp"
#include "SFML/Graphics.hpp"
#include "Bola.hpp"

class Poderes:public Entidade{
protected:
    sf::RectangleShape* sprite;
    CoordF tamanho;
    short int id;
    bool ativo;
public:
    Poderes();
    virtual ~Poderes();
    
    void setTamanho(CoordF t){tamanho = t;}
    CoordF getTamanho(){return tamanho;}
    void setAtivo(bool a){ativo = a;}
    bool getAtivo(){return ativo;}
    
    virtual void executar(Bola* bola)=0;
    
    
};

#endif /* Poderes_hpp */
