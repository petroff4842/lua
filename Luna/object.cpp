#include "object.h"

GameObject::GameObject( int x )
{
	attribute = x;
}

int GameObject::getAttr()
{
	return ( int )attribute;
}

void GameObject::setAttr( int set )
{
	attribute = set;
}

void GameObject::setMessage( const char* new_message )
{
	message.assign( new_message );
}

const char* GameObject::getMessage()
{
	return message.c_str();
}

GameObject::~GameObject()
{
	printf( "deleted Object (%p)\n", this );
}


GameObject2::GameObject2( int x )
{
	attribute = x;
}

int GameObject2::getAttr()
{
	return ( int )attribute;
}

void GameObject2::setAttr( int set )
{
	attribute = set;
}

void GameObject2::setMessage( const char* new_message )
{
	message.assign( new_message );
}

const char* GameObject2::getMessage()
{
	return message.c_str();
}

GameObject2::~GameObject2()
{
	printf( "deleted Object2 (%p)\n", this );
}