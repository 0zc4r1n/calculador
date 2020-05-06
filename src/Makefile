include ../build/conanbuildinfo.mak

#----------------------------------------
#     Make variables for a sample App
#----------------------------------------

CXX_SRCS = \
calculador.c

CXX_OBJ_FILES = \
calculador.o

EXE_FILENAME = \
calculador

#----------------------------------------
#     Prepare flags from variables
#----------------------------------------

CFLAGS          += $(CONAN_CFLAGS)
CXXFLAGS        += $(CONAN_CXXFLAGS)
CPPFLAGS        += $(addprefix -I, $(CONAN_INCLUDE_DIRS))
CPPFLAGS        += $(addprefix -D, $(CONAN_DEFINES))
LDFLAGS         += $(addprefix -L, $(CONAN_LIB_DIRS))
LDLIBS          += $(addprefix -l, $(CONAN_LIBS))


#----------------------------------------
#     Make Commands
#----------------------------------------

COMPILE_CXX_COMMAND         ?= \
	gcc -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

CREATE_EXE_COMMAND          ?= \
	gcc $(CXX_OBJ_FILES) \
	$(CXXFLAGS) $(LDFLAGS) $(LDLIBS) \
	-o $(EXE_FILENAME)


#----------------------------------------
#     Make Rules
#----------------------------------------

.PHONY                  :   exe
exe                     :   $(EXE_FILENAME)

$(EXE_FILENAME)         :   $(CXX_OBJ_FILES)
	$(CREATE_EXE_COMMAND)

%.o                     :   $(CXX_SRCS)
	$(COMPILE_CXX_COMMAND)
clean
	rm -rf *.o $(EXE_FILENAME)
