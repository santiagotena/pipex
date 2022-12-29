# pipex
 
<p align="center">
<img src="https://github.com/santiagotena/assets/blob/master/logos/42%20logo.jpeg?raw=true" alt="42 Wolfsburg Logo" width="150" height="150">
</p>
 
Pipex is a project from 42 Wolfsburg whose aim is to replicate the functionality of shell commands that have pipes within them.
 
We are meant to replicate the following kind of shell command:
 
```
$ < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
 
New concepts that were important for this project include child processes and pipes.
 
# Usage
 
Use `make` to compile the program.
 
### Example:
 
The following shell command
 
```
$ < test.txt cat | wc -l | cat > out.txt 
```
 
should produce the same effect as the following
 
```
./pipex test.txt "cat" "wc -l" "cat" out.txt
```
