CC      ?= cc
CFLAGS  := -Wall -Wextra -g -I../Core/Inc -DPLATFORM_SIM
BUILD   := ../build/sim
TARGET  := $(BUILD)/fsm_sim

SRCS := main.c led_sim.c ../Core/Src/fsm.c
OBJS := $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRCS)))

vpath %.c . ../Core/Src

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)

run: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(BUILD)

.PHONY: all run clean
