//
//  automata.cpp
//  
//
//  Created by David Bohl on 4/15/14.
//
//

# include <iostream>
# include <vector>
# include <bitset>

using namespace std;

void calculateNextLevel (vector <int>&  _vector, bitset<8> _ruleAsBitset);

int main (int argc, char* argv[]){
    
    int length = 75;
    int numLevels = 34;
    int ruleNumber;
    
    if ( argc > 1 ) {
        ruleNumber = atoi(argv[1]);
    }
    else{
        cout << "please enter a number from 0-255 to see Wolfram Automaton" << endl;
        cin >> ruleNumber;
    }
    
    bitset<8> ruleAsBitset((long unsigned int)ruleNumber);
    
    cout << ruleNumber << " in binary is " << ruleAsBitset << endl;
    
   
    
    vector <int> autoVector;
    
    for (int i = 0; i < length; i++) {
        if ( i == (length/2) ) {
            autoVector.push_back(1);
        }
        else autoVector.push_back(0);
    }
    
    for (int j = 0; j < numLevels; j++) {
        
        for (int i = 0; i < length; i++) {
            
            if (autoVector[i] == 0)
                cout << ' ';
            else cout << '*';
            
        }
        
        calculateNextLevel (autoVector, ruleAsBitset);
        
        cout << endl;
    }
    
    return 0;
}

void calculateNextLevel (vector <int>&  _vector, bitset<8> _ruleAsBitset){ // rule 54
    //cout << "_ruleAsBitset [2] : " << _ruleAsBitset[2] << endl;
    
    
    //for (int i = 0; i < 8; i++) {
    //    cout << _ruleAsBitset[i];
    //}
    
    
    vector <int> oldVec = _vector;
    
   // cout << "vector -1 is :  " << oldVec[-1] << endl;
   // cout << "vector [size] is : " << oldVec[oldVec.size()] << endl;
    for (int i = 0; i < _vector.size(); i++) {
        
        if ( oldVec[i-1] == 1 && oldVec[i] == 1 && oldVec[i+1] == 1 ){
            _vector[i] = _ruleAsBitset[7];
        }
        else if ( oldVec[i-1] == 1 && oldVec[i] == 1 && oldVec[i+1] == 0 ){
            _vector[i] = _ruleAsBitset[6];
        }
        else if ( oldVec[i-1] == 1 && oldVec[i] == 0 && oldVec[i+1] == 1 ){
            _vector[i] = _ruleAsBitset[5];
        }
        else if ( oldVec[i-1] == 1 && oldVec[i] == 0 && oldVec[i+1] == 0 ){
            _vector[i] = _ruleAsBitset[4];
        }
        else if ( oldVec[i-1] == 0 && oldVec[i] == 1 && oldVec[i+1] == 1 ){
            _vector[i] = _ruleAsBitset[3];
        }
        else if ( oldVec[i-1] == 0 && oldVec[i] == 1 && oldVec[i+1] == 0 ){
            _vector[i] = _ruleAsBitset[2];
        }
        else if ( oldVec[i-1] == 0 && oldVec[i] == 0 && oldVec[i+1] == 1 ){
            _vector[i] = _ruleAsBitset[1];
        }
        else if ( oldVec[i-1] == 0 && oldVec[i] == 0 && oldVec[i+1] == 0 ){
            _vector[i] = _ruleAsBitset[0];
        }

    }
}