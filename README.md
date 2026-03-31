. ├── main.c # Entry point of the shell ├── minishell.h # Main header file with structures and function declarations ├── build_in.c # Built-in command implementations ├── the_pipe.c # Pipe handling logic ├── find_path.c # Command path resolution ├── ft_herdoc.c # Here-document implementation ├── handlers.c # Signal handlers ├── node.c # AST node management ├── utils1.c - utils6.c # Utility functions ├── Makefile # Build configuration ├── libft/ # Custom C library ├── ftprintf/ # Custom printf implementation ├── get_next_line/ # Line reading utility ├── shassoun_parsing/ # Parsing utilities └── builting_commandes/ # Built-in commands directory

Code

## Building

### Requirements

- GCC or Clang compiler
- Make
- Linux/Unix environment

### Compilation

```bash
make
This will compile all source files and create the minishell executable.

Clean
bash
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Clean and rebuild
Usage
Run the shell:

bash
./minishell
Once started, you can:

Execute commands (both built-in and external):

bash
$ ls -la
$ pwd
$ echo "Hello, World!"
Use pipes to chain commands:

bash
$ cat file.txt | grep "pattern" | wc -l
Redirect input/output:

bash
$ echo "data" > output.txt
$ cat < input.txt
$ echo "append" >> file.txt
Use here-documents:

bash
$ cat << EOF
> Enter text
> EOF
Access environment variables:

bash
$ echo $HOME
$ echo $PATH
Key Components
Command Parsing (shassoun_parsing/)
Handles parsing of command line input into tokens and building an abstract syntax tree (AST).

Execution Engine (main.c, build_in.c)
Processes parsed commands
Manages process creation and execution
Handles built-in commands vs external programs
Pipe Management (the_pipe.c)
Implements pipe creation and communication between processes.

Redirection (find_path.c, utils*.c)
Manages file descriptor manipulation for input/output redirection.

Utilities
libft/: Custom string manipulation and memory functions
ftprintf/: Custom printf implementation
get_next_line/: Efficient line reading from file descriptors
Limitations
This is a simplified shell implementation and does not support all bash features:

No job control (bg, fg)
Limited variable expansion
No command substitution
No advanced pattern matching
Single-threaded operation only
License
This project is provided as-is for educational purposes.

Author
Created by somaya-Hassoune

References
For understanding shell implementation:

POSIX Shell Specification
Linux man pages: bash(1), execve(2), fork(2), pipe(2)
"The Linux Programming Interface" by Michael Kerrisk
