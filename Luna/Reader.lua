function printf(...) io.write(string.format(unpack(arg))) end

function Reader:show()
	local fileData = self:ReadFile()
	printf("Reader %s\n", fileData)
end

function Reader:OpenFile( filename )
	self:Open( filename )
end