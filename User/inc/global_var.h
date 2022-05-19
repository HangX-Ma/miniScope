/**
 * @file global_var.h
 * @author MContour (m-contour@qq.com)
 * @brief Global variables
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Apache 2.0 LICENSE
 * 
 *****************************************************************************
 * Copyright (c) 2022 MContour m-contour@qq.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************
 */

#ifndef __GLOBAL_VAR__H__
#define __GLOBAL_VAR__H__

#include "core_stc8x.h"

#if (LIB_MCU_MODULE == STC8Ax)
    #include "config_stc8ax.h"
#elif (LIB_MCU_MODULE == STC8Hx)
    #include "config_stc8hx.h"
#endif

#define VBAT_UPDATE_FREQ            40              //!< Battery voltage information updating frequency VBAT_UPDATE_FREQ*25ms
#define VBAT_RATIO                  500             //!< 'battery voltage ratio' * 100,(2K+8K)/(2K)*100=5*100=500
#define CHX_VBAT_RATIO              500             //!< 'battery voltage ratio'
#define ADC_SAMPLE_BUF_SIZE         220             //!< ADC sampling point buffer size
#define ADC_SINGLE_TRIGGER_BUF_SIZE 62              //!< ADC single trigger sampling point buffer size

/* Region for waveform on display*/
#define CHART_H_MAX 127
#define CHART_H_MIN 32
#define CHART_V_MAX 53
#define CHART_V_MIN 10


extern uint16_t VBAT;                               //!< Battery voltage
extern uint16_t SVin_ratio;                         //!< Sampling port voltage division ratio

extern uint16_t G_WaveAvgLengthSumNum;              //!< Average wave length sum counts
extern uint32_t G_WaveAvgLengthSum;                 //!< Average wave length sum

extern bit      G_ADC_Complete_FLAG;                //!< ADC sampling complete flag
extern bit      G_ADC_Interrupt_FLAG;               //!< ADC sampling interrupt flag

extern bit      G_EC11PressWithRotate_FLAG;         //!< press and rotate EC11 flag

extern bit      G_PlotModeSel;                      //!< Plot mode selection, 0: vector, 1: dot
extern bit      G_MeasureWaySel;                    //!< Waveform measurement way selection, 0: DC, 1: AC

extern bit      G_Scale_Auto_FLAG;                  //!< Auto Scale flag
extern bit      G_WaveScroll_FLAG;                  //!< Waveform scrolling flag
extern bit      G_WaveUpdate_FLAG;                  //!< Waveform updating flag
extern bit      G_DisplayUpdate_FLAG;               //!< Screen display updated flag
extern bit      G_ClearDisplay_FLAG;                //!< Clear screen flag
extern bit      G_ClearWave_FLAG;                   //!< Clear waveform flag

extern int8_t   G_OLED_Brightness;                  //!< OLED brightness 1~254
extern bit      G_OLED_BrightnessChanged_FLAG;      //!< OLED brightness modified flag

extern uint16_t G_TriggerLevel_mV;                  //!< User setting trigger voltage level (mV)
extern uint16_t G_TriggerLevel_mV_Modified;         //!< User setting trigger voltage level (mV) [modified]
extern uint16_t G_TriggerADCx;                      //!< Trigger voltage level ADC conversion result
extern int8_t   G_TriggerPosOffset;                 //!< Trigger position offset
extern int8_t   G_TriggerPos;                       //!< Trigger Position
extern int8_t   G_TriggerMode;                      //!< Trigger Mode: 2: Single(stop sampling after triggering, manually waiting for next triggering), 1: Normal(stop sampling after triggering, automatically waiting for next triggering), 0: Auto(continuously sample, manually stop)
extern bit      G_TriggerSlope_FLAG;                //!< Trigger direction: 1: rising edge trigger, 0: falling edge trigger
extern bit      G_TriggerFail_FLAG;                 

extern int8_t   G_ScaleH;                           //!< time interval: 500ms ~ 100us
extern int32_t  G_VolV_Min;                         //!< Minimum voltage on vertical axis
extern int32_t  G_VolV_Max;                         //!< Maximum voltage on vertical axis
extern int32_t  G_VolV_Min_Modified;                //!< Minimum voltage on vertical axis (Modified)
extern int32_t  G_VolV_Max_Modified;                //!< Maximum voltage on vertical axis (Modified)
extern int32_t  G_VMin;                             //!< Minimum waveform voltage on screen
extern int32_t  G_VMax;                             //!< Maximum waveform voltage on screen (65535mV MAX)
extern int32_t  G_VMin_Modified;                    //!< Modified minimum waveform voltage on screen (-327675mV MIN)
extern int32_t  G_VMax_Modified;                    //!< Modified maximum waveform voltage on screen (+327675mV MAX)
extern int32_t  G_Voltage_Modified;                 //!< The modified measured voltages are positive and negative, divided into DC and AC.
extern int32_t  G_Bias_Voltage;                     //!< Bias voltage


extern int8_t   G_OptionInSettings;                 //!< setting options interface[ 0:PlotMode, 1:SVin_ratio, 2:OLED_Brightness ]
extern int8_t   G_OptionInChart;                    //!< main screen options interface[ 0:ScaleH, 1:ScaleV, 2:TriggerLevel, 3:TriggerSlope, 4:TriggerMode 5 MeasureWay ]

extern bit      G_State_Settings_FLAG;              //!< Setting interface state flag
extern bit      G_State_OptionChanged_FLAG;         //!< Options changed state flag

/* Time scale: 500ms, 200ms, 100ms, 50ms, 20ms, 10ms, 5ms, 2ms, 1ms, 500us, 200us, 100us */
typedef enum {
    Scale_500ms = 0x00,
    Scale_200ms,
    Scale_100ms,
    Scale_50ms,
    Scale_20ms,
    Scale_10ms,
    Scale_5ms,
    Scale_2ms,
    Scale_1ms,
    Scale_500us,
    Scale_200us,
    Scale_100us,
} ScaleSel_TypeDef;

typedef enum {
    TriggerSel_Auto = 0x00,
    TriggerSel_Normal,
    TriggerSel_Single,
} TriggerModeSel_TypeDef;

typedef enum {
    ChartSel_ScaleH = 0x00,
    ChartSel_ScaleV,
    ChartSel_TriggerLevel,
    ChartSel_TriggerSlope,
    ChartSel_TriggerMode,
    ChartSel_MeasureWay,
} OptionInChartSel_TypeDef;

typedef enum {
    SettingSel_PlotMode = 0x00,
    SettingSel_SVin_ratio,
    SettingSel_OLED_Brightness,
} OptionInSettingSel_TypeDef;

#endif  //!__GLOBAL_VAR__H__