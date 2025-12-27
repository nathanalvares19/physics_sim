# Instructions

## Requirements

- Windows 10 / 11
- MSYS2 installed
- Use **MSYS2 MinGW64** shell

---

## Install raylib

Open **MSYS2 MinGW64** and run:

```bash
pacman -S mingw-w64-x86_64-raylib
```

````

Verify:

```bash
ls /mingw64/include/raylib.h
```

---

## Compile

From the project directory:

```bash
g++ main.cpp -o main -lraylib
```

Ensure the correct compiler:

```bash
which g++
```

Expected:

```
/mingw64/bin/g++
```

---

## Run

```bash
./main
```
````
