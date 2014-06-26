//------------------------------------------------------------------------------
// Class: Factory
//
// Description: Class factory
//------------------------------------------------------------------------------
#ifndef _CLIPS_FACTORY_H_
#define _CLIPS_FACTORY_H_

namespace Eaagles {

namespace Basic { 
class Object;
}

namespace Clips {

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
