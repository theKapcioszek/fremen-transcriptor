DESTDIR := /opt
SYMLINK := /bin

fremen: ./src/main.c
	cc -o fremen src/main.c -I./raylib/raylib-5.0_linux_amd64/include -L./raylib/raylib-5.0_linux_amd64/lib/ -l:libraylib.a -lm
install:
	mkdir $(DESTDIR)/fremen-transcriptor
	cp fremen $(DESTDIR)/fremen-transcriptor
	cp -r fremen-assets $(DESTDIR)/fremen-transcriptor
	ln -s $(DESTDIR)/fremen-transcriptor/fremen $(SYMLINK)/fremen-transcriptor
uninstall:
	rm -rf $(SYMLINK)/fremen-transcriptor
	rm -rf $(DESTDIR)/fremen-transcriptor/
