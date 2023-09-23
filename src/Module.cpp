#include "Module.h"

Module::Module(int Module_ID, int Area){
    this->Module_ID = Module_ID;
    this->Module_Name = "M" + to_string(Module_ID);
    this->Area = Area;

    // Find possible width / length of the soft block
    vector<pair<int, int>> Width_Length_Combination_Int;
    set<pair<double, double>> Width_Length_Combination_Double_Set;
    vector<pair<double, double>> Width_Length_Combination_Double_Vector;
    
    // Find possible integer factor
    for(int i = 1; i <= Area; i++){
        if(Area % i == 0){
            double Width = i;
            double Length = Area / i;
            double Aspect_Ratio = Width / Length;
            Width_Length_Combination_Int.push_back({Width, Length});
            if(Aspect_Ratio >= MIN_ASPECT_RATIO && Aspect_Ratio <= MAX_ASPECT_RATIO){
                Width_Length_Combination_Double.insert({Width, Length});
            }
        }
    }

    // for (const pair<int, int>& p : Width_Length_Combination_Int) {
    //     cout << "Width: " << p.first << ", Length: " << p.second << endl;
    // }

    // Divide by 2 or 5 to find the length & width in the aspect ratio
    const vector<int> factor = {2, 4, 5, 8, 16, 25};
    for(int i = 0; i < factor.size(); i++){
        for(const pair<int, int>& p: Width_Length_Combination_Int){
            double Width = p.first;
            double Length = p.second;
            double New_Width;
            double New_Length;
            double New_Aspect_Ratio;

            // 2-factor
            New_Width = Width * 2;
            New_Length = Length / 2;
            New_Aspect_Ratio = New_Width / New_Length;
            if(New_Aspect_Ratio >= MIN_ASPECT_RATIO && New_Aspect_Ratio <= MAX_ASPECT_RATIO){
                Width_Length_Combination_Double.insert({New_Width, New_Length});
            }
        }
    }

    cout << "------------" << Module_Name << "---------------" << endl;
    if(Width_Length_Combination_Double.size() == 0){
        cout << "Error" << endl;
    }
    sort(Width_Length_Combination_Double.begin(), Width_Length_Combination_Double.end());
    for (const pair<double, double>& p : Width_Length_Combination_Double) {
        cout << "Width: " << p.first << ", Length: " << p.second << endl;
    }

}

Module::~Module(){

}