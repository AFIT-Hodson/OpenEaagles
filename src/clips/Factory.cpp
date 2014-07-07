/**
 * @file        Factory.cpp
 * @brief       Implementation of class Eaagles::Clips::Factory.
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
 */
#include "Factory.h"
#include "ClipsArbiter.h"

#include "openeaagles/basic/Object.h"
#include "openeaagles/basic/Factory.h"

namespace Eaagles {
namespace Basic{}
namespace Clips {

Factory::Factory()
{}

Basic::Object* Factory::createObj(const char* name)
{
    Basic::Object* obj = 0;

    if ( strcmp(name, ClipsArbiter::getFactoryName()) == 0 )
    {
        obj = new ClipsArbiter();
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

