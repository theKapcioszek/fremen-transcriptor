DESTDIR := /opt
SYMLINK := /bin

default: fremen

fremen: ./src/main.c
	cc -o fremen src/main.c -I./raylib/raylib-5.0_linux_amd64/include -L./raylib/raylib-5.0_linux_amd64/lib/ -l:libraylib.a -lm
fremen.exe: ./src/main.c
	x86_64-w64-mingw32-gcc src/main.c -I./raylib/raylib-5.0_win64_mingw-w64/include/ -L./raylib/raylib-5.0_win64_mingw-w64/lib/ -lraylib -lwinmm -lgdi32 -o fremen.exe
install: fremen
	mkdir $(DESTDIR)/fremen-transcriptor
	cp fremen $(DESTDIR)/fremen-transcriptor
	cp -r fremen-assets $(DESTDIR)/fremen-transcriptor
	ln -s $(DESTDIR)/fremen-transcriptor/fremen $(SYMLINK)/fremen-transcriptor
uninstall:
	rm -rf $(SYMLINK)/fremen-transcriptor
	rm -rf $(DESTDIR)/fremen-transcriptor/
