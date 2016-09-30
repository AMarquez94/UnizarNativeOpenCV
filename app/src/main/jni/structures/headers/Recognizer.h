//
// Created by alejandro on 27/09/16.
//

#ifndef ANDROIDNATIVEOPENCV_RECOGNIZER_H
#define ANDROIDNATIVEOPENCV_RECOGNIZER_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <android/log.h>
#include "Object.h"

using namespace std;
using namespace cv;

class Recognizer {

private:
    Ptr<FeatureDetector> detector;
    Ptr<DescriptorExtractor> extractor;
    Ptr<DescriptorMatcher> matcher;
    vector<Object> objects;
    int matcherDistanceFilter;
public:

    /* Constructors */
    Recognizer();
    Recognizer(String detector, String extractor, String matcher);
    Recognizer(String detector, String extractor, String matcher, vector<Object> objects);
    Recognizer(String detector, vector<int> detectorParams, String extractor,
               vector<int> extractorParams, String matcher, vector<int> matcherParams);
    Recognizer(String detector, vector<int> detectorParams, String extractor,
               vector<int> extractorParams, String matcher, vector<int> matcherParams,
               vector<Object> objects);

    /* Getters */
    Ptr<FeatureDetector> getDescriptor();
    Ptr<DescriptorExtractor> getExtractor();
    Ptr<DescriptorMatcher> getMatcher();

    /* Setters */
    void setDescriptor(String detector);
    void setExtractor(String extractor);
    void setMatcher(String matcher);

    /* Methods */
    Object createObject(String path, bool add);
    String RecognizeObject(Mat cameraImgGray, Mat cameraImgColour, Mat dstImg);

};


#endif //ANDROIDNATIVEOPENCV_RECOGNIZER_H
