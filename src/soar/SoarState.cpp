/**
 * @file  SoarState.cpp
 * @brief  Declaration of class SoarState.
 *
 * @author   (),
 *
 * @internal
 * Created  13/06/2014
 * Revision  $Id
 * Compiler  msvc
 * Company  
 * Copyright  Copyright (c) 2014, 
 *
 */

#include "openeaagles/soar/SoarState.h"

namespace Eaagles {
namespace Soar {
    
IMPLEMENT_SUBCLASS(SoarState, "SoarState")
EMPTY_COPYDATA(SoarState)
EMPTY_SERIALIZER(SoarState)
EMPTY_SLOTTABLE(SoarState)
EMPTY_DELETEDATA(SoarState)

SoarState::SoarState()
{
    
}
SoarState::SoarState( sml::Agent * agent )
{
    setAgent( agent );
}

}
}