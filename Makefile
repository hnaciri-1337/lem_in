all :
	cd libft && make && make clean && mv libft.a .. && cd .. && gcc *.c libft.a -o lem_in -fsanitize=address
fclean:
	rm -rf lem_in libft.a
