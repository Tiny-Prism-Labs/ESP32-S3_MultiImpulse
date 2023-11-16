/**
 * @file pins_definition.h
 * @author Errol Joshua (errol@tinyprismlabs.com)
 * @brief All the definition of pins for the sensors.
 * @version 0.1
 * @date 2023-11-16
 * 
 * 
 */


/**
 * @brief Camera pins defined below
 * 
 */
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     10
#define SIOD_GPIO_NUM     40
#define SIOC_GPIO_NUM     39

#define Y9_GPIO_NUM       48
#define Y8_GPIO_NUM       11
#define Y7_GPIO_NUM       12
#define Y6_GPIO_NUM       14
#define Y5_GPIO_NUM       16
#define Y4_GPIO_NUM       18
#define Y3_GPIO_NUM       17
#define Y2_GPIO_NUM       15
#define VSYNC_GPIO_NUM    38
#define HREF_GPIO_NUM     47
#define PCLK_GPIO_NUM     13


/**
 * @brief Microphone pins and I2S configuration defined here
 * 
 */
#define RECORD_TIME   10 
#define NUM_CHANNELS (1)
#define SAMPLE_RATE 16000
#define BITS_PER_SAMPLE 16
#define SAMPLE_SIZE (16 * 1024)
#define BYTE_RATE (SAMPLE_RATE * (BITS_PER_SAMPLE / 8)) * NUM_CHANNELS
#define I2S_PORT I2S_NUM_0
#define I2S_WS 42
#define I2S_SD 41
#define I2S_SCK -1