
#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_SOLID_MULTISPLASH_RAND_COLOR)

#        ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH_RAND_COLOR
RGB_MATRIX_EFFECT(SOLID_MULTISPLASH_RAND_COLOR)
#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV SOLID_SPLASH_RAND_COLOR_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = 8 * (tick - dist);
    if ((effect > 255) || (dist > 30)) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}


#            ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH_RAND_COLOR
bool SOLID_MULTISPLASH_RAND_COLOR(effect_params_t* params) {
    return effect_runner_reactive_splash_custom_color(0, params, &SOLID_SPLASH_RAND_COLOR_math);
}
#            endif

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_SPLASH) && !defined(ENABLE_RGB_MATRIX_MULTISPLASH)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
