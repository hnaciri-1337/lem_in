all :
	cd libft && make && make clean && mv libft.a .. && cd .. && gcc lem_in.c libft.a -o lem_in
fclean:
	rm -rf lem_in libft.a
