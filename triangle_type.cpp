#include<iostream>
using namespace std;
int main(){
    double trig_sides[3];
    while(true){
        
        for ( int i = 0 ; i < 3 ; i++ ){
            cout << "Enter side #" << i+1 ": ";
            cin >> trig_sides[i];
        }
        
        double temp , a ,b ,c;
        for ( int outer = 0 ; outer < 3 ; outer++){
            
            for ( int inner = outer + 1 ; inner < 3 ; inner++ ){
                
                if(trig_sides[outer] < trig_sides[inner]){
                    temp = trig_sides[outer];
                    trig_sides[outer]=trig_sides[inner];
                    trig_sides[inner]=temp;
                }   
            }
            
        }
        a = trig_sides[0];
        b = trig_sides[1];
        c = trig_sides[2];
        
        if ( a >= b+c || b >= a+c || c >= b+a){
            cout << "can't form a traiangle" << endl;
            exit(0);
        }
        if ( (a*a)==(b*b)+(c*c) ){
            cout << "right traiangle" << endl;
        }
        if ( (a*a)>(b*b)+(c*c) ){
            cout << "not right triangle angle greater than π/2 radians" << endl;
        }
        if ( (a*a)<(b*b)+(c*c) ){
            cout << "not right triangle angle lesser than π/2 radians" << endl;
        }
        if ( a == b && b == c ){
            cout << "equalibrium triangle" << endl;
        }
        if ( a == b && b != c || c == b && b != a || a == c && c != b){
            cout << "different sides triangle" << endl;
        }
        
        cout << "1.Continue, 2.Exit ? ";
        int proceed; cin >> proceed;
        if ( proceed == 2 ) break;
           
    }
    
    return 0;
}
