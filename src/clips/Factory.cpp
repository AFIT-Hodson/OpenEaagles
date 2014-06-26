//------------------------------------------------------------------------------
// Class: Factory
//------------------------------------------------------------------------------
#include "Factory.h"
#include "ClipsArbiter.h"

#include "openeaagles/basic/Object.h"
#include "openeaagles/basic/Factory.h"

namespace Eaagles {
namespace Basic{}
namespace Clips {

Factory::Factory()
{}

Basic::Object* Factory::createObj(const char* name)
{
    Basic::Object* obj = 0;

    if ( strcmp(name, ClipsArbiter::getFactoryName()) == 0 )
    {
        obj = new ClipsArbiter();
    }

    if ( obj == 0 )
    {
        obj = xBehaviors::Factory::createObj( name );
    }
    
    if ( obj == 0 )
    {
        obj = Basic::Factory::createObj( name );
    }

    return obj;
}

}  // end namespace Clips
}  // end namespace Eaagles

