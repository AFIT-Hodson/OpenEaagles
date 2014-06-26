
#include "openeaagles/lua/LuaBehavior.h"

namespace Eaagles {
namespace Lua {
//----------------------------------------------------------------
// LuaBehavior
//----------------------------------------------------------------
IMPLEMENT_SUBCLASS(LuaBehavior, "LuaBehavior")
EMPTY_COPYDATA(LuaBehavior)
EMPTY_SERIALIZER(LuaBehavior)

BEGIN_SLOTTABLE(LuaBehavior)
   "luaFileName",                   //  1) luaFileName
   "luaFunctionName",               //  2) luaFunctionName
   "optPairStream"                  //  3) luaParams
END_SLOTTABLE(LuaBehavior)

//  mapping of slots to handles
BEGIN_SLOT_MAP(LuaBehavior)
   ON_SLOT(1, setSlotLuaFileName,       Basic::String)
   ON_SLOT(2, setSlotLuaFunctionName,   Basic::String)
   ON_SLOT(3, setSlotLuaParams,         Basic::PairStream)
END_SLOT_MAP()

LuaBehavior::LuaBehavior()
{
    STANDARD_CONSTRUCTOR()
    
    m_lua_State = luaL_newstate();
    luaL_openlibs   ( m_lua_State );
    luaopen_base    ( m_lua_State );
    luaopen_math    ( m_lua_State );

    luaParams = 0;

    Luna<Eaagles::Lua::LuaState>::Register( m_lua_State );
    Luna<Eaagles::Lua::LuaAction>::Register( m_lua_State );

}

bool LuaBehavior::LoadFile()
{
    int erred = luaL_dofile( m_lua_State, getLuaFileName() );
    if( erred )
    {
        std::cout << "Lua error: " << luaL_checkstring( m_lua_State, -1 ) << std::endl;
        return false;
    }
    return true;
}

Basic::Object* LuaBehavior::getSlotByIndex(const int si)
{
   return BaseClass::getSlotByIndex(si);
}

bool LuaBehavior::setSlotLuaFileName( Basic::String * const x )
{
    if ( x != 0)
    {
        luaFileName = x -> getCopyString();
        LoadFile();
    }
    return true;
}

bool LuaBehavior::setSlotLuaFunctionName( Basic::String * const x )
{
    if ( x != 0)
    {
        luaFunctionName = x -> getCopyString();
    }
    return true;
}
bool LuaBehavior::setSlotLuaParams( Basic::PairStream * const x)
{
    if ( x != 0 )
    {
        luaParams = x -> clone();    
        Basic::List::Item* item = luaParams -> getFirstItem();
        while ( item != 0 )
        {
            Basic::Pair* pair = static_cast<Basic::Pair*>( item->getValue() );
        
            if( std::strcmp( pair -> slot() -> getString() , "float" ) == 0 )
            {
                luaParamsTypes.push_back( TYPE_FLOAT );
            }
            else if( std::strcmp( pair -> slot() -> getString() , "char" ) == 0 )
            {
                luaParamsTypes.push_back( TYPE_CHAR );
            }
            else if( std::strcmp( pair -> slot() -> getString() , "int" ) == 0 )
            {
                luaParamsTypes.push_back( TYPE_INT );
            }
            else if( std::strcmp( pair -> slot() -> getString() , "bool" ) == 0 )
            {
                luaParamsTypes.push_back( TYPE_BOOL );
            }

            item = item -> getNext();
        }
    }

    return true;
}

Basic::Ubf::Action* LuaBehavior::genAction(const Basic::Ubf::State* const state, const LCreal dt)
{
    Eaagles::xBehaviors::PlaneAction* action = 0;
    const Eaagles::xBehaviors::PlaneState* pState = dynamic_cast<const Eaagles::xBehaviors::PlaneState*>(state->getUbfStateByType(typeid(Eaagles::xBehaviors::PlaneState)));
    
    if (pState!=0)
    {
        action = new Eaagles::xBehaviors::PlaneAction();

        LuaState * l_luaState = new LuaState( pState );
        
        lua_getglobal( m_lua_State, getLuaFunctionName() );
        Luna<Eaagles::Lua::LuaState>::push( m_lua_State, l_luaState );

        int i = 0;
        if( luaParams != 0 )
        {
            Basic::List::Item* item = luaParams -> getFirstItem();
            while ( item != 0 )
            {
                Basic::Pair* pair = static_cast<Basic::Pair*>( item->getValue() );
                
                switch( luaParamsTypes.at( i ) )
                {
                    case TYPE_FLOAT:
                    {
                        lua_pushnumber( m_lua_State, ( (Basic::Float*) pair -> object() ) -> getFloat() );
                        break;
                    }
                    case TYPE_INT:
                    {
                        lua_pushinteger( m_lua_State, ( (Basic::Integer*) pair -> object() ) -> getInt() );
                        break;
                    }
                    case TYPE_CHAR:
                    {
                        lua_pushstring( m_lua_State, ( (Basic::String*) pair -> object() ) -> getString() );
                        break;
                    }
                    case TYPE_BOOL:
                    {
                        lua_pushboolean( m_lua_State, ( (Basic::Boolean*) pair -> object() ) -> getBoolean() );
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                item = item->getNext();
                i++;
            }
        }

        lua_pcall( m_lua_State, i+1, 1, 0 );
        action = (Eaagles::xBehaviors::PlaneAction*) Luna<Eaagles::Lua::LuaAction>::check( m_lua_State, -1 );

        action -> setVote( getVote() );
    }
    return action;
}

void LuaBehavior::deleteData()
{
    lua_close( m_lua_State );
}

}// End namespace Lua
}// End namespace Eaagles
