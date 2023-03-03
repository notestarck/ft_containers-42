#!/bin/bash
# tester_perso.sh

function header()
{
    printf "${EOC}${BOLD}${DBLUE}\
    *------------------------------------------------*
    |	___            _                             |
    |	 | _ _|_ _ _  (_|_   _ _  _ |_ _ . _  _ _    |
    |	 |(-_)|_(-|   | |___(_(_)| )|_(_||| )(-|     |
    |                                                |
    |                               estarck 02/23    |
    *------------------------------------------------*
    ${EOC}\n"
}

function compare()
{
    file1="$1"
    file2="$2"
    i=0

    if [ ! -f "$file1" ]; then
      echo "Error: $file1 does not exist"
      exit 1
    fi

    if [ ! -f "$file2" ]; then
       echo "Error: $file2 does not exist"
      exit 1
    fi

    while IFS= read -r line1 <&3 && IFS= read -r line2 <&4; do
      if [ -z "$line1" ] && [ -z "$line2" ]; then
        echo ""
        continue
      fi

      if [[ "$line1" == "diff :"* ]]; then
        nums1=${line1#diff :}
        nums2=${line2#diff :}
        if diff <(echo "$line1") <(echo "$line2") >/dev/null; then
          echo "    $nums1 -> 🆗"
        else
          echo "$nums1 -> ❌"
          diff <(echo "$line1") <(echo "$line2")
          i+=1
        fi
      else
        echo "$line1"
      fi
    done 3<"$file1" 4<"$file2"
    if [ $i -eq 0 ]; then
          echo -e "\n|-> test resussi"
        else
          echo -e "\n|-> echec du test"
    fi
}

function runMap()
{
    ./ft_container_map > out_ft_map.txt
    ./std_container_map > out_std_map.txt
}

function runVector()
{
    ./ft_container_vector > out_ft_vector.txt
    ./std_container_vector > out_std_vector.txt
}

function runStack()
{
    ./ft_container_stack > out_ft_stack.txt
    ./std_container_stack > out_std_stack.txt
}

function compilMap()
{
    make map
    runMap
    echo ""
    compare out_ft_map.txt out_std_map.txt
}

function compilVector()
{
    make vector
    runVector
    echo ""
    compare out_ft_vector.txt out_std_vector.txt
}

function compilStack()
{
    make stack
    runStack
    echo ""
    compare out_ft_stack.txt out_std_stack.txt
}

function compilFull()
{
    make
    runStack
    runVector
    runMap
    echo ""
    compare out_ft_stack.txt out_std_stack.txt
    echo ""
    compare out_ft_vector.txt out_std_vector.txt
    echo ""
    compare out_ft_map.txt out_std_map.txt
}

function testTime
{
    make
    echo -e "\033[1;31m\nStack Speed Test :\033[0m\n"
    echo -e "\033[33mStack ft :\033[0m"
    time ./ft_container_stack > /dev/null
    echo -e "\033[33m\nStack std :\033[0m"
    time ./std_container_stack > /dev/null
    echo -e "\033[1;31m\nVector Speed Test :\033[0m\n"
    echo -e "\033[33mVector ft :\033[0m"
    time ./ft_container_vector > /dev/null
    echo -e "\033[33m\nVector std :\033[0m"
    time ./std_container_vector > /dev/null
    echo -e "\033[1;31m\nMap Speed Test :\033[0m\n"
    echo -e "\033[33mMap ft :\033[0m"
    time ./ft_container_map > /dev/null
    echo -e "\033[33m\nMap std :\033[0m"
    time ./std_container_map > /dev/null
}

function main()
{
    if [ $# -eq 0 ]; then
        compilFull
    elif [ $1 = stack ]; then
        compilStack
    elif [ $1 = vector ]; then
        compilVector
    elif [ $1 = map ]; then
        compilMap
    elif [ $1 = speed ]; then
        testTime
    else
        echo "bad argument : "$1" is not authorized !"
        exit 2
    fi
}

#run script
if [ $# -gt 1 ]; then
    echo "bad argument : need only one"
    exit 1
fi
header
if [ -d ./bin ]; then
    make fclean > /dev/null;
    echo ""
fi
main $1

exit 0