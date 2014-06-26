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
namespace Basic {
namespace Ubf {
    class Action;
    class Behabior;
}
}
namespace xBehaviors {
    class PlaneBehaviorBase;
    class PlaneAction;
    class PlaneState;
}
namespace Lua {
#define TYPE_FLOAT      0
#define TYPE_CHAR       1
#define TYPE_INT        2
#define TYPE_BOOL       3

//------------------------------------------------------------------------------
// Class: LuaBehavior
//
// Description: Behavior class to handle a Lua behavior script
//------------------------------------------------------------------------------
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
    Basic::PairStream * luaParams;
    lua_State   * m_lua_State;
    std::vector<char> luaParamsTypes;
};

}// End namespace Lua
}// End namespace Eaagles
#endif
