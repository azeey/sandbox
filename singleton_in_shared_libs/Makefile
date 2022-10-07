CXXFLAGS = -std=c++17

example1: main.cpp hello.so libsingleton.so
	$(CXX) $(CXXFLAGS)  -o example1 main.cpp -ldl -L . -lsingleton -Wl,--rpath .

hello.so: hello.cpp libsingleton.so
	$(CXX) $(CXXFLAGS)  -shared -fPIC -o hello.so hello.cpp -L . -lsingleton -Wl,--rpath .

libsingleton.so: singleton.cpp
	$(CXX) $(CXXFLAGS) -shared -fPIC -o libsingleton.so singleton.cpp

clean:
	rm -f example1 hello.so libsingleton.so

.PHONY: clean
