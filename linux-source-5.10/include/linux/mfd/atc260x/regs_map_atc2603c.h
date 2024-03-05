/*
 * ATC2603C Spec Version_V1.03
 */

#ifndef __ATC2603C_REG_DEFINITION_H___
#define __ATC2603C_REG_DEFINITION_H___

/* PMU Register Address */
#define ATC2603C_PMU_BASE			(0X00)
#define ATC2603C_PMU_SYS_CTL0			(ATC2603C_PMU_BASE + 0x00)
#define ATC2603C_PMU_SYS_CTL1			(ATC2603C_PMU_BASE + 0x01)
#define ATC2603C_PMU_SYS_CTL2			(ATC2603C_PMU_BASE + 0x02)
#define ATC2603C_PMU_SYS_CTL3			(ATC2603C_PMU_BASE + 0x03)
#define ATC2603C_PMU_SYS_CTL4			(ATC2603C_PMU_BASE + 0x04)
#define ATC2603C_PMU_SYS_CTL5			(ATC2603C_PMU_BASE + 0x05)
#define ATC2603C_PMU_SYS_CTL6			(ATC2603C_PMU_BASE + 0x06)
#define ATC2603C_PMU_SYS_CTL7			(ATC2603C_PMU_BASE + 0x07)
#define ATC2603C_PMU_SYS_CTL8			(ATC2603C_PMU_BASE + 0x08)
#define ATC2603C_PMU_SYS_CTL9			(ATC2603C_PMU_BASE + 0x09)
#define ATC2603C_PMU_BAT_CTL0			(ATC2603C_PMU_BASE + 0x0A)
#define ATC2603C_PMU_BAT_CTL1			(ATC2603C_PMU_BASE + 0x0B)
#define ATC2603C_PMU_VBUS_CTL0			(ATC2603C_PMU_BASE + 0x0C)
#define ATC2603C_PMU_VBUS_CTL1			(ATC2603C_PMU_BASE + 0x0D)
#define ATC2603C_PMU_WALL_CTL0			(ATC2603C_PMU_BASE + 0x0E)
#define ATC2603C_PMU_WALL_CTL1			(ATC2603C_PMU_BASE + 0x0F)
#define ATC2603C_PMU_SYS_PENDING		(ATC2603C_PMU_BASE + 0x10)
#define ATC2603C_PMU_DC1_CTL0			(ATC2603C_PMU_BASE + 0x11)
#define ATC2603C_PMU_DC1_CTL1			(ATC2603C_PMU_BASE + 0x12)
#define ATC2603C_PMU_DC1_CTL2			(ATC2603C_PMU_BASE + 0x13)
#define ATC2603C_PMU_DC2_CTL0			(ATC2603C_PMU_BASE + 0x14)
#define ATC2603C_PMU_DC2_CTL1			(ATC2603C_PMU_BASE + 0x15)
#define ATC2603C_PMU_DC2_CTL2			(ATC2603C_PMU_BASE + 0x16)
#define ATC2603C_PMU_DC3_CTL0			(ATC2603C_PMU_BASE + 0x17)
#define ATC2603C_PMU_DC3_CTL1			(ATC2603C_PMU_BASE + 0x18)
#define ATC2603C_PMU_DC3_CTL2			(ATC2603C_PMU_BASE + 0x19)
#define ATC2603C_PMU_DC4_CTL0			(ATC2603C_PMU_BASE + 0x1A)
#define ATC2603C_PMU_DC4_CTL1			(ATC2603C_PMU_BASE + 0x1B)
#define ATC2603C_PMU_DC5_CTL0			(ATC2603C_PMU_BASE + 0x1C)
#define ATC2603C_PMU_DC5_CTL1			(ATC2603C_PMU_BASE + 0x1D)
#define ATC2603C_PMU_LDO1_CTL			(ATC2603C_PMU_BASE + 0x1E)
#define ATC2603C_PMU_LDO2_CTL			(ATC2603C_PMU_BASE + 0x1F)
#define ATC2603C_PMU_LDO3_CTL			(ATC2603C_PMU_BASE + 0x20)
#define ATC2603C_PMU_LDO4_CTL			(ATC2603C_PMU_BASE + 0x21)
#define ATC2603C_PMU_LDO5_CTL			(ATC2603C_PMU_BASE + 0x22)
#define ATC2603C_PMU_LDO6_CTL			(ATC2603C_PMU_BASE + 0x23)
#define ATC2603C_PMU_LDO7_CTL			(ATC2603C_PMU_BASE + 0x24)
#define ATC2603C_PMU_LDO8_CTL			(ATC2603C_PMU_BASE + 0x25)
#define ATC2603C_PMU_LDO9_CTL			(ATC2603C_PMU_BASE + 0x26)
#define ATC2603C_PMU_LDO10_CTL			(ATC2603C_PMU_BASE + 0x27)
#define ATC2603C_PMU_LDO11_CTL			(ATC2603C_PMU_BASE + 0x28)
#define ATC2603C_PMU_SWITCH_CTL			(ATC2603C_PMU_BASE + 0x29)
#define ATC2603C_PMU_OV_CTL0			(ATC2603C_PMU_BASE + 0x2A)
#define ATC2603C_PMU_OV_CTL1			(ATC2603C_PMU_BASE + 0x2B)
#define ATC2603C_PMU_OV_STATUS			(ATC2603C_PMU_BASE + 0x2C)
#define ATC2603C_PMU_OV_EN			(ATC2603C_PMU_BASE + 0x2D)
#define ATC2603C_PMU_OV_INT_EN			(ATC2603C_PMU_BASE + 0x2E)
#define ATC2603C_PMU_OC_CTL			(ATC2603C_PMU_BASE + 0x2F)
#define ATC2603C_PMU_OC_STATUS			(ATC2603C_PMU_BASE + 0x30)
#define ATC2603C_PMU_OC_EN			(ATC2603C_PMU_BASE + 0x31)
#define ATC2603C_PMU_OC_INT_EN			(ATC2603C_PMU_BASE + 0x32)
#define ATC2603C_PMU_UV_CTL0			(ATC2603C_PMU_BASE + 0x33)
#define ATC2603C_PMU_UV_CTL1			(ATC2603C_PMU_BASE + 0x34)
#define ATC2603C_PMU_UV_STATUS			(ATC2603C_PMU_BASE + 0x35)
#define ATC2603C_PMU_UV_EN			(ATC2603C_PMU_BASE + 0x36)
#define ATC2603C_PMU_UV_INT_EN			(ATC2603C_PMU_BASE + 0x37)
#define ATC2603C_PMU_OT_CTL			(ATC2603C_PMU_BASE + 0x38)
#define ATC2603C_PMU_CHARGER_CTL0		(ATC2603C_PMU_BASE + 0x39)
#define ATC2603C_PMU_CHARGER_CTL1		(ATC2603C_PMU_BASE + 0x3A)
#define ATC2603C_PMU_CHARGER_CTL2		(ATC2603C_PMU_BASE + 0x3B)
#define ATC2603C_PMU_BAKCHARGER_CTL		(ATC2603C_PMU_BASE + 0x3C)
#define ATC2603C_PMU_APDS_CTL			(ATC2603C_PMU_BASE + 0x3D)
#define ATC2603C_PMU_AUXADC_CTL0		(ATC2603C_PMU_BASE + 0x3E)
#define ATC2603C_PMU_AUXADC_CTL1		(ATC2603C_PMU_BASE + 0x3F)
#define ATC2603C_PMU_BATVADC			(ATC2603C_PMU_BASE + 0x40)
#define ATC2603C_PMU_BATIADC			(ATC2603C_PMU_BASE + 0x41)
#define ATC2603C_PMU_WALLVADC			(ATC2603C_PMU_BASE + 0x42)
#define ATC2603C_PMU_WALLIADC			(ATC2603C_PMU_BASE + 0x43)
#define ATC2603C_PMU_VBUSVADC			(ATC2603C_PMU_BASE + 0x44)
#define ATC2603C_PMU_VBUSIADC			(ATC2603C_PMU_BASE + 0x45)
#define ATC2603C_PMU_SYSPWRADC			(ATC2603C_PMU_BASE + 0x46)
#define ATC2603C_PMU_REMCONADC			(ATC2603C_PMU_BASE + 0x47)
#define ATC2603C_PMU_SVCCADC			(ATC2603C_PMU_BASE + 0x48)
#define ATC2603C_PMU_CHGIADC			(ATC2603C_PMU_BASE + 0x49)
#define ATC2603C_PMU_IREFADC			(ATC2603C_PMU_BASE + 0x4A)
#define ATC2603C_PMU_BAKBATADC			(ATC2603C_PMU_BASE + 0x4B)
#define ATC2603C_PMU_ICTEMPADC			(ATC2603C_PMU_BASE + 0x4C)
#define ATC2603C_PMU_AUXADC0			(ATC2603C_PMU_BASE + 0x4D)
#define ATC2603C_PMU_AUXADC1			(ATC2603C_PMU_BASE + 0x4E)
#define ATC2603C_PMU_AUXADC2			(ATC2603C_PMU_BASE + 0x4F)
#define	ATC2603C_PMU_ICMADC			(ATC2603C_PMU_BASE + 0x50)
#define ATC2603C_PMU_BDG_CTL			(ATC2603C_PMU_BASE + 0x51)
#define ATC2603C_RTC_CTL			(ATC2603C_PMU_BASE + 0x52)
#define ATC2603C_RTC_MSALM			(ATC2603C_PMU_BASE + 0x53)
#define ATC2603C_RTC_HALM			(ATC2603C_PMU_BASE + 0x54)
#define ATC2603C_RTC_YMDALM			(ATC2603C_PMU_BASE + 0x55)
#define ATC2603C_RTC_MS				(ATC2603C_PMU_BASE + 0x56)
#define ATC2603C_RTC_H				(ATC2603C_PMU_BASE + 0x57)
#define ATC2603C_RTC_DC				(ATC2603C_PMU_BASE + 0x58)
#define ATC2603C_RTC_YMD			(ATC2603C_PMU_BASE + 0x59)
#define ATC2603C_EFUSE_DAT			(ATC2603C_PMU_BASE + 0x5A)
#define ATC2603C_EFUSECRTL1			(ATC2603C_PMU_BASE + 0x5B)
#define ATC2603C_EFUSECRTL2			(ATC2603C_PMU_BASE + 0x5C)
#define ATC2603C_PMU_FW_USE0			(ATC2603C_PMU_BASE + 0x5D)
#define ATC2603C_PMU_FW_USE1			(ATC2603C_PMU_BASE + 0x5E)
#define ATC2603C_PMU_FW_USE2			(ATC2603C_PMU_BASE + 0x5F)
#define ATC2603C_PMU_FW_USE3			(ATC2603C_PMU_BASE + 0x60)
#define ATC2603C_PMU_FW_USE4			(ATC2603C_PMU_BASE + 0x61)
#define ATC2603C_PMU_ABNORMAL_STATUS		(ATC2603C_PMU_BASE + 0x62)
#define ATC2603C_PMU_WALL_APDS_CTL		(ATC2603C_PMU_BASE + 0x63)
#define ATC2603C_PMU_REMCON_CTL0		(ATC2603C_PMU_BASE + 0x64)
#define ATC2603C_PMU_REMCON_CTL1		(ATC2603C_PMU_BASE + 0x65)
#define ATC2603C_PMU_MUX_CTL0			(ATC2603C_PMU_BASE + 0x66)
#define ATC2603C_PMU_SGPIO_CTL0			(ATC2603C_PMU_BASE + 0x67)
#define ATC2603C_PMU_SGPIO_CTL1			(ATC2603C_PMU_BASE + 0x68)
#define ATC2603C_PMU_SGPIO_CTL2			(ATC2603C_PMU_BASE + 0x69)
#define ATC2603C_PMU_SGPIO_CTL3			(ATC2603C_PMU_BASE + 0x6A)
#define ATC2603C_PMU_SGPIO_CTL4			(ATC2603C_PMU_BASE + 0x6B)
#define ATC2603C_PWMCLK_CTL			(ATC2603C_PMU_BASE + 0x6C)
#define ATC2603C_PWM0_CTL			(ATC2603C_PMU_BASE + 0x6D)
#define ATC2603C_PWM1_CTL			(ATC2603C_PMU_BASE + 0x6E)
#define ATC2603C_PMU_ADC_DBG0			(ATC2603C_PMU_BASE + 0x70)
#define ATC2603C_PMU_ADC_DBG1			(ATC2603C_PMU_BASE + 0x71)
#define ATC2603C_PMU_ADC_DBG2			(ATC2603C_PMU_BASE + 0x72)
#define ATC2603C_PMU_ADC_DBG3			(ATC2603C_PMU_BASE + 0x73)
#define ATC2603C_PMU_ADC_DBG4			(ATC2603C_PMU_BASE + 0x74)
#define ATC2603C_IRC_CTL			(ATC2603C_PMU_BASE + 0x80)
#define ATC2603C_IRC_STAT			(ATC2603C_PMU_BASE + 0x81)
#define ATC2603C_IRC_CC				(ATC2603C_PMU_BASE + 0x82)
#define ATC2603C_IRC_KDC			(ATC2603C_PMU_BASE + 0x83)
#define ATC2603C_IRC_WK				(ATC2603C_PMU_BASE + 0x84)
#define ATC2603C_IRC_RCC			(ATC2603C_PMU_BASE + 0x85)
#define ATC2603C_IRC_FILTER			(ATC2603C_PMU_BASE + 0x86)

/* AUDIO_OUT Register Address */
#define ATC2603C_AUDIO_OUT_BASE			(0xA0)
#define ATC2603C_AUDIOINOUT_CTL			(ATC2603C_AUDIO_OUT_BASE + 0x0)
#define ATC2603C_AUDIO_DEBUGOUTCTL		(ATC2603C_AUDIO_OUT_BASE + 0x1)
#define ATC2603C_DAC_DIGITALCTL			(ATC2603C_AUDIO_OUT_BASE + 0x2)
#define ATC2603C_DAC_VOLUMECTL0			(ATC2603C_AUDIO_OUT_BASE + 0x3)
#define ATC2603C_DAC_ANALOG0			(ATC2603C_AUDIO_OUT_BASE + 0x4)
#define ATC2603C_DAC_ANALOG1			(ATC2603C_AUDIO_OUT_BASE + 0x5)
#define ATC2603C_DAC_ANALOG2			(ATC2603C_AUDIO_OUT_BASE + 0x6)
#define ATC2603C_DAC_ANALOG3			(ATC2603C_AUDIO_OUT_BASE + 0x7)

/* AUDIO_IN Register Address */
#define ATC2603C_AUDIO_IN_BASE			(0xA0)
#define ATC2603C_ADC_DIGITALCTL			(ATC2603C_AUDIO_IN_BASE + 0x8)
#define ATC2603C_ADC_HPFCTL			(ATC2603C_AUDIO_IN_BASE + 0x9)
#define ATC2603C_ADC_CTL			(ATC2603C_AUDIO_IN_BASE + 0xA)
#define ATC2603C_AGC_CTL0			(ATC2603C_AUDIO_IN_BASE + 0xB)
#define ATC2603C_AGC_CTL1			(ATC2603C_AUDIO_IN_BASE + 0xC)
#define ATC2603C_AGC_CTL2			(ATC2603C_AUDIO_IN_BASE + 0xD)
#define ATC2603C_ADC_ANALOG0			(ATC2603C_AUDIO_IN_BASE + 0xE)
#define ATC2603C_ADC_ANALOG1			(ATC2603C_AUDIO_IN_BASE + 0xF)

/* PCM_IF Register Address */
#define ATC2603C_PCM_IF_BASE			(0xA0)
#define ATC2603C_PCM0_CTL			(ATC2603C_PCM_IF_BASE + 0x10)
#define ATC2603C_PCM1_CTL			(ATC2603C_PCM_IF_BASE + 0x11)
#define ATC2603C_PCM2_CTL			(ATC2603C_PCM_IF_BASE + 0x12)
#define ATC2603C_PCMIF_CTL			(ATC2603C_PCM_IF_BASE + 0x13)

/* CMU_CONTROL Register Address */
#define ATC2603C_CMU_CONTROL_BASE		(0xC0)
#define ATC2603C_CMU_DEVRST			(ATC2603C_CMU_CONTROL_BASE + 0x1)

/* INTS Register Address */
#define ATC2603C_INTS_BASE			(0xC8)
#define ATC2603C_INTS_PD			(ATC2603C_INTS_BASE + 0x0)
#define ATC2603C_INTS_MSK			(ATC2603C_INTS_BASE + 0x1)

/* MFP Register Address */
#define ATC2603C_MFP_BASE			(0xD0)
#define ATC2603C_MFP_CTL			(ATC2603C_MFP_BASE + 0x00)
#define ATC2603C_PAD_VSEL			(ATC2603C_MFP_BASE + 0x01)
#define ATC2603C_GPIO_OUTEN			(ATC2603C_MFP_BASE + 0x02)
#define ATC2603C_GPIO_INEN			(ATC2603C_MFP_BASE + 0x03)
#define ATC2603C_GPIO_DAT			(ATC2603C_MFP_BASE + 0x04)
#define ATC2603C_PAD_DRV			(ATC2603C_MFP_BASE + 0x05)
#define ATC2603C_PAD_EN				(ATC2603C_MFP_BASE + 0x06)
#define ATC2603C_DEBUG_SEL			(ATC2603C_MFP_BASE + 0x07)
#define ATC2603C_DEBUG_IE			(ATC2603C_MFP_BASE + 0x08)
#define ATC2603C_DEBUG_OE			(ATC2603C_MFP_BASE + 0x09)
#define ATC2603C_BIST_START			(ATC2603C_MFP_BASE + 0x0A)
#define ATC2603C_BIST_RESULT		(ATC2603C_MFP_BASE + 0x0B)
#define ATC2603C_CHIP_VER			(ATC2603C_MFP_BASE + 0x0C)

/* TWSI Register Address */
#define ATC2603C_TWI_BASE			(0xF8)
#define ATC2603C_SADDR				(ATC2603C_TWI_BASE + 0x7)

#endif
