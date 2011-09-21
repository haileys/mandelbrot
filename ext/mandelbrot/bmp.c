#include "bmp.h"

void new_bmp_header(int width, int height, char* header)
{
    header[0] = 'B';
    header[1] = 'M';
    
    // file size
    *(uint32_t*)&(header[2]) = 54 + (((24 * width + 31)/32) * 4) * height;
    
    // reserved
    *(uint32_t*)&(header[6]) = 0;
    
    // offset
    *(uint32_t*)&(header[10]) = 54;
    
    // dib header size
    *(uint32_t*)&(header[14]) = 40;
    
    // width
    *(uint32_t*)&(header[18]) = width;
    
    // height
    *(uint32_t*)&(header[22]) = height;
    
    // planes
    *(uint16_t*)&(header[26]) = 1;
    
    // depth
    *(uint16_t*)&(header[28]) = 24;
    
    // compression
    *(uint32_t*)&(header[30]) = 0;
    
    // image size
    *(uint32_t*)&(header[34]) = (((24 * width + 31)/32) * 4) * height;
    
    // horiz resolution
    *(uint32_t*)&(header[38]) = 72;
    
    // vert resolution
    *(uint32_t*)&(header[42]) = 72;
    
    // colour palette
    *(uint32_t*)&(header[46]) = 0;
    
    // important colours
    *(uint32_t*)&(header[50]) = 0;
    
    /*
    header->file_header.magic[0] = 'B';
    header->file_header.magic[1] = 'M';
    header->file_header.file_size = (uint32_t)sizeof(bmp_header_t) + (((24 * width + 31)/32) * 4) * height;
    header->file_header.reserved = 0;
    header->file_header.offset = sizeof(bmp_header_t);
    
    header->dib_header.header_size = sizeof(bmp_dib_header_t);
    header->dib_header.image_width = width;
    header->dib_header.image_height = height;
    header->dib_header.color_planes = 1;
    header->dib_header.color_depth = 24;    
    */
}