//
// Created by Mason Self on 7/8/23.
//
#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
class IAudioProcessor
{
public:
    virtual juce::AudioProcessorValueTreeState& GetAPVTS() = 0;
    virtual const juce::Array<juce::AudioProcessorParameter*> & GetParams() = 0;
};
