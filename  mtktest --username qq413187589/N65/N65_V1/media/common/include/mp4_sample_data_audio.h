/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * mp4_sample_data_audio.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio sample data file accessing utilities for MPEG-4 recording
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __MP4_SAMPLE_DATA_AUDIO_H__
#define __MP4_SAMPLE_DATA_AUDIO_H__


#ifndef MP4_UT_ONWIN32
   /// For target and MoDIS
   #define MP4_PARSER_VERBOSE 0
   #include "kal_release.h"
   #include "l1d_cid.h"
   #include "med_status.h"
#else
   /// For Win32 standalone application, unit test and PC Simulator
   #include <stdio.h>
   #include <assert.h>
   #include <string.h>
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
   #define MP4_PARSER_VERBOSE 1
   #define kal_mem_cpy(a,b,c) memcpy(a,b,c)
   #include "kal_non_specific_general_types.h"
   #include "med_status.h"
#endif

#include "mp4_common.h"
#include "fsal.h"

typedef enum {
   MP4_SAMPLE_DATA_OK = MED_STAT_MP4_SAMPLEDATA_START,
   MP4_SAMPLE_DATA_FILE_READ_ERROR,
   MP4_SAMPLE_DATA_FILE_WRITE_ERROR,
   MP4_SAMPLE_DATA_FILE_SEEK_ERROR,
   MP4_SAMPLE_DATA_FILE_FORMAT_ERROR,
   MP4_SAMPLE_DATA_INVALID_ARGUMENT
} MP4_SampleData_Status;


typedef struct {
   STFSAL *pstFSAL;
   FSAL_Status eFSALErr;

   MP4_Audio_Type eAudioType;
   kal_bool    bIsVidEdit;
} STMp4SampleDataAudio;

/* ------ Private Macros ------ */

#define MP4_SAMPLE_DATA_CHECK_ARG(exp) \
   if (!(exp)) \
      return MP4_SAMPLE_DATA_INVALID_ARGUMENT

/* --- public functions --- */

extern MP4_SampleData_Status MP4_AudioSampleData_Init(STMp4SampleDataAudio *pstMp4SampleData, STFSAL *pstFSAL);
extern MP4_SampleData_Status MP4_AudioSampleData_SetVidEditFlag(STMp4SampleDataAudio *pstMp4SampleData);

extern MP4_Audio_Type MP4_AudioSampleData_GetAudioType(STMp4SampleDataAudio *pstMp4SampleData);

extern MP4_SampleData_Status MP4_AudioSampleData_GetSampleCount(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 *puSampleCount);
extern kal_bool MP4_AudioSampleData_EqualSampleSize(STMp4SampleDataAudio *pstMp4SampleData);
extern MP4_SampleData_Status MP4_AudioSampleData_GetSampleSize(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 uSampleNo, kal_uint32 *puSampleSize);
extern MP4_SampleData_Status MP4_AudioSampleData_GetSampleOffset(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 uSampleNo, kal_uint32 *puSampleOffset, kal_uint32 uSampleNo_Ref, kal_uint32 uSampleOffset_Ref);
extern MP4_SampleData_Status MP4_AudioSampleData_GetTimeScale(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 *puTimeScale);
extern MP4_SampleData_Status MP4_AudioSampleData_Get_FMT_MP4A_Size(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 *puSize);
extern MP4_SampleData_Status MP4_AudioSampleData_Get_FMT_MP4A_Data(STMp4SampleDataAudio *pstMp4SampleData, kal_uint8 *pbData, kal_uint32 size);
extern MP4_SampleData_Status MP4_AudioSampleData_WriteSampleCount(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 uSampleCount);
#endif


