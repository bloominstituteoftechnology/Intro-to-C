SRC=$(wildcard *.c)
EXE=$(subst .c,,$(SRC))

$(EXE): $(SRC)
	gcc -Wall -Wextra -std=c99 -g -o $@ $^

test: tests

.PHONY: clean test tests

# Sean's testing stuff below:

CFLAGS=-g -O2 -Wall -Wextra -I. -DTESTING -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
tests: clean $(TARGET) $(SO_TARGET) tests2

dev: CFLAGS=-g -std=c99 -Wall -Isrc -Wall -Wextra %(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
#tests2: CFLAGS += $(TARGET)
tests2: $(TESTS)
	sh ./tests/runtests.sh

$(TESTS): $(TEST_SRC)
	$(CC) $(CFLAGS) $^ $(TARGET) -o $@

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc" -exec rm -f {} \;
	rm -rf `find . -name "*.dSYM" -print`
	rm -f $(EXE)
