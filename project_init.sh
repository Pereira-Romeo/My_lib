#!/bin/bash

function my_readlink() {
    cd $1
    pwd
    cd - > /dev/null
}

AV=()

#------------------- flags -----------------------------------------

F_DEBUG=false
#if active, include the library
F_INCLUDE_LIB=false
#if active, make a c++ project, else, make a c project
F_CPP_PROJECT=false


#------------------- flag funcs ------------------------------------

function debug_flag() {
    F_DEBUG=true
}

function helper_flag() {
    echo -e "\033[1mUsage:\033[0m project_init.sh [OPTIONS] directory"
    echo ""
    echo "OPTIONS:"
    echo "    --lib          include the library in your project."
    echo "    --cpp, --cxx   start a C++ project, if none of those flags are active, start a C project."
    echo ""
    echo "directoy           path to an empty directory or a directory only conatining a .git"
    exit 0
}

function include_lib_flag() {
    F_INCLUDE_LIB=true
}

function cpp_flag() {
    F_CPP_PROJECT=true
}


#------------------- flag handling funcs ---------------------------

short_flags_list=("d" "h")
short_flags_funcs=(debug_flag helper_flag)

function short_flag_handler() { #prolly gonna have to be able to deal with more args
    SUC=false
    for ((i=0;i<${#short_flags_list[@]};i++)); do
        if [[ "$1" == "${short_flags_list[$i]}" ]]; then
            ${short_flags_funcs[$i]}
            SUC=true
            break
        fi
    done

    if [[ "$SUC" == "false" ]]; then
        echo "Invalid option '-$1'."
        exit 1
    fi
}


long_flags_list=("help" "lib" "cpp" "cxx")
long_flags_funcs=(helper_flag include_lib_flag cpp_flag cpp_flag)

long_flag_handler() {
    SUC=false
    for ((i=0;i<${#long_flags_list[@]};i++)); do
        if [[ "$1" == ${long_flags_list[$i]} ]]; then
            ${long_flags_funcs[$i]}
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

for arg in "$@"
do
    if [ "${arg::2}" == "--" ]; then
        long_flag_handler "${arg:2}"
    elif [ "${arg::1}" == "-" ]; then
        short_flag_handler "${arg:1}"
    else
        AV+=("$arg")
    fi
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

for arg in "${AV[@]}"
do
    echo "- $arg"
done


# if [ $# == 1 ] && [ $1 == "--help" ]; then
#     cat_readme; exit 0;
# elif [ $# == 1 ] || [ $# = 2 ];
# then
#     if [ $# == 1 ];
#     then
#         REPORTS_DIR=$(my_readlink ".")
#     elif [ $# = 2 ];
#     then
#         REPORTS_DIR=$(my_readlink "$REPORTS_DIR_ARG")
#     fi
# else
#     cat_readme; exit 1;
# fi