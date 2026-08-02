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



class Poderes;
class Bola:public Entidade{
protected:
    float raio;
    CoordF velocidade;
    CoordF velocidadePadrao;
    short int ultimo;
    sf::CircleShape* sprite;
    
    Raquete* ultima;
    
    std::vector<Raquete*> raquetes;
    std::vector<Raquete*>::iterator it;
    
    
    std::vector<Gol*> gols;
    std::vector<Gol*>::iterator i;
    
    std::vector<Poderes*> poderes;
    std::vector<Poderes*>::iterator p;
    
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
    
    CoordF getVelocidadePadrao(){return velocidadePadrao;}
    
    void tratarColisaoPoderes();
    
    Raquete* getUltima(){return ultima;}
    void atualizarPoderes();
    
    void setPoderes(Poderes* p){
        poderes.push_back(p);
    }
    
    
    
    
    sf::CircleShape* getSprite(){
        return sprite;
    }
    
};

#endif /* Bola_hpp */
