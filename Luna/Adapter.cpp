#include "Adapter.h"

LuaWriterObject::LuaWriterObject(lua_State * L)
{
	
}

LuaWriterObject::~LuaWriterObject()
{
	
}

int LuaWriterObject::Open(lua_State * L)
{
	return 0;
}

int LuaWriterObject::Write(lua_State * L)
{
	return 0;
}

int LuaWriterObject::Close(lua_State * L)
{
	return 0;
}

LuaReaderObject::LuaReaderObject(lua_State * L)
{
}

LuaReaderObject::~LuaReaderObject()
{
}

int LuaReaderObject::Open(lua_State * L)
{
	return 0;
}

int LuaReaderObject::Read(lua_State * L)
{
	return 0;
}

int LuaReaderObject::Close(lua_State * L)
{
	return 0;
}
