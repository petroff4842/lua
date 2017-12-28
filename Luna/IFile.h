#pragma once
class IFile
{
public:
	IFile();
	virtual ~IFile();
	virtual void Open(const char* file) = 0;
	virtual void Close() = 0;
};