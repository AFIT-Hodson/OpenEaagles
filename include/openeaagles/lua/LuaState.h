/**
 * @file  LuaState.h
 * @brief  Declaration of class LuaState.
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

#ifndef _LUA_STATE_H
#define _LUA_STATE_H

#include "openeaagles/lua/lua-5.2.3/lua.hpp"
#include "openeaagles/lua/lua-5.2.3/luna.h"

#include "openeaagles/xBehaviors/PlaneState.h"

namespace Eaagles {

namespace xBehaviors {
    class PlaneState;
}

namespace Lua {
/**
 * @brief
 */

class LuaState : public Eaagles::xBehaviors::PlaneState
{
    DECLARE_SUBCLASS(LuaState, Eaagles::xBehaviors::PlaneState)
public:
    static const char * className;
    static const Luna<Eaagles::Lua::LuaState>::FunctionType methods[];
    static const Luna<Eaagles::Lua::LuaState>::PropertyType properties[];
    LuaState(){};
    LuaState( lua_State * l );
    LuaState( const PlaneState * pState );

    // properties
    int getRoll( lua_State * l );
    int getPitch( lua_State * l );
    int getHeading( lua_State * l );
    int getRollRate( lua_State * l );
    int getPitchRate( lua_State * l );
    int getYawRate( lua_State * l );
    int getAltitude( lua_State * l );
    int getThrottle( lua_State * l );
    int getSpeed( lua_State * l );
    int getPitchTrim( lua_State * l );
    int getNumTracks( lua_State * l );
    int getTargetTrack( lua_State * l );
    int getNumEngines( lua_State * l );

    int isAlive( lua_State * l );
    int isTracking( lua_State * l );
    int isMissileFired( lua_State * l );
    int isIncomingMissile( lua_State * l );
    
    // methods
    int getPitchToTracked( lua_State * l );
    int getHeadingToTracked( lua_State * l );
    int getDistanceToTracked( lua_State * l );
};

}// End namespace Lua
}// End namespace Eaagles
#endif  //_LUA_STATE_H
