#ifndef _ADS7229_H_
#define _ADS7229_H_

/* Configuration */
#define ADS7229_CFG_AUTO_CHAN_SELECT		(1 << 11)
#define ADS7229_CFG_MANUAL_CHAN_SELECT	(0) // Not supported on ADS7229

#define ADS7229_CFG_INTERNAL_OSC			(1 << 10)
#define ADS7229_CFG_SCLK_OSC					(0)

#define ADS7229_CFG_MANUAL_TRIGGER		(1 << 9)
#define ADS7229_CFG_AUTO_TRIGGER			(0)

#define ADS7229_CFG_EOC_ACTIVE_LOW		(1 << 7)
#define ADS7229_CFG_EOC_ACTIVE_HIGH		(0)

#define ADS7229_CFG_PIN10_OUT_USE_EOC	(1 << 6)
#define ADS7229_CFG_PIN10_OUT_USE_INT (0)

#define ADS7229_CFG_PIN10_CHAIN_USE_EOC	(1 << 5)
#define ADS7229_CFG_PIN10_CHAIN_USE_CDI (0)

#define ADS7229_CFG_AUTO_NAP_DISABLED	(1 << 4)
#define ADS7229_CFG_AUTO_NAP_ENABLED	(0)

#define ADS7229_CFG_NAP_WAKEUP				(1 << 3)
#define ADS7229_CFG_NAP_PWR_DOWN			(0)

#define ADS7229_CFG_DEEP_WAKEUP				(1 << 2)
#define ADS7229_CFG_DEEP_PWR_DOWN			(0)

#define ADS7229_CFG_NORMAL_OP					(1)
#define ADS7229_CFG_SYSTEM_RESET			(0)

#define ADS7229_CFG_DEFAULT	(ADS7229_CFG_AUTO_CHAN_SELECT | \
														 ADS7229_CFG_INTERNAL_OSC | \
														 ADS7229_CFG_MANUAL_TRIGGER | \
														 ADS7229_CFG_EOC_ACTIVE_LOW | \
														 ADS7229_CFG_PIN10_OUT_USE_EOC |  \
														 ADS7229_CFG_PIN10_CHAIN_USE_EOC | \
														 ADS7229_CFG_AUTO_NAP_DISABLED | \
														 ADS7229_CFG_NAP_WAKEUP | \
														 ADS7229_CFG_DEEP_WAKEUP | \
														 ADS7229_CFG_NORMAL_OP)

void ads7229_init();
void ads7229_config(uint16_t cfg_word);
uint16_t ads7229_convert_and_read();

#endif
