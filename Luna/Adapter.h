
#include "Writer.h"
#include "luna.h"

class LuaReaderObject
{
public:
	static const char className[];
	static Luna<LuaReaderObject>::RegType methods[];

	LuaReaderObject(lua_State *L);

	~LuaReaderObject();

	int Open(lua_State *L);

	int Read(lua_State *L);

	int Close(lua_State *L);

};

class LuaWriterObject
{
public:
	static const char className[];
	static Luna<LuaWriterObject>::RegType methods[];

	LuaWriterObject(lua_State *L);
	~LuaWriterObject();

	int Open(lua_State *L);
	int Write(lua_State *L);
	int Close(lua_State *L);
};

