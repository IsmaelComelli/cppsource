#include <vector>
#include <string>
#include <iostream>


using namespace std;

void add_dish(std::string szIngredient, std::string szDish, std::vector<std::vector<std::string>> & listIngredients)
    {
        std::vector<std::vector<std::string>>::iterator it;

        if (listIngredients.empty())
            {
                std::vector<std::string> ingredient;
                ingredient.push_back(szIngredient);
                ingredient.push_back(szDish);
                listIngredients.push_back(ingredient);
                return;
            }

        int i = 0;
        for(it = listIngredients.begin(); it < listIngredients.end(); it++)
            {

                std::string aux = listIngredients[i][0].data();

                if (szIngredient.compare(aux) == 0)
                    {
                        it[i].push_back(szDish);
                        return;
                    }

                i++;
            }

        std::vector<std::string> ingredient;
        ingredient.push_back(szIngredient);
        ingredient.push_back(szDish);
        listIngredients.push_back(ingredient);

        return;

    }

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {

    std::vector<std::vector<std::string>>::iterator itx;
    std::vector<std::string>::iterator ity;

    std::vector<std::vector<std::string>> ingrList = {};

    int i = 0;
    itx = dishes.begin();
    for (; itx < dishes.end(); itx++) //percorre elementos
        {
            ity = dishes[i].begin() + 1;
            for (; ity < dishes[i].end(); ity++) //percorre elementos
                {
                    std::string szIngredient = *ity;
                    std::string szDish = *dishes[i].begin();
                    add_dish(szIngredient, szDish, ingrList);
                }
            i++;
        }

    for (int i = 0; i < ingrList.size(); i++)
    {
        for (int j = 0; j < ingrList[i].size(); j++)
            {
                cout << ingrList[i][j]  << " ";
            }
        cout << "\n";
    }
    return ingrList;
}

int main()
    {
        std::vector<std::vector<std::string>> dishes;

        std::vector<std::string> ingredients;
        ingredients.push_back("salada");
        ingredients.push_back("alface");
        ingredients.push_back("tomate");
        ingredients.push_back("repolho");
        dishes.push_back(ingredients);

        std::vector<std::string> ingredients2;
        ingredients2.push_back("pizza");
        ingredients2.push_back("tomate");
        ingredients2.push_back("queijo");
        ingredients2.push_back("calabresa");
        dishes.push_back(ingredients2);

        std::vector<std::string> ingredients3;
        ingredients3.push_back("risoto");
        ingredients3.push_back("tomate");
        ingredients3.push_back("arroz");
        ingredients3.push_back("queijo");
        dishes.push_back(ingredients3);

        for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                    {
                        cout << " " << dishes[i][j];
                    }
                cout << "\n";
            }
        cout << "\n";
        groupingDishes(dishes);


        return 0;
    }
