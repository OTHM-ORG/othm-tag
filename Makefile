all:

.PHONY : clean install uninstall test
clean :
	-rm test
install :
	cp othm_tag.h /usr/include/
	ldconfig
uninstall :
	-rm  /usr/include/othm_tag.h
	ldconfig
test :
	gcc -o test test.c
	./test
