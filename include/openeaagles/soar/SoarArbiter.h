/**
 * @file        SoarArbiter.h
 * @brief       Declaration of class SoarArbiter.
 * @details     It is an arbiter that uses Soar to generate actions.
 *
 * @author      Marsil de Athayde Costa e Silva,
 * @author      Instituto Tecnologico de Aeronautica - ITA
 * @author      Laboratorio de Comando e Controle - ITA LAB C2
 * 
 * @date        13/06/2014
 * @version     1.0
 * @pre         
 * @bug         
 * @copyright   Copyright (c) 2014
 *
 */
#ifndef _SOAR_ARBITER_H_
#define _SOAR_ARBITER_H_

#include "soar/sml_Client.h"

#include "openeaagles/basic/Pair.h"
#include "openeaagles/basic/PairStream.h"
#include "openeaagles/basic/List.h"
#include "openeaagles/basic/String.h"
#include "openeaagles/basic/Number.h"
#include "openeaagles/basic/Integer.h"
#include "openeaagles/basic/Float.h"

#include "openeaagles/basic/ubf/Action.h"
#include "openeaagles/basic/ubf/Arbiter.h"
#include "openeaagles/basic/ubf/State.h"

#include "openeaagles/xbehaviors/PlaneAction.h"

#include "openeaagles/xbehaviors/Factory.h"
#include "openeaagles/lua/Factory.h"

#include "openeaagles/soar/SoarState.h"

namespace Eaagles {

namespace Soar {
using namespace sml;

/** @class SoarArbiter
 *  @brief A meta-behavior that generates a "complex action" using Soar Cognitive Architecture.
 *    Object -> Component -> Behavior -> Arbiter -> SoarArbiter
 * 
 * Factory name: SoarArbiter
 * Slots:
 *    soarFileName <String>        Name of the .soar file
 */
class SoarArbiter : public Eaagles::Basic::Ubf::Arbiter
{
    DECLARE_SUBCLASS(SoarArbiter, Eaagles::Basic::Ubf::Arbiter)
public:
    SoarArbiter();
    
    Basic::Ubf::Action * genAction( const Basic::Ubf::State* const state, const LCreal dt );
    Basic::Ubf::Action * genComplexAction( Basic::List* const actionSet );
    void trimChangeValidation( Basic::Ubf::Action * const complexAction );

    void Commit( const Basic::Ubf::State * const state );
    void Run();
    void Retrieve();

protected:
    void initSoar();

    const Basic::String  * getSoarFileName()    { return soarFileName; };
    // slot functions
    bool setSlotSoarFileName( Basic::String * const );

private:
    Kernel      * m_Kernel;
    sml::Agent  * m_smlAgent;
    SoarState   * m_soarState;
    
    sml::Identifier * m_inputLink;
    sml::Identifier * m_ID;

    const Basic::String * soarFileName;
};

}// End namespace Soar
}// End namespace Eaagles
#endif  //_SOAR_ARBITER_H_
