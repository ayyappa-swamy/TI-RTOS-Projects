# invoke SourceDir generated makefile for empty.pem4f
empty.pem4f: .libraries,empty.pem4f
.libraries,empty.pem4f: package/cfg/empty_pem4f.xdl
	$(MAKE) -f /home/ayyappa/TIRTOSLabsWS/blink_TM4C_CLK/src/makefile.libs

clean::
	$(MAKE) -f /home/ayyappa/TIRTOSLabsWS/blink_TM4C_CLK/src/makefile.libs clean
