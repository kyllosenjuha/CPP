#include <iostream>
#include <vector>
#include <iomanip>
#include <locale>
#include <iterator>


using namespace std;

int main()
{
    int counter {};
    int prod;
    int quant;
    double unit_p;

    std::vector<int> product;
    std::vector<int> quantity;
    std::vector<double> unit_price;
    std::vector<double> cost;
    double total_cost {};

    do {
        std::cout << "Give a product number (-1, ends): ";
        cin >> prod;

        if(prod == -1)
            break;

        std::cout << "Give a quantity: ";
        std::cin >> quant;

        std::cout << "Give a unit price: ";
        std::cin >> unit_p;

        product.push_back(prod);
        quantity.push_back(quant);
        unit_price.push_back(unit_p);

        cost.push_back((double)quant*unit_p);

        total_cost += (double)quant*unit_p;

        counter++;

    } while(prod != -1);

    std::cout << "------------------------------------------------" << std::endl;
    std::cout.width(12); std::cout << std::left << "Product";
    std::cout.width(12); std::cout << std::left << "Quantity";
    std::cout.width(12); std::cout << std::left << "Unit Price";
    std::cout.width(12); std::cout << std::left << "Cost" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for(int index {}; index<counter; ++index)
    {

        std::cout.width(12); std::cout << std::left << product[index];
        std::cout.width(12); std::cout << std::left << quantity[index];
        std::cout.width(12); std::cout << std::left << unit_price[index];
        std::cout.width(12); std::cout << std::left << cost[index] << std::endl;
    }

    std::cout.width(12); std::cout << std::left << "";
    std::cout.width(12); std::cout << std::left << "";
    std::cout.width(12); std::cout << std::left << "";
    std::cout.width(12); std::cout << std::left << total_cost << std::endl;

    std::cout << "------------------------------------------------" << std::endl;;

    return 0;
}
