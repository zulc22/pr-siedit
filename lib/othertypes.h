#ifndef OTHERTYPES_H
#define OTHERTYPES_H

#include "types.h"

namespace si {

class WAVFmt
{
public:
  // Standard WAV header
  uint16_t Format;
  uint16_t Channels;
  uint32_t SampleRate;
  uint32_t ByteRate;
  uint16_t BlockAlign;
  uint16_t BitsPerSample;

  // Mindscape extensions (not confirmed yet)
  uint32_t DataSize;
  uint32_t Flags;
};

// Copied from https://www.compuphase.com/flic.htm#FLICHEADER
class FLIC
{
public:
  uint32_t size;          /* Size of FLIC including this header */
  uint16_t type;          /* File type 0xAF11, 0xAF12, 0xAF30, 0xAF44, ... */
  uint16_t frames;        /* Number of frames in first segment */
  uint16_t width;         /* FLIC width in pixels */
  uint16_t height;        /* FLIC height in pixels */
  uint16_t depth;         /* Bits per pixel (usually 8) */
  uint16_t flags;         /* Set to zero or to three */
  uint32_t speed;         /* Delay between frames */
  uint16_t reserved1;     /* Set to zero */
  uint32_t created;       /* Date of FLIC creation (FLC only) */
  uint32_t creator;       /* Serial number or compiler id (FLC only) */
  uint32_t updated;       /* Date of FLIC update (FLC only) */
  uint32_t updater;       /* Serial number (FLC only), see creator */
  uint16_t aspect_dx;     /* Width of square rectangle (FLC only) */
  uint16_t aspect_dy;     /* Height of square rectangle (FLC only) */
  uint16_t ext_flags;     /* EGI: flags for specific EGI extensions */
  uint16_t keyframes;     /* EGI: key-image frequency */
  uint16_t totalframes;   /* EGI: total number of frames (segments) */
  uint32_t req_memory;    /* EGI: maximum chunk size (uncompressed) */
  uint16_t max_regions;   /* EGI: max. number of regions in a CHK_REGION chunk */
  uint16_t transp_num;    /* EGI: number of transparent levels */
  uint8_t reserved2[24]; /* Set to zero */
  uint32_t oframe1;       /* Offset to frame 1 (FLC only) */
  uint32_t oframe2;       /* Offset to frame 2 (FLC only) */
  uint8_t reserved3[40]; /* Set to zero */
};

// Copied from https://wiki.multimedia.cx/index.php/Smacker#Header
class SMK2
{
public:
  uint32_t Signature;
  uint32_t Width;
  uint32_t Height;
  uint32_t Frames;
  uint32_t FrameRate;
  uint32_t Flags;
  uint32_t AudioSize[7];
  uint32_t TreesSize;
  uint32_t MMap_Size;
  uint32_t MClr_Size;
  uint32_t Full_Size;
  uint32_t Type_Size;
  uint32_t AudioRate[7];
  uint32_t Dummy;
};

}

#endif // OTHERTYPES_H
