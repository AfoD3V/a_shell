### a_shell – a tiny Unix-like shell in C

This project is a minimal interactive shell implemented in C. It reads commands, tokenizes them, and either executes built-in commands or launches external programs using fork/exec, then waits for them to finish.

Inspired by Stephen Brennan’s excellent tutorial “Write a Shell in C.” Read it here: `https://brennan.io/2015/01/16/write-a-shell-in-c/`.

### How it works (high level)
- **Loop**: Prompt ? read line ? split into arguments ? execute ? repeat until exit.
- **Reading**: `lsh_read_line()` dynamically grows a buffer to read an entire line from stdin.
- **Parsing**: `lsh_split_line()` tokenizes the line on whitespace into an argv-style array ending with NULL.
- **Execution**:
  - Builtins are handled in-process: `cd`, `help`, `exit`.
  - Non-builtin commands are run by `lsh_launch()` via `fork()` + `execvp()` and `waitpid()`.

### Built-in commands
- `cd <dir>`: change current directory
- `help`: show builtin names and a short message
- `exit`: terminate the shell

### Requirements
- C toolchain (e.g., `gcc`)
- POSIX-compatible environment (macOS, Linux)

### Build
```bash
gcc -o main main.c
```

### Run
```bash
./main
```

Example session:
```text
> pwd
/current/working/dir
> cd ..
> ls
> help
> exit
```

### Notes and limitations
- No quoting/escaping or globbing. Arguments are split on whitespace only.
- No pipelines `|` or redirection `<`, `>`.
- Minimal error handling.

These omissions are intentional to keep the implementation compact and educational. They are good next steps if you want to extend the shell.

### Reference
- Stephen Brennan, “Write a Shell in C”: `https://brennan.io/2015/01/16/write-a-shell-in-c/`


