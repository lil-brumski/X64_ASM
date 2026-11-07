Building Docs {#page}
======================

If you're on a Debian/Ubuntu-based OS then run the following commands on your command line:

```bash
sudo apt update
sudo apt install doxygen python3
```

Clone the GitHub repository:
```bash
git clone https://github.com/lil-brumski/X64_ASM.git
cd X64_ASM/docs
```

Finally, run:
```bash
doxygen Doxyfile
python -m http.server -d html
```

Open the shown URL in a browser.
