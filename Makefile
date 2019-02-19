all: oucat ouecho ouhead outail ouseq ouwc
  
oucat: oucat.c
	gcc oucat.c -o oucat

ouecho: ouecho.c
	gcc ouecho.c -o ouecho

ouhead: ouhead.c
	gcc ouhead.c -o ouhead

outail: outail.c
	gcc outail.c -o outail

ouseq: ouseq.c
	gcc ouseq.c -o ouseq

ouwc: ouwc.c
	gcc ouwc.c -o ouwc

clean:
	rm oucat
	rm ouecho
	rm ouhead
	rm outail
	rm ouseq
	rm ouwc
