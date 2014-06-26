/**
 * @file  LuaAction.h
 * @brief  Declaration of class LuaAction.
 *
 * @author  Marsil,
 *
 * @internal
 * Created  30/05/2014
 * Revision  $Id
 * Compiler  gcc/g++
 * Company  
 * Copyright  Copyright (c) 2014, 
 *
 */

#ifndef _LUA_ACTION_H
#define _LUA_ACTION_H

#include "openeaagles/lua/lua-5.2.3/lua.hpp"
#include "openeaagles/lua/lua-5.2.3/luna.h"

#include "openeaagles/xBehaviors/PlaneAction.h"

namespace Eaagles {

namespace xBehaviors {
    class PlaneAction;
}

namespace Lua {
/**
 * @brief
 */

class LuaAction : public Eaagles::xBehaviors::PlaneAction
{
    DECLARE_SUBCLASS(LuaAction, Eaagles::xBehaviors::PlaneAction)
public:
    static const char * className;
    static const Luna<Eaagles::Lua::LuaAction>::FunctionType methods[];
    static const Luna<Eaagles::Lua::LuaAction>::PropertyType properties[];
    LuaAction();
    LuaAction( lua_State * l );

    // properties
    int setRoll( lua_State * l );
    int getRoll( lua_State * l );
    
    int setPitch( lua_State * l );
    int getPitch( lua_State * l );
    
    int setHeading( lua_State * l );
    int getHeading( lua_State * l );
    
    int setThrottle( lua_State * l );
    int getThrottle( lua_State * l );
    
    //int setSpeed( lua_State * l );
    //int getSpeed( lua_State * l );
    
    int setPitchTrim( lua_State * l );
    int getPitchTrim( lua_State * l );
    
    int setFireMissile( lua_State * l );
    int getFireMissile( lua_State * l );
};

}// End namespace Lua
}// End namespace Eaagles
#endif  //_LUA_ACTION_H
