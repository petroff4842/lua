/**
* Main program to actually run the Lua code against the C++ object
*/
#include "object.h"
#include "luaobject.h"
#include "Adapter.h"
#include "Writer.h" 

// Define the Lua ClassName
const char LuaGameObject::className[] = "LuaGameObject";
//const char LuaReaderObject::className[] = "Reader";

const char LuaWriterObject::className[] = "Writer";

//#define method(class, name) {#name, &class::name}
//Luna<LuaReaderObject>::RegType LuaReaderObject::methods[] = {
//	method(LuaReaderObject, Open),
//	method(LuaReaderObject, Read),
//	method(LuaReaderObject, Close),
//	{ 0,0 }
//};

#define method(class, name) {#name, &class::name}
Luna<LuaWriterObject>::RegType LuaWriterObject::methods[] = {
	method(LuaWriterObject, Open),
	method(LuaWriterObject, Write),
	method(LuaWriterObject, Close),
	{ 0,0 }
};
// Define the methods we will expose to Lua
// Check luaobject.h for the definitions...
#define method(class, name) {#name, &class::name}
Luna<LuaGameObject>::RegType LuaGameObject::methods[] = {
	method( LuaGameObject, setAttr ),
	method( LuaGameObject, getAttr ),
	method( LuaGameObject, getMessage ),
	method( LuaGameObject, setMessage ),
	method( LuaGameObject, setGO2 ),
	method( LuaGameObject, getPP ),
	//method( LuaGameObject, create ),
	{ 0,0 }
};


class Account
{
	lua_Number m_balance;
public:
	static const char className[];
	static Luna<Account>::RegType methods[];

	Account( lua_State *L )
	{
		m_balance = luaL_checknumber( L, 1 );
	}
	int deposit( lua_State *L )
	{
		m_balance += luaL_checknumber( L, 1 ); return 0;
	}
	int withdraw( lua_State *L )
	{
		m_balance -= luaL_checknumber( L, 1 ); return 0;
	}
	int balance( lua_State *L )
	{
		lua_pushnumber( L, m_balance ); return 1;
	}
	~Account()
	{
		printf( "deleted Account (%p)\n", this );
	}
};

const char Account::className[] = "Account";

#define method(class, name) {#name, &class::name}

Luna<Account>::RegType Account::methods[] = {
	method( Account, deposit ),
	method( Account, withdraw ),
	method( Account, balance ),
	{ 0,0 }
};

#define USE_TWO 1


int main( int argc, char *argv[] )
{
	lua_State *L = lua_open();

	luaopen_base( L );
	luaopen_table( L );
	luaopen_io( L );
	luaopen_string( L );
	luaopen_math( L );
	luaopen_debug( L );

#if USE_TWO == 1
	
//	Luna<Account>::Register( L );
	Luna<LuaWriterObject>::Register(L);
	
	//lua_dofile( L, "account.lua" );
	lua_dofile(L, "App.lua");
	lua_setgcthreshold( L, 0 );  // collected garbage
	lua_close( L );

	

#else
	 Init Lua

	 Register the LuaGameObject data type with Lua
	Luna<LuaGameObject>::Register( L );

	// In C++ - Create a GameObject for use in our program
	GameObject temp( 20 );
	temp.setMessage( "I'm set in C++" );

	// Push a pointer to this GameObject to the Lua stack
	lua_pushlightuserdata( L, ( void* )&temp );
	// And set the global name of this pointer
	lua_setglobal( L, "gameobject" );

	printf( "In C: %p => %d, %s\n", &temp, temp.getAttr(), temp.getMessage() );

	printf( "Loading lua----------\n" );
	luaL_loadfile( L, "gameobject.lua" );
	printf( "lua is loaded--------\n" );

	printf( "Running lua----------\n" );
	lua_pcall( L, 0, 0, 0 );
	lua_dofile( L, "gameobject.lua" );
	printf( "Lua is done----------\n" );
	//lua_setgcthreshold(L, 0);  // collected garbage

	//luaL_loadfile( L, "gameobject.lua" );
	//printf( "Running lua2---------\n" );
	//lua_pcall( L, 0, 0, 0 );
	//printf( "Lua is done2---------\n" );

	// GC + Close out Lua
	lua_close( L );

	//printf( "In C++: %p => %d, %s\n", &temp, temp.getAttr(), temp.getMessage() );
#endif
//	Writer w;
//	w.Open("test.txt");
//	w.Write();
//	w.Close();
	return 0;
}