//
//  Raquete.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 13/07/26.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entidade.hpp"

#ifndef Raquete_hpp
#define Raquete_hpp

class Raquete:public Entidade{
protected:
    CoordF velocidade;
    sf::RectangleShape* sprite;
    CoordF tamanho;
    
    //-------- bools para movimentar a raquete
public://deixei os bools public para poder alterar eles direto da janela do jogo, provavlemente deve ter um jeito melhor mas...
    bool moveCima;
    bool moveBaixo;
    bool moveEsq;
    bool moveDir;
    
    Raquete(CoordF v, CoordF t);
    ~Raquete();
    
    
    void setSize(CoordF t);
    CoordF getSize();
    
    void setVelocidade(CoordF v){velocidade = v;}
    CoordF getVelocidade(){return velocidade;}
    
    void setColor(sf::Color c){
        if(sprite!=NULL){
            sprite->setFillColor(c);
        }
    }
    
    void mover();
    
    void setPos(CoordF p);
    
    sf::RectangleShape* getSprite(){
        return sprite;
    }
    
};

#endif
