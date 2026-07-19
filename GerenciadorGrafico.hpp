//
//  GerenciadorGrafico.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/07/26.
//

#ifndef GerenciadorGrafico_hpp
#define GerenciadorGrafico_hpp


#include <iostream>
#include <SFML/Graphics.hpp>

namespace Gerenciadores{
        
    class GerenciadorGrafico{
        private:
            sf::RenderWindow* window;
            sf::Font* font;
            sf::Clock clock;
            static float dt;
            
            static Gerenciadores::GerenciadorGrafico* instance;

            GerenciadorGrafico();//permite criar apenas um gerenciador para o jogo
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getInstance();
            void render(sf::RectangleShape* hitbox);
            
            void render(sf::Text* txt);
            
            bool windowopen()const;
            
            void closeWindow();
            
            void display();
            
            void clear();
            
            sf::RenderWindow* getWindow();

            sf::Font* getFont();
            
    };

    #define pGraphicM Gerenciadores::GerenciadorGrafico::getInstance()

}

#endif
