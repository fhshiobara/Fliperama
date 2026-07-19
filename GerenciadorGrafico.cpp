//
//  GerenciadorGrafico.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/07/26.
//

#include "GerenciadorGrafico.hpp"

namespace Gerenciadores{
    GerenciadorGrafico* GerenciadorGrafico::instance = NULL;

    GerenciadorGrafico* GerenciadorGrafico::getInstance(){
        if(instance==NULL){
            instance = new GerenciadorGrafico();
        }
        return instance;
    }

    GerenciadorGrafico::GerenciadorGrafico() {
        
            window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gerenciador Grafico");
            window->setFramerateLimit(100);
        }

    GerenciadorGrafico::~GerenciadorGrafico(){
        delete window;
    }

    void GerenciadorGrafico::render(sf::RectangleShape* hitbox){
        window->draw(*hitbox);
    }

    void GerenciadorGrafico::render(sf::Text* txt){
        window->draw(*txt);
    }
    bool GerenciadorGrafico::windowopen()const{
        return window->isOpen();
    }

    void GerenciadorGrafico::display(){
        if(windowopen()){
            window->display();
        }
    }

    sf::RenderWindow* GerenciadorGrafico::getWindow(){
        return window;
    }

    void GerenciadorGrafico::closeWindow(){
        window->close();
    }

    void GerenciadorGrafico::clear(){
        window->clear();
    }

    sf::Font* GerenciadorGrafico::getFont(){
    if(font == NULL){
        font = new sf::Font();
        
        if(!font->loadFromFile("../assets/Font/FONT.ttf")){

            std::cerr << "ERRO: falha ao carregar assets/fonte.ttf" << std::endl;
            delete font;
            font = NULL;
        }
        }
        return font;
    }
}
