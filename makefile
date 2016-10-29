string:  BufferedFile.o StreamSource.o main.o 
	g++ -pedantic -g -o  BufferedFile.o StreamSource.o main.o

BufferedFile.o:  BufferedFile.h BufferedFile.cpp TrackingDeque.h
	g++ -pedantic -g -c BufferedFile.cpp

StreamSource.o:  StreamSource.h  StreamSource.cpp BufferedFile.h
	g++ -pedantic -g -c StreamSource.cpp

main.o:  main.cpp StreamSource.h
	g++ -pedantic -g -c main.cpp

clean:
	rm -rf string string.exe *.o
