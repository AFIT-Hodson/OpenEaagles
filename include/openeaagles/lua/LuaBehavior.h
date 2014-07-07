/**
 * @file        LuaBehavior.h
 * @brief       Declaration of class LuaBehavior.
 * @details     It is used to interface with Lua and allow creation of behaviors in Lua script language.
 *
 * @author      Marsil de Athayde Costa e Silva,
 * @author      Instituto Tecnologico de Aeronautica - ITA
 * @author      Laboratorio de Comando e Controle - ITA LAB C2
 * 
 * @date        30/05/2014
 * @version     1.0
 * @pre         
 * @bug         
 * @copyright   Copyright (c) 2014
 *
 */

#ifndef _LUA_BEHAVIOR_H_
#define _LUA_BEHAVIOR_H_

#include "openeaagles/xBehaviors/PlaneBehaviors.h"
#include "openeaagles/xBehaviors/PlaneAction.h"
#include "openeaagles/xBehaviors/PlaneState.h"

#include "openeaagles/lua/lua-5.2.3/lua.hpp"
#include "openeaagles/lua/lua-5.2.3/luna.h"

#include "openeaagles/lua/LuaState.h"
#include "openeaagles/lua/LuaAction.h"

#include "openeaagles/basic/String.h"
#include "openeaagles/basic/Number.h"
#include "openeaagles/basic/Float.h"
#include "openeaagles/basic/Boolean.h"
#include "openeaagles/basic/Integer.h"
#include "openeaagles/basic/Pair.h"
#include "openeaagles/basic/PairStream.h"

#include <vector>

namespace Eaagles {

namespace Lua {

const int TYPE_FLOAT = 0;
const int TYPE_CHAR  = 1;
const int TYPE_INT   = 2;
const int TYPE_BOOL  = 3;

/** @class LuaBehavior
 *  @brief Behavior class to handle a Lua behavior script.
 */
class LuaBehavior : public Eaagles::xBehaviors::PlaneBehaviorBase
{
    DECLARE_SUBCLASS(LuaBehavior, Eaagles::xBehaviors::PlaneBehaviorBase)
public:
    LuaBehavior();
    bool LoadFile();

    Basic::Ubf::Action* genAction(const Basic::Ubf::State* const state, const LCreal dt);
    
    char * getLuaFileName(){ return luaFileName; };
    void setLuaFileName( char * str ){ luaFileName = str; };
    bool setSlotLuaFileName( Basic::String * const );

    char * getLuaFunctionName(){ return luaFunctionName; };
    void setLuaFunctionName( char * str ){ luaFunctionName = str; };
    bool setSlotLuaFunctionName( Basic::String * const );
    
    Basic::PairStream * getLuaParams(){ return luaParams; };
    bool setSlotLuaParams( Basic::PairStream * const );

private:
    char * luaFileName;
    char * luaFunctionName;
    
    /** 
     * @property luaParams
     * @brief This is intended to allow user to create functions with any number of input parameter.
     * The parameters should be set in the EPP file by setting the identifier to float, char, int or bool. For example:
     * float: 1.0
     */
    Basic::PairStream * luaParams;
    lua_State   * m_lua_State;
    std::vector<char> luaParamsTypes;
};

}// End namespace Lua
}// End namespace Eaagles
#endif
