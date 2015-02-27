TestSuiteDir=../../TestSuite
CXXFLAGS += -I$(TestSuiteDir)

%o:%cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

01.exe: 01.o $(TestSuiteDir)/Test.o
	$(CXX) $^ -o $@

test01.exe: 01.exe
	./$^

.PHONY: test01.exe

clean:
	rm -rf *.o *.exe
