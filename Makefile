LIBS = $(wildcard lib/*)
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
TARGET = znyy
CC = arm-linux-gcc

CPPFLAGS += -I ./inc
CPPFLAGS += -I ./inc/libxml2
LDFLAGS  += -L ./lib

LDFLAGS += -lxml2
LDFLAGS += -lasound
LDFLAGS += -lz
LDFLAGS += -lpthread

LDFLAGS += -Wl,-rpath=. -Wl,-rpath=./lib

$(TARGET):$(OBJS) $(LIBS)  # @    <:依赖文件的第一个文件的完整名称  ^:依赖文件
	$(CC) $(OBJS) -o $(TARGET)  $(CPPFLAGS) $(LDFLAGS) -Wall

%.o:%.c
	$(CC) -c $(<) -o $(@) $(CPPFLAGS) $(LDFLAGS) -Wall

#voicectl:voicectl.c common.c $(LIBS)
#	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -Wall

clean:
	rm $(OBJS) $(TARGET)
