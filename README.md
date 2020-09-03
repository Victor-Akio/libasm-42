# LibASM

This project consist in recoding some of the libft functions in x86-64 Intel Assembly.

### How to use it

Using ``make`` will create the ``libasm.a`` binary.
This will result in the creation of the lib that will be uses in the tester program.

If you inted to create all library with the program, please run `make test` and this
will generate a program named `tester`.

After generating the program, you must use the comand `./tester` to run all tests available 
within the programm.

### Available functions

```
size_t		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);

ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);

```

Note that this project was made for educational purposes and the code will be commented to better understanding of those who read the files.

### Useful links
[Assembly Cheat Sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
[Open Source Seneca](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start)