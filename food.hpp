#include <iostream>
#include <string>

using namespace std;

class Food{
    string name;
    int calories;
    int carbs;
    int fat;
    int protein;
    string meal;
    int timesMade;
    float rating;
public:
    Food();
    Food(string nameIn, int caloriesIn, int carbsIn, int fatIn, int proteinIn, string mealIn, int timesMadeIn, float ratingIn);
    void setName(string nameIn);
    void setCalories(int caloriesIn);
    void setCarbs(int carbsIn);
    void setFat(int fatIn);
    void setProtein(int proteinIn);
    void setMeal(string mealIn);
    void setTimesMade(int timesMadeIn);
    void setRating(float ratingIn);
    string getName();
    int getCalories();
    int getCarbs();
    int getFat();
    int getProtein();
    string getMeal();
    int getTimesMade();
    float getRating();
    void updateTimesMade();
    void updateRating(float rating);

};

Food::Food(){

};

Food::Food(string nameIn, int caloriesIn, int carbsIn, int fatIn, int proteinIn, string mealIn, int timesMadeIn, float ratingIn)
{
    name=nameIn;
    calories=caloriesIn;
    carbs=carbsIn;
    fat=fatIn;
    protein=proteinIn;
    meal=mealIn;
    timesMade=timesMadeIn;
    rating=ratingIn;
};

void Food::setName(string nameIn){
    name=nameIn;
}
void Food::setCalories(int caloriesIn){
    calories=caloriesIn;
}
void Food::setCarbs(int carbsIn){
    carbs=carbsIn;
}
void Food::setFat(int fatIn){
    fat=fatIn;
}
void Food::setProtein(int proteinIn){
    protein=proteinIn;
}
void Food::setMeal(string mealIn){
    meal=mealIn;
}
void Food::setTimesMade(int timesMadeIn){
    timesMade=timesMadeIn;
}
void Food::setRating(float ratingIn){
    rating=ratingIn;
}

string Food::getName(){
    return name;
}
int Food::getCalories(){
    return calories;
}
int Food::getCarbs(){
    return carbs;
}
int Food::getFat(){
    return fat;
}
int Food::getProtein(){
    return protein;
}
string Food::getMeal(){
    return meal;
}
int Food::getTimesMade(){
    return timesMade;
}
float Food::getRating(){
    return rating;
}

void Food::updateTimesMade(){
    timesMade = getTimesMade() + 1;
}

void Food::updateRating(float ratingIn){
    int timesMade = getTimesMade();
    float totalRating = getRating() * timesMade;
    totalRating += ratingIn;
    updateTimesMade();
    timesMade = getTimesMade();
    rating = totalRating/timesMade;
}