# Simple-Unix-Utilities

A collection of lightweight, low-level implementations of classic Unix command-line utilities (`pwd`, `echo`, `cp`, `mv`). Written entirely in C, this project demonstrates direct interaction with POSIX system calls, explicit memory management, and rigorous, system-level error handling.

## ⚙️ Repository Overview

This project bypasses high-level standard library wrappers to interact directly with the operating system kernel. 

**Key Technical Highlights:**
* **System Calls:** Direct utilization of POSIX APIs (`getcwd`, `open`, `read`, `write`, `rename`) via `<unistd.h>` and `<fcntl.h>`.
* **Memory Management:** Safe, stack-based buffer allocations (chunking 4096 bytes at a time) to ensure memory stability even when processing massive files.
* **Strict Error Handling:** Implements rigorous validation on all system operations (including standard I/O writes) utilizing custom negative exit codes to pinpoint exact points of failure.
* **Modular Design:** Functions are encapsulated (e.g., `pwd_main` instead of standard `main`) to allow seamless integration into automated testing environments, custom shells, or larger control systems.

---

## 🛠️ Utilities Included

### 1. `pwd` (Print Working Directory)
Retrieves the absolute path of the current working directory from the OS.
* **Core API:** `getcwd()`
* **Safety:** Allocates a strict `PATH_MAX` equivalent buffer (4096 bytes) to prevent overflow.

### 2. `echo` (Echo Output)
Parses command-line arguments and prints them sequentially to standard output.
* **Core Logic:** Iterates through the `argv` array, explicitly verifying every `printf` write operation.

### 3. `cp` (Copy File)
Creates a byte-for-byte duplicate of a file to a specified destination.
* **Core API:** `open()`, `read()`, `write()`
* **Logic:** Uses bitwise flags (`O_WRONLY | O_CREAT | O_TRUNC`) to properly generate or overwrite destination files while managing correct file permissions (`0666`).

### 4. `mv` (Move/Rename File)
Moves a file to a new destination or renames it within the file system index.
* **Core API:** `rename()`
* **Efficiency:** Updates the file system index pointer rather than moving raw data, allowing instant execution regardless of file size.

---

## Example Outputs


# 1. pwd 

$ ./custom_pwd
/home/developer/projects/unix_utilities



# 2. echo 

$ ./custom_echo Hello World!
Hello World!

$ ./custom_echo
# Prints a blank newline



# 3. cp 

# Basic usage (Successful copy returns silently with a 0 exit code)
$ ./custom_cp source.txt destination.txt

# Triggering an error (e.g., missing arguments)
$ ./custom_cp
 ./custom_cp source_file destination_file


# 4. mv Output Example

# Renaming a file in the same directory (Successful move returns silently)
$ ./custom_mv old_name.txt new_name.txt

# Moving a file to a different directory
$ ./custom_mv file.txt /tmp/file.txt

# Triggering an error (e.g., source file does not exist)
$ ./custom_mv missing.txt /tmp/missing.txt
could not move the file
