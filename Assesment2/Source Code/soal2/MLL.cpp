#include "MLL.h"
#include <iostream>
#include <iomanip>
#include <sstream>


static std::string formatRating(float r) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << r;
    std::string s = oss.str();

    if (s.find('.') != std::string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }
    return s;
}


void createListParent(ListParent& L) {
    L.first = nullptr;
    L.last  = nullptr;
}

void createListChild(ListChild& L) {
    L.first = nullptr;
    L.last  = nullptr;
}


NodeParent* alokasiNodeParent(const Genre& g) {
    NodeParent* p = new NodeParent;
    p->info = g;
    p->next = nullptr;
    p->prev = nullptr;
    createListChild(p->child);
    return p;
}

NodeChild* alokasiNodeChild(const Film& f) {
    NodeChild* c = new NodeChild;
    c->info = f;
    c->next = nullptr;
    c->prev = nullptr;
    return c;
}


void dealokasiNodeParent(NodeParent* p) {
    delete p;
}

void dealokasiNodeChild(NodeChild* c) {
    delete c;
}


void insertFirstParent(ListParent& L, NodeParent* p) {
    if (p == nullptr) return;

    if (L.first == nullptr) { 
        L.first = p;
        L.last  = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}


void insertLastChild(ListChild& L, NodeChild* c) {
    if (c == nullptr) return;

    if (L.first == nullptr) { 
        L.first = c;
        L.last  = c;
    } else {
        c->prev = L.last;
        L.last->next = c;
        L.last = c;
    }
}

void hapusListChild(ListChild& L) {
    NodeChild* cur = L.first;
    while (cur != nullptr) {
        NodeChild* nxt = cur->next;
        dealokasiNodeChild(cur);
        cur = nxt;
    }
    L.first = nullptr;
    L.last  = nullptr;
}

bool deleteAfterParent(ListParent& L, NodeParent* prec) {
    if (prec == nullptr) return false;
    if (prec->next == nullptr) return false;

    NodeParent* del = prec->next;

    // relink next
    prec->next = del->next;
    if (del->next != nullptr) {
        del->next->prev = prec;
    } else {
        L.last = prec; 
    }


    hapusListChild(del->child);

    dealokasiNodeParent(del);
    return true;
}


void searchFilmByRatingRange(const ListParent& L, float minRating, float maxRating) {
    bool found = false;

    NodeParent* p = L.first;
    int posParent = 1;

    while (p != nullptr) {
        NodeChild* c = p->child.first;
        int posChild = 1;

        while (c != nullptr) {
            float r = c->info.ratingFilm;

            if (r >= minRating && r <= maxRating) {
                found = true;

                std::cout << "Data Film ditemukan pada list child dari node parent "
                          << p->info.namaGenre << " pada posisi ke-" << posChild << "!\n";

                std::cout << "--- Data Film (Child) ---\n";
                std::cout << "Judul Film : " << c->info.judulFilm << "\n";
                std::cout << "Posisi dalam list child : posisi ke-" << posChild << "\n";
                std::cout << "ID Film : " << c->info.idFilm << "\n";
                std::cout << "Durasi Film : " << c->info.durasiFilm << " menit\n";
                std::cout << "Tahun Tayang : " << c->info.tahunTayang << "\n";
                std::cout << "Rating Film : " << formatRating(c->info.ratingFilm) << "\n";

                std::cout << "-----------------------------\n";

                std::cout << "--- Data Genre (Parent) ---\n";
                std::cout << "ID Genre : " << p->info.idGenre << "\n";
                std::cout << "Posisi dalam list parent : posisi ke-" << posParent << "\n";
                std::cout << "Nama Genre : " << p->info.namaGenre << "\n";

                std::cout << "============================================\n";
            }

            c = c->next;
            posChild++;
        }

        p = p->next;
        posParent++;
    }

    if (!found) {
        std::cout << "Tidak ada film pada rentang rating "
                  << formatRating(minRating) << " - " << formatRating(maxRating) << ".\n";
    }
}


void printStrukturMLL(const ListParent& L) {
    NodeParent* p = L.first;
    int idxParent = 1;

    while (p != nullptr) {
        std::cout << "=== Parent " << idxParent << " ===\n";
        std::cout << "ID Genre : " << p->info.idGenre << "\n";
        std::cout << "Nama Genre : " << p->info.namaGenre << "\n";

        NodeChild* c = p->child.first;
        int idxChild = 1;

        while (c != nullptr) {
            std::cout << " - Child " << idxChild << " :\n";
            std::cout << "    ID Film : " << c->info.idFilm << "\n";
            std::cout << "    Judul Film : " << c->info.judulFilm << "\n";
            std::cout << "    Durasi Film : " << c->info.durasiFilm << " menit\n";
            std::cout << "    Tahun Tayang : " << c->info.tahunTayang << "\n";
            std::cout << "    Rating Film : " << formatRating(c->info.ratingFilm) << "\n";
            c = c->next;
            idxChild++;
        }

        std::cout << "-----------------------------\n";
        p = p->next;
        idxParent++;
    }
}


NodeParent* findParentByID(ListParent& L, const std::string& idGenre) {
    NodeParent* p = L.first;
    while (p != nullptr) {
        if (p->info.idGenre == idGenre) return p;
        p = p->next;
    }
    return nullptr;
}
