# Simple Unix Utilities

# Unix Commands Implementation

Custom implementations of core Unix commands written in C using low-level system calls. Each command mirrors the behavior of its standard Unix counterpart, built from scratch without relying on standard library wrappers.

---

## Commands Overview

| File | Command | Description |
|------|---------|-------------|
| `echo.c` | `echo` | Prints arguments to stdout, space-separated |
| `pwd.c` | `pwd` | Prints the current working directory |
| `cp.c` | `cp` | Copies a file from source to destination |
| `mv.c` | `mv` | Moves (renames) a file to a new path |

---

## Compilation

Each file contains a named entry-point (e.g. `cp_main`) intended to be called from a course-provided `main.c`. To compile and test standalone, wrap it with a minimal `main`:

```c
// main.c
int cp_main(int argc, char *argv[]);
int main(int argc, char *argv[]) {
    return cp_main(argc, argv);
}
```

Then compile with:

```bash
# echo
gcc main.c echo.c -o my_echo

# pwd
gcc main.c pwd.c -o my_pwd

# cp
gcc main.c cp.c -o my_cp

# mv
gcc main.c mv.c -o my_mv
```

---

## Example Output

### echo
```bash
$ ./my_echo Hello World
Hello World

$ ./my_echo one two three
one two three
```

### pwd
```bash
$ ./my_pwd
/home/user/projects
```

### cp
```bash
$ ./my_cp source.txt destination.txt
# destination.txt now contains a copy of source.txt

$ ./my_cp missing.txt dest.txt
could not open source file
```

### mv
```bash
$ ./my_mv old_name.txt new_name.txt
# file has been renamed/moved

$ ./my_mv missing.txt dest.txt
could not move the file
```

---

## Project Structure

```
.
├── echo.c   # Print arguments to stdout
├── pwd.c    # Print current working directory
├── cp.c     # Copy file using read/write syscalls
└── mv.c     # Move/rename file using rename syscall
```

---

## Key Concepts Covered

- **File I/O** — `open()`, `read()`, `write()`, `close()` with flags like `O_RDONLY`, `O_CREAT`, `O_TRUNC`
- **Directory API** — `getcwd()` to retrieve the working directory path
- **File management** — `rename()` for atomic move/rename across paths
- **Error handling** — exit codes and descriptive messages for each failure path
