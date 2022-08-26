CXX=g++
CPPFLAGS=
OUTFILE=main
OBJECTS=main.o Field.o MovableEntity.o Entity.o Utils.o

main: $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o $(OUTFILE) $(OBJECTS)

%.o: $.cpp
	$(CPP) -c $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f $(OUTFILE)