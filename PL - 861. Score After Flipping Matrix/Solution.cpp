//Runtime: 0 ms
//May 13, 2024


/**
OBJECTIVE: Given a binary matrix of size mXn. Return the highest possible score after making any number of moves (including zero moves).

TODO:
+ Caluclate the sum of the matrix             "gridCount"
+ Ensure the 1st Column, Col 0, is all 1's    "matrixScore"
+ Check if we are done (there is only 1 Col)  "matrixScore"
+ Max each Column (other than Col 0)          "matrixScore"
*/
class Solution {
public:

    //Calculates the max value of a binary matrix only using Row and Column Flips (0>1 & 1>0)
    int matrixScore(vector<vector<int>>& grid) {
        //MAX out Col 1 with Row flips (all of Col 1 should be 1's)
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] != 1){
                for(int j = 0; j < grid[i].size(); j++){
                    grid[i][j] = std::abs(grid[i][j] - 1);
                }
                // std::cout << "FLIP ROW " << i << std::endl; 
            }
        }

        //If the grid only consists of one row, we are done.
        if(grid[0].size() < 2){
            return gridCount(grid);
        }


        //MAX out each Col, using Col flips (skip Col 1 because we know it is maxed out)
        for (int j = 1; j < grid[0].size(); j++){
            int curCol = 0;
            int tmpCol = 0;

            //Caluclate the current Col sum, and the fliped Col sum
            for(int x = 0; x < grid.size(); x++){
                curCol += grid[x][j];
                tmpCol += std::abs(grid[x][j] - 1);
            }

            //If fliping the Col is greater than it is currently, we save this flip
            if(tmpCol > curCol){
                for(int x = 0; x < grid.size(); x++){
                    grid[x][j] = std::abs(grid[x][j] - 1);
                }
                // std::cout << "FLIP COL " << j << std::endl;
            }
        }

        return gridCount(grid);
    }

    //Converts each Row of the matrix ("grid") from binary to decimal, then sums each row of the matrix together
    int gridCount(vector<vector<int>>& grid){
        uint32_t sum = 0;
        
        for (int m = 0; m < grid.size(); m++){
            uint32_t  i = 0;

            for (int n = 0; n < grid[m].size(); n++){
                i = (i*2) + grid[m][n];
            }
            sum += i;
        }
        return sum;
    }
};
