//
//  Poderes.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 01/08/26.
//

#include "Poderes.hpp"

Poderes::Poderes():sprite(NULL),tamanho(CoordF(50.f,50.f)),id(0){}

Poderes::~Poderes(){
    if(sprite!=NULL){
        delete sprite;
        sprite = NULL;
    }
}
