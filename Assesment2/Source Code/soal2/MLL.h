#ifndef MLL_H
#define MLL_H

#include <string>


struct Genre {
    std::string idGenre;
    std::string namaGenre;
};

struct Film {
    std::string idFilm;
    std::string judulFilm;
    int durasiFilm;     
    int tahunTayang;
    float ratingFilm;
};


struct NodeChild {
    Film info;
    NodeChild* next;
    NodeChild* prev;
};

struct ListChild {
    NodeChild* first;
    NodeChild* last;
};


struct NodeParent {
    Genre info;
    NodeParent* next;
    NodeParent* prev;
    ListChild child; 
};

struct ListParent {
    NodeParent* first;
    NodeParent* last;
};


void createListParent(ListParent& L);
void createListChild(ListChild& L);

NodeParent* alokasiNodeParent(const Genre& g);
NodeChild*  alokasiNodeChild(const Film& f);

void dealokasiNodeParent(NodeParent* p);
void dealokasiNodeChild(NodeChild* c);

void insertFirstParent(ListParent& L, NodeParent* p);
void insertLastChild(ListChild& L, NodeChild* c);

bool deleteAfterParent(ListParent& L, NodeParent* prec); 
void hapusListChild(ListChild& L);

void searchFilmByRatingRange(const ListParent& L, float minRating, float maxRating);
void printStrukturMLL(const ListParent& L);

NodeParent* findParentByID(ListParent& L, const std::string& idGenre);

#endif
