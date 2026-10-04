main: main.o stats.o report.o
	gcc -Wall -Wextra -o main main.o stats.o report.o

main.o: main.c report.h
	gcc -Wall -Wextra -c main.c

stats.o: stats.c stats.h
	gcc -Wall -Wextra -c stats.c

report.o: report.c report.h stats.h
	gcc -Wall -Wextra -c report.c

clean:
	rm -f main main.o stats.o report.o