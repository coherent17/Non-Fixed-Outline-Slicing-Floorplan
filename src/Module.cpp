#include "Module.h"

Module::Module(int Module_ID, int Area){
    this->Module_ID = Module_ID;
    this->Module_Name = "M" + to_string(Module_ID);
    this->Area = Area;

    // Find possible width / length of the soft block
    vector<pair<int, int>> Width_Length_Combination_Int;
    vector<pair<double, double>> Width_Length_Combination_Double;
    
    // Find possible integer factor
    for(int i = 1; i <= Area; i++){
        if(Area % i == 0){
            double Width = i;
            double Length = Area / i;
            double Aspect_Ratio = Width / Length;
            Width_Length_Combination_Int.push_back({Width, Length});
            if(Aspect_Ratio >= MIN_ASPECT_RATIO && Aspect_Ratio <= MAX_ASPECT_RATIO){
                Width_Length_Combination_Double.push_back({Width, Length});
            }
        }
    }

    // Divide by factor to find the length & width in floating number
    
    const vector<int> factor = {2, 4, 5, 8, 10};
    for(size_t i = 0; i < factor.size(); i++){
        for(const pair<int, int>& p: Width_Length_Combination_Int){
            double Width = p.first;
            double Length = p.second;
            double New_Width;
            double New_Length;
            double New_Aspect_Ratio;

            // 2-factor
            New_Width = Width * factor[i];
            New_Length = Length / factor[i];
            New_Aspect_Ratio = New_Width / New_Length;
            if(New_Aspect_Ratio >= MIN_ASPECT_RATIO && New_Aspect_Ratio <= MAX_ASPECT_RATIO){
                Width_Length_Combination_Double.push_back({New_Width, New_Length});
            }
        }
    }

    // remove the duplicate width & length in the vector
    sort(Width_Length_Combination_Double.begin(), Width_Length_Combination_Double.end());
    Width_Length_Combination_Double.erase(unique(Width_Length_Combination_Double.begin(), Width_Length_Combination_Double.end()), Width_Length_Combination_Double.end());
    this->Width_Length_Combination = Width_Length_Combination_Double;
}

Module::~Module(){

}

ostream &operator<<(ostream &out, const Module &m){
    out << m.Module_Name << " Area: " << m.Area << endl;
    assert(m.Width_Length_Combination.size() > 0);
    for(size_t i = 0; i < m.Width_Length_Combination.size(); i++){
        double W = m.Width_Length_Combination[i].first;
        double L = m.Width_Length_Combination[i].second;
        double Aspect_Ratio = W / L;
        assert(abs(W * L - double(m.Area)) < CALCULATION_ERROR_THRESHOLD);
        assert(Aspect_Ratio >= MIN_ASPECT_RATIO && Aspect_Ratio <= MAX_ASPECT_RATIO);
        out << "(W/L/W*L/Ratio): \t" << W << "\t" << L << "\t" << W*L << "\t" << Aspect_Ratio << endl;
    }
    return out;
}