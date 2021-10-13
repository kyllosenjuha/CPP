#include "testOperation.h"
#include "imaginarySDK.h"
#include <iostream>

testOperation::testOperation()
{
    //ctor
}

testOperation::~testOperation()
{
    //dtor
}

void testOperation::testScript()
{
    unsigned short testImage[MAX_WIDTH*MAX_HEIGHT] {};

    for(int index {}, value{}; index < MAX_WIDTH*MAX_HEIGHT; ++value, ++index)
    {
        if(value == 65536)
            value = 0;

        testImage[index] = 65535-(unsigned short)value;

    }

    unsigned short* p_testImage;
    p_testImage = testImage;

    std::thread write_thread1(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, -6, 10);
    std::thread write_thread2(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 16, 80);
    std::thread write_thread3(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 87, 10);
    std::thread write_thread4(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 30, 8);
    std::thread write_thread5(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 4, 10);
    std::thread write_thread6(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 16, 10);
    std::thread write_thread7(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 10, 680);
    std::thread write_thread8(&imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback, p_testImage, 4, 4);

    std::thread read_thread1(&imaginarySDK::readDataFromBuffer);
    std::thread read_thread2(&imaginarySDK::readDataFromBuffer);
    std::thread read_thread3(&imaginarySDK::readDataFromBuffer);
    std::thread read_thread4(&imaginarySDK::readDataFromBuffer);

    write_thread1.join();
    write_thread2.join();
    write_thread3.join();
    write_thread4.join();
    write_thread5.join();
    write_thread6.join();
    write_thread7.join();
    write_thread8.join();

    read_thread1.join();
    read_thread2.join();
    read_thread3.join();
    read_thread4.join();

    imaginarySDK imagSDK;

    int widthFromBuffer {};
    int heightFromBuffer {};
    std::vector<unsigned short> DataVectorFromBuffer;
    std::vector<int> widthAndHeightVectorFrombuffer;

    if(imagSDK.get_ConsumerExecutedAtLeastOnce() == true)
    {
        std::cout << std::endl << "This is a last read vector from buffer after the all threads has ended." << std::endl;
        std::cout << std::endl;

        DataVectorFromBuffer = imagSDK.get_DataFromBuffer();
        widthAndHeightVectorFrombuffer = imagSDK.get_widthAndHeightFromBuffer();

        widthFromBuffer = widthAndHeightVectorFrombuffer[0];
        heightFromBuffer = widthAndHeightVectorFrombuffer[1];
    }

    for(int row_index {}; row_index < heightFromBuffer; ++row_index)
        for(int column_index {}; column_index < widthFromBuffer; ++column_index)
            std::cout << "pixel: (" << row_index << ", " << column_index << "), value: " << DataVectorFromBuffer[row_index*widthFromBuffer + column_index] << std::endl;

    std::cout << std::endl;
    std::cout << "Producer Calls: " << imagSDK.get_ProducerCount() << std::endl;
    std::cout << "Consumer Calls: " << imagSDK.get_ConsumerCount() << std::endl;
    std::cout << std::endl;

    bool positive = imagSDK.get_isWidthAndHeightPositive();
    bool big = imagSDK.get_isWidthAndHeightNotBig();
    bool divided = imagSDK.get_isWidthAndHeightDividibleByTwo();

    std::cout << (positive == false ? "Some width/height value were <= 0." : "") << std::endl;
    std::cout << (big == false ? "Some width/height value were too much big." : "") << std::endl;
    std::cout << (divided == false ? "Some width/height value were not dividible by 2." : "") << std::endl;

    if(big == false)
        std::cout << std::endl << "MAX_WIDTH = " << MAX_WIDTH << ", MAX_HEIGHT = " << MAX_HEIGHT << std::endl << std::endl;

    std::vector<std::vector<int>> wrongWidthHeight = imagSDK.get_wrongWidthAndHeight();
    int rows = imagSDK.get_wrongWidthAndHeightCount();

    std::cout << std::endl;
    if(positive == false || big == false || divided == false)
        std::cout << "There was something wrong with these (width, height) pairs:" << std::endl << std::endl;

    if(imagSDK.get_wrongWidthAndHeightExecutedAtLeastOnce() == true)
        for(int row_index {}; row_index < rows; ++row_index)
            std::cout << "(width, height) = (" << wrongWidthHeight[row_index][0] << ", " << wrongWidthHeight[row_index][1] << ")" << std::endl;

    p_testImage = nullptr;
    delete p_testImage;
}
