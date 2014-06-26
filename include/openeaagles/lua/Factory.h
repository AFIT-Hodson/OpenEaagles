//------------------------------------------------------------------------------
// Class: Factory
//
// Description: Class factory
//------------------------------------------------------------------------------
#ifndef _LUA_FACTORY_H_
#define _LUA_FACTORY_H_

namespace Eaagles {

namespace Basic { 
class Object;
}

namespace Lua {

class Factory
{
public:
   static Basic::Object* createObj(const char* name);

protected:
   Factory();   // prevent object creation
};

}  // end namespace Lua
}  // end namespace Eaagles

#endif