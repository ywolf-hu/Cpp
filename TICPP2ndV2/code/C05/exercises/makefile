TestSuiteDir=../../TestSuite
CXXFLAGS += -I$(TestSuiteDir) -Wall

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $^ -o $@

C0501.exe: C0501.o
	$(CXX) $^ -o $@

# test01.exe: 01.exe
# 	./$^

# .PHONY: C0501.exe

clean:
	rm -rf *.o *.exe
