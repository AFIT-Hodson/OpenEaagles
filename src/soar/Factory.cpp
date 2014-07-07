/**
 * @file        Factory.cpp
 * @brief       Implementation of class Eaagles::Soar::Factory.
 * @details     
 *
 * @author      Marsil de Athayde Costa e Silva,
 * @author      Instituto Tecnologico de Aeronautica - ITA
 * @author      Laboratorio de Comando e Controle - ITA LAB C2
 * 
 * @date        15/04/2014
 * @version     1.0
 * @pre         
 * @bug         
 * @copyright   Copyright (c) 2014
 *
 */#include "openeaagles/soar/Factory.h"
#include "openeaagles/soar/SoarArbiter.h"

#include "openeaagles/basic/Object.h"
#include "openeaagles/basic/Factory.h"

namespace Eaagles {
namespace Soar {

Factory::Factory()
{}

Basic::Object* Factory::createObj(const char* name)
{
    Basic::Object* obj = 0;

    if ( strcmp(name, SoarArbiter::getFactoryName()) == 0 )
    {
        obj = new SoarArbiter();
    }

    if ( obj == 0 )
    {
        obj = xBehaviors::Factory::createObj( name );
    }
    
    if ( obj == 0 )
    {
        obj = Basic::Factory::createObj( name );
    }

    return obj;
}

}  // end namespace Clips
}  // end namespace Eaagles

