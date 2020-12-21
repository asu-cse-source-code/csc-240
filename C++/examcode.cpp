#include <iostream>
using namespace std;

void computeVolumeAndDiagonal( double _arcLength, double _PI, 
                               double &_diagonal, double &_volume);
                              

int main(){
{
    const double PI = 3.14159; 
    double diagonal, arcLength, volume;
    
    while(arc <= 0){
   
        cout << "Please give the arc length of smaller polystrudel: "<< endl;
        cin >> arc;
        if (arcLength <= 0){
        cout << "The length cannot be negative silly!" << endl;
        }
   
   
    computeVolumeAndDiagonal(arc, PI, diagonal, volume);
    
   

return 0;
    }
}
//Calculate diagonal and volume
void computeVolumeAndDiagonal( double _arcLength, double _PI, 
                               double &_diagonal, double &_volume){
   // (PI) * (arcLength/2) is stored in the address by the pointer *diagonal    
   _diagonal = _PI*(_arcLength/2);
   // (4/3) * (arcLength) is stored in the address by the pointer *voulme    
   _volume = (4/3)*_arcLength*_diagonal;
}
//How to call the function
//computeVolumeAndDiagonal( a, pie, &d, &v);
