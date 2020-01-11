main: main.o StudentDB.o Course.o Student.o
	g++ -o main main.o StudentDB.o Course.o Student.o -std=c++11

main.o: main.cpp Student.cpp Student.h Course.cpp Course.h StudentDB.cpp StudentDB.h
	g++ -c main.cpp Student.cpp Course.cpp StudentDB.cpp -std=c++11

StudentDB.o: StudentDB.cpp StudentDB.h
	g++ -c StudentDB.cpp -std=c++11

Course.o: Course.cpp Course.h
	g++ -c Course.cpp -std=c++11

Student.o: Student.cpp Student.h
	g++ -c Student.cpp -std=c++11

clean :
	rm *.o main
