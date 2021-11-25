#include <iostream>
#include <vector>

template<typename T, typename A> void swap(std::vector<T, A> &vect, size_t first, size_t second);
template<typename T, typename A> void sort(std::vector<T, A> &vect, size_t start, size_t end);
template<typename T, typename A> void print_vect(std::vector<T, A> &vect);

int main()
{
    std::vector<int> i_vect {1, 7, 9, 4, 2, 8, 5, 90, 50, 45, 3};
    std::vector<double> d_vect {-4.5, 2.9, 50.25, 10.5, 12.7, -100.9};
    std::vector<std::string> str {"Juha", "Matti", "Aarne", "Kekkonen"};

    std::cout << "unsorted vector:" << std::endl;

    print_vect(i_vect);
    print_vect(d_vect);
    print_vect(str);

    sort(i_vect, 0, size(i_vect)-1);
    sort(d_vect, 0, size(d_vect)-1);
    sort(str, 0, size(str)-1);

    std::cout << "sorted vector:" << std::endl;

    print_vect(i_vect);
    print_vect(d_vect);
    print_vect(str);

    return 0;
}

template<typename T, typename A> void swap(std::vector<T, A> &vect, size_t first, size_t second)
{
    auto temp{vect[first]};
    vect[first] = vect[second];
    vect[second] = temp;
}

template<typename T, typename A> void sort(std::vector<T, A> &vect, size_t start, size_t end)
{
    if(!(start < end))
        return;

    swap(vect, start, (start+end) / 2);

    size_t current {start};
    for(size_t i {start+1}; i <= end; i++)
    {
        if(vect[i] < vect[start])
            swap(vect, ++current, i);
    }

    swap(vect, start, current);

    if(current > start) sort(vect, start, current-1);
    if(end > current+1) sort(vect, current+1, end);
}

template<typename T, typename A> void print_vect(std::vector<T, A> &vect)
{
    for(auto x : vect)
        std::cout << x << ", ";

    std::cout << std::endl;
}
