#!/bin/bash
# speedtest.sh

bin_folder="bin/"
selected_files="$@"

if [ "$1" = "" ]; then
	selected_files=*_speedtest.cpp
elif [ "$1" = "clean" ]; then
	echo "Cleaning up..."
	rm -rf $bin_folder
	exit 0
fi

mkdir -p "$bin_folder"

for file in $selected_files; do
	bin_suffix=${file%.cpp}
	clang++ -Wall -Wextra -Werror -std=c++98 -D IS_STD=1 -o "$bin_folder/std_$bin_suffix" $file > /dev/null
	clang++ -Wall -Wextra -Werror -std=c++98 -I../incs/ -I../incs/iterators -I../incs/RBTree -I../incs/utils -o "$bin_folder/ft_$bin_suffix" $file > /dev/null
	echo -e "\n\033[1;31m$bin_suffix :\033[0m\n"
    echo -e "\033[33mft :\033[0m"
	time "./$bin_folder/ft_$bin_suffix"
    echo -e "\033[33m\nstd :\033[0m"
	time "./$bin_folder/std_$bin_suffix"
done
