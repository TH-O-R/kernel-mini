/* kernel.c */

#define VID_MEM ((char*)0xb8000)
#define LIGHT_GREY_ON_BLACK 0x07

void kmain(void) {
    const char *str = "Hello, Kernel! This is my first kernel";
    char *vidptr = VID_MEM; // Video Memory begins here
    // two variables for looping
    unsigned int i = 0;
    unsigned int j = 0;

    /* This loop clears the screen */
    /* 25 lines and 80 columns each element takes 2 bytes */
    while(j < 25 * 80 * 2) {
        // Clear the screen with ' ' <- Space character
        vidptr[j] = ' ';
        // Attribute-byte - light grey on black screen
        vidptr[j+1] = LIGHT_GREY_ON_BLACK;
        j += 2;
    }

    j=0;

    /* This loop writes the string to Video Memory */
    while(str[j] != '\0') {
        vidptr[i] = str[j]; // ASCII char
        vidptr[i+1] = LIGHT_GREY_ON_BLACK; // Attr byte
        ++j;
        i += 2;
    }
    return;
}
