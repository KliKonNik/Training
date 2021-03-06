/** Задача состоит в том, чтобы выбрать, какие предметы, имеющие вес и стоимость, поместить в рюкзак ограниченной ёмкости W, да так, чтобы
 * максимизировать общую ценность его содержимого. Мы можем определить соотношение стоимости предмета к его весу, т. е. с «жадностью» выбирать
 * предметы, имеющие высокую стоимость, но в то же время маленький вес, а затем сортировать их по этим критериям. В задаче с дробным рюкзаком
 * нам разрешено брать дробные части предмета.
 */

#include "proccess.h"

constexpr int MAX_WEIGHT = 50;      /// kg
constexpr int MAX_PRICE = 100;      /// dollars

int main(int argc, char* argv)
{
    Proccess proc(MAX_WEIGHT, MAX_PRICE);

    proc.init();

    proc.display();

    proc.execute();

    proc.display();

    return 0;
}