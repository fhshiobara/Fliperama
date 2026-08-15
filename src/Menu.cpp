//
//  Menu.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 15/08/26.
//

#include "Menu.hpp"

Menu::Menu():pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL),moldura(NULL),faixaTitulo(NULL),destaque(NULL),visivel(true),selecionado(0),escolha(EscolhaJogo::NENHUM){
    criarCenario();
    criarTextos();
}

Menu::~Menu(){
    if(fundo!=NULL){ delete fundo; fundo=NULL; }
    if(moldura!=NULL){ delete moldura; moldura=NULL; }
    if(faixaTitulo!=NULL){ delete faixaTitulo; faixaTitulo=NULL; }
    if(destaque!=NULL){ delete destaque; destaque=NULL; }
}

void Menu::criarCenario(){
    fundo = new sf::RectangleShape;
    fundo->setOrigin(0.f,0.f);
    fundo->setSize(sf::Vector2f(1280.f,720.f));
    fundo->setFillColor(sf::Color(15,10,30)); // roxo quase preto

    moldura = new sf::RectangleShape;
    moldura->setSize(sf::Vector2f(700.f,500.f));
    moldura->setPosition(290.f,110.f);
    moldura->setFillColor(sf::Color(15,10,30));
    moldura->setOutlineThickness(6.f);
    moldura->setOutlineColor(sf::Color(255,0,180)); // magenta neon

    faixaTitulo = new sf::RectangleShape;
    faixaTitulo->setSize(sf::Vector2f(700.f,90.f));
    faixaTitulo->setPosition(290.f,110.f);
    faixaTitulo->setFillColor(sf::Color(255,0,180));

    destaque = new sf::RectangleShape;
    destaque->setSize(sf::Vector2f(400.f,60.f));
    destaque->setFillColor(sf::Color(0,255,220)); // ciano neon
}

void Menu::criarTextos(){
    sf::Font* fonte = pGG->getFont();
    if(fonte != NULL){
        titulo.setFont(*fonte);
        titulo.setString("F L I P E R A M A");
        titulo.setCharacterSize(40);
        titulo.setStyle(sf::Text::Bold);
        titulo.setFillColor(sf::Color(15,10,30));
        sf::FloatRect bT = titulo.getLocalBounds();
        titulo.setOrigin(bT.left+bT.width/2.f, bT.top+bT.height/2.f);
        titulo.setPosition(640.f, 155.f);

        opcaoTetris.setFont(*fonte);
        opcaoTetris.setString("TETRIS");
        opcaoTetris.setCharacterSize(36);
        sf::FloatRect b1 = opcaoTetris.getLocalBounds();
        opcaoTetris.setOrigin(b1.left+b1.width/2.f, b1.top+b1.height/2.f);
        opcaoTetris.setPosition(640.f, 340.f);

        opcaoPong.setFont(*fonte);
        opcaoPong.setString("PONG");
        opcaoPong.setCharacterSize(36);
        sf::FloatRect b2 = opcaoPong.getLocalBounds();
        opcaoPong.setOrigin(b2.left+b2.width/2.f, b2.top+b2.height/2.f);
        opcaoPong.setPosition(640.f, 440.f);

        instrucao.setFont(*fonte);
        instrucao.setString("USE AS SETAS (OU W/S) PARA NAVEGAR");
        instrucao.setCharacterSize(16);
        instrucao.setFillColor(sf::Color(150,150,170));
        sf::FloatRect b3 = instrucao.getLocalBounds();
        instrucao.setOrigin(b3.left+b3.width/2.f, b3.top+b3.height/2.f);
        instrucao.setPosition(640.f, 510.f);

        rodape.setFont(*fonte);
        rodape.setString("PRESSIONE ENTER PARA JOGAR");
        rodape.setCharacterSize(20);
        rodape.setFillColor(sf::Color::Yellow);
        sf::FloatRect b4 = rodape.getLocalBounds();
        rodape.setOrigin(b4.left+b4.width/2.f, b4.top+b4.height/2.f);
        rodape.setPosition(640.f, 575.f);
    }

    atualizarDestaque();
}

void Menu::atualizarDestaque(){
    if(selecionado == 0){
        destaque->setPosition(440.f, 310.f);
        opcaoTetris.setFillColor(sf::Color(15,10,30));
        opcaoPong.setFillColor(sf::Color::White);
    } else {
        destaque->setPosition(440.f, 410.f);
        opcaoPong.setFillColor(sf::Color(15,10,30));
        opcaoTetris.setFillColor(sf::Color::White);
    }
}

void Menu::tratarEventos(){
    sf::Event event;
    while(pGG->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            pGG->closeWindow();
            escolha = EscolhaJogo::SAIR;
        }
        if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    selecionado = (selecionado==0) ? 1 : 0;
                    atualizarDestaque();
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    selecionado = (selecionado==1) ? 0 : 1;
                    atualizarDestaque();
                    break;
                case sf::Keyboard::Enter:
                    escolha = (selecionado==0) ? EscolhaJogo::TETRIS : EscolhaJogo::PONG;
                    break;
                case sf::Keyboard::Escape:
                    pGG->closeWindow();
                    escolha = EscolhaJogo::SAIR;
                    break;
                default: break;
            }
        }
    }
}

void Menu::atualizar(){
    if(clockPiscar.getElapsedTime().asSeconds() >= 0.5f){
        visivel = !visivel;
        clockPiscar.restart();
    }
    sf::Color cor = rodape.getFillColor();
    cor.a = visivel ? 255 : 60;
    rodape.setFillColor(cor);
}

void Menu::desenhar(){
    pGG->clear();
    pGG->render(fundo);
    pGG->render(moldura);
    pGG->render(faixaTitulo);
    pGG->render(destaque);
    pGG->render(&titulo);
    pGG->render(&opcaoTetris);
    pGG->render(&opcaoPong);
    pGG->render(&instrucao);
    pGG->render(&rodape);
    pGG->display();
}

EscolhaJogo Menu::executar(){
    escolha = EscolhaJogo::NENHUM;
    while(pGG->windowopen() && escolha==EscolhaJogo::NENHUM){
        tratarEventos();
        atualizar();
        desenhar();
    }
    return escolha;
}
