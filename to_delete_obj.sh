#!/bin/bash

check=`/bin/ls`

declare -a OBJ=("main.o" "abdeltif2.o" "ft_split.o" "get_next_line.o" "param2.o" "render3d.o" "traitmap.o" "ft_atoi.o" "ft_split_virgules.o" "get_next_line_utils.o" "raycast.o" "sprite1.o" "traitmap2.o" "ft_isdigit.o" "ft_split_whitespaces.o" "param.o" "readfile.o" "texturetrait.o" "utils.o")

for i in "${OBJ[@]}"; do
	if [[ "$check" =~ "$i" ]];then
		/bin/rm "$i"
	fi
done
