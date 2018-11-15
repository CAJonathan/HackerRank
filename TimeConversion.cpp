#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

char * cut(char * str, int low, int high){
    if(low < 0 || high < 0 || low > strlen(str) || high > strlen(str) || low > high){
        return NULL;
    }
    int len = high - low + 1;
    char * strResult = new char[len];
    for(int i = low ; i <= high ; i ++){
        strResult[i - low] = str[i];
    }
    return strResult;
}

bool cmp(char * str1, const char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2){
        return false;
    }

    int i = 0;
    int j = 0;
    while(i < len1 && j < len2){
        if(str1[i] != str2[j]){
            return false;
        }
        i++;
        j++;
    }

    return true;
}

int main(){
    char * time = new char[10];
    cin >> time;

    int hour = atoi(cut(time, 0, 1));
    int minute = atoi(cut(time, 3, 4));
    int second = atoi(cut(time, 6, 7));
    char * session = cut(time, 8, 9);

    hour = cmp(session, "AM")?((hour == 12)?0:hour):((hour != 12)?(hour+12):hour);

    cout << ((hour < 10)?"0":"") << hour << ((minute < 10)?":0":":") << minute << ((second < 10)?":0":":") << second;

    return 0;
}