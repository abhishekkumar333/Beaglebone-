#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
if(argc <= 1)
{
cout<<"please enter a valid path for the image "<<endl;
return -1;
}
Mat img;
img = imread(argv[1],CV_LOAD_IMAGE_UNCHANGED);
if(img.empty())
{
cout<<"error opening image "<<endl;
return -1;
}
namedWindow("Lion",CV_WINDOW_NORMAL);
imshow("lion",img);
waitKey(0);
destroyWindow("LION");
return 0;
}
