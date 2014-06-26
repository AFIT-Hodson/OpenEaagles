//------------------------------------------------------------------------------
// Class: PlaneAction
//------------------------------------------------------------------------------

#include "PlaneAction.h"

#include "openeaagles/simulation/AirVehicle.h"
#include "openeaagles/simulation/StoresMgr.h"

namespace Eaagles {
namespace xBehaviors {

IMPLEMENT_SUBCLASS(PlaneAction, "PlaneAction")
EMPTY_SLOTTABLE(PlaneAction)
EMPTY_DELETEDATA(PlaneAction)
EMPTY_SERIALIZER(PlaneAction)

PlaneAction::PlaneAction()
{
   STANDARD_CONSTRUCTOR()

   pitch = 0;
   pitchChanged = false;

   roll = 0;
   rollChanged = false;

   heading = 0;
   headingChanged = false;

   yaw = 0;
   yawChanged = false;

   throttle = 0;
   throttleChanged = false;

   speed = 0;
   speedChanged = false;

   pitchTrim = 0;
   pitchTrimChanged = false;
   fireMissile = false;
   fireMissileChanged = false;
}

void PlaneAction::copyData(const PlaneAction& org, const bool cc)
{
   BaseClass::copyData(org);
   heading = org.heading;
   headingChanged = org.headingChanged;

   pitch = org.pitch;
   pitchChanged = org.pitchChanged;

   roll = org.roll;
   rollChanged = org.rollChanged;

   fireMissile = org.fireMissile;
   fireMissileChanged = org.fireMissileChanged;

   throttle = org.throttle;
   throttleChanged = org.throttleChanged;

   pitchTrim = org.pitchTrim;
   pitchTrimChanged = org.pitchTrimChanged;
}

void PlaneAction::setPitch(const double x)
{
   pitch = x;
   pitchChanged = true;
}

void PlaneAction::setRoll(const double x)
{
   roll = x;
   rollChanged = true;
}

void PlaneAction::setHeading(const double x)
{
   heading = x;
   headingChanged = true;
}

void PlaneAction::setThrottle(const double x)
{
   throttle = x;
   throttleChanged = true;
}

void PlaneAction::setFireMissile(const bool x)
{
   fireMissile = x;
   fireMissileChanged = true;
}

void PlaneAction::setPitchTrim(const double x)
{
   pitchTrim = x;
   pitchTrimChanged = true;
}

bool PlaneAction::execute(Basic::Component* actor)
{
   Simulation::AirVehicle* airVehicle = dynamic_cast<Simulation::AirVehicle*>(actor);
   if (airVehicle != 0) {
      airVehicle->setControlStick((LCreal)getRoll(), (LCreal)getPitch());

      // set throttle to engines(assuming there are 8 or less)
      LCreal throttles[8];
      for(int i = 0 ; i < airVehicle->getNumberOfEngines() ; i++) {
         throttles[i] = (LCreal)getThrottle();
      }
      if (isThrottleChanged()) {
         airVehicle->setThrottles(throttles,2);
      }
      if(isPitchTrimChanged()) {
         airVehicle->setTrimSwitch(0, (LCreal)getPitchTrim());
      }
      
	  //------------------------------------
      if( isHeadingChanged() )
	  {
		  airVehicle -> setCommandedHeading( getHeading() );
	  }

      if (getFireMissile()) {
         // this should be an action generated by a behavior
         // Set weapons to anti-aircraft mode.
         Simulation::StoresMgr* sms = airVehicle->getStoresManagement();
         if (sms != 0) {
            sms->setWeaponDeliveryMode(Simulation::StoresMgr::A2A);
            std::cout << "Set A/A Weapon Mode!" << std::endl;

            airVehicle->event(Eaagles::Basic::Component::WPN_REL_EVENT);
            //WPN_REL_EVENT         = 1405,  // Passes requested switch state as Boolean
                                          // or no argument for one-shot event
            std::cout << "Launched A/A Weapon !" << std::endl;
         }
      }
      return true;
   }
   return false;
}

}
}

