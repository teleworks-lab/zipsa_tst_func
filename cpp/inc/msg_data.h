/*
 * define transfer data format
 */
#include <iostream>

#define DATA_FORMAT_STRING
//#define DATA_FORMAT_STRUCTURE

#define MSQ_KEY_VAL     2278744

typedef struct cam_image_info
{
    int img_format;           // 0: raw_rgb,  1: raw_yuv:  2: jpeg,  3: png
    char file_path[100];
    char file_name[64];
} payload;

struct message
{
    long msg_type;
    payload data;
};

#if defined(DATA_FORMAT_STRUCTURE)
typedef struct message ZIPSA_MSG;
#elif defined(DATA_FORMAT_STRING)
typedef std::string ZIPSA_MSG;
#endif
