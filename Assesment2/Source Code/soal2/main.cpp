#include <iostream>
#include "MLL.h"

int main() {
    ListParent LP;
    createListParent(LP);

    NodeParent* G001 = alokasiNodeParent({"G001", "Action"});
    NodeParent* G002 = alokasiNodeParent({"G002", "Comedy"});
    NodeParent* G003 = alokasiNodeParent({"G003", "Horror"});
    NodeParent* G004 = alokasiNodeParent({"G004", "Romance"});

    insertFirstParent(LP, G004);
    insertFirstParent(LP, G003);
    insertFirstParent(LP, G002);
    insertFirstParent(LP, G001);

    NodeParent* p;

    p = findParentByID(LP, "G001");
    insertLastChild(p->child, alokasiNodeChild({"FA001", "The Raid", 101, 2011, 7.6f}));

    p = findParentByID(LP, "G002");
    insertLastChild(p->child, alokasiNodeChild({"FC001", "Agak Laen", 119, 2024, 8.0f}));
    insertLastChild(p->child, alokasiNodeChild({"FC002", "My Stupid Boss", 108, 2016, 6.8f}));

    p = findParentByID(LP, "G003");
    insertLastChild(p->child, alokasiNodeChild({"FH001", "Pengabdi Setan", 107, 2017, 8.4f}));

    p = findParentByID(LP, "G004");
    insertLastChild(p->child, alokasiNodeChild({"FR001", "Habibie & Ainun", 118, 2012, 7.6f}));
    insertLastChild(p->child, alokasiNodeChild({"FR002", "Dilan 1990", 110, 2018, 6.6f}));

    printStrukturMLL(LP);

    searchFilmByRatingRange(LP, 8.0f, 8.5f);

    NodeParent* prec = findParentByID(LP, "G001");
    deleteAfterParent(LP, prec);
   
    printStrukturMLL(LP);
    
    NodeParent* cur = LP.first;
    while (cur != nullptr) {
        NodeParent* next = cur->next;
        hapusListChild(cur->child);
        dealokasiNodeParent(cur);
        cur = next;
    }
    createListParent(LP);

    return 0;
}
