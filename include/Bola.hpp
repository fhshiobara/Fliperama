//
//  Bola.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#ifndef Bola_hpp
#define Bola_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "VectorTL.hpp"
#include "Entidade.hpp"
#include "Raquete.hpp"
#include "Gol.hpp"


class Bola:public Entidade{
protected:
    float raio;
    CoordF velocidade;
    sf::CircleShape* sprite;
    
    std::vector<Raquete*> raquetes;
    std::vector<Raquete*>::iterator it;
    
    std::vector<Gol*> gols;
    std::vector<Gol*>::iterator i;
    
    CoordF tamJanela;
    void atualizarSprite();
public:
    Bola(CoordF v, float r);
    ~Bola();
    
    void mover();
    
    void setVelocidade(CoordF vel){velocidade = vel;}
    CoordF getVelocidade(){return velocidade;}
    
    void setRaio(float r){raio = r;}
    float getRaio(){return raio;}
    
    void setTamJanela(CoordF t){tamJanela = t;}
    
    void tratarColisaoParede();
    
    
    void setRaquete(Raquete* r);
    void tratarColisaoRaquete();
    
    void setPos(CoordF p);
    
    void setGol(Gol* g);
    void tratarColisaoGol();
    
    
    
    sf::CircleShape* getSprite(){
        return sprite;
    }
    
};

#endif /* Bola_hpp */
