/*
  ==============================================================================

    LinearSliderBase.h
    Created: 5 Jul 2023 9:01:04am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "IAudioProcessor.h"
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_audio_processors/juce_audio_processors.h>

class SOSLinearSliderBase : public juce::Slider
{
public:
    //constructor without color choices
    SOSLinearSliderBase(IAudioProcessor& p, const juce::Identifier& paramID , int paramIndex);

    //constructor with color choices
    SOSLinearSliderBase(IAudioProcessor& p,
                        const juce::Identifier& paramID ,
                        int paramIndex,
                        juce::Colour _trackColor,
                        juce::Colour _fillColor,
                        juce::Colour _handleColor);

    IAudioProcessor& audioProcessor;
    juce::Colour trackColor {juce::Colours::grey};
    juce::Colour trackFillColor {juce::Colours::pink};
    juce::Colour handleColor {juce::Colours::yellow};
    juce::Rectangle<float> handleRectangle {4.0f, 10.0f};
    const float trackWidth {4.0f};
    const float amountRounded {3.0f};
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
};
