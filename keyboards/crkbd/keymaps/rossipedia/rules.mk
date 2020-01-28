
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        ./layer_state_reader.c \
        #./lib/layer_state_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

# Trim the fat
LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes

BOOTMAGIC_ENABLE = lite
MOUSEKEYS_ENABLE = no
EXTRAKEY_ENABLE = yes      # Audio control and System control(+450)
