// Copyright (c) 2022 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _MFX_UNIFIED_H264D_LOGGING_H_
#define _MFX_UNIFIED_H264D_LOGGING_H_

#include "mfx_config.h"

#include "umc_va_base.h"
#include "umc_h264_frame_list.h"
#include "mfx_unified_decode_logging.h"

typedef struct _EVENTDATA_SURFACEOUT_H264
{
    uint32_t  CropH;
    uint32_t  CropW;
    uint32_t  CropX;
    uint32_t  CropY;
    uint32_t  ChromaFormat;
    uint32_t  AspectRatioH;
    uint32_t  AspectRatioW;
    uint32_t  FrameRateExtD;
    uint32_t  FrameRateExtN;
    uint32_t  PicStruct;
    uint32_t  FrameOrder;
    uint32_t  DataFlag;
    uint32_t  TimeStamp;
} EVENTDATA_SURFACEOUT_H264D;


typedef struct _EVENTDATA_H264DPBINFO
{
    uint32_t PicOrderCnt[2];
    int32_t FrameId;
    uint32_t isShortTermRef;
    uint32_t isLongTermRef;
    int32_t refCounter;
} EVENTDATA_H264DPBINFO;

typedef struct _EVENTDATA_DPBINFO_H264D
{
    uint32_t eventCount;
    EVENTDATA_H264DPBINFO DpbInfo[16];
} EVENTDATA_DPBINFO_H264D;

typedef struct _EVENTDATA_QMATRIX_H264D
{
    uint32_t  bScalingLists4x4[6][16];
    uint32_t  bScalingLists8x8[2][64];
} EVENTDATA_QMATRIX_H264D;

void EventH264DecodeSurfaceOutparam(EVENTDATA_SURFACEOUT_H264D* pEventData, mfxFrameSurface1* surface_out);
void EventH264DecodeDpbInfo(EVENTDATA_DPBINFO_H264D* pEventData, UMC::H264DBPList* pDPBList);

#endif

