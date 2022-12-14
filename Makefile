CC=clang
CFLAGS=-std=c99 -Wall
LFLAGS=

SRCDIR=src
BUILDDIR=build

OBJS=$(BUILDDIR)/tuple.o \
	 $(BUILDDIR)/color.o \
	 $(BUILDDIR)/utils.o

TOBJS=$(BUILDDIR)/tuple.test.o \
	  $(BUILDDIR)/color.test.o

run: $(BUILDDIR) $(OBJS) $(TOBJS)
	for test in $(TOBJS); do \
		./$$test ; \
	done


$(BUILDDIR)/%.test.o: $(SRCDIR)/%.test.c
	$(CC) $(OBJS) $< -o $@ $(LFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	$(RM) -r $(BUILDDIR)

