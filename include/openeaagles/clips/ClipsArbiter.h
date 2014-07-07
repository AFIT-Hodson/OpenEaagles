/**
 * @file        ClipsArbiter.h
 * @brief       Declaration of class ClipsArbiter.
 * @details     It interfaces CLIPS in order to allow the creation of an arbiter using CLIPS.
 *
 * @author      Marsil de Athayde Costa e Silva,
 * @author      Instituto Tecnologico de Aeronautica - ITA
 * @author      Laboratorio de Comando e Controle - ITA LAB C2
 * 
 * @date        15/04/2014
 * @version     1.0
 * @pre         
 * @bug         
 * @copyright   Copyright (c) 2014
 *
 */
 
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

/** @class ClipsArbiter
 *  @brief A meta-behavior that generates a "complex action" using CLIPS Expert System.
 *    Object -> Component -> Behavior -> Arbiter -> ClipsArbiter
 * 
 * Factory name: ClipsArbiter
 * Slots:
 *    clipsFileName <String>        Name of the .CLP file
 */
class ClipsArbiter : public Eaagles::Basic::Ubf::Arbiter
{
    DECLARE_SUBCLASS( ClipsArbiter, Eaagles::Basic::Ubf::Arbiter )

public:
    ClipsArbiter();
    
    virtual Basic::Ubf::Action * genAction( const Basic::Ubf::State * const state, const LCreal dt );

protected:
    const Basic::String  * getClipsFileName()    { return clipsFileName; };
    
    /** Evaluates a list of actions and return an optional "complex action"
     * (default: returns the action with the highest vote value) 
     */
    virtual Basic::Ubf::Action * genComplexAction(Basic::List* const actionSet);
    
    // Clear behavior list.
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

