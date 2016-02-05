TestSuiteDir=../../TestSuite
CXXFLAGS += -I$(TestSuiteDir) -Wall -std=c++11 -g -Werror
CXX = clang++
# CXX = gfilt

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $^ -o $@

C0501.exe: C0501.o
	$(CXX) $^ -o $@

C0502.exe: C0502.o
	$(CXX) $^ -o $@

C0503.exe: C0503.o
	$(CXX) $^ -o $@

C0504.exe: C0504.o
	$(CXX) $^ -o $@

C0505.exe: C0505.o
	$(CXX) $^ -o $@

test01.exe: C0501.exe
	./$^

test02.exe: C0502.exe
	./$^

test03.exe: C0503.exe
	./$^

test04.exe: C0504.exe
	./$^

test05.exe: C0505.exe
	./$^

C0506.exe: C0506.o
	$(CXX) $^ -o $@

test06.exe: C0506.exe
	./$^

C0507.exe: C0507.o
	$(CXX) $^ -o $@

test07.exe: C0507.exe
	./$^

C0508.exe: C0508.o
	$(CXX) $^ -o $@

test08.exe: C0508.exe
	./$^

C0509.exe: C0509.o
	$(CXX) $^ -o $@

test09.exe: C0509.exe
	./$^

C0510.exe: C0510.o
	$(CXX) $^ -o $@

test10.exe: C0510.exe
	./$^

C0511.exe: C0511.o
	$(CXX) $^ -o $@

test11.exe: C0511.exe
	./$^

# .PHONY: C0501.exe

clean:
	rm -rf *.o *.exe
