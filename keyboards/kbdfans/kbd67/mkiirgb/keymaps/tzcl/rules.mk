SRC += features/caps_word.c

# Reduce hex file size
CONSOLE_ENABLE = no
EXTRAFLAGS += -flto
