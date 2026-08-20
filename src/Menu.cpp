//
//  Menu.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 15/08/26.
//

#include "Menu.hpp"

Menu::Menu():pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL),moldura(NULL),faixaTitulo(NULL),destaque(NULL),visivel(true),selecionado(0),escolha(EscolhaJogo::NENHUM){
    // Lista dos jogos disponíveis
    nomesOpcoes = {"TETRIS", "PONG", "SNAKE"};

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
    fundo->setFillColor(sf::Color(15,10,30)); // Roxo escuro estilo arcade

    moldura = new sf::RectangleShape;
    moldura->setSize(sf::Vector2f(720.f, 540.f));
    moldura->setPosition(280.f, 90.f);
    moldura->setFillColor(sf::Color(20,15,40));
    moldura->setOutlineThickness(6.f);
    moldura->setOutlineColor(sf::Color(255, 0, 180)); // Magenta Neon

    faixaTitulo = new sf::RectangleShape;
    faixaTitulo->setSize(sf::Vector2f(720.f, 90.f));
    faixaTitulo->setPosition(280.f, 90.f);
    faixaTitulo->setFillColor(sf::Color(255, 0, 180));

    destaque = new sf::RectangleShape;
    destaque->setSize(sf::Vector2f(440.f, 55.f));
    destaque->setFillColor(sf::Color(0, 255, 220)); // Ciano Neon
}

void Menu::criarTextos(){
    sf::Font* fonte = pGG->getFont();
    if(fonte != NULL){
        // Título Principal
        titulo.setFont(*fonte);
        titulo.setString("F L I P E R A M A");
        titulo.setCharacterSize(42);
        titulo.setStyle(sf::Text::Bold);
        titulo.setFillColor(sf::Color(15,10,30));
        sf::FloatRect bT = titulo.getLocalBounds();
        titulo.setOrigin(bT.left + bT.width/2.f, bT.top + bT.height/2.f);
        titulo.setPosition(640.f, 135.f);

        // Opções dinâmicas dos jogos
        float startY = 240.f;
        float espacamentoY = 65.f;

        for(size_t i = 0; i < nomesOpcoes.size(); ++i){
            sf::Text txt;
            txt.setFont(*fonte);
            txt.setString(nomesOpcoes[i]);
            txt.setCharacterSize(34);
            txt.setStyle(sf::Text::Bold);
            
            sf::FloatRect bounds = txt.getLocalBounds();
            txt.setOrigin(bounds.left + bounds.width/2.f, bounds.top + bounds.height/2.f);
            txt.setPosition(640.f, startY + (i * espacamentoY));

            textosOpcoes.push_back(txt);
        }

        // Instruções
        instrucao.setFont(*fonte);
        instrucao.setString("USE AS SETAS (OU W/S) PARA NAVEGAR");
        instrucao.setCharacterSize(16);
        instrucao.setFillColor(sf::Color(170,170,200));
        sf::FloatRect b3 = instrucao.getLocalBounds();
        instrucao.setOrigin(b3.left + b3.width/2.f, b3.top + b3.height/2.f);
        instrucao.setPosition(640.f, 530.f);

        // Rodapé Piscante
        rodape.setFont(*fonte);
        rodape.setString("PRESSIONE ENTER PARA JOGAR");
        rodape.setCharacterSize(20);
        rodape.setStyle(sf::Text::Bold);
        rodape.setFillColor(sf::Color::Yellow);
        sf::FloatRect b4 = rodape.getLocalBounds();
        rodape.setOrigin(b4.left + b4.width/2.f, b4.top + b4.height/2.f);
        rodape.setPosition(640.f, 580.f);
    }

    atualizarDestaque();
}

void Menu::atualizarDestaque(){
    if(textosOpcoes.empty()) return;

    float startY = 240.f;
    float espacamentoY = 65.f;

    // Reposiciona a caixa de destaque sobre a opção selecionada
    destaque->setPosition(420.f, (startY + (selecionado * espacamentoY)) - 27.f);

    // Ajusta a cor dos textos para dar contraste
    for(size_t i = 0; i < textosOpcoes.size(); ++i){
        if(static_cast<int>(i) == selecionado){
            textosOpcoes[i].setFillColor(sf::Color(15,10,30)); // Escuro dentro do destaque ciano
        } else {
            textosOpcoes[i].setFillColor(sf::Color::White);
        }
    }
}

void Menu::tratarEventos(){
    sf::Event event;
    int totalOpcoes = static_cast<int>(nomesOpcoes.size());

    while(pGG->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            pGG->closeWindow();
            escolha = EscolhaJogo::SAIR;
        }
        if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    selecionado = (selecionado - 1 + totalOpcoes) % totalOpcoes;
                    atualizarDestaque();
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    selecionado = (selecionado + 1) % totalOpcoes;
                    atualizarDestaque();
                    break;
                case sf::Keyboard::Enter:
                    if(selecionado == 0) escolha = EscolhaJogo::TETRIS;
                    else if(selecionado == 1) escolha = EscolhaJogo::PONG;
                    else if(selecionado == 2) escolha = EscolhaJogo::SNAKE;
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
    if(clockPiscar.getElapsedTime().asSeconds() >= 0.4f){
        visivel = !visivel;
        clockPiscar.restart();
    }
    sf::Color cor = rodape.getFillColor();
    cor.a = visivel ? 255 : 40;
    rodape.setFillColor(cor);
}

void Menu::desenhar(){
    pGG->clear();
    pGG->render(fundo);
    pGG->render(moldura);
    pGG->render(faixaTitulo);
    pGG->render(destaque);
    pGG->render(&titulo);

    for(auto& txt : textosOpcoes){
        pGG->render(&txt);
    }

    pGG->render(&instrucao);
    pGG->render(&rodape);
    pGG->display();
}

EscolhaJogo Menu::executar(){
    escolha = EscolhaJogo::NENHUM;
    while(pGG->windowopen() && escolha == EscolhaJogo::NENHUM){
        tratarEventos();
        atualizar();
        desenhar();
    }
    return escolha;
}
