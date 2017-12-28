#include "Writer.h"


void Writer::Open(const char * file)
{
	m_of.open(file);
}

void Writer::Close()
{
	m_of.close();
}

void Writer::Write()
{
	m_of << "123";
}
