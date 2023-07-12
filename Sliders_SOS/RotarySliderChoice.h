/*
  ==============================================================================

    RotarySliderChoice.h
    Created: 5 Jul 2023 9:22:20am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "RotarySliderLookAndFeel.h"
#include <sos_IAudioProcessor/sos_IAudioProcessor.h>
#include <juce_audio_processors/juce_audio_processors.h>


class SOSRotaryChoiceSlider : public juce::Slider
{
public:
    SOSRotaryChoiceSlider(IAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, juce::Colour _fillColor, juce::Colour _outlineColor, juce::Colour _pointerColor);
    ~SOSRotaryChoiceSlider();


    IAudioProcessor& audioProcessor;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
private:
    SOSRotarySliderLookAndFeel feel;

};

