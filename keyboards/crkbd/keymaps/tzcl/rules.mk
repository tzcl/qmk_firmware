OLED_ENABLE       = yes
OLED_DRIVER       = SSD1306

RGB_MATRIX_ENABLE = yes
COMBO_ENABLE      = yes
WPM_ENABLE        = yes

SRC += features/caps_word.c
SRC += features/repeat.c

RGBLIGHT_ENABLE = no
CONSOLE_ENABLE  = no
COMMAND_ENABLE  = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
AUDIO_ENABLE    = no

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no

LTO_ENABLE = yes

