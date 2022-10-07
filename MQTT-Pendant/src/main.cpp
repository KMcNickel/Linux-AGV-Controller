#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>

int main () {
    auto gamepad = open("/dev/input/by-id/usb-8BitDo_8BitDo_Pro_2_000000000003-event-joystick", 
                        O_RDONLY|O_NONBLOCK);
    assert(gamepad != -1);
    int gamepad_debug_event_count = 0;
    int gamepad_button_A_down = 0;
    int gamepad_button_B_down = 0;
    int gamepad_stick_left_x = 0;
    int gamepad_stick_left_y = 0;
    for (;;) {
        struct input_event events[8]; // 8 events per frame is pretty extreme, more like 1 or 2, sometimes as high as 4
        auto r1 = read(gamepad, events, sizeof events);
        if (r1 != -1) {
            int new_event_count = r1/sizeof(struct input_event);
            for (int evi=0; evi<new_event_count; evi++) {
                auto& ev = events[evi];
                switch (ev.type) {
                    case EV_SYN:
                        break;
                    case EV_ABS:
                        switch (ev.code) {
                            case ABS_X:
                                printf("Joy X: %d\r\n", ev.value);
                                break;
                            case ABS_Y:
                                printf("Joy Y: %d\r\n", ev.value);
                                break;
                            case ABS_Z:
                                printf("Joy Z: %d\r\n", ev.value);
                                break;
                            case ABS_RX:
                                printf("Joy RX: %d\r\n", ev.value);
                                break;
                            case ABS_RY:
                                printf("Joy RY: %d\r\n", ev.value);
                                break;
                            case ABS_RZ:
                                printf("Joy RZ: %d\r\n", ev.value);
                                break;
                            case ABS_HAT0X:
                                printf("Joy HAT 0X: %d\r\n", ev.value);
                                break;
                            case ABS_HAT0Y:
                                printf("Joy HAT 0Y: %d\r\n", ev.value);
                                break;
                            default:
                                printf("Joy 0x%X: %d\r\n", ev.code, ev.value);
                                break;
                        }
                        break;
                    case EV_KEY:
                        switch (ev.code) {
                            case BTN_A:
                                printf("Btn A: %d\r\n", ev.value);
                                break;
                            case BTN_B:
                                printf("Btn B: %d\r\n", ev.value);
                                break;
                            case BTN_X:
                                printf("Btn X: %d\r\n", ev.value);
                                break;
                            case BTN_Y:
                                printf("Btn Y: %d\r\n", ev.value);
                                break;
                            case BTN_TL:
                                printf("Btn TL: %d\r\n", ev.value);
                                break;
                            case BTN_TR:
                                printf("Btn TR: %d\r\n", ev.value);
                                break;
                            case BTN_TL2:
                                printf("Btn TL2: %d\r\n", ev.value);
                                break;
                            case BTN_TR2:
                                printf("Btn TR2: %d\r\n", ev.value);
                                break;
                            case BTN_THUMBL:
                                printf("Btn THUMB L: %d\r\n", ev.value);
                                break;
                            case BTN_THUMBR:
                                printf("Btn THUMB R: %d\r\n", ev.value);
                                break;
                            case BTN_SELECT:
                                printf("Btn SELECT: %d\r\n", ev.value);
                                break;
                            case BTN_START:
                                printf("Btn START: %d\r\n", ev.value);
                                break;
                            case BTN_MODE:
                                printf("Btn MODE: %d\r\n", ev.value);
                                break;
                            default:
                                printf("Btn 0x%X: %d\r\n", ev.code, ev.value);
                                break;
                            
                        }
                        break;
                    default:
                        printf("Type: 0x%X Code: 0x%X Value: 0x%X\r\n", ev.type, ev.code, ev.value);
                        break;
                }
                gamepad_debug_event_count ++;
            }
        }
        
        assert(r1 != -1 || errno == EWOULDBLOCK || errno == EAGAIN);        
    }
    usleep(20*1000);
    
}