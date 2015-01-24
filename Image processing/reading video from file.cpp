#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
if(argc <= 1)
{
cout<<"please enter file name "<<endl;
return -1;
}
VideoCapture cap(argv[1]);
if(!cap.isOpened())
{
cout<<"error opening video file "<<endl;
return -1;
}
double fps = cap.get(CV_CAP_PROP_FPS);
cout<<"FPS = "<<fps<<endl;
namedWindow("Cam_Video",CV_WINDOW_AUTOSIZE);
while(1)
{
Mat frame;
cap.read(frame);
imshow("Cam_Video",frame);
if(waitKey(30) == 27)
{
cout<<"key is pressed by user "<<endl;
break;
}
}
return 0;
}
