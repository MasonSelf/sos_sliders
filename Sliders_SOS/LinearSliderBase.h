/*
  ==============================================================================

    LinearSliderBase.h
    Created: 5 Jul 2023 9:01:04am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

class SOSLinearSliderBase : public juce::Slider
{
public:
    SOSLinearSliderBase(AudioPluginAudioProcessor& p, const juce::Identifier& paramID , int paramIndex, juce::Colour _trackColor, juce::Colour _fillColor, juce::Colour _handleColor)
    : audioProcessor(p), trackColor(_trackColor), trackFillColor(_fillColor), handleColor(_handleColor)
    {
        sliderAttachment =
            std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>
            (audioProcessor.apvts, paramID.toString(), *this);

        auto param = std::make_unique<juce::AudioParameterFloat*>(static_cast<juce::AudioParameterFloat*>(audioProcessor.getParameters().getUnchecked(paramIndex)));

        setRange((*param)->range.start, (*param)->range.end, 0.0000001);
        setValue((*param)->get());
        setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    }

    AudioPluginAudioProcessor& audioProcessor;
    juce::Colour trackColor, trackFillColor, handleColor;
    juce::Rectangle<float> handleRectangle {4.0f, 10.0f};
    const float trackWidth {4.0f};
    const float amountRounded {3.0f};
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
};
