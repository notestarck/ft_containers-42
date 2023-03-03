# ft_containers

C++ containers, easy mode

## Languages

* C++
* Makefile
* Bash

## Competences

* Language C++
* STL
* Containers implementation
* Namespace
* Iterators
* Binary trees
* Writing your own tests in bash

## How to compile

In your terminal
```
../ft_containers » make
../ft_containers » make stack
../ft_containers » make vector
../ft_containers » make map
```

## How to delete

In your terminal

To delete .o files
```
../ft_containers » make clean
```

To delete executable
```
../ft_containers » make fclean
```
## Documentation

This documentation is in french.

- How use a Namespace : [Using Namespace](https://learn.microsoft.com/fr-fr/cpp/cpp/namespaces-cpp?view=msvc-170) - [FAQ Namespace](https://cpp.developpez.com/faq/cpp/?page=Les-namespaces)
- How use a Containers : [Using Contenainers](https://learn.microsoft.com/fr-fr/cpp/standard-library/stl-containers?view=msvc-170) - [FAQ Containers](https://cpp.developpez.com/faq/cpp/?page=Conteneurs)
- What is an iterator ? - [Iterator](https://ec56229aec51f1baff1d-185c3068e22352c56024573e929788ff.ssl.cf1.rackcdn.com/attachments/original/0/9/9/002752099.pdf)
- Source code information library : [libstdc++](https://www.deepl.com/translator#fr/en/librairie%20d'information%20sur%20le%20code%20source)
- Other documention in ./documentation

## Projet

Implement the following containers and turn in the necessary `<container>.hpp` files with a Makefile:
- vector
	- You don’t have to do the `vector<bool>` specialization.
- map
- stack

You also have to implement:
- std::iterator_traits
- std::reverse_iterator
- std::enable_if
	- Yes, it is C++11 but you will be able to implement it in a C++98 manner.
	- This is asked so you can discover SFINAE.
- std::is_integral
- std::equal and/or std::lexicographical_compare
- std::pair
- std::make_pair

## Rules

- Code compiled in C++98
- The namespace must be ft.
- Each inner data structure used in your containers must be logical and justified (this means using a simple array for map is not ok).
- You cannot implement more public functions than the ones offered in the standard containers Everything else must be private or protected. Each public function or variable must be justified.
- All the member functions, non-member functions and overloads of the standard containers are expected.
- You must follow the original naming. Take care of details.
- If the container has an iterator system, you must implement it.
- You must use std::allocator.
- For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.
- Of course, for the implementation of std::map::value_compare, the keyword friend is allowed.

## Tester

Two tester are available :

### ./tester_perso.sh 

- Compil and run test.
- Can be used without option to test all containers.
- Can be used with `map` `vector` `stack` to test a particular container.
- Can be used with `speed` to test speed of execution of the standard main.

	#### ./clean_test.sh
	
	- make fclean
	- clean log file

### ./speedtest/speedtest.sh

Speed test on containers: each container can be tested with different sizes.

## Author

* **notestarck** - [GitHub](https://github.com/notestarck)