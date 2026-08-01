//
//  Poderes.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 01/08/26.
//

#include "Poderes.hpp"

Poderes::Poderes():sprite(NULL){}

Poderes::~Poderes(){
    if(sprite!=NULL){
        delete sprite;
        sprite = NULL;
    }
}
