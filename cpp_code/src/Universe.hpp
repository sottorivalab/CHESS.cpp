#ifndef UNIVERSE_H
#define UNIVERSE_H

// Forward declerations: ///////////////////////////////////////////////////////
//class Phylogeny_Node;
class Cell;
class CellType;

// Includes: ///////////////////////////////////////////////////////////////////
#include <vector>
#include "boost/multi_array.hpp"
#include "CImg.h"

// Universe ////////////////////////////////////////////////////////////////////

class Universe {
    float mTime;
    boost::multi_array<Cell*, 3> mSpace; // the space
    std::vector<CellType*> mpTypes;
    //std::vector<Phylogeny> phylos;
    bool mLimitReached;
  public:
    // Constructor:
    Universe(int, int, int);

    // Destructor:
    //:ToDo: Add destructor

    // Getter functions:
    float Time();
    bool LimitIsReached();
    bool ContainsCell(int, int, int);
    bool ContainsCoordinate(int, int, int);
    class Cell* GetCell (int x, int y, int z);
    class Cell* RemoveCell (int, int, int);
    class CellType* NextReactionType(double&);
    std::vector< std::array<int, 3> > FreeNeighbours(int, int, int);

    // Setter functions:
    void IncrementTimeBy(float);
    void MarkLimitIsReached();
    bool InsertCell(int, int, int, Cell*);
    bool InsertCell(int, int, int, Cell*, bool);
    void RegisterType(CellType *);

    // Output Functions:
    void Print();
    void Display(cimg_library::CImg<unsigned char>*,
                 cimg_library::CImgDisplay*);
    void SpaceToCsvFile(std::string);
    void TypesToCsvFile(std::string);
    void PhylogeniesToCsvFiles(std::string);

    // Other functions:
    bool PushCell(int, int, int, int, int, int, unsigned int);

};

#endif // UNIVERSE_H