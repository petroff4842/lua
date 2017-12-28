#pragma once
#include "IFile.h"
#include <fstream>


class Writer : public IFile
{
public:
	void Open(const char* file);
	void Close();
	void Write();
public:
	std::ofstream m_of;
};