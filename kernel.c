/* kernel.c */

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

#define VID_MEM ((uint8_t*)0xb8000)
#define LIGHT_GREY_ON_BLACK 0x07

#define SCREEN_WIDTH    80
#define SCREEN_HEIGHT   25

void clear_screen(uint8_t *vidptr) {
    uint32_t j = 0;
    /* This loop clears the screen */
    /* 25 lines and 80 columns each element takes 2 bytes */
    while(j < SCREEN_HEIGHT * SCREEN_WIDTH * 2) {
        // Clear the screen with ' ' <- Space character
        vidptr[j] = ' ';
        // Attribute-byte - light grey on black screen
        vidptr[j+1] = LIGHT_GREY_ON_BLACK;
        j += 2;
    }
}

void write_string(uint8_t *vidptr, const char *str) {
    uint32_t i = 0;
    while (*str) {
        vidptr[i] = *str;             // ASCII character
        vidptr[i + 1] = LIGHT_GREY_ON_BLACK;  // Attribute byte
        ++str;
        i += 2; // Advance by 2 since we write 2 bytes each time
    }
}

void kmain(void) {
    const char *str = "Hello, Kernel! This is my first kernel";
    uint8_t *vidptr = VID_MEM; // Video Memory begins here
    
    // Clear the screen with a black screen and grey chars
    clear_screen(vidptr);

    // Write the buffer to the cleared screen
    write_string(vidptr, str);
    return;
}
