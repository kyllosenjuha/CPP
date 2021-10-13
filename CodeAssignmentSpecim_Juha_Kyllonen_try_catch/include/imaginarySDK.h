#ifndef IMAGINARYSDK_H
#define IMAGINARYSDK_H

#include "ProCon.h"

class imaginarySDK : public ProCon
{
    public:
        imaginarySDK();
        virtual ~imaginarySDK();

        static void onDataCallback(unsigned short* dataPtr, int width, int height);
        static void readDataFromBuffer();
        static void ifWidthAndHeightAreValid_MakeOnDataCallback(unsigned short* dataPtr, int width, int height);
        bool areWidthAndHeightValid(int width, int height);
        bool get_isWidthAndHeightPositive() const {return isWidthAndHeightPositive;};
        bool get_isWidthAndHeightNotBig() const {return isWidthAndHeightNotBig;};
        bool get_isWidthAndHeightDividibleByTwo() const {return isWidthAndHeightDividibleByTwo;};
        std::vector<std::vector<int>> get_wrongWidthAndHeight() const {return wrongWidthAndHeight_2D;};
        int get_wrongWidthAndHeightCount() const {return wrongWidthAndHeightCount;};
        bool get_wrongWidthAndHeightExecutedAtLeastOnce () const {return wrongWidthAndHeightExecutedAtLeastOnce;};
        static void writeWrongWidthAndHeight_2D(int width, int height);

    protected:

    private:
        static std::mutex width_height_mutex;
        static bool isWidthAndHeightPositive;
        static bool isWidthAndHeightNotBig;
        static bool isWidthAndHeightDividibleByTwo;
        static std::vector<std::vector<int>> wrongWidthAndHeight_2D;
        static int wrongWidthAndHeightCount;
        static bool wrongWidthAndHeightExecutedAtLeastOnce;
};

#endif // IMAGINARYSDK_H
