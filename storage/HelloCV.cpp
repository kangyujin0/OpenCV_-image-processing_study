#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void writeData();
void readData();
String filename = "mydata.yml";
//String filename = "mydata.xml"; 형식에 맞게 데이터를 저장
//String filename = "mydata.json";

int main()
{
    writeData();
    readData();

    return 0;
}

void writeData()
{
    String name = "Jane";
    int age = 10;
    FileStorage fs;
    fs.open(filename,FileStorage::WRITE);
    if (fs.isOpened() != true) {
        cerr << "File open error" << endl;
        return;
    }

    fs << "name"<< name;
    fs << "age" << age;
    
    fs.release();
}

void readData()
{
    String name;
    int age;

    FileStorage fs("mydata.yml", FileStorage::READ);
    if (fs.isOpened() != true) {
        cerr << "File open error" << endl;
        return;
    }

    fs["name"] >> name;
    fs["age"] >> age;

    fs.release();

    cout << "name:" << name << endl;
       
}
