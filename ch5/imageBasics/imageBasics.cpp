#include <iostream>
#include <chrono>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv) {
  // read image argv[1]
  cv::Mat image;
  image = cv::imread(argv[1]); //cv::imread read the image from file 

  // check data is not null
  if (image.data == nullptr) { // maybe the file doesn't exist
    cerr << "file" << argv[1] << "Doesn't exist." << endl;
    return 0;
  }

  // print informations
  cout << "Image cols : " << image.cols << ", rows : " << image.rows << ", channels : " << image.channels() << endl;
  cv::imshow("image", image);      // use cv::imshow to show the image
  cv::waitKey(0);                  // wait for keyboard input

  // check image type
  if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
    // it needs to be grey scale or rgb
    cout << "Please put a grey scale or rgb image" << endl;
    return 0;
  }

  // go throught all pixels 
  // std::chrono takes time
  chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
  for (size_t y = 0; y < image.rows; y++) {
    // cv::Mat::ptr to get pointer of each row
    unsigned char *row_ptr = image.ptr<unsigned char>(y);  // row_ptr is the head pointer of the first Y line
    for (size_t x = 0; x < image.cols; x++) {
      // read pixel on x,y 
      unsigned char *data_ptr = &row_ptr[x * image.channels()]; // data_ptr Pointing to the pixel data to be visited
      // get every channel of the pixel
      for (int c = 0; c != image.channels(); c++) {
        unsigned char data = data_ptr[c]; // data should be pixel of I(x,y) in C Channel
      }
    }
  }
  chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
  chrono::duration<double> time_used = chrono::duration_cast < chrono::duration < double >> (t2 - t1);
  cout << "Time of traversing images : " << time_used.count() << " Seconds" << endl;

  // copying cv::Mat 
  // the = assignment does not copy data, it copy the reference instead
  cv::Mat image_another = image;
  // changing image_another will also change image 
  image_another(cv::Rect(0, 0, 100, 100)).setTo(0); // Set top left 100*100  to zero
  cv::imshow("image", image);
  cv::imshow("image_another", image_another);
  cv::waitKey(0);

  // actually clone the data
  cv::Mat image_clone = image.clone();
  image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
  cv::imshow("image", image);
  cv::imshow("image_clone", image_clone);
  cv::waitKey(0);

  // There are many basic rperations for images, such as shearing, rotating, scaling, etc., and it is limited to the space. Please refer to the official document of OpenCV to check the call method of each function.
  cv::destroyAllWindows();
  return 0;
}
