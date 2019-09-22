#include "csv.cpp"

using namespace std;

Food getFoodSelection(std::vector<Food> foodVectorIn,  int noveltyChoice);

Food getLeastEatenFood(std::vector<Food> foodVectorIn);
Food getMostEatenFood(std::vector<Food> foodVectorIn);

int main(){
    int mealChoice;
    int novelty_choice_in;
    string meal;
    //user input
    cout<<"Select what meal you're cooking\n";
    cout<<"[0] Breakfast\n";
    cout<<"[1] Lunch\n";
    cout<<"[2] Dinner\n";
    cout<<"[3] Snack\n";
    cout<<"Enter here : ";
    cin>>mealChoice;
    while(mealChoice < 0 || mealChoice > 3){
        std::cout << "Not valid, please select 0-3?\n";
        std::cout << "Enter Here: ";
        std::cin>>mealChoice;
    }
    switch(mealChoice){
        case(0):
            meal = "Breakfast";
            break;
        case(1):
            meal = "Lunch";
            break;
        case(2):
            meal= "Dinner";
            break;
        case(3):
            meal="Snack";
            break;

    };
    cout<<"\n\n";
    cout<<"Do you want something new or an old favorite?\n";
    cout<<"[0] New\n";
    cout<<"[1] Old Favorite\n";
    cout<<"Enter here : ";
    cin>>novelty_choice_in;
    while(novelty_choice_in < 0 || novelty_choice_in > 1){
        std::cout << "Not valid, please select 0 or 1?\n";
        std::cout << "Enter Here: ";
        std::cin>>novelty_choice_in;
    }
    //Ingest csv database and create foods
    CSVReader reader("example.csv");
 
	// Get the data from CSV File
	std::vector<Food> dataList = reader.getData();

    Food finalRecomendation;

    std::vector<Food> foodForMeal;
 
    // Print the content of row by row on screen
    for (size_t i = 0; i < dataList.size(); i++)
    {
        //filter all the food for just the ones relevant to the meal
        if(dataList[i].getMeal() == meal){
            foodForMeal.push_back(dataList[i]);
        }
        
    }
    finalRecomendation = getFoodSelection(foodForMeal, novelty_choice_in);
    std::cout << "You should eat "<<finalRecomendation.getName()<<"\n";
    std::cout << "How would you rate it 0-5?\n";
    std::cout << "Enter Here: ";
    float rating = -1.0;
    std::cin>>rating;
    while(rating < 0 || rating > 5){
        std::cout << "Not valid, please rate 0-5?\n";
        std::cout << "Enter Here: ";
        std::cin>>rating;
    }
    finalRecomendation.updateRating(rating);

    //Add updated food back to dataset
    for (size_t i = 0; i < dataList.size(); i++)
    {
        //update reccomended food in dataList
        if(dataList[i].getName() == finalRecomendation.getName()){
            dataList[i] = finalRecomendation;
        }
        
    }
    //write updated dataset back to database
    reader.writeData(dataList);
    return 0;
}

Food getFoodSelection(std::vector<Food> foodVectorIn, int noveltyChoice){
    Food selectedFood;
    if(noveltyChoice == 0){
        selectedFood = getLeastEatenFood(foodVectorIn);
    }
    else{
        selectedFood = getMostEatenFood(foodVectorIn);
    }
    return selectedFood;
};

Food getLeastEatenFood(std::vector<Food> foodVectorIn){
    Food selectedFood = foodVectorIn[0];
    for (size_t i = 1; i < foodVectorIn.size(); i++){
        if(selectedFood.getTimesMade() >  foodVectorIn[i].getTimesMade()){
            selectedFood = foodVectorIn[i];
        }
    }
    return selectedFood;
};


Food getMostEatenFood(std::vector<Food> foodVectorIn){
    Food selectedFood = foodVectorIn[0];
    for (size_t i = 1; i > foodVectorIn.size(); i++){
        if(selectedFood.getTimesMade() >  foodVectorIn[i].getTimesMade()){
            selectedFood = foodVectorIn[i];
        }
    }
    return selectedFood;
};
