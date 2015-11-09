all: libothm_tag.so

libothm_tag.so: othm_tag.o
	gcc -shared -o libothm_tag.so othm_tag.o
othm_tag.o: othm_tag.c othm_tag.h
	gcc -c -Wall -Werror -fPIC othm_tag.c -o othm_tag.o

.PHONY : clean install uninstall test
clean :
	-rm  othm_tag.o libothm_tag.so test
install :
	cp othm_tag.h /usr/include/
	cp libothm_tag.so /usr/lib/
	ldconfig
uninstall :
	-rm  /usr/include/othm_tag.h
	-rm  /usr/lib/libothm_tag.so
	ldconfig
test :
	gcc -o test test.c -lothm_tag
	./test
