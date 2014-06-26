/**
 * @file  LuaState.cpp
 * @brief  Declaration of class PlaneAction.
 *
 * @author   (),
 *
 * @internal
 * Created  30/05/2014
 * Revision  $Id
 * Compiler  gcc/g++
 * Company  
 * Copyright  Copyright (c) 2014, 
 *
 */

#include "openeaagles/lua/LuaState.h"

namespace Eaagles {
namespace Lua {
    
IMPLEMENT_ABSTRACT_SUBCLASS(LuaState, "LuaState")
EMPTY_COPYDATA(LuaState)
EMPTY_SERIALIZER(LuaState)
EMPTY_SLOTTABLE(LuaState)
EMPTY_DELETEDATA(LuaState)

const char * Eaagles::Lua::LuaState::className = "LuaState";                 
const Luna<Eaagles::Lua::LuaState>::FunctionType Eaagles::Lua::LuaState::methods[] =      
{
    { "getPitchToTracked",      &getPitchToTracked      },
    { "getPitchToTracked",      &getPitchToTracked      },
    { "getHeadingToTracked",    &getHeadingToTracked    },
    { "getDistanceToTracked",   &getDistanceToTracked   },
    {NULL, NULL}
};                                                      
                                                        
const Luna<Eaagles::Lua::LuaState>::PropertyType Eaagles::Lua::LuaState::properties[] =   
{
    { "roll",               &getRoll,           NULL },
    { "pitch",              &getPitch,          NULL },
    { "heading",            &getHeading,        NULL },
    { "rollrate",           &getRollRate,       NULL },
    { "pitchrate",          &getPitchRate,      NULL },
    { "yawrate",            &getYawRate,        NULL },
    { "altitude",           &getAltitude,       NULL },
    { "throttle",           &getThrottle,       NULL },
    { "speed",              &getSpeed,          NULL },
    { "pitchtrim",          &getPitchTrim,      NULL },
    { "numtracks",          &getNumTracks,      NULL },
    { "targettrack",        &getTargetTrack,    NULL },
    { "numengines",         &getNumEngines,     NULL },

    { "isAlive",            &isAlive,           NULL },
    { "isIncomingMissile",  &isIncomingMissile, NULL },
    { "isTracking",         &isTracking,        NULL },
    { "isMissileFired",     &isMissileFired,    NULL },
    
    { NULL, NULL, NULL }
};

LuaState::LuaState( lua_State * l )
{

}

LuaState::LuaState( const PlaneState * pState )
{
    setAlive            ( pState -> isAlive( )          );
    setRoll             ( pState -> getRoll( )          );
    setPitch            ( pState -> getPitch( )         );
    setHeading          ( pState -> getHeading( )       );
    setRollRate         ( pState -> getRollRate( )      );
    setPitchRate        ( pState -> getPitchRate( )     );
    setYawRate          ( pState -> getYawRate( )       );
    setAltitude         ( pState -> getAltitude( )      );
    setThrottle         ( pState -> getThrottle( )      );
    setSpeed            ( pState -> getSpeed( )         );
    setPitchTrim        ( pState -> getPitchTrim( )     );
    setNumTracks        ( pState -> getNumTracks( )     );
    setTargetTrack      ( pState -> getTargetTrack( )   );
    setNumEngines       ( pState -> getNumEngines( )    );
    setTracking         ( pState -> isTracking( )       );
    setIncomingMissile  ( pState -> isIncomingMissile( ) );
    setMissileFired     ( pState -> isMissileFired( ) );

    unsigned int a = pState -> getTargetTrack();
    if( a < PlaneState::MAX_TRACKS )
    {
        setDistanceToTracked( a, pState -> getDistanceToTracked( a ) );
        setHeadingToTracked( a, pState -> getHeadingToTracked( a ) );
        setPitchToTracked( a, pState -> getPitchToTracked( a ) );
    }
}

int LuaState::getRoll( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getRoll() );
    return 1;
}

int LuaState::getPitch( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getPitch() );
    return 1;
}

int LuaState::getHeading( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getHeading() );
    return 1;
}

int LuaState::getRollRate( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getRollRate() );
    return 1;
}

int LuaState::getPitchRate( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getPitchRate() );
    return 1;
}

int LuaState::getYawRate( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getYawRate() );
    return 1;
}

int LuaState::getAltitude( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getAltitude() );
    return 1;
}

int LuaState::getThrottle( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getThrottle() );
    return 1;
}

int LuaState::getSpeed( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getSpeed() );
    return 1;
}

int LuaState::getPitchTrim( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getPitchTrim() );
    return 1;
}

int LuaState::getNumTracks( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getNumTracks() );
    return 1;
}

int LuaState::getTargetTrack( lua_State * l )
{
    lua_pushinteger( l, BaseClass::getTargetTrack() );
    return 1;
}

int LuaState::getNumEngines( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getNumEngines() );
    return 1;
}

int LuaState::isAlive( lua_State * l )
{
    lua_pushboolean( l, BaseClass::isAlive() );
    return 1;
}

int LuaState::isIncomingMissile( lua_State * l )
{
    lua_pushboolean( l, BaseClass::isIncomingMissile() );
    return 1;
}

int LuaState::isTracking( lua_State * l )
{
    lua_pushboolean( l, BaseClass::isTracking() );
    return 1;
}

int LuaState::isMissileFired( lua_State * l )
{
    lua_pushboolean( l, BaseClass::isMissileFired() );
    return 1;
}

int LuaState::getPitchToTracked( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getPitchToTracked( luaL_checkinteger( l, -1 ) ) );
    return 1;
}

int LuaState::getHeadingToTracked( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getHeadingToTracked( luaL_checkinteger( l, -1 ) ) );
    return 1;
}

int LuaState::getDistanceToTracked( lua_State * l )
{
    lua_pushnumber( l, BaseClass::getDistanceToTracked( luaL_checkinteger( l, -1 ) ) );
    return 1;
}

}// End namespace Lua
}// End namespace Eaagles
