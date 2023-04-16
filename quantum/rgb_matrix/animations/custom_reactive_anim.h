#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
    #ifdef ENABLE_RGB_MATRIX_CUSTOM_REACTIVE
        RGB_MATRIX_EFFECT(CUSTOM_REACTIVE)
        #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

            static HSV CUSTOM_REACTIVE_math(HSV hsv, uint16_t offset)
            {
		#ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
		hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
		#endif
                // hsv.h += qsub8(14, offset);

		hsv.h -= map8(offset, 242, 1); // Gradually increase hue from Orange to Red degrees

    		if (hsv.h >= 360) {
        		hsv.h -= 360; // Keep hue within 0-359 range
    		}
                return hsv;
            }

            bool CUSTOM_REACTIVE(effect_params_t *params)
            {
                return effect_runner_custom_reactive(params, &CUSTOM_REACTIVE_math);
            }

        #endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
    #endif // ENABLE_RGB_MATRIX_CUSTOM_REACTIVE
#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
