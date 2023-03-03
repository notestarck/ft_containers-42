#!/bin/bash
#clean_test.sh

make fclean
if ls out_* 1> /dev/null 2>&1;
  then
	echo -e "\033[1;31mDeleting out_*\033[0m"
	rm out_* 2> /dev/null
  else
	echo -e "\033[32mAlready remove out_*\033[0m"
fi
