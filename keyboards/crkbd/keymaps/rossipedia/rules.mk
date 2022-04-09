BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = no

OLED_ENABLE = yes
OLED_DRIVER = SSD1306    # OLED display

# If you want to change the display of OLED, you need to change here
SRC +=  ./layer_state_reader.c \
        ./lib/keylogger.c \
	    ./lib/timelogger.c \
        ./lib/logo_reader.c \
		./lib/timelogger.c \
