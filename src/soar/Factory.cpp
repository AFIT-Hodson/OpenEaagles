//------------------------------------------------------------------------------
// Class: Factory
//------------------------------------------------------------------------------
#include "openeaagles/soar/Factory.h"
#include "openeaagles/soar/SoarArbiter.h"

#include "openeaagles/basic/Object.h"
#include "openeaagles/basic/Factory.h"

namespace Eaagles {
namespace Soar {

Factory::Factory()
{}

Basic::Object* Factory::createObj(const char* name)
{
    Basic::Object* obj = 0;

    if ( strcmp(name, SoarArbiter::getFactoryName()) == 0 )
    {
        obj = new SoarArbiter();
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

