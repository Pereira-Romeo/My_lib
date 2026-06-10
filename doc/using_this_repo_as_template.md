# Using this repository as template

Table of contents:
1. **[Setup](#setting-up-alias-for-easier-use)**.
2. **[Init new project](#initializing-a-new-project)**.
3. **[Dependencies](#dependencies)**.

## setting up alias for easier use

in your **[bashrc](~/.bashrc)** add this line (adapting the path):
```sh
#init a project in c or c++
alias cinit="$HOME/path/to/mylib/project_init.sh"
```
or you can just execute this line (still adapting the path) to add it:
```sh
echo "#init a project in c or c++
alias cinit=\"$HOME/path/to/mylib/project_init.sh\"" >> ~/.bashrc
```


## initializing a new project

> [!NOTE]
> This section makes use of the earlier section
> so an instane of 'cinit' is the project_init.sh script.

### the basics
```sh
cinit . --name "my_project"
```
The line above will, in your current working directory, initialize a project called "my_project" in c.

This script will not execute if your target directory isn't empty. \
By "isn't empty" we mean if there is any NOT hidden files in your dir. \
Hidden files (like `.git`) will not make us consider the dir as not empty.

after executing this script (in an empty dir) you can expect the following tree:
```sh
.
├── .git #(Not created by the script, was present before)
├── .gitignore #(created by the script because a .git was found)
├── include
├── lib #(if --lib was used)
│   └── ...
├── Makefile
└── src
    └── Main.cpp #(main.c if it wasn't a cpp project)
```

### every flags

|flag|description|
|:---:|:---:|
|`--lib`| use this flag if you wish to add my library to your project |
|`--cpp` or `--cxx`| use one of these flags to make a c++ project, choose the flag depending on your desired extension (respectivly `.cpp` & `.cxx`) |
|`--force`| use this flag if your target directory isn't empy. This action is NOT recommended. in the even you were to use it, **[please read](#about---force)**.|
|`--name`| use this to define a name for your project. This flag requires an argument (obviously). if --name is not used, the project name will default to your target directory's name|

### about `--force`

Using this flag in a directory that isn't empty will lead to the following:
- new entries in your .gitignore (if your project has a .git)
- changed Makefile (if you had a Makefile before using the script, it's gone.)
- new folder `include` (if you didn't have it)
- new folder `src` (if you didn't have it)
- new file `main.c` or `Main.cpp` or `Main.cxx` (if you didn't have any)


# dependencies

> [!WARNING]
> This section may not contain everything.

- grep
- sed
