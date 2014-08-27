/*
 * max77804k-private.h - Voltage regulator driver for the Maxim 77804k
 *
 *  Copyright (C) 2011 Samsung Electrnoics
 *  SangYoung Son <hello.son@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINUX_MFD_MAX77804K_PRIV_H
#define __LINUX_MFD_MAX77804K_PRIV_H

#include <linux/i2c.h>

#define MAX77804K_NUM_IRQ_MUIC_REGS	3
#define MAX77804K_REG_INVALID		(0xff)

#define MAX77804K_IRQSRC_CHG		(1 << 0)
#define MAX77804K_IRQSRC_TOP		(1 << 1)
#define MAX77804K_IRQSRC_FLASH		(1 << 2)
#define MAX77804K_IRQSRC_MUIC		(1 << 3)

/* pmic revision */
enum max77804k_pmic_rev {
	MAX77804K_REV_PASS1	= 0x00,
	MAX77804K_REV_PASS2	= 0x01,
	MAX77804K_REV_PASS3	= 0x02,
};

/* Slave addr = 0xCC: Charger, Flash LED, Haptic */
enum max77804k_pmic_reg {
	MAX77804K_LED_REG_IFLASH				= 0x00,
	MAX77804K_LED_REG_RESERVED_01			= 0x01,
	MAX77804K_LED_REG_ITORCH				= 0x02,
	MAX77804K_LED_REG_ITORCHTORCHTIMER		= 0x03,
	MAX77804K_LED_REG_FLASH_TIMER			= 0x04,
	MAX77804K_LED_REG_FLASH_EN			= 0x05,
	MAX77804K_LED_REG_MAX_FLASH1			= 0x06,
	MAX77804K_LED_REG_MAX_FLASH2			= 0x07,
	MAX77804K_LED_REG_MAX_FLASH3			= 0x08,
	MAX77804K_LED_REG_MAX_FLASH4			= 0x09,
	MAX77804K_LED_REG_VOUT_CNTL			= 0x0A,
	MAX77804K_LED_REG_VOUT_FLASH			= 0x0B,
	MAX77804K_LED_REG_RESERVED_0C			= 0x0C,
	MAX77804K_LED_REG_RESERVED_0D			= 0x0D,
	MAX77804K_LED_REG_FLASH_INT			= 0x0E,
	MAX77804K_LED_REG_FLASH_INT_MASK			= 0x0F,
	MAX77804K_LED_REG_FLASH_INT_STATUS		= 0x10,
	MAX77804K_LED_REG_RESERVED_11			= 0x11,

	MAX77804K_PMIC_REG_PMIC_ID1			= 0x20,
	MAX77804K_PMIC_REG_PMIC_ID2			= 0x21,
	MAX77804K_PMIC_REG_INTSRC			= 0x22,
	MAX77804K_PMIC_REG_INTSRC_MASK			= 0x23,
	MAX77804K_PMIC_REG_TOPSYS_INT			= 0x24,
	MAX77804K_PMIC_REG_RESERVED_25			= 0x25,
	MAX77804K_PMIC_REG_TOPSYS_INT_MASK		= 0x26,
	MAX77804K_PMIC_REG_RESERVED_27			= 0x27,
	MAX77804K_PMIC_REG_TOPSYS_STAT			= 0x28,
	MAX77804K_PMIC_REG_RESERVED_29			= 0x29,
	MAX77804K_PMIC_REG_MAINCTRL1			= 0x2A,
	MAX77804K_PMIC_REG_LSCNFG			= 0x2B,
	MAX77804K_PMIC_REG_RESERVED_2C			= 0x2C,
	MAX77804K_PMIC_REG_RESERVED_2D			= 0x2D,

	MAX77804K_CHG_REG_CHG_INT			= 0xB0,
	MAX77804K_CHG_REG_CHG_INT_MASK			= 0xB1,
	MAX77804K_CHG_REG_CHG_INT_OK			= 0xB2,
	MAX77804K_CHG_REG_CHG_DTLS_00			= 0xB3,
	MAX77804K_CHG_REG_CHG_DTLS_01			= 0xB4,
	MAX77804K_CHG_REG_CHG_DTLS_02			= 0xB5,
	MAX77804K_CHG_REG_CHG_DTLS_03			= 0xB6,
	MAX77804K_CHG_REG_CHG_CNFG_00			= 0xB7,
	MAX77804K_CHG_REG_CHG_CNFG_01			= 0xB8,
	MAX77804K_CHG_REG_CHG_CNFG_02			= 0xB9,
	MAX77804K_CHG_REG_CHG_CNFG_03			= 0xBA,
	MAX77804K_CHG_REG_CHG_CNFG_04			= 0xBB,
	MAX77804K_CHG_REG_CHG_CNFG_05			= 0xBC,
	MAX77804K_CHG_REG_CHG_CNFG_06			= 0xBD,
	MAX77804K_CHG_REG_CHG_CNFG_07			= 0xBE,
	MAX77804K_CHG_REG_CHG_CNFG_08			= 0xBF,
	MAX77804K_CHG_REG_CHG_CNFG_09			= 0xC0,
	MAX77804K_CHG_REG_CHG_CNFG_10			= 0xC1,
	MAX77804K_CHG_REG_CHG_CNFG_11			= 0xC2,
	MAX77804K_CHG_REG_CHG_CNFG_12			= 0xC3,
	MAX77804K_CHG_REG_CHG_CNFG_13			= 0xC4,
	MAX77804K_CHG_REG_CHG_CNFG_14			= 0xC5,
	MAX77804K_CHG_REG_SAFEOUT_CTRL			= 0xC6,

	MAX77804K_PMIC_REG_END,
};

/* Slave addr = 0x4A: MUIC */
enum max77804k_muic_reg {
	MAX77804K_MUIC_REG_ID		= 0x00,
	MAX77804K_MUIC_REG_INT1		= 0x01,
	MAX77804K_MUIC_REG_INT2		= 0x02,
	MAX77804K_MUIC_REG_INT3		= 0x03,
	MAX77804K_MUIC_REG_STATUS1	= 0x04,
	MAX77804K_MUIC_REG_STATUS2	= 0x05,
	MAX77804K_MUIC_REG_STATUS3	= 0x06,
	MAX77804K_MUIC_REG_INTMASK1	= 0x07,
	MAX77804K_MUIC_REG_INTMASK2	= 0x08,
	MAX77804K_MUIC_REG_INTMASK3	= 0x09,
	MAX77804K_MUIC_REG_CDETCTRL1	= 0x0A,
	MAX77804K_MUIC_REG_CDETCTRL2	= 0x0B,
	MAX77804K_MUIC_REG_CTRL1		= 0x0C,
	MAX77804K_MUIC_REG_CTRL2		= 0x0D,
	MAX77804K_MUIC_REG_CTRL3		= 0x0E,
	MAX77804K_MUIC_REG_CTRL4		= 0x16,

	MAX77804K_MUIC_REG_END,
};

/* Slave addr = 0x90: Haptic */
enum max77804k_haptic_reg {
	MAX77804K_HAPTIC_REG_STATUS		= 0x00,
	MAX77804K_HAPTIC_REG_CONFIG1		= 0x01,
	MAX77804K_HAPTIC_REG_CONFIG2		= 0x02,
	MAX77804K_HAPTIC_REG_CONFIG_CHNL		= 0x03,
	MAX77804K_HAPTIC_REG_CONFG_CYC1		= 0x04,
	MAX77804K_HAPTIC_REG_CONFG_CYC2		= 0x05,
	MAX77804K_HAPTIC_REG_CONFIG_PER1		= 0x06,
	MAX77804K_HAPTIC_REG_CONFIG_PER2		= 0x07,
	MAX77804K_HAPTIC_REG_CONFIG_PER3		= 0x08,
	MAX77804K_HAPTIC_REG_CONFIG_PER4		= 0x09,
	MAX77804K_HAPTIC_REG_CONFIG_DUTY1	= 0x0A,
	MAX77804K_HAPTIC_REG_CONFIG_DUTY2	= 0x0B,
	MAX77804K_HAPTIC_REG_CONFIG_PWM1		= 0x0C,
	MAX77804K_HAPTIC_REG_CONFIG_PWM2		= 0x0D,
	MAX77804K_HAPTIC_REG_CONFIG_PWM3		= 0x0E,
	MAX77804K_HAPTIC_REG_CONFIG_PWM4		= 0x0F,
	MAX77804K_HAPTIC_REG_REV			= 0x10,

	MAX77804K_HAPTIC_REG_END,
};

/* MAX77804K REGISTER ENABLE or DISABLE bit */
#define MAX77804K_ENABLE_BIT 1
#define MAX77804K_DISABLE_BIT 0

/* MAX77804K CHG_CNFG_00 register */
#define CHG_CNFG_00_MODE_SHIFT		0
#define CHG_CNFG_00_CHG_SHIFT		0
#define CHG_CNFG_00_OTG_SHIFT		1
#define CHG_CNFG_00_BUCK_SHIFT		2
#define CHG_CNFG_00_BOOST_SHIFT		3
#define CHG_CNFG_00_DIS_MUIC_CTRL_SHIFT	5
#define CHG_CNFG_00_MODE_MASK		(0xf << CHG_CNFG_00_MODE_SHIFT)
#define CHG_CNFG_00_CHG_MASK		(1 << CHG_CNFG_00_CHG_SHIFT)
#define CHG_CNFG_00_OTG_MASK		(1 << CHG_CNFG_00_OTG_SHIFT)
#define CHG_CNFG_00_BUCK_MASK		(1 << CHG_CNFG_00_BUCK_SHIFT)
#define CHG_CNFG_00_BOOST_MASK		(1 << CHG_CNFG_00_BOOST_SHIFT)
#define CHG_CNFG_00_DIS_MUIC_CTRL_MASK	(1 << CHG_CNFG_00_DIS_MUIC_CTRL_SHIFT)

/* MAX77804K CHG_CNFG_04 register */
#define CHG_CNFG_04_CHG_CV_PRM_SHIFT		0
#define CHG_CNFG_04_CHG_CV_PRM_MASK		(0x1f << CHG_CNFG_04_CHG_CV_PRM_SHIFT)

/* MAX77804K CHG_CNFG_12 register */
#define CHG_CNFG_12_CHGINSEL_SHIFT		5
#define CHG_CNFG_12_CHGINSEL_MASK		(0x1 << CHG_CNFG_12_CHGINSEL_SHIFT)

/* MAX77804K STATUS1 register */
#define STATUS1_ADC_SHIFT		0
#define STATUS1_ADCLOW_SHIFT		5
#define STATUS1_ADCERR_SHIFT		6
#define STATUS1_ADC1K_SHIFT		7
#define STATUS1_ADC_MASK		(0x1f << STATUS1_ADC_SHIFT)
#define STATUS1_ADCLOW_MASK		(0x1 << STATUS1_ADCLOW_SHIFT)
#define STATUS1_ADCERR_MASK		(0x1 << STATUS1_ADCERR_SHIFT)
#define STATUS1_ADC1K_MASK		(0x1 << STATUS1_ADC1K_SHIFT)

/* MAX77804K STATUS2 register */
#define STATUS2_CHGTYP_SHIFT		0
#define STATUS2_CHGDETRUN_SHIFT		3
#define STATUS2_DXOVP_SHIFT		5
#define STATUS2_VBVOLT_SHIFT		6
#define STATUS2_CHGTYP_MASK		(0x7 << STATUS2_CHGTYP_SHIFT)
#define STATUS2_CHGDETRUN_MASK		(0x1 << STATUS2_CHGDETRUN_SHIFT)
#define STATUS2_DXOVP_MASK		(0x1 << STATUS2_DXOVP_SHIFT)
#define STATUS2_VBVOLT_MASK		(0x1 << STATUS2_VBVOLT_SHIFT)

/* MAX77804K CDETCTRL1 register */
#define CHGDETEN_SHIFT			0
#define CHGTYPM_SHIFT			1
#define CHGDETEN_MASK			(0x1 << CHGDETEN_SHIFT)
#define CHGTYPM_MASK			(0x1 << CHGTYPM_SHIFT)

/* MAX77804K CONTROL1 register */
#define CLEAR_IDBEN_MICEN_MASK	0x3f
#define COMN1SW_SHIFT				0x0
#define COMP2SW_SHIFT				0x3
#define MICEN_SHIFT					0x6
#define COMN1SW_MASK				(0x7 << COMN1SW_SHIFT)
#define COMP2SW_MASK				(0x7 << COMP2SW_SHIFT)
#define MICEN_MASK					(0x1 << MICEN_SHIFT)

/* MAX77804K CONTROL2 register */
#define CTRL2_ACCDET_SHIFT		5
#define CTRL2_ACCDET_MASK		(0x1 << CTRL2_ACCDET_SHIFT)
#define CTRL2_CPEn_SHIFT		2
#define CTRL2_CPEn_MASK		(0x1 << CTRL2_CPEn_SHIFT)
#define CTRL2_LOWPWD_SHIFT		0
#define CTRL2_LOWPWD_MASK		(0x1 << CTRL2_LOWPWD_SHIFT)
#define CTRL2_CPEn1_LOWPWD0 ((MAX77804K_ENABLE_BIT << CTRL2_CPEn_SHIFT) | \
				(MAX77804K_DISABLE_BIT << CTRL2_LOWPWD_SHIFT))
#define CTRL2_CPEn0_LOWPWD1 ((MAX77804K_DISABLE_BIT << CTRL2_CPEn_SHIFT) | \
				(MAX77804K_ENABLE_BIT << CTRL2_LOWPWD_SHIFT))

/* MAX77804K CONTROL3 register */
#define CTRL3_JIGSET_SHIFT		0
#define CTRL3_BOOTSET_SHIFT		2
#define CTRL3_ADCDBSET_SHIFT	4
#define CTRL3_JIGSET_MASK		(0x3 << CTRL3_JIGSET_SHIFT)
#define CTRL3_BOOTSET_MASK		(0x3 << CTRL3_BOOTSET_SHIFT)
#define CTRL3_ADCDBSET_MASK		(0x3 << CTRL3_ADCDBSET_SHIFT)

/* MAX77804 CONTROL4 register */
#define CTRL4_ADCMODE_SHIFT		6
#define CTRL4_ADCDBSET_SHIFT	0
#define CTRL4_ADCMODE_MASK		(0x3 << CTRL4_ADCMODE_SHIFT)
#define CTRL4_ADCDBSET_MASK		(0x3 << CTRL4_ADCDBSET_SHIFT)

/* Interrupt 1 */
#define INT_DETACH		(0x1 << 1)
#define INT_ATTACH		(0x1 << 0)

/* muic register value for COMN1, COMN2 in CTRL1 reg  */
enum max77804k_reg_ctrl1_val {
	MAX77804K_MUIC_CTRL1_BIN_0_000 = 0x00,
	MAX77804K_MUIC_CTRL1_BIN_1_001 = 0x01,
	MAX77804K_MUIC_CTRL1_BIN_2_010 = 0x02,
	MAX77804K_MUIC_CTRL1_BIN_3_011 = 0x03,
	MAX77804K_MUIC_CTRL1_BIN_4_100 = 0x04,
	MAX77804K_MUIC_CTRL1_BIN_5_101 = 0x05,
	MAX77804K_MUIC_CTRL1_BIN_6_110 = 0x06,
	MAX77804K_MUIC_CTRL1_BIN_7_111 = 0x07,
};

enum max77804k_switch_sel_val {
	MAX77804K_SWITCH_SEL_1st_BIT_USB		= 0x1 << 0,
	MAX77804K_SWITCH_SEL_2nd_BIT_UART	= 0x1 << 1,
};

enum max77804k_reg_ctrl1_type {
	CTRL1_AP_USB =
		(MAX77804K_MUIC_CTRL1_BIN_1_001 << COMP2SW_SHIFT)
		| MAX77804K_MUIC_CTRL1_BIN_1_001 ,
	CTRL1_AUDIO =
		(MAX77804K_MUIC_CTRL1_BIN_2_010 << COMP2SW_SHIFT)
		| MAX77804K_MUIC_CTRL1_BIN_2_010 ,
	CTRL1_CP_USB =
		(MAX77804K_MUIC_CTRL1_BIN_4_100 << COMP2SW_SHIFT)
		| MAX77804K_MUIC_CTRL1_BIN_4_100 ,
	CTRL1_AP_UART =
		(MAX77804K_MUIC_CTRL1_BIN_3_011 << COMP2SW_SHIFT)
		| MAX77804K_MUIC_CTRL1_BIN_3_011 ,
	CTRL1_CP_UART =
		(MAX77804K_MUIC_CTRL1_BIN_5_101 << COMP2SW_SHIFT)
		| MAX77804K_MUIC_CTRL1_BIN_5_101 ,
};
/*TODO must modify H/W rev.5*/

enum max77804k_irq_source {
	LED_INT = 0,
	TOPSYS_INT,
	CHG_INT,
	MUIC_INT1,
	MUIC_INT2,
	MUIC_INT3,

	MAX77804K_IRQ_GROUP_NR,
};

enum max77804k_irq {
	/* PMIC; FLASH */
	MAX77804K_LED_IRQ_FLED2_OPEN,
	MAX77804K_LED_IRQ_FLED2_SHORT,
	MAX77804K_LED_IRQ_FLED1_OPEN,
	MAX77804K_LED_IRQ_FLED1_SHORT,
	MAX77804K_LED_IRQ_MAX_FLASH,

	/* PMIC; TOPSYS */
	MAX77804K_TOPSYS_IRQ_T120C_INT,
	MAX77804K_TOPSYS_IRQ_T140C_INT,
	MAX77804K_TOPSYS_IRQLOWSYS_INT,

	/* PMIC; Charger */
	MAX77804K_CHG_IRQ_BYP_I,
	MAX77804K_CHG_IRQ_BATP_I,
#if defined(CONFIG_SEC_H_PROJECT)
	MAX77804K_CHG_IRQ_THM_I,
#endif
	MAX77804K_CHG_IRQ_BAT_I,
	MAX77804K_CHG_IRQ_CHG_I,
	MAX77804K_CHG_IRQ_WCIN_I,
	MAX77804K_CHG_IRQ_CHGIN_I,

	/* MUIC INT1 */
	MAX77804K_MUIC_IRQ_INT1_ADC,
	MAX77804K_MUIC_IRQ_INT1_ADCLOW,
	MAX77804K_MUIC_IRQ_INT1_ADCERR,
	MAX77804K_MUIC_IRQ_INT1_ADC1K,

	/* MUIC INT2 */
	MAX77804K_MUIC_IRQ_INT2_CHGTYP,
	MAX77804K_MUIC_IRQ_INT2_CHGDETREUN,
	MAX77804K_MUIC_IRQ_INT2_DCDTMR,
	MAX77804K_MUIC_IRQ_INT2_DXOVP,
	MAX77804K_MUIC_IRQ_INT2_VBVOLT,
	MAX77804K_MUIC_IRQ_INT2_VIDRM,

	/* MUIC INT3 */
	MAX77804K_MUIC_IRQ_INT3_EOC,
	MAX77804K_MUIC_IRQ_INT3_CGMBC,
	MAX77804K_MUIC_IRQ_INT3_OVP,
	MAX77804K_MUIC_IRQ_INT3_MBCCHGERR,
	MAX77804K_MUIC_IRQ_INT3_CHGENABLED,
	MAX77804K_MUIC_IRQ_INT3_BATDET,

	MAX77804K_IRQ_NR,
};

struct max77804k_dev {
	struct device *dev;
	struct i2c_client *i2c; /* 0xCC; Charger, Flash LED */
	struct i2c_client *muic; /* 0x4A; MUIC */
	struct i2c_client *haptic; /* 0x90; Haptic */
	struct mutex iolock;

	int type;

	int irq;
	int irq_base;
	int irq_gpio;
	bool wakeup;
	struct mutex irqlock;
	int irq_masks_cur[MAX77804K_IRQ_GROUP_NR];
	int irq_masks_cache[MAX77804K_IRQ_GROUP_NR];

#ifdef CONFIG_HIBERNATION
	/* For hibernation */
	u8 reg_pmic_dump[MAX77804K_PMIC_REG_END];
	u8 reg_muic_dump[MAX77804K_MUIC_REG_END];
	u8 reg_haptic_dump[MAX77804K_HAPTIC_REG_END];
#endif

	/* pmic revision */
	u8 pmic_rev;	/* REV */
	u8 pmic_ver;	/* VERSION */
};

enum max77804k_types {
	TYPE_MAX77804K,
};

extern struct device *switch_dev;
extern int max77804k_irq_init(struct max77804k_dev *max77804k);
extern void max77804k_irq_exit(struct max77804k_dev *max77804k);
extern int max77804k_irq_resume(struct max77804k_dev *max77804k);

extern int max77804k_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest);
extern int max77804k_bulk_read(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int max77804k_write_reg(struct i2c_client *i2c, u8 reg, u8 value);
extern int max77804k_bulk_write(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int max77804k_update_reg(struct i2c_client *i2c,
				u8 reg, u8 val, u8 mask);
extern int max77804k_muic_get_charging_type(void);
extern int max77804k_muic_get_status1_adc1k_value(void);
extern int max77804k_muic_get_status1_adc_value(void);
extern void otg_control(int);
extern void powered_otg_control(int);
extern int max77804k_muic_set_audio_switch(bool enable);

#ifdef CONFIG_MFD_MAX77804K
enum cable_type_muic {
	CABLE_TYPE_NONE_MUIC = 0,		/* 0 */
	CABLE_TYPE_USB_MUIC,			/* 1 */
	CABLE_TYPE_OTG_MUIC,			/* 2 */
	CABLE_TYPE_TA_MUIC,			/* 3 */
	CABLE_TYPE_DESKDOCK_MUIC,		/* 4 */
	CABLE_TYPE_CARDOCK_MUIC,		/* 5 */
	CABLE_TYPE_JIG_UART_OFF_MUIC,		/* 6 */
	CABLE_TYPE_JIG_UART_OFF_VB_MUIC,	/* 7 VBUS enabled */
	CABLE_TYPE_JIG_UART_ON_MUIC,		/* 8 */
	CABLE_TYPE_JIG_USB_OFF_MUIC,		/* 9 */
	CABLE_TYPE_JIG_USB_ON_MUIC,		/* 10 */
	CABLE_TYPE_MHL_MUIC,			/* 11 */
	CABLE_TYPE_MHL_VB_MUIC,			/* 12 */
	CABLE_TYPE_SMARTDOCK_MUIC,		/* 13 */
	CABLE_TYPE_SMARTDOCK_TA_MUIC,		/* 14 */
	CABLE_TYPE_SMARTDOCK_USB_MUIC,		/* 15 */
	CABLE_TYPE_AUDIODOCK_MUIC,		/* 16 */
	CABLE_TYPE_INCOMPATIBLE_MUIC,		/* 17 */
	CABLE_TYPE_CDP_MUIC,			/* 18 */
#if defined(CONFIG_MUIC_MAX77804K_SUPPORT_HMT_DETECTION)
	CABLE_TYPE_HMT_MUIC,			/* 19 */
	CABLE_TYPE_HMT_TA_MUIC,			/* 20 */
#endif
#if defined(CONFIG_MUIC_DET_JACK)
	CABLE_TYPE_EARJACK_MUIC,
#endif
	CABLE_TYPE_UNKNOWN_MUIC
};

enum {
	OPEN_USB_MODE = 0,
	AP_USB_MODE,
	AUDIO_MODE,
	CP_USB_MODE,
};

enum {
	ADC_ALWAYS = 0,
	ADC_ALWAYS_1M,
	ADC_ONESHOT,
	ADC_PULSE,
};

enum usb_cable_status {
	USB_CABLE_DETACHED = 0,
	USB_CABLE_ATTACHED,
	USB_OTGHOST_DETACHED,
	USB_OTGHOST_ATTACHED,
	USB_POWERED_HOST_DETACHED,
	USB_POWERED_HOST_ATTACHED,
	USB_CABLE_DETACHED_WITHOUT_NOTI,
};

enum {
	UART_PATH_CP = 0,
	UART_PATH_AP,
};

#if defined(CONFIG_MUIC_DET_JACK)
enum {
	NOT_INIT = 0,
	INIT_START,
	INIT_DONE,
};
#endif

#endif /* CONFIG_MFD_MAX77804K */

#endif /*  __LINUX_MFD_MAX77804K_PRIV_H */
