CXX=	clang++
#CXX=	eg++
LD=	${CXX}

# compiler flags.
CXXFLAGS+=	-std=c++11 -Ofast -gfull -mtune=native
#CXXFLAGS+=	-std=c++11 -Ofast -gfull -mtune=native
LDFLAGS+=	-lc++
#LDFLAGS+=	-lestdc++

CLEANFILES= *.o catg

all:		catg
clean:
	@rm -rf ${CLEANFILES}

