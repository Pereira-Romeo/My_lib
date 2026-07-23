#!/bin/bash

function my_readlink() {
    cd $1
    pwd
    cd - > /dev/null
}

#list of arguments given that aren't flags
AV=()

#where this script lives
ORIGIN="$(my_readlink "$(dirname "$0")")"

#used inside flag functions to say wether it used the next arg or not
USED_NEXT_ARG=false

LOLCAT=false
if command -v lolcat >/dev/null 2>&1
then
    LOLCAT=true
fi

#------------------- flags -----------------------------------------
#-d
F_DEBUG=false
#--lib
#if active, include the library
F_INCLUDE_LIB=false
#--cpp || --cxx
#if active, make a c++ project, else, make a c project
F_CPP_PROJECT=false
F_EXT=".c"

#used if you don't want this script to check wether the target dir is "empty"
F_FORCE=false

PROJECT_NAME=


#------------------- flag funcs ------------------------------------

function debug_flag() {
    F_DEBUG=true
}

function helper_flag() {
    echo -e "\033[1mUsage:\033[0m project_init.sh [OPTIONS] directory"
    echo ""
    echo "OPTIONS:"
    echo "    --lib                 include the library in your project."
    echo "    --cpp, --cxx          start a C++ project, if none of those flags are active, start a C project. using --cpp will set the expect extension to .cpp, --cxx will set it to .cxx"
    echo "    --force               initialize project even if folder is not 'empty'. This will essentially try merging with the current state of your project."
    echo "    --name [project_name] set the project name. if this option is absent, the project name will the the target directory"
    echo ""
    echo "directoy           path to an empty directory or a directory only conatining a .git"
    exit 0
}

function include_lib_flag() {
    F_INCLUDE_LIB=true
}

function cpp_flag() {
    F_EXT=".$1"
    F_CPP_PROJECT=true
}

function name_flag() {
    if [ -z "$2" ]; then
        echo "--name option needs a name to use, none was provided" >&2
        exit 1
    fi
    PROJECT_NAME="$2"
    USED_NEXT_ARG=true
}

function force_flag() {
    F_FORCE=true
}


#------------------- flag handling funcs ---------------------------

short_flags_list=("d" "h")
short_flags_funcs=(debug_flag helper_flag)

function short_flag_handler() { #prolly gonna have to be able to deal with more args
    SUC=false
    for ((i=0;i<${#short_flags_list[@]};i++)); do
        if [[ "$1" == "${short_flags_list[$i]}" ]]; then
            ${short_flags_funcs[$i]} $2 $3
            SUC=true
            break
        fi
    done

    if [[ "$SUC" == "false" ]]; then
        echo "Invalid option '-$1'."
        exit 1
    fi
}


long_flags_list=("help" "lib" "cpp" "cxx" "name" "force")
long_flags_funcs=(helper_flag include_lib_flag cpp_flag cpp_flag name_flag force_flag)

long_flag_handler() {
    SUC=false
    for ((i=0;i<${#long_flags_list[@]};i++)); do
        if [[ "$1" == ${long_flags_list[$i]} ]]; then
            ${long_flags_funcs[$i]} $2 $3
            SUC=true
            break
        fi
    done

    if [[ "$SUC" == "false" ]]; then
        echo "Invalid option '-$1'."
        exit 1
    fi
}

#------------------- arg handling ----------------------------------
argIndex=1

for arg in "$@"
do
    nextArg=$(( argIndex + 1 ))
    if [ "$USED_NEXT_ARG" == "false" ]; then
        if [ "${arg::2}" == "--" ]; then
            long_flag_handler "${arg:2}" ${!argIndex:2} ${!nextArg}
        elif [ "${arg::1}" == "-" ]; then
            short_flag_handler "${arg:1}" ${!argIndex:1} ${!nextArg}
        else
            AV+=("$arg")
        fi
    else
        #last flag used that argument so it shouldn't be added to AV
        USED_NEXT_ARG=false
    fi
    argIndex=$(( argIndex + 1 ))
done

#-------------------------------------------------------------------
#------------------ project init -----------------------------------
#-------------------------------------------------------------------

if [[ "${#AV[@]}" -ne 1 ]]; then
    echo "Invalid number of arguments, refer to --help." >&2
    exit 1
fi

if [[ ! -d "${AV[0]}"  ]]; then
    echo "Path '${AV[0]}' is not a directoy." >&2
    exit 1
fi

TARGET_DIR="$(my_readlink "${AV[0]}")"

#--- check if dir is empty, if not cancel unless --force is present
if [ "$F_FORCE" == "false" ] && [ ! -z "$( ls "$TARGET_DIR")" ]; then
    echo "It appears your directory is not empty, please remove all file or use --force to ignore this issue" >&2
    exit 1
fi

if [ -z "$PROJECT_NAME" ]; then
    PROJECT_NAME="$(basename "$TARGET_DIR")"
fi


echo -e "Inititating project '\033[1m$PROJECT_NAME\033[0m' at \033[4m$TARGET_DIR\033[0m."

cd "$TARGET_DIR"

#basic tree architecture
mkdir -p "src"
mkdir -p "include"


#populating .gitignore with basic stuff if a .git was found
if [ -d ".git" ]; then
    grep -qxF '.build/' .gitignore 2> /dev/null || echo ".build/" >> .gitignore
    grep -qxF "$PROJECT_NAME" .gitignore || echo "$PROJECT_NAME" >> .gitignore
    grep -qxF '*.log' .gitignore || echo '*.log' >> .gitignore
    grep -qxF '.local/' .gitignore || echo '.local/' >> .gitignore
    grep -qxF '*.bin' .gitignore || echo '*.bin' >> .gitignore
fi


#adding lib if asked
if [ "$F_INCLUDE_LIB" == "true" ]; then
    cp -r "$ORIGIN/lib" .
fi


#copy and adapt makefile
cp -f "$ORIGIN/Makefile" .
sed -i "s/^NAME = .*/NAME = $PROJECT_NAME/" Makefile
sed -i "s/^EXT = .*/EXT = $F_EXT/" Makefile
sed -i "s/^INCLUDE_LIB = .*/INCLUDE_LIB = $F_INCLUDE_LIB/" Makefile


#populating main if it doesn't yet exists
if [ "$F_CPP_PROJECT" == "true" ]; then
    MAIN_NAME="Main$F_EXT"
    sed -i "s|^EXECSRC = .*|EXECSRC = \$(SRCDIR)/Main\$(EXT)|" Makefile
else
    MAIN_NAME="main.c"
    sed -i "s|^EXECSRC = .*|EXECSRC = \$(SRCDIR)/main\$(EXT)|" Makefile
fi

if [ ! -f "src/$MAIN_NAME" ]; then
echo "int main(int ac, char **av)
{
    return 0;
}" > "src/$MAIN_NAME"
fi


#-------------------------------------------------------------------
#------------------ end of prog ------------------------------------
#-------------------------------------------------------------------

echo ""
if [ "$LOLCAT" == "true" ]; then
    echo -e "Project '\033[1m$PROJECT_NAME\033[0m' initialized successfully :D" | lolcat
else
    echo -e "Project '\033[1m$PROJECT_NAME\033[0m' initialized successfully :D"
fi
cd - > /dev/null
