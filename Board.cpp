#include "Board.hpp"
#include <iostream>
#include <vector>
using namespace std;

namespace ariel{
    Board::Board(){
        this->matrix = vector<vector<char>>(1, vector<char> (1, '_'));
    }

    void Board::postHorizontal(unsigned int row, unsigned int column, const string& s){
        unsigned int sSize = s.length();
        unsigned int H = row+1-matrix.size();

        if(row>=matrix.size()){
            addRows(matrix, H, matrix[0].size());
        }
        if(column+sSize>matrix[0].size()){
            addColumns(matrix, column+sSize, matrix.size());
        }

    }

    void Board::postVartical(unsigned int row, unsigned int column, const string& s){
        unsigned int sSize = s.length();
        unsigned int V = row+sSize-matrix.size();

        if(row+sSize>matrix.size()){
            addRows(matrix, V, matrix[0].size());
        }
        if(column>=matrix[0].size()){
            addColumns(matrix, column+1, matrix.size());
        }
    }

    void Board::readHorizontal(unsigned int row, unsigned int column, unsigned int s){
        unsigned int H = row+1-matrix.size();
        if(row>=matrix.size()){
                addRows(matrix, H, matrix[0].size());
        }
        if(column+s>matrix[0].size()){
            addColumns(matrix, column+s, matrix.size());
        }
    }

    void Board::readVartical(unsigned int row, unsigned int column, unsigned int s){
        unsigned int V = row+s-matrix.size();
        if(row+s>matrix.size()){
            addRows(matrix, V, matrix[0].size());
        }
        if(column>=matrix[0].size()){
            addColumns(matrix, column+1, matrix.size());
        }
    }

    void Board::post(unsigned int row, unsigned int column, ariel::Direction d,const string& s){
        unsigned int sSize = s.length();

        if(sSize == 0){
            return;
        }
        
        if(d == Direction::Horizontal){   
            postHorizontal(row, column, s);

            unsigned int i=0;
            for(unsigned int j=column; j<sSize+column; j++){
                matrix.at(row).at(j) = s[i];
                i++;
            }

        }
        else{
            postVartical(row, column, s);

            unsigned int i=0;
            for(unsigned int j=row; j<sSize+row; j++){
                matrix.at(j).at(column) = s[i];
                i++;
            }
        }
    }

    string Board::read(unsigned int row, unsigned int column ,ariel::Direction d,unsigned int s){
        string message;
        
        if(d == Direction::Horizontal){
            readHorizontal(row, column, s);
            for(unsigned int j=column; j<s+column; j++){
                message += matrix.at(row).at(j);
            }
        }
        else{
            readVartical(row, column, s);
            for(unsigned int j=row; j<s+row; j++){
                message += matrix.at(j).at(column);
            }
        }
        return message;
    }

    void Board::show(){
        for(unsigned int i=0; i<matrix.size(); i++){
            cout << i << ": ";
            for(unsigned int j=0; j<matrix.size(); j++){
                cout << this->matrix.at(i).at(j) << " ";
            }
            cout << "\n\n";
        }
        cout << "\n";
    }

    Board::~Board(){

    }
}