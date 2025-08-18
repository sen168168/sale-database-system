# Compile any .cpp file by running: make filename (without .cpp)
%: %.cpp
	g++ -o $@ $<

# Clean all compiled files
clean:
	rm -f *.o *.out *.exe *.a *.so
	rm -f $(basename $(wildcard *.cpp))
