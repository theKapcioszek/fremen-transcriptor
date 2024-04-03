fremen: ./src/main.c
	cc -o fremen src/main.c -I./raylib/raylib-5.0_linux_amd64/include -L./raylib/raylib-5.0_linux_amd64/lib/ -l:libraylib.a -lm
