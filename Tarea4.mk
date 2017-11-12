Resultados_HW4.pdf : Plots.py resultado.dat
	python Plots.py

a.out : Ondas.c
	gcc $< -lm -O2

clean :
	rm a.out Resultados.pdf resultado.dat
