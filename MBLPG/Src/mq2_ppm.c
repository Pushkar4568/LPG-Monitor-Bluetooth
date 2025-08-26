#include <math.h>
#include <stdio.h>

#define VREF     3.3f
#define ADC_RES  4095.0f   // 12-bit ADC
#define RL       10000.0f  // 10 kΩ
#define RO       1000.0f  // 24 kΩ (calibrated in clean air)
#define A        565.0f
#define B        -1.48f

float MQ2_PPM_OP(int adc_val) {
    // Convert ADC reading to voltage
    float voltage = ((float)adc_val / ADC_RES) * VREF;
    if (voltage <= 0.01f) return 0.0f;  // safeguard

    // Calculate sensor resistance Rs
    float Rs = RL * (VREF - voltage) / voltage;
    if (Rs <= 0.0f) return 0.0f;        // safeguard

    // Rs/Ro ratio
    float ratio = Rs / RO;
    if (ratio <= 0.0f) return 0.0f;     // safeguard

    // Compute LPG concentration in ppm
    float ppm = A * powf(ratio, B);
    if (!isfinite(ppm) || ppm < 0.0f) return 0.0f;

    return ppm;
}
