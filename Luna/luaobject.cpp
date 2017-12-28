#include "luaobject.h"

LuaGameObject::LuaGameObject( lua_State *L )
{
	lua_Number num = lua_tonumber( L, 1 );
	real_object = new GameObject( num );// ( GameObject* )lua_touserdata( L, 1 );
}


//int LuaGameObject::create( lua_State *L )
//{
//	real_object = ( GameObject* )lua_touserdata( L, 1 );
//}

void LuaGameObject::setObject( lua_State *L )
{
	real_object = ( GameObject* )lua_touserdata( L, 1 );
}

int LuaGameObject::setAttr( lua_State *L )
{
	real_object->setAttr( ( int )luaL_checknumber( L, 1 ) );
	return 0;
}
int LuaGameObject::getAttr( lua_State *L )
{
	lua_pushnumber( L, real_object->getAttr() );
	return 1;
}

int LuaGameObject::setMessage( lua_State *L )
{
	real_object->setMessage( lua_tostring( L, 1 ) );
	return 0;
}
int LuaGameObject::getMessage( lua_State *L )
{
	lua_pushstring( L, real_object->getMessage() );
	return 1;
}


int LuaGameObject::setGO2( lua_State *L )
{
	real_object->setGO2( ( GameObject2* )lua_touserdata( L, 1 ) );
	return 0;
}

int LuaGameObject::getPP( lua_State *L )
{
	return 1;
}


LuaGameObject::~LuaGameObject()
{
	printf( "deleted Lua Object (%p)\n", this );
}
