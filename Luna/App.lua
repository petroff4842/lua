require("Writer.lua")

writer = Writer:new()
writer:Open("test.txt")
writer:Write()
writer:Close()