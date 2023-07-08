//
// Created by Mason Self on 7/8/23.
//

#include "LinearSliderVertical.h"

SOSSliderVertical::SOSSliderVertical(IAudioProcessor& p, const juce::Identifier& paramID , int paramIndex, juce::Colour _trackColor, juce::Colour _fillColor, juce::Colour _handleColor)
: SOSLinearSliderBase(p, paramID, paramIndex, _trackColor, _fillColor, _handleColor)
{
    handleRectangle = {50.0f, 8.0f};
    setSliderStyle(juce::Slider::LinearVertical);
}

void SOSSliderVertical::paint(juce::Graphics& g)
{
    juce::Point<float> trackTopLeft {getWidth() / 2.0f - trackWidth / 2.0f, 0.0f};
    juce::Point<float> trackBottomRight {getWidth() / 2.0f + trackWidth / 2.0f, static_cast<float>(getHeight())};
    //track
    juce::Rectangle<float> trackRectangle {trackTopLeft, trackBottomRight};
    g.setColour(trackColor);
    g.setOpacity(0.8f);
    g.fillRoundedRectangle(trackRectangle, amountRounded);

    //track fill
    auto handleY = GetHandlePosition(trackRectangle.getHeight());
    auto trackFillRectangle = trackRectangle.withTop(handleY + handleRectangle.getHeight() / 2.0f);
    g.setColour(trackFillColor);
    g.setOpacity(0.8f);

    g.fillRoundedRectangle(trackFillRectangle, amountRounded);

    //handle
    g.setColour(handleColor);

    handleRectangle.setY(handleY);
    handleRectangle.setX(trackRectangle.getCentreX() - handleRectangle.getWidth() / 2);
    g.fillRect(handleRectangle);
}

float SOSSliderVertical::GetHandlePosition(float trackHeight)
{
    auto multiplier = (trackHeight - handleRectangle.getHeight()) / trackHeight;
    auto normalizedValue = static_cast<float>(getValue()) / getRange().getEnd();
    return trackHeight - normalizedValue * trackHeight * multiplier - handleRectangle.getHeight();
}