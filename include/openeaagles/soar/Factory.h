//------------------------------------------------------------------------------
// Class: Factory
//
// Description: Class factory
//------------------------------------------------------------------------------
#ifndef _SOAR_FACTORY_H_
#define _SOAR_FACTORY_H_

namespace Eaagles {

namespace Basic { 
class Object;
}

namespace Soar {

class Factory
{
public:
   static Basic::Object* createObj(const char* name);

protected:
   Factory();   // prevent object creation
};

}  // end namespace Soar
}  // end namespace Eaagles

#endif
