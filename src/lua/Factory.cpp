//------------------------------------------------------------------------------
// Class: Factory
//------------------------------------------------------------------------------
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

