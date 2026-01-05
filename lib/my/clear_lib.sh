#! /usr/bin/env bash

script_dir="$(cd "$(dirname "$0")" && pwd)" # should always get the correct path

lib_path=$script_dir
lib_header_path="$lib_path/headers"

lib_funcs=()
lib_funcs_i=0

lib_used_funcs=()
lib_used_funcs_i=0

user_headers=""

project_path="$(dirname $(dirname $script_dir))" #needs change adapt with script_dir
src_path="$project_path/src"


#------------------- flags -----------------------------------------

f_debug=false
f_last=false

#------------------- flag funcs ------------------------------------

debug_flag() {
    f_debug=true
}

help() {
    echo -e "\033[1mUsage:\033[0m"
    echo "This programm is supposed to be in the lib/my/ dir of your project, it currently expects the following paths:"
    echo "  lib: $lib_path; $lib_header_path"
    echo "  src: $src_path"
    exit 0
}

initial_clear() {
    echo "executing initial clear at $project_path"
    rm $project_path/LICENSE.md $project_path/README.md
    exit 0
}

last_clear() {
    echo "clearing everything and deleting clear script"
    f_last=true
}


#------------------- flag handling funcs ---------------------------

short_flags_list=("d" "h")
short_flags_funcs=(debug_flag help)

short_flag_handler() { #prolly gonna have to be able to deal with more args
    for flag in $1; do
        for ((i=0;i<${#short_flags_list[@]};i++)); do
            if [[ "$flag" == "${short_flags_list[$i]}" ]]; then
                ${short_flags_funcs[$i]}
                break
            fi
        done
    done
}


long_flags_list=("init" "last")
long_flags_funcs=(initial_clear last_clear)

long_flag_handler() {
    for ((i=0;i<${#long_flags_list[@]};i++)); do
        if [[ "$1" == ${long_flags_list[$i]} ]]; then
            ${long_flags_funcs[$i]}
        fi
    done
}

#------------------- arg handling ----------------------------------

for arg in "$@"
do
    if [ "${arg::2}" == "--" ]; then
        long_flag_handler "${arg:2}"
    elif [ "${arg::1}" == "-" ]; then
        short_flag_handler "${arg:1}"
    fi
done

#------------------- flag handling ---------------------------------

if [ "$f_debug" == "true" ]; then
    echo "flags after handling:"
    echo "f_debug: $f_debug"
    echo ""
fi
# echo "number of args: ${#@}"
# echo "$(date +"%d-%m-%Y")_$(date +"%H-%M-%S-%N")"

# NBRS='^[0-9]+$'
# if ((${#@}>0)); then
#     if ! [[ $1 =~ $NBRS ]]; then
#         echo "first arg needs to be numbers"
#         exit 1
#     fi
# fi
#------------------- cleaning script -------------------------------


#listing all .h in headers
headers=`find $lib_header_path -type f -name '*.h'`
if [ "$?" == "1" ]; then
    echo -e "\033[1;31mERROR:\033[0;0m path to library's headers may be wrong"
    exit 1
fi
if [[ "${#headers[@]}" &&  ${headers[0]} =~ '.h'  ]]; then
    echo "lib's header files:"
    for entry in $headers
    do
        echo "- $entry"
    done
    # call func to handle everything about the headers ?
else
    echo -e "\033[1;34mEmpty headers file\033[0;0m"
    exit 0
fi


{
    echo "wtf"

    echo "multi line echo ?"

    echo "using multiple echo ?"
} | lolcat

echo "but it's all in one pipe ?"



echo "$(ls lib/my)"












# if [ "$f_debug" == "true" ]; then
#     echo "x2 dirname of lib_path $(dirname $(dirname $lib_path))"
# fi

# echo "${lib_funcs[0]}"

# echo "path to lib: $lib_path"



# echo ""

# # for header in $headers
# # do
# #     echo "file $header:"
# #     while read -r line
# #     do
# #         echo "  $line"
# #     done < $header
# #     echo ""
# # done

# echo ""

# #listing all .c in src/
# src_files=`find $src_path -type f -name '*.c'`
# echo "user's source files:"
# for src in $src_files
# do
#     echo "- $src"
# done

# echo ""

# #files with only #includes are considered empty ????????? to investigate
# for src in $src_files
# do
#     echo -e "file $src contains:\033[0;31m"
#     while read -r line
#     do
#         echo "$line"
#     done < "$src"
#     echo -e "\033[0;0m"
# done

if [ "$f_last" == "true" ]; then # should always be last in this script
    echo "deleting self, bye :)"
    rm $script_dir/clear_lib.sh
fi