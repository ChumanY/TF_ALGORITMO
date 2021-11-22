#include "Libreria.hpp"
class Juego
{
   int Rank,Year;
   string Name, Platform, Genre, Publisher;
   float NA_Sales, EU_Sales, JP_Sales, Other_Sales, Global_Sales;
   
public:
    Juego(int Rank=0,string Name="", string Platform="", int Year=0, string Genre="", string Publisher="", float NA_Sales=0.00,
            float EU_Sales=0.00, float JP_Sales=0.00,float Other_Sales=0.00,float Global_Sales=0.00):Rank(Rank), Name(Name), Platform(Platform),Year(Year),
            Genre(Genre),Publisher(Publisher), NA_Sales(NA_Sales), EU_Sales(EU_Sales),JP_Sales(JP_Sales), Other_Sales(Other_Sales), 
            Global_Sales(Global_Sales){ }
 
    friend ostream& operator << (ostream& s, const Juego& j){
        s<<j.Rank<<" "<<j.Name<<" "<<j.Platform<<" "<<j.Year<<" "<<j.Genre<<" "<<j.Publisher<<" "<<j.NA_Sales<<" "<<j.EU_Sales<<" "<<j.JP_Sales<<" "<<j.Other_Sales<<" "<<j.Global_Sales<<endl;
        return s;
    }
    bool operator<(const Juego& j) {
		return this->Rank < j.Rank;
	}
    bool operator>=(const Juego& j) {
		return this->Rank >= j.Rank;
	}
  	bool operator>(const Juego& j) {
		return this->Rank > j.Rank;
	}
    bool operator==(const Juego& j) {
		return this->Rank == j.Rank;
	}
  
  int getRank(){return Rank;}
  int getYear(){return Year;}
  string getName(){return Name;}
  int setRank(int Rank){return this->Rank=Rank;}
};