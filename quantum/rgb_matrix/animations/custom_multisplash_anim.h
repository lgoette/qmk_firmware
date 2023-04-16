#include "print.h"
#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
    #ifdef ENABLE_RGB_MATRIX_CUSTOM_MULTISPLASH

        RGB_MATRIX_EFFECT(CUSTOM_MULTISPLASH)
        #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

            HSV CUSTOM_MULTISPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick)
            {
                uint16_t effect = tick - dist;
                if (effect > 255)
                    effect = 255;

              	effect = map8(effect, 0, 5);
		
		int8_t hue = hsv.h;
		
		if (effect > 4) 
		{
                    effect = 4;
                }
  		hue = qadd8(hue, 4 - effect);
		if (hue > rgb_matrix_config.hsv.h + 4) 
		{
                    hue = rgb_matrix_config.hsv.h + 4;
                }
		
		//if (hue < 0) 
		//{
                //    hue = qadd8(hue , 255);
                //}
		
                hsv.h = hue;
                
                return hsv;
            }

            bool CUSTOM_MULTISPLASH(effect_params_t *params)
            {
                return effect_runner_custom_multisplash(0, params, &CUSTOM_MULTISPLASH_math);
            }

        #endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
     #endif // ENABLE_RGB_MATRIX_CUSTOM_MULTISPLASH
#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
