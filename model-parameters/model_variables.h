/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _EI_CLASSIFIER_MODEL_VARIABLES_H_
#define _EI_CLASSIFIER_MODEL_VARIABLES_H_

#include <stdint.h>
#include "model_metadata.h"

#include "tflite-model/trained_model_mic_compiled.h"
#include "tflite-model/trained_model_fomo_compiled.h"
#include "edge-impulse-sdk/classifier/ei_model_types.h"
#include "edge-impulse-sdk/classifier/inferencing_engines/engines.h"

const char* ei_classifier_inferencing_categories_mic[] = { "noise", "off", "on", "unknown" };

uint8_t ei_dsp_config_5_axes[] = { 0 };
const uint32_t ei_dsp_config_5_axes_size = 1;
ei_dsp_config_mfe_t ei_dsp_config_5 = {
    5, // uint32_t blockId
    3, // int implementationVersion
    1, // int length of axes
    0.02f, // float frame_length
    0.01f, // float frame_stride
    40, // int num_filters
    256, // int fft_length
    0, // int low_frequency
    0, // int high_frequency
    101, // int win_size
    -52 // int noise_floor_db
};

const size_t ei_dsp_blocks_size_mic = 1;
ei_model_dsp_t ei_dsp_blocks_mic[ei_dsp_blocks_size_mic] = {
    { // DSP block 5
        3960,
        &extract_mfe_features,
        (void*)&ei_dsp_config_5,
        ei_dsp_config_5_axes,
        ei_dsp_config_5_axes_size
    }
};

const ei_config_tflite_eon_graph_t ei_config_tflite_graph_mic_0 = {
    .implementation_version = 1,
    .model_init = &trained_model_mic_init,
    .model_invoke = &trained_model_mic_invoke,
    .model_reset = &trained_model_mic_reset,
    .model_input = &trained_model_mic_input,
    .model_output = &trained_model_mic_output,
};

const ei_learning_block_config_tflite_graph_t ei_learning_block_config_mic_0 = {
    .implementation_version = 1,
    .block_id = 0,
    .object_detection = 0,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_UNKNOWN,
    .output_data_tensor = 0,
    .output_labels_tensor = 1,
    .output_score_tensor = 2,
    .graph_config = (void*)&ei_config_tflite_graph_mic_0
};

const size_t ei_learning_blocks_size_mic = 1;
const ei_learning_block_t ei_learning_blocks_mic[ei_learning_blocks_size_mic] = {
    {
        &run_nn_inference,
        (void*)&ei_learning_block_config_mic_0,
    },
};

const ei_model_performance_calibration_t ei_calibration_mic = {
    1, /* integer version number */
    false, /* has configured performance calibration */
    (int32_t)(EI_CLASSIFIER_RAW_SAMPLE_COUNT / ((EI_CLASSIFIER_FREQUENCY > 0) ? EI_CLASSIFIER_FREQUENCY : 1)) * 1000, /* Model window */
    0.8f, /* Default threshold */
    (int32_t)(EI_CLASSIFIER_RAW_SAMPLE_COUNT / ((EI_CLASSIFIER_FREQUENCY > 0) ? EI_CLASSIFIER_FREQUENCY : 1)) * 500, /* Half of model window */
    0   /* Don't use flags */
};


const ei_impulse_t impulse_229721_1 = {
    .project_id = 229721,
    .project_owner = "Dmitry",
    .project_name = "reference-kws-off-on-50",
    .deploy_version = 1,

    .nn_input_frame_size = 3960,
    .raw_sample_count = 16000,
    .raw_samples_per_frame = 1,
    .dsp_input_frame_size = 16000 * 1,
    .input_width = 0,
    .input_height = 0,
    .input_frames = 0,
    .interval_ms = 0.0625,
    .frequency = 16000,
    .dsp_blocks_size = ei_dsp_blocks_size_mic,
    .dsp_blocks = ei_dsp_blocks_mic,

    .object_detection = 0,
    .object_detection_count = 0,
    .object_detection_threshold = 0,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_UNKNOWN,
    .fomo_output_size = 0,

    .tflite_output_features_count = 1,
    .learning_blocks_size = ei_learning_blocks_size_mic,
    .learning_blocks = ei_learning_blocks_mic,

    .inferencing_engine = EI_CLASSIFIER_TFLITE,

    .quantized = 1,

    .compiled = 1,

    .sensor = EI_CLASSIFIER_SENSOR_MICROPHONE,
    .fusion_string = "audio",
    .slice_size = (16000/4),
    .slices_per_model_window = 4,

    .has_anomaly = 0,
    .label_count = 4,
    .calibration = ei_calibration_mic,
    .categories = ei_classifier_inferencing_categories_mic
};

const char* ei_classifier_inferencing_categories_fomo[] = { "face" };

uint8_t ei_dsp_config_17_axes[] = { 0 };
const uint32_t ei_dsp_config_17_axes_size = 1;
ei_dsp_config_image_t ei_dsp_config_17 = {
    17, // uint32_t blockId
    1, // int implementationVersion
    1, // int length of axes
    "Grayscale" // select channels
};

const size_t ei_dsp_blocks_size_fomo = 1;
ei_model_dsp_t ei_dsp_blocks_fomo[ei_dsp_blocks_size_fomo] = {
    { // DSP block 17
        9216,
        &extract_image_features,
        (void*)&ei_dsp_config_17,
        ei_dsp_config_17_axes,
        ei_dsp_config_17_axes_size
    }
};

const ei_config_tflite_eon_graph_t ei_config_tflite_graph_fomo_0 = {
    .implementation_version = 1,
    .model_init = &trained_model_fomo_init,
    .model_invoke = &trained_model_fomo_invoke,
    .model_reset = &trained_model_fomo_reset,
    .model_input = &trained_model_fomo_input,
    .model_output = &trained_model_fomo_output,
};

const ei_learning_block_config_tflite_graph_t ei_learning_block_config_fomo_0 = {
    .implementation_version = 1,
    .block_id = 0,
    .object_detection = 1,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_FOMO,
    .output_data_tensor = 0,
    .output_labels_tensor = 1,
    .output_score_tensor = 2,
    .graph_config = (void*)&ei_config_tflite_graph_fomo_0
};

const size_t ei_learning_blocks_size_fomo = 1;
const ei_learning_block_t ei_learning_blocks_fomo[ei_learning_blocks_size_fomo] = {
    {
        &run_nn_inference,
        (void*)&ei_learning_block_config_fomo_0,
    },
};

const ei_model_performance_calibration_t ei_calibration_fomo = {
    1, /* integer version number */
    false, /* has configured performance calibration */
    (int32_t)(EI_CLASSIFIER_RAW_SAMPLE_COUNT / ((EI_CLASSIFIER_FREQUENCY > 0) ? EI_CLASSIFIER_FREQUENCY : 1)) * 1000, /* Model window */
    0.8f, /* Default threshold */
    (int32_t)(EI_CLASSIFIER_RAW_SAMPLE_COUNT / ((EI_CLASSIFIER_FREQUENCY > 0) ? EI_CLASSIFIER_FREQUENCY : 1)) * 500, /* Half of model window */
    0   /* Don't use flags */
};

const ei_impulse_t impulse_179676_100 = {
    .project_id = 179676,
    .project_owner = "Dmitry",
    .project_name = "Face detection - FOMO",
    .deploy_version = 100,

    .nn_input_frame_size = 9216,
    .raw_sample_count = 9216,
    .raw_samples_per_frame = 1,
    .dsp_input_frame_size = 9216 * 1,
    .input_width = 96,
    .input_height = 96,
    .input_frames = 1,
    .interval_ms = 1,
    .frequency = 0,
    .dsp_blocks_size = ei_dsp_blocks_size_fomo,
    .dsp_blocks = ei_dsp_blocks_fomo,

    .object_detection = 1,
    .object_detection_count = 10,
    .object_detection_threshold = 0.5,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_FOMO,
    .fomo_output_size = 12,

    .tflite_output_features_count = 288,
    .learning_blocks_size = ei_learning_blocks_size_fomo,
    .learning_blocks = ei_learning_blocks_fomo,

    .inferencing_engine = EI_CLASSIFIER_TFLITE,

    .quantized = 1,

    .compiled = 1,

    .sensor = EI_CLASSIFIER_SENSOR_CAMERA,
    .fusion_string = "image",
    .slice_size = (9216/4),
    .slices_per_model_window = 4,

    .has_anomaly = 0,
    .label_count = 1,
    .calibration = ei_calibration_fomo,
    .categories = ei_classifier_inferencing_categories_fomo
};

const ei_impulse_t ei_default_impulse = impulse_229721_1;

#endif // _EI_CLASSIFIER_MODEL_METADATA_H_
