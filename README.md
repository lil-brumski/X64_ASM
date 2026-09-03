# X64_ASM (#main)

- [X64\_ASM (#main)](#x64_asm-main)
  - [Introduction ## {#intro}](#introduction--intro)
  - [Building Documentation ## {#build-docs}](#building-documentation--build-docs)
  
## Introduction ## {#intro}
This repo is for practicing how to use:
- Git
- Assembly
- Python
- Better C++
- CMake
- GitHub
- GitLab
- KiCad
- FreeCAD

## Building Documentation ## {#build-docs}
If you're on a Debian/Ubuntu-based OS then run the following commands on your command line:

```bash
sudo apt update
sudo apt install doxygen
```

Clone the GitHub repository:
```bash
git clone https://github.com/lil-brumski/X64_ASM.git
cd X64_ASM/docs
```

Finally, run:
```bash
doxygen Doxyfile
cd html
```

Open the `index.html` file in a browser.