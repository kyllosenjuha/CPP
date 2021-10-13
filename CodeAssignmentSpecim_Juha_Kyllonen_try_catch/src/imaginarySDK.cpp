#include "imaginarySDK.h"
#include <iostream>

imaginarySDK::imaginarySDK()
{
    //ctor
}

imaginarySDK::~imaginarySDK()
{
    //dtor
}

void imaginarySDK::onDataCallback(unsigned short* dataPtr, int width, int height)
{
    std::thread producer_thread(&ProCon::producer, dataPtr, width, height);
    producer_thread.join();
}

void imaginarySDK::readDataFromBuffer()
{
    std::thread consumer_thread(&ProCon::consumer);
    consumer_thread.join();
}

void imaginarySDK::ifWidthAndHeightAreValid_MakeOnDataCallback(unsigned short* dataPtr, int width, int height)
{
    imaginarySDK imagSDK;

    if(imagSDK.areWidthAndHeightValid(width, height))
    {
        std::thread write_thread(&imaginarySDK::onDataCallback, dataPtr, width, height);
        write_thread.join();
    }
}

bool imaginarySDK::areWidthAndHeightValid(int width, int height)
{
    std::lock_guard<std::mutex> guard(width_height_mutex);

    imaginarySDK imagSDK;

    if(width <= 0 || height <= 0)
    {
        isWidthAndHeightPositive=false;
        imagSDK.writeWrongWidthAndHeight_2D(width, height);
        return false;
    }
    else
        if(width > MAX_WIDTH || height > MAX_HEIGHT)
        {
            isWidthAndHeightNotBig=false;
            imagSDK.writeWrongWidthAndHeight_2D(width, height);
            return false;
        }
        else
            if(!(width % 2 == 0 && height % 2 == 0))
            {
                isWidthAndHeightDividibleByTwo=false;
                imagSDK.writeWrongWidthAndHeight_2D(width, height);
                return false;
            }
            else
            {
                return true;
            }
}

void imaginarySDK::writeWrongWidthAndHeight_2D(int width, int height)
{
    if(MAX_ERRORBUFFER_DEPTH > 0)
    {
        if(wrongWidthAndHeightCount < MAX_ERRORBUFFER_DEPTH)
        {
            wrongWidthAndHeightExecutedAtLeastOnce=true;

            try
            {
                wrongWidthAndHeight_2D.push_back(std::vector<int>());
                wrongWidthAndHeight_2D[wrongWidthAndHeightCount].push_back(width);
                wrongWidthAndHeight_2D[wrongWidthAndHeightCount].push_back(height);
                wrongWidthAndHeightCount++;
            }
            catch(std::bad_alloc& ba)
            {
                std::cerr << "wrongWidthAndHeight_2D, bad_alloc caught: " << ba.what() << '\n';
                exit(0);
            }
        }
        else
        {
            try
            {
                wrongWidthAndHeight_2D.erase(wrongWidthAndHeight_2D.begin());
                wrongWidthAndHeight_2D.push_back(std::vector<int>());
                wrongWidthAndHeight_2D[wrongWidthAndHeightCount-1].push_back(width);
                wrongWidthAndHeight_2D[wrongWidthAndHeightCount-1].push_back(height);
            }
            catch(std::bad_alloc& ba)
            {
                std::cerr << "wrongWidthAndHeight_2D, bad_alloc caught: " << ba.what() << '\n';
                exit(0);
            }
        }
    }
}

std::mutex imaginarySDK::width_height_mutex;
bool imaginarySDK::isWidthAndHeightPositive {true};
bool imaginarySDK::isWidthAndHeightNotBig {true};
bool imaginarySDK::isWidthAndHeightDividibleByTwo {true};
std::vector<std::vector<int>> imaginarySDK::wrongWidthAndHeight_2D;
int imaginarySDK::wrongWidthAndHeightCount {};
bool imaginarySDK::wrongWidthAndHeightExecutedAtLeastOnce {false};
