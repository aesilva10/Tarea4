PuntoNemo.pdf:plots.py datos.txt
	python Plots.py
Plots.py : a.out
	./a.out
a.out : PuntoGeographicPoint.c
	cc PuntoGeographicPoint.c -lm

