# Multi Impulse Example on Xiao ESP32 S3 Sense

This is port of [example-standalone-inferencing-multi-impulse-arduino-esp32](https://github.com/edgeimpulse/example-standalone-inferencing-multi-impulse-arduino-esp32) by Edge Impulse to Xiao ESP32-S3 Sense using ESP-IDF

## Requirements

### Hardware

* [XIAO ESP32S3 Sense](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html).

While the script is mainly tested with XIAO ESP32S3 Sense, other ESP32-based development boards will work too with changes to pins of the camera and other code changes.

### Software

* [Edge Impulse CLI](https://docs.edgeimpulse.com/docs/cli-installation).

* [ESP IDF 4.4](https://docs.espressif.com/projects/esp-idf/en/v4.4/esp32/get-started/index.html).

I personally use dockerized version of ESP-IDF as versions are much easier to manage which I on different versions of ESP-IDF

* [ESP IDF 4.4 Docker](https://docs.espressif.com/projects/esp-idf/en/release-v4.4/esp32s3/api-guides/tools/idf-docker-image.html)

## Pinout for Xiao ESP32-S3 Sense

```c
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
```

## Building the application

### Get the Edge Impulse SDK

The directory structure looks like this

   ```
├── CMakeLists.txt
├── edge-impulse-sdk
│   ├── classifier
│   ├── cmake
│   ├── CMSIS
│   ├── create-arduino-library.sh
│   ├── dsp
│   ├── LICENSE
│   ├── LICENSE-apache-2.0.txt
│   ├── porting
│   ├── README.md
│   ├── sources.txt
│   ├── tensorflow
│   └── third_party
├── LICENSE
├── main
│   ├── CMakeLists.txt
│   └── main.cpp
├── model-parameters
│   ├── model_metadata.h
│   └── model_variables.h
├── README.md
├── sdkconfig
└── tflite-model
    ├── trained_model_fomo_compiled.cpp
    ├── trained_model_fomo_compiled.h
    ├── trained_model_mic_compiled.cpp
    ├── trained_model_mic_compiled.h
    ├── trained_model_ops_define.h
    └── trained_model_ops_fomo_define.h

12 directories, 19 files
```



### Build Flash Monitor

1. Open the project in Docker:
   ```bash
   docker run --privileged --rm -v $PWD:/project -w /project -it espressif/idf:release-v4.4
   ```
2. Compile:
   ```bash
   idf.py build flash monitor
   ```

### Output

In due time


## References

* [Multi Impulse Docs](https://docs.edgeimpulse.com/docs/tutorials/advanced-inferencing/multi-impulse)
