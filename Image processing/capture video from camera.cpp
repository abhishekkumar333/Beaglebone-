#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
VideoCapture cap(0);
if(!cap.isOpened())
{
cout<<"error opening video file "<<endl;
return -1;
}
cap.set(CV_CAP_PROP_FRAME_WIDTH,352);
cap.set(CV_CAP_PROP_FRAME_HEIGHT,288);
double dwidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
double dheight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
cout<<"frame size = "<<dwidth<<"x"<<dheight<<endl;
namedWindow("CAM_FEED",CV_WINDOW_AUTOSIZE);
while(1)
{
Mat frame;
cap.read(frame);
imshow("CAM_FEED",frame);
if(waitKey(30) == 27)
{
cout<<"key is pressed by user "<<endl;
break;
}
}
return 0;
}