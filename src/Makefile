object = fileio.o type.o semantics.o convert.o var.o main.o
rootdir = /cygdrive/d/develop/p2c
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
depdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libsubdir = $(libdir)/p2c
libname = p2c
libsta = lib$(libname).a
libdyn = cyg$(libname).dll

CXX = g++
CXXINC = -I$(depdir) -I$(incdir)
CXXFLAGS = -std=gnu++17 -Wall -g3 $(CXXINC)
LIBS =

all: bin install-bin

re: clean all

bin: $(object)
	$(CXX) $(CXXFLAGS) $(object) $(LIBS) -o p2c.exe

lib: lib-dep
	$(AR) cru $(libsta) */*.o
	$(CXX) $(libsta) -fPIC -shared -o $(libdyn)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib-dep:
	cp $(depdir)/libp/lib/*.a $(libdir)
	cp $(depdir)/libp/bin/*.dll $(bindir)

install: install-bin install-lib

install-bin:
	mkdir -p $(bindir)
	cp p2c.exe $(bindir)

install-lib:
	cp $(libsta) $(libdir)
	cp $(libdyn) $(bindir)

clean: clean-bin clean-lib

clean-bin:
	rm -f *.exe

clean-lib:
	rm -f *.a *.o *.dll
