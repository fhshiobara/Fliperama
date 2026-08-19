//
//  Frutinha.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/08/26.
//

#include "Frutinha.hpp"
Frutinha::Frutinha():x(0),y(0){}

Frutinha::~Frutinha(){}

void Frutinha::setPos(CoordI pos){
    x = pos.x;
    y = pos.y;
}

CoordI Frutinha::getPos(){
    CoordI pos = CoordI(x,y);
    return pos;
}
