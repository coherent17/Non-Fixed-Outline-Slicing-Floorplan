#include "Module.h"

Module::Module(int Module_ID, int Area){
    this->Module_ID = Module_ID;
    this->Module_Name = "M" + to_string(Module_ID);
    this->Area = Area;

    // Find possible width / length of the soft block
    vector<pair<int, int>> Width_Height_Combination_Int;
    vector<pair<double, double>> Width_Height_Combination_Double;
    
    // Find possible integer factor
    for(int i = 1; i <= Area; i++){
        if(Area % i == 0){
            double Width = i;
            double Height = Area / i;
            double Aspect_Ratio = Width / Height;
            Width_Height_Combination_Int.push_back({Width, Height});
            if(Aspect_Ratio >= MIN_ASPECT_RATIO && Aspect_Ratio <= MAX_ASPECT_RATIO){
                Width_Height_Combination_Double.push_back({Width, Height});
            }
        }
    }

    // Divide by factor to find the length & width in floating number
    
    const vector<int> factor = {2, 4, 5, 8, 10};
    for(size_t i = 0; i < factor.size(); i++){
        for(const pair<int, int>& p: Width_Height_Combination_Int){
            double Width = p.first;
            double Height = p.second;
            double New_Width;
            double New_Height;
            double New_Aspect_Ratio;

            New_Width = Width * factor[i];
            New_Height = Height / factor[i];
            New_Aspect_Ratio = New_Width / New_Height;
            if(New_Aspect_Ratio >= MIN_ASPECT_RATIO && New_Aspect_Ratio <= MAX_ASPECT_RATIO){
                Width_Height_Combination_Double.push_back({New_Width, New_Height});
            }
        }
    }

    // remove the duplicate width & length in the vector
    sort(Width_Height_Combination_Double.begin(), Width_Height_Combination_Double.end());
    Width_Height_Combination_Double.erase(unique(Width_Height_Combination_Double.begin(), Width_Height_Combination_Double.end()), Width_Height_Combination_Double.end());
    this->Width_Height_Combination = Width_Height_Combination_Double;

    this->Width = Width_Height_Combination[0].first;
    this->Height = Width_Height_Combination[0].second;
}

Module::~Module(){

}

int Module::Get_Module_ID()const{
    return Module_ID;
}

string Module::Get_Module_Name()const{
    return Module_Name;
}

int Module::Get_Module_Area()const{
    return Area;
}

double Module::Get_Width()const{
    return Width;
}

double Module::Get_Height()const{
    return Height;
}

ostream &operator<<(ostream &out, const Module &m){
    out << m.Module_Name << " Area: " << m.Area << endl;
    assert(m.Width_Height_Combination.size() > 0);
    if(PRINT_MODULE_DETAIL){
        for(size_t i = 0; i < m.Width_Height_Combination.size(); i++){
            double W = m.Width_Height_Combination[i].first;
            double H = m.Width_Height_Combination[i].second;
            double Aspect_Ratio = W / H;
            assert(abs(W * H - double(m.Area)) < CALCULATION_ERROR_THRESHOLD);
            assert(Aspect_Ratio >= MIN_ASPECT_RATIO && Aspect_Ratio <= MAX_ASPECT_RATIO);
            out << "(W/H/W*H/Ratio): \t" << W << "\t" << H << "\t" << W*H << "\t" << Aspect_Ratio << endl;
        }
    }
    out << "Current (W/H): " << m.Get_Width() << "," << m.Get_Height() << endl;
    return out;
}