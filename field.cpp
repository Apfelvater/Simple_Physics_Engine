#include <iostream>
#include <vector>

#define INIT_CHAR 96

using namespace std;

class Field {

    private:
    int max_size;
    vector<vector<int>> field_vector;

    public:
    Field(int max_size) max_size(max_size) {
        field_vector = new vector<vector<int>>(max_size, new vector<int>(max_size, INIT_CHAR));
    }
    ~Field() {
        for (vec : field_vector) {
            delete vec;
        }
        delete field_vector;
    }

    void draw_field() {
        string cout_string = "";
        for(int i = 0; i < ; i++) {
            for(int j = 0; j < ; j++) {
                cout_string.append(field_vector[i][j]);
            }
        }
    } 
}




