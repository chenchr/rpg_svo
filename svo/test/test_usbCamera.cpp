//
// Created by chenchr on 17-5-18.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int, char**) {
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened()) {
        std::cout << "Camera not opend!" << std::endl;
        return -1;
    }  // check if we succeeded
    double fps = cap.get(CV_CAP_PROP_FPS);
    std::cout << "FPS:\t" << fps << std::endl;
    Mat edges;
    namedWindow("edges",1);
    int count = 0;
    while (1) {
        std::cout << count++ << std::endl;
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if (waitKey(0) == 'q') break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
