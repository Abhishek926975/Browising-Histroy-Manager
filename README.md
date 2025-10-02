# Browsing History (C)

A simple command-line simulation of a web browser's history implemented in C using a doubly linked list.

Features
- Visit a new URL (adds to history and clears forward history)
- Go Back to previous pages
- Go Forward to pages after going back
- Show full browsing history with a pointer to the current page

## Files
- `main.c` - main source code
- `Makefile` - build helper

## How to build
```bash
# build with make
make

# or compile manually
gcc -std=c11 -O2 -o browsing_history main.c
git init
git add .
git commit -m "Add browsing history C program (doubly linked list)"
git branch -M main
# replace <REMOTE_URL> with the GitHub repo URL, e.g. https://github.com/Abhishek926975/browsing-history-c.git
git remote add origin <REMOTE_URL>
git push -u origin main

