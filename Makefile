all: final
final: BFS.o DFS.o module3.o mod4.o module5.o test.o
	g++ BFS.o DFS.o module3.o mod4.o module5.o test.o -o final
	
BFS.o:BFS.cpp
	g++ -c BFS.cpp

DFS.o:DFS.cpp
	g++ -c DFS.cpp
	
module3.o:module3.cpp
	g++ -c module3.cpp
		
mod4.o:mod4.cpp
	g++ -c mod4.cpp
		
module5.o:module5.cpp
	g++ -c module5.cpp
				
test.o:test.cpp
	g++ -c test.cpp
