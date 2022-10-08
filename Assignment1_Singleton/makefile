
# Authors : Dnyanesh Marne,  Sanskruti Jadhav

rotator: rotator.o ppm.o pgm.o 
	g++ rotator.o ppm.o pgm.o -o rotator

rotator.o: rotator.cpp
	g++ -c rotator.cpp 

ppm.o: ppm.cpp ppm.h
	g++ -c ppm.cpp ppm.h

pgm.o: pgm.cpp pgm.h colorPixel.h grayPixel.h
	g++ -c pgm.cpp pgm.h colorPixel.h grayPixel.h


clean:
	rm *.o rotator




