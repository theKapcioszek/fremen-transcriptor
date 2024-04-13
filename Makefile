fremen: ./src/main.c
	cc -o fremen src/main.c -I./raylib/raylib-5.0_linux_amd64/include -L./raylib/raylib-5.0_linux_amd64/lib/ -l:libraylib.a -lm
install:
	mkdir /opt/fremen-transcriptor
	cp fremen /opt/fremen-transcriptor
	cp -r fremen-assets /opt/fremen-transcriptor
	ln -s /opt/fremen-transcriptor/fremen /bin/fremen-transcriptor
uninstall:
	rm -rf /bin/fremen-transcriptor
	rm -rf /opt/fremen-transcriptor/
