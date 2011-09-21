#include <stdlib.h>
#include <stdint.h>

/*
typedef struct {
    char magic[2];
    uint32_t file_size;
    uint32_t reserved;
    uint32_t offset;
} __attribute__((packed)) bmp_file_header_t;

typedef struct {
    uint32_t header_size;
    uint16_t image_width;
    uint16_t image_height;
    uint16_t color_planes; // must be 1
    uint16_t color_depth;
} __attribute__((packed)) bmp_dib_header_t;

typedef struct {
    bmp_file_header_t file_header;
    bmp_dib_header_t dib_header;
} __attribute__((packed)) bmp_header_t;
*/

void new_bmp_header(int width, int height, char* header);