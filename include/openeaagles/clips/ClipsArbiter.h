//------------------------------------------------------------------------------
// Class: Arbiter
//------------------------------------------------------------------------------
#ifndef _CLIPS_ARBITER_H_
#define _CLIPS_ARBITER_H_

#include "openeaagles/basic/Pair.h"
#include "openeaagles/basic/PairStream.h"
#include "openeaagles/basic/Integer.h"
#include "openeaagles/basic/Float.h"

#include "openeaagles/basic/ubf/Behavior.h"
#include "openeaagles/basic/ubf/Arbiter.h"
#include "openeaagles/basic/ubf/Action.h"

#include "openeaagles/xBehaviors/PlaneBehaviors.h"
#include "openeaagles/xBehaviors/PlaneState.h"
#include "openeaagles/xBehaviors/PlaneAction.h"

#include "openeaagles/clips/clips/clips.h"
#include "openeaagles/clips/clips/clipscpp.h"

#include "openeaagles/basic/Factory.h"
#include "openeaagles/lua/Factory.h"
#include "openeaagles/xBehaviors/Factory.h"

namespace Eaagles {

namespace Clips {

//-----------------------------------------------------------------------------------------------
// @class ClipsArbiter
//
// @brief A meta-behavior that generates a "complex action" based on the actions generated our list of behaviors.
//    Object -> Component -> Behavior -> Arbiter -> ClipsArbiter
//
// Note:
//    The default is to select the Action with the highest vote value.
//
// Factory name: ClipsArbiter
// Slots:
//    clipsFileName <String>        Name of the .CLP file
//-----------------------------------------------------------------------------------------------
class ClipsArbiter : public Eaagles::Basic::Ubf::Arbiter
{
   DECLARE_SUBCLASS( ClipsArbiter, Eaagles::Basic::Ubf::Arbiter )

public:
   ClipsArbiter();

   // Basic::Ubf::Behavior class functions
   virtual Basic::Ubf::Action * genAction(const Basic::Ubf::State* const state, const LCreal dt);

protected:
   const Basic::String  * getClipsFileName()    { return clipsFileName; };

   // evaluates a list of actions and return an optional "complex action"
   // (default: returns the action with the highest vote value)
   virtual Basic::Ubf::Action * genComplexAction(Basic::List* const actionSet);

   // clear behavior list
   void clearBehaviors();

   // slot functions
   bool setSlotClipsFileName( Basic::String * const );

   void assertFacts( const Basic::Ubf::State * state );
   void getFacts();

private:

   CLIPSCPPEnv * clipsCppEnv;

   const Basic::String * clipsFileName;

   unsigned int m_behaviorBucket;
   unsigned int m_behaviorNameBucket;
   unsigned int m_removeBucket;
   unsigned int m_optParamsBucket;
   unsigned int m_optPairStreamBucket;

   void trimChangeValidation( Basic::Ubf::Action* const complexAction );
};

} // End Clips namespace
} // End Eaagles namespace

#endif // _CLIPS_ARBITER_H_

