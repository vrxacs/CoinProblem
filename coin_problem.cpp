#include <vector>
#include <iostream>


using std::vector;

vector<vector<int>> getTriples(vector<int> &);
int sumTriple(vector<int> &);

int main(){

    vector<int> coins{1, 2, 5, 10, 20, 50};
    int amount = 374;

    //A list of all the possible combinations of coin types
    vector<vector<int>> triples = getTriples(coins);


    int sum;

    //For each triple, find the sum
    for(auto i = triples.begin(); i != triples.end(); ++i){
        sum = sumTriple(*i);

        if(amount % sum == 0)
            std::cout << amount / sum << " of " << i->at(0) << ", " << i->at(1) << ", " << i->at(2) << std::endl;

    }

    return 0;

}

int sumTriple(vector<int> &triple){

    int sum = 0;

    for(auto i = triple.begin(); i != triple.end(); ++i)
        sum += *i;

    return sum;

}

vector<vector<int>> getTriples(vector<int> &coins){

    vector<vector<int>> triples;

    for(auto i = coins.begin(); i != coins.end(); ++i){

        if(i + 2 != coins.end()){
            for(auto j = i+1; j != coins.end(); ++j){

                if(j + 1 != coins.end()){
                    for(auto k = j+1; k != coins.end(); ++k){
                        triples.push_back(vector<int>{*i, *j, *k});
                    }
                }
            }
        }
    }

    return triples;

}
