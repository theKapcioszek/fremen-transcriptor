# fremen-transcriptor

Software to transcript ASCII into desert people's writing from popular sci-fi franchise.

## Quick start:  

### Linux & Windows:  
- Download the zip file from [Releases tab](https://github.com/theKapcioszek/fremen-transcriptor/releases) for your respectible system
- Extract the zip file
- Run the fremen-transcriptor executable
- enjoy :)
- Press **f2** to take a screenshot and **f3** to capture only generated text
- Press **Select** button in GUI window to select a directory and save your screenshot  

Also available as an **AUR Package** for Arch Linux:  
[https://aur.archlinux.org/packages/fremen-transcriptor-git](https://aur.archlinux.org/packages/fremen-transcriptor-git)  

## Building:

### Linux:  

```console
$ make
$ ./fremen # To run it
$ sudo make install # To install it
```
### Windows:  
The Makefile I made is not really suited for Windows,  
but you can compile it on Linux using mingw and run it with wine if you want  
```console
$ make fremen.exe # Requires mingw 
$ wine fremen.exe # To run it
```
If you want to compile this project on Windows you have to look into it yourself.  
If you do you can also submit a pull request :)

## TODO:
- [X] Add text box instead of passing an argument
- [X] Option to save result as an image
- [ ] Add numbers

<br><br>

<p align=center>
  <img src="./screenshot.png">
</p>

