//
// Created by Mason Self on 7/8/23.
//

#pragma once
#include "LinearSliderBase.h"

SOSLinearSliderBase::SOSLinearSliderBase(IAudioProcessor &p, const juce::Identifier &paramID, int paramIndex)
        : audioProcessor(p)
{
    sliderAttachment =
            std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>
                    (audioProcessor.GetAPVTS(), paramID.toString(), *this);

    auto param = std::make_unique<juce::AudioParameterFloat*>(static_cast<juce::AudioParameterFloat*>(audioProcessor.GetParams().getUnchecked(paramIndex)));

    setRange((*param)->range.start, (*param)->range.end, 0.0000001);
    setValue((*param)->get());
    setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
}

SOSLinearSliderBase::SOSLinearSliderBase(IAudioProcessor& p,
                                         const juce::Identifier& paramID ,
                                         int paramIndex,
                                         juce::Colour _trackColor,
                                         juce::Colour _fillColor,
                                         juce::Colour _handleColor)
: SOSLinearSliderBase(p, paramID, paramIndex)
{
    trackColor = _trackColor;
    trackFillColor = _fillColor;
    handleColor = _handleColor;
}


