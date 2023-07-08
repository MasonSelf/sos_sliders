//
// Created by Mason Self on 7/8/23.
//

#include "LinearSliderHorizontal.h"

SOSSliderHorizontal::SOSSliderHorizontal(IAudioProcessor& p, const juce::Identifier& paramID , int paramIndex, juce::Colour _trackColor, juce::Colour _fillColor, juce::Colour _handleColor)
: SOSLinearSliderBase(p, paramID, paramIndex, _trackColor, _fillColor, _handleColor)
{
}


void SOSSliderHorizontal::paint(juce::Graphics& g)
{
    juce::Point<float> trackTopLeft {0.0f, getHeight() / 2.0f - trackWidth / 2.0f};
    juce::Point<float> trackBottomRight {static_cast<float>(getWidth()), getHeight() / 2.0f + trackWidth / 2.0f};
    //track
    juce::Rectangle<float> trackRectangle {trackTopLeft, trackBottomRight};
    g.setColour(trackColor);
    g.setOpacity(0.8f);
    g.fillRoundedRectangle(trackRectangle, amountRounded);

    //track fill
    auto handleX = GetHandlePosition();
    auto trackFillRectangle = trackRectangle.withRight(handleX + handleRectangle.getWidth() / 2.0f);
    g.setColour(trackFillColor);
    g.setOpacity(0.8f);

    g.fillRoundedRectangle(trackFillRectangle, amountRounded);

    //handle
    g.setColour(handleColor);

    handleRectangle.setX(handleX);
    handleRectangle.setY(trackRectangle.getCentre().y - handleRectangle.getHeight() / 2);
    g.fillRect(handleRectangle);
}

float SOSSliderHorizontal::GetHandlePosition()
{
    auto multiplier = (static_cast<float>(getWidth()) - handleRectangle.getWidth()) / static_cast<float>(getWidth());
    auto normalizedValue = static_cast<float>(getValue()) / getRange().getEnd();
    return normalizedValue * getWidth() * multiplier;
}