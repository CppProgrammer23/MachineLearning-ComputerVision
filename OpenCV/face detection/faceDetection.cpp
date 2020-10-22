#include "opencv2/opencv.hpp"
#include <vector>
#include <Windows.h>

int main()
{
	double scale = 3.0;
	bool playsoundPerson = false, playsoundNotPerson = false;
	cv::CascadeClassifier facedetection;
	facedetection.load("D:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml"); //change this to your cuurent directory
	cv::VideoCapture vc(0); //an object of the video capture
	if (!vc.isOpened())
		return -1;
	for (;;)
	{
		cv::Mat frame;
		vc >> frame;
		cv::Mat gs;
		cv::cvtColor(frame, gs, cv::COLOR_BGR2GRAY); //convert from BGR to gray because opencv deals with gray images
		cv::resize(gs, gs, cv::Size(gs.size().width / scale, gs.size().height / scale));
		std::vector<cv::Rect> faces;
		facedetection.detectMultiScale(gs, faces); //this function takes only a vector so std::vector is the only choice
		for (auto face : faces)
		{
			cv::Scalar color = cv::Scalar(0, 200, 200);
			cv::rectangle(frame, cv::Point(cvRound(face.x * scale), cvRound(face.y * scale)), cv::Point(cvRound(face.x + face.width - 1) * scale,
				cvRound(face.y + face.height - 1) * scale), color);
		}
		//std::cout << "There's " << faces.size()  << " Person(s)\n";
		if (faces.size())
		{
			playsoundNotPerson = false;
			if(!playsoundPerson)
				playsoundPerson = PlaySoundW(TEXT("Person.wav"), nullptr, SND_FILENAME | SND_ASYNC);
			cv::putText(frame, "Person (" + std::to_string(faces.size()) + ")", cv::Point(30, 30),
				cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 200), 2, false); //put text on the frame to inform us whether it's a face or not
		}
		else
		{
			playsoundPerson = false;
			if (!playsoundNotPerson)
				playsoundNotPerson = PlaySoundW(TEXT("Not-Person.wav"), nullptr, SND_FILENAME|SND_ASYNC);
			cv::putText(frame, "Not-Person", cv::Point(30, 30), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 200), 2, false);
		}
		cv::imshow("WebCam", frame);
		if (cv::waitKey(5)>5)
			break;
	}
	return 0;
}
