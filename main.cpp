//
//  main.cpp
//  URL DFA
//
//  Created by Zach Abdallah on 9/13/23.



#include <iostream>
#include <typeinfo>
using namespace std;
#include <vector>

int main(){
    string text;
    vector<string> accepted;
    cout << "please enter your text" << endl;
    getline(cin, text);
    text.push_back(' ');
    int currentState = 0;
    string word = "";
    for(string::iterator it = text.begin(); it != text.end(); ++it) {
        switch (currentState){
            case 0:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'h':
                        currentState = 1;
                        word.push_back(*it);
                        cout << "h encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                    default:
                        if (isdigit(*it)){
                            word.push_back(*it);
                            
                            if (*(it+1) == '.'){
                                cout << "d. intro" << endl;
                                currentState = 5;
                                cout << "going to state " << currentState << endl;
                            }
                            else if (isdigit(*(it+1))){
                                ++it;
                                word.push_back(*it);
                                
                                if (*(it+1) == '.'){
                                    cout << "dd. intro" << endl;
                                    currentState = 5;
                                    cout << "going to state " << currentState << endl;
                                }
                                
                                else if (isdigit(*(it+1))){
                                    ++it;
                                    word.push_back(*it);
                                    
                                    if (*(it+1) == '.'){ //it + 1 checks for the next character without actually iterating it; characters in c++ take up 1 bit i believe
                                        currentState = 5;
                                        cout << "ddd. intro" << endl;
                                        cout << "going to state " << currentState << endl;
                                    }
                                    else{
                                        currentState = 12;
                                        cout << "ddd? intro" << endl;
                                        cout << "going to state " << currentState << endl;
                                    }
                                }
                            }
                        }
                        else{
                            currentState = 12;
                            word.push_back(*it);
                            cout << "random text encountered, switching to state " << currentState << endl;
                            cout << " current word: " << word << endl;
                            break;
                        }
                }
                break;
            case 1:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 't':
                        currentState = 2;
                        word.push_back(*it);
                        cout << "t encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                    default:
                        currentState = 12;
                        word.push_back(*it);
                        cout << "random text encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                }
                break;
            case 2:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 't':
                        currentState = 3;
                        word.push_back(*it);
                        cout << "t encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                    default:
                        currentState = 12;
                        word.push_back(*it);
                        cout << "random text encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                }
                break;
            case 3:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'p':
                        currentState = 4;
                        word.push_back(*it);
                        cout << "p encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                    default:
                        currentState = 12;
                        word.push_back(*it);
                        cout << "random text encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                }
                break;
            case 4:
                switch(*it){
                    case ' ':
                        currentState = 0;
                        cout << "WEBSITE ENCOUNTRED: " << word << endl;
                        cout << "switch back to state " << currentState << endl;
                        accepted.push_back(word);
                        word = "";
                        break;
                    default:
                        currentState = 4;
                        word.push_back(*it);
                        cout << "text encountered, switching to state " << currentState << endl;
                        cout << " current word: " << word << endl;
                        break;
                }
                break;
            case 5:
                switch(*it){
                    case '.':
                        word.push_back(*it);
                        currentState = 6;
                        cout << ". encountered in case 5" << endl;
                        cout << "going to state " << currentState << endl;
                        break;
                    default:
                        word.push_back(*it);
                        cout << "default case entered on state 5" << endl;
                        currentState = 12;
                        cout << "going to state " << currentState << endl;
                        break;
                }
                break;
            case 6:
                if (isdigit(*it)){
                    word.push_back(*it);
                    ++it;
                    if (*it == '.'){
                        cout << "d. in case 6" << endl;
                        currentState = 7;
                        cout << "going to state " << currentState << endl;
                    }
                    else if (isdigit(*it)){
                        word.push_back(*it);
                        ++it;
                        if (*it == '.'){
                            cout << "dd. in case 6" << endl;
                            currentState = 7;
                            cout << "going to state " << currentState << endl;
                        }
                        else if (isdigit(*it)){
                            word.push_back(*it);
                            ++it;
                            if (*it == '.'){
                                currentState = 7;
                                cout << "ddd. in case 6" << endl;
                                cout << "going to state " << currentState << endl;
                            }
                            else{
                                currentState = 12;
                                cout << "ddd? in case 6" << endl;
                                cout << "going to state " << currentState << endl;
                            }
                        }
                    }
                }
            case 7:
                switch(*it){
                    case '.':
                        word.push_back(*it);
                        cout << ". encountered in case 7" << endl;
                        currentState = 8;
                        cout << "going to state " << currentState << endl;
                        break;
                    default:
                        word.push_back(*it);
                        cout << "default case encountered in case 7" << endl;
                        currentState = 12;
                        cout << "going to state " << currentState << endl;
                        break;
                }
                break;
            case 8:
                if (isdigit(*it)){
                    word.push_back(*it);
                    ++it;
                    if (*it == '.'){
                        cout << "d. case 8" << endl;
                        currentState = 9;
                        cout << "going to state " << currentState << endl;
                    }
                    else if (isdigit(*it)){
                        word.push_back(*it);
                        ++it;
                        if (*it == '.'){
                            cout << "dd. in case 8" << endl;
                            currentState = 9;
                            cout << "going to state " << currentState << endl;
                        }
                        else if (isdigit(*it)){
                            word.push_back(*it);
                            ++it;
                            if (*it == '.'){
                                currentState = 9;
                                cout << "ddd. in case 8" << endl;
                                cout << "going to state " << currentState << endl;
                            }
                            else{
                                currentState = 12;
                                cout << "ddd? in case 8" << endl;
                                cout << "going to state " << currentState << endl;
                            }
                        }
                    }
                }
            case 9:
                switch(*it){
                    case '.':
                        word.push_back(*it);
                        currentState = 10;
                        cout << ". encountered in case 9" << endl;
                        cout << "going to state " << currentState << endl;
                        break;
                    default:
                        word.push_back(*it);
                        cout << "default case encountered in case 9" << endl;
                        currentState = 12;
                        cout << "going to state " << currentState << endl;
                        break;
                }
                break;
            case 10:
            
                    if (isdigit(*it)){
                        word.push_back(*it);
                        ++it;
                        if (!(isdigit(*it))){
                            cout << "d? encountered in state 10" << endl;
                            currentState = 11;
                            word.push_back(*it);
                            cout << "going to state " << currentState << endl;
                        }
                        else{//otherwise dd
                            cout << "dd encountered in state 10" << endl;
                            word.push_back(*it);
                            ++it;
                            if (!(isdigit(*it))){
                                cout << "dd? encountered in state 10" << endl;
                                currentState = 11;
                                word.push_back(*it);
                                cout << "going to state " << currentState << endl;
                            }
                            else{//ddd
                                cout << "ddd encountered in state 10" << endl;
                                word.push_back(*it);
                                ++it;
                                if (isdigit(*it)){
                                    cout << "dddd encountered in case 10" << endl;
                                    word.push_back(*it);
                                    currentState = 12;
                                    cout << "going to state " << currentState << endl;
                                }
                                else{
                                    cout << "ddd? encountered in case 10" << endl;
                                    if (*it == ' '){
                                        cout << "?==' ', revert to state 0" << endl;
                                        currentState = 0;
                                        cout << "going to state " << currentState << endl;
                                    }
                                    else{
                                        word.push_back(*it);
                                        currentState = 11;
                                        cout << "going to state " << currentState << endl;
                                    }
                                }
                            }
                        }
                    }
            
                break;
            
            case 11:
                
                switch(*it){
                    case ' ':
                        cout << "website encountered" << endl;
                        accepted.push_back(word);
                        word = "";
                        currentState = 0;
                        break;
                    default:
                        string word_iterator = word;
                        int numberOne, numberTwo, numberThree, numberFour;
                        int x = 0;
                        for (int i = 0; i <= 3; ++i){//0.0.0.0xxx
                            string temp = "";
                            for(string::iterator jj = word_iterator.begin() + x; jj != word_iterator.end(); ++jj){
                                ++x;
                                if (*jj == '.'){
                                    break;
                                }
                                if (isdigit(*jj)){
                                    temp.push_back(*jj);
                                }
                                else{
                                    break;
                                }
                            }
                            cout << "i = " << i << endl;
                            if (i == 0){
                                numberOne = stoi(temp);
                                cout << "the first number is: " << numberOne <<endl;
                            }
                            else if (i == 1){
                                numberTwo = stoi(temp);
                                cout << "the second number is: " << numberTwo <<endl;
                            }
                            else if (i == 2){
                                numberThree = stoi(temp);
                                cout << "the third number is: " << numberThree <<endl;
                            }
                            else if (i == 3){
                                numberFour = stoi(temp);
                                cout << "the fourth number is: " << numberFour <<endl;
                            }
                        }
                        for (int i = 0; i <= 3; ++i){
                            if (i == 0){
                                if (numberOne < 0 || numberOne > 255){
                                    cout << "The first number is either too small or too large. Is not part of an IP address" << endl;
                                    cout << "switching to state 0" << endl;
                                    currentState = 0;
                                    break;
                                }
                            }
                            if (i == 1){
                                if (numberTwo < 0 || numberTwo > 255){
                                    cout << "The second number is either too small or too large. Is not part of an IP address" << endl;
                                    cout << "switching to state 0" << endl;
                                    currentState = 0;
                                    break;
                                }
                            }
                            if (i == 2){
                                if (numberThree < 0 || numberThree > 255){
                                    cout << "The third number is either too small or too large. Is not part of an IP address" << endl;
                                    cout << "switching to state 0" << endl;
                                    currentState = 0;
                                    break;
                                }
                            }
                            if (i == 3){
                                if (numberFour < 0 || numberFour > 255){
                                    cout << "The fourth number is either too small or too large. Is not part of an IP address" << endl;
                                    cout << "switching to state 0" << endl;
                                    currentState = 0;
                                    break;
                                }
                            }
                        }
                        word.push_back(*it);
                        break;
                }
                break;
            case 12:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case '@':
                        while (*it != ' '){
                            ++it;
                        }
                        word = "";
                        currentState = 0;
                        cout << "@ encountered. go to state " << currentState << endl;
                        break;
                    case '.':
                        word.push_back(*it);
                        currentState = 13;
                        cout << "(.) encountered, go to state 13." << endl;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 12;
                        cout << "random text encountered, recurse onto state " << currentState << endl;
                        cout << "the word is " << word << endl;
                        break;
                }
                break;
            case 13:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'c':
                        word.push_back(*it);
                        currentState = 14;
                        break;
                    case 'e':
                        word.push_back(*it);
                        currentState = 15;
                        break;
                    case 'o':
                        word.push_back(*it);
                        currentState = 16;
                        break;
                    case 'n':
                        word.push_back(*it);
                        currentState = 17;
                        break;
                    case 'g':
                        word.push_back(*it);
                        currentState = 18;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 14:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'o':
                        word.push_back(*it);
                        currentState = 19;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 15:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'd':
                        word.push_back(*it);
                        currentState = 20;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 16:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'r':
                        word.push_back(*it);
                        currentState = 21;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 17:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'e':
                        word.push_back(*it);
                        currentState = 22;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 18:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'o':
                        word.push_back(*it);
                        currentState = 23;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 19:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'm':
                        word.push_back(*it);
                        currentState = 24;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 20:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'u':
                        word.push_back(*it);
                        currentState = 24;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 21:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'g':
                        word.push_back(*it);
                        currentState = 24;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 22:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 't':
                        word.push_back(*it);
                        currentState = 24;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 23:
                switch(*it){
                    case ' ':
                        word = "";
                        currentState = 0;
                        break;
                    case 'v':
                        word.push_back(*it);
                        currentState = 24;
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 0;
                        break;
                }
                break;
            case 24: //accepting state
                switch(*it){
                    case ' ':
                        cout << "WEBSITE FOUND: " << endl;
                        cout << word << endl;
                        currentState = 0;
                        accepted.push_back(word);
                        word = "";
                        break;
                    default:
                        word.push_back(*it);
                        currentState = 24;
                        break;
                }
                break;
        }
    }
    cout << endl << endl;
    cout << "Here is what was found: " << endl << endl;
    for (int i = 0; i < accepted.size(); ++i){
        cout << accepted[i] << endl;
    }
    cout << endl;
    return 0;
}
