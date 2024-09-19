.PHONY: all clean exercises labos

EXERCISES_DIR := exercises
LABOS_DIRS := $(wildcard labos/*/)

all: exercises labos

exercises:
	$(MAKE) -C $(EXERCISES_DIR)

labos:
	for dir in $(LABOS_DIRS); do \
		$(MAKE) -C $$dir $(MAKEFLAGS); \
	done

clean:
	$(MAKE) -C $(EXERCISES_DIR) clean
	for dir in $(LABOS_DIRS); do \
		$(MAKE) -C $$dir clean $(MAKEFLAGS); \
	done