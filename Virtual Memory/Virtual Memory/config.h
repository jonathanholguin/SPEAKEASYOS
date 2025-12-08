#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

//Config Constants
constexpr int PAGE_SIZE = 256;       //Bytes per page (8-bit offset)
constexpr int PAGE_TABLE_SIZE = 256; //Number of entries (8-bit page number)
constexpr int PHYSICAL_FRAMES = 256; //Number of frames in RAM
constexpr int OFFSET_MASK = 255;     //0xFF
constexpr int PAGE_MASK = 65280;     //0xFF00

#endif