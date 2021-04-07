#include "Direction.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

namespace ariel{
    
    class Board{
        
        private:
        std::vector<std::vector<char>> matrix;
        void postHorizontal(unsigned int row, unsigned int column, const std::string& s);
        void postVartical(unsigned int row, unsigned int column, const std::string& s);
        void readHorizontal(unsigned int row, unsigned int column, unsigned int s);
        void readVartical(unsigned int row, unsigned int column, unsigned int s);

        void addRows(std::vector<std::vector<char>> &vec, unsigned int size, unsigned int c){
            std::vector<char> line(c);
            fill(line.begin(), line.end(), '_');
            for(unsigned int i=0; i<size; i++){
                vec.push_back(line);
            }
        }

        void addColumns(std::vector<std::vector<char>> &vec, unsigned int size, unsigned int sizeRow){
            unsigned int sizeCol = vec[0].size();
            for(unsigned int i=0; i<sizeRow; i++){
                vec[i].resize(size);
                fill(vec[i].begin()+sizeCol, vec[i].end(), '_');
            }
        }

        public:
        Board();
        void post(unsigned int row, unsigned int column, Direction d,const std::string& s);
        std::string read(unsigned int row, unsigned int column ,Direction d,unsigned int s);
        void show();
        ~Board();
    };

}