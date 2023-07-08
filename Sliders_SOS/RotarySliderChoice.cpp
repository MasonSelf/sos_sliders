//
// Created by Mason Self on 7/8/23.
//

#pragma once
#include "RotarySliderChoice.h"

SOSRotaryChoiceSlider::SOSRotaryChoiceSlider(IAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, juce::Colour& _fill, juce::Colour& _outline, juce::Colour& _pointer)
: audioProcessor(p), feel(_fill, _outline, _pointer)
{
    sliderAttachment =
            std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>
                    (audioProcessor.GetAPVTS(), paramID.toString(), *this);

    auto param = std::make_unique<juce::AudioParameterChoice*>(static_cast<juce::AudioParameterChoice*>(audioProcessor.GetParams().getUnchecked(paramIndex)));

    setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    setLookAndFeel(&feel);
    setValue((*param)->getIndex());
    setTextBoxStyle(juce::Slider::TextBoxBelow, true, 200, 20);
    setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::black);
    setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::transparentBlack);
    setLookAndFeel(&feel);

}
SOSRotaryChoiceSlider::~SOSRotaryChoiceSlider()
{
    setLookAndFeel(nullptr);
}