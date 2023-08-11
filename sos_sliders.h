#pragma once

#if 0

BEGIN_JUCE_MODULE_DECLARATION

      ID:               sos_sliders
      vendor:           Mason Self
      version:          0.0.1
      name:             sos_sliders
      description:      SlidersSynthsOfSelf
      license:          GPL/Commercial
      dependencies:     juce_audio_utils, juce_gui_basics, sos_IAudioProcessor

     END_JUCE_MODULE_DECLARATION

#endif

#include "Sliders_SOS/LinearSliderBase.h"
#include "Sliders_SOS/LinearSliderHorizontal.h"
#include "Sliders_SOS/LinearSliderVertical.h"
#include "Sliders_SOS/RotarySliderChoice.h"
#include "Sliders_SOS/RotarySliderFloat.h"
#include "Sliders_SOS/RotarySliderLookAndFeel.h"
#include "Sliders_SOS/LinearSliderDragFillBox.h"
