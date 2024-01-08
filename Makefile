all :
	gcc -Wall -Wextra -Werror src/*.c tools/*.c -o lem_in
fclean:
	rm -rf lem_in
re: fclean all
