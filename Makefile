Resultado.png: graficador.py datos.txt
	python graficador.py
    
datos.txt: a.out
	./a.out

a.out: EqString.cpp
	g++ EqString.cpp

clean:
	rm -rf *.out *.txt Resultado.png