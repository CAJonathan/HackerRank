#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

const char * read(int number){
    
    switch(number){
        case 0:{return "o' clock";}
        case 1:{return "one";}
        case 2:{return "two";}
        case 3:{return "three";}
        case 4:{return "four";}
        case 5:{return "five";}
        case 6:{return "six";}
        case 7:{return "seven";}
        case 8:{return "eight";}
        case 9:{return "nine";}
        case 10:{return "ten";}
        case 11:{return "eleven";}
        case 12:{return "twelve";}
        case 13:{return "thirteen";}
        case 14:{return "fourteen";}
        case 15:{return "quarter";}
        case 16:{return "sixteen";}
        case 17:{return "seventeen";}
        case 18:{return "eighteen";}
        case 19:{return "nineteen";}
        case 30:{return "half";}
        default: {return "";}
    }
}

void LOL(int h, int m){
    if(m > 30){
        m = 60 - m;
        if(m > 19){
            cout << "twenty " << ((m == 20) ? "" : read(m % 10)) << " minutes" << " to " << ((h == 12) ? read(1) : read(h + 1));
        } else{
            cout << read(m) << ((m == 15) ? "" : ((m != 1) ? " minutes" : " minute")) << " to " << ((h == 12) ? read(1) : read(h + 1));
        }
    } else{
        if(m == 0){
            cout << read(h) << " " << read(m);
        } else if(m > 19 && m < 30) {
            cout << "twenty " << ((m == 20) ? "" : read(m % 10)) << " minutes" << " past " << read(h);
        }else{
            cout << read(m) << ((m == 15 || m == 30) ? "" : ((m != 1) ? " minutes" : " minute")) << " past " << read(h);
        }
    }
}

int main(){
    // for(int i = 1 ; i < 13 ; i ++){
    //     for(int j = 0 ; j < 60 ; j ++){
    //         LOL(i, j);
    //         cout << endl;
    //     }
    // }
    int h, m;
    cin >> h >> m;
    LOL(h, m);
    return 0;
}