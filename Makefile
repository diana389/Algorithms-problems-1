# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: p1 p2 p3 p4

run-p1:
	./p1
run-p2:
	./p2
run-p3:
	./p3
run-p4:
	./p4

# Nu uitați să modificați numele surselor și, eventual, ale executabilelor.
p1: ./skel/feribot.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: ./skel/nostory/nostory-skeleton.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: ./skel/semnale/semnale-skeleton.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: ./skel/sushi/sushi-skeleton.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f p1 p2 p3 p4