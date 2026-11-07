# C++ Command Line Interpreter

A simple command-line interpreter written in C++, developed as a coursework project for Object-Oriented Programming.

The program provides built-in commands for text processing and file operations, with support for input/output redirection, pipelines and batch execution from text files.

## Features

- Interactive command execution with a customizable prompt.
- Text input from quoted arguments, files or standard input.
- Word and character counting, substring replacement and removal and extraction of the first lines of text.
- File creation, truncation and deletion.
- System time and date display.
- Input/output redirection using `<`, `>` and `>>`.
- Command pipelines using `|` and batch execution using `batch`.
- Exception-based error reporting.

## Requirements and Build

The interpreter starts with the `$ ` prompt. Enter the examples below inside the running interpreter. To quit on macOS/Linux, press `Ctrl+D` at an empty prompt. There is no built-in `exit` command.

## Commands

| Command | Purpose | Example |
| --- | --- | --- |
| `echo [argument]` | Print input text | `echo "Hello world"` |
| `prompt "text"` | Change the prompt | `prompt "cli>"` |
| `time` | Display the current time | `time` |
| `date` | Display the current date | `date` |
| `touch filename` | Create an empty file | `touch notes.txt` |
| `truncate filename` | Clear a file's contents | `truncate notes.txt` |
| `rm filename` | Delete a file | `rm notes.txt` |
| `wc -w [argument]` | Count words | `wc -w "one two three"` |
| `wc -c [argument]` | Count characters, subject to the limitations below | `wc -c "abc"` |
| `tr [argument] "what" ["with"]` | Replace or remove a substring | `tr "hello world" "world" "everyone"` |
| `head -ncount [argument]` | Print the first lines of input | `head -n2 input.txt` |
| `batch [argument]` | Execute a sequence of command lines | `batch commands.txt` |

Square brackets indicate optional parts and should not be typed. For `head`, the line count immediately follows `-n`, for example `-n2`.

For commands that read text, a quoted argument supplies text directly, while an unquoted argument specifies a filename. Relative file paths are resolved from the directory where the interpreter is launched.

## Usage Examples

### Text Processing

The `$ ` prefix below represents the interpreter prompt; do not type it yourself.

```text
$ echo "Hello world"
Hello world
$ wc -w "one two three"
3
$ wc -c "abc"
3
$ tr "hello world" "world" "everyone"
hello everyone
$ tr "banana" "na"
ba
```

### Redirection

```text
echo "one two three" > input.txt
wc -w < input.txt
echo " four" >> input.txt
```

The `>` operator writes output to a file, replacing its previous contents. The `>>` operator appends output, and `<` reads input from a file. Here, `wc` prints `3` before the fourth word is appended.

### Pipelines

```text
echo "one two three" | wc -w
echo "one two three" | tr "three" "four" | wc -w
```

Both examples print `3`. Each command's output becomes the next command's input.

### Batch Execution

Create a file named `commands.txt` containing:

```text
echo "Batch execution works"
wc -w "one two three"
```

Then run this command inside the interpreter:

```text
batch commands.txt
```

## Project Structure

```text
.
├── cpp/          # Class implementations and main.cpp
├── h/            # Headers, interfaces and exceptions
├── .gitignore
└── README.md
```

- `CommandLineInterpreter` manages command-line input and the prompt.
- `CommandLine` splits command lines into tokens.
- `ExecuteCommands` selects the appropriate command handler.
- The `Execute*` classes process arguments, options and redirections.
- Classes such as `Echo`, `Wc`, `Tr` and `Head` implement operations through the shared `CommandBaseInterface`.
- `Exceptions.h` defines error types.

## Implementation Notes and Known Limitations

- Only the first 512 bytes of each command line are processed.
- Pipelines use the temporary files `redirection1.txt` and `redirection2.txt` in the working directory. Keep these names available for the interpreter; the files are excluded by `.gitignore`.
- The backtick character (ASCII 96), defined as `END` in `Definitions.h`, acts as an additional end-of-input marker in several commands. It can also stop those commands from reading a file containing that character.
- When reading from an input stream, `wc -c` currently skips newline characters.
- In `tr`, replacement text containing the search substring can cause an infinite loop. Avoid these replacements until the algorithm is updated.


