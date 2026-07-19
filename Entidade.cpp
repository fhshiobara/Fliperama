//
//  Entidade.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/07/26.
//

#include "Entidade.hpp"


Entidade::Entidade():pos(0.f,0.f){}

Entidade::~Entidade(){};

void Entidade::setPos(CoordF p){pos = p;}

CoordF Entidade::getPos(){return pos;}
