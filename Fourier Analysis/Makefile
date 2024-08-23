CC = gcc
CFLAGS = -Wall -O2

TARGET = signal_processing

SRCS = main.c DFT/dft.c IDFT/idft.c

OBJS = $(SRCS:.c=.o)

HDRS = DFT/dft.h IDFT/idft.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
