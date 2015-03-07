TestSuiteDir=../../TestSuite
CXXFLAGS += -I$(TestSuiteDir)

all: test01.exe

%o:%cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

01.exe: 01.o $(TestSuiteDir)/Test.o
	$(CXX) $^ -o $@

test01.exe: 01.exe
	./$^

.PHONY: test01.exe

02.exe: 02.o
	$(CXX) $^ -o $@

03.exe: 03.o
	$(CXX) $^ -o $@

04.exe: 04.o
	$(CXX) $^ -o $@

05.exe: 05.o
	$(CXX) $^ -o $@

clean:
	rm -rf *.o *.exe
