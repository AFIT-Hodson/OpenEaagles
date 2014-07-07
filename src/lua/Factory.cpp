/**
 * @file        Factory.cpp
 * @brief       Implementation of class Eaagles::Lua::Factory.
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

#include "openeaagles/basic/Object.h"
#include "openeaagles/basic/Factory.h"

#include "LuaBehavior.h"

namespace Eaagles {
namespace Lua {

Factory::Factory()
{}

Basic::Object* Factory::createObj(const char* name)
{
    Basic::Object* obj = 0;

    if ( strcmp(name, LuaBehavior::getFactoryName()) == 0 )
    {
        obj = new LuaBehavior();
    }
    else if ( strcmp(name, LuaState::getFactoryName()) == 0 )
    {
        obj = new LuaState();
    }

    return obj;
}

}  // end namespace Clips
}  // end namespace Eaagles

